//
//  DryUMAnalytics.h
//  DryUM
//
//  Created by Ruiying Duan on 2019/7/19.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface DryUMAnalytics : NSObject

/// @说明 手动页面时长统计, 记录某个页面展示的时长
/// @参数 pageName:   统计的页面名称(视图控制器名称)
/// @参数 seconds:    单位为秒
/// @返回 void
+ (void)logPageView:(NSString *)pageName seconds:(int)seconds;

/// @说明 自动页面时长统计, 开始记录某个页面展示时长
/// @注释 必须配对调用beginLogPageView:和endLogPageView:两个函数来完成自动统计，若只调用某一个函数不会生成有效数据
/// @参数 pageName:   统计的页面名称(视图控制器名称)
/// @返回 void
+ (void)beginLogPageView:(NSString *)pageName;

/// @说明 自动页面时长统计, 结束记录某个页面展示时长
/// @注释 必须配对调用beginLogPageView:和endLogPageView:两个函数来完成自动统计，若只调用某一个函数不会生成有效数据
/// @参数 pageName:   统计的页面名称(视图控制器名称)
/// @返回 void
+ (void)endLogPageView:(NSString *)pageName;

/// @说明 自定义事件，数量统计
/// @注释 请先到友盟App管理后台的设置->编辑自定义事件 中添加相应的事件ID，然后在工程中传入相应的事件ID
/// @参数 eventId:    网站上注册的事件Id
/// @返回 void
+ (void)event:(NSString *)eventId;

/// @说明 自定义事件，数量统计
/// @注释 请先到友盟App管理后台的设置->编辑自定义事件 中添加相应的事件ID，然后在工程中传入相应的事件ID
/// @参数 eventId:    网站上注册的事件Id
/// @参数 label:      分类标签
///                  [不同的标签会分别进行统计，方便同一事件的不同标签的对比]
///                  [为nil或空字符串时后台会生成和eventId同名的标签]
/// @返回 voids
+ (void)event:(NSString *)eventId label:(nullable NSString *)label;

/// @说明 根据用户账号统计
/// @注释 友盟在统计用户时以设备为标准，如果需要统计应用自身的账号，请使用以下接口
///      [集成账号统计功能后，请到友盟管理后台我的产品-设置-应用信息，选择启动使用账号统计报表]
/// @参数 puid:   户账号ID(长度小于64字节)
/// @返回 void
+ (void)profileSignInWithPUID:(NSString *)puid;

/// @说明 根据用户账号统计
/// @注释 友盟在统计用户时以设备为标准，如果需要统计应用自身的账号，请使用以下接口
///      [集成账号统计功能后，请到友盟管理后台我的产品-设置-应用信息，选择启动使用账号统计报表]
/// @参数 puid:       户账号ID(长度小于64字节)
/// @参数 provider:   账号来源(长度小于32字节)
///                  [不能以下划线"_"开头，使用大写字母和数字标识]
///                  [如果是上市公司，建议使用股票代码，例:(微信登录:WECHAT)]
/// @返回 void
+ (void)profileSignInWithPUID:(NSString *)puid provider:(nullable NSString *)provider;

/// @说明 停止sign-in PUID的统计(退出登录时使用)
/// @返回 void
+ (void)profileSignOff;

/// @说明 设置经纬度
/// @参数 latitude:   纬度
/// @参数 longitude:  经度
/// @返回 void
+ (void)setLatitude:(double)latitude longitude:(double)longitude;

@end

NS_ASSUME_NONNULL_END

//
//  DryUMPush.h
//  DryUM
//
//  Created by Ruiying Duan on 2019/7/19.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// 结果回调
typedef void (^BlockDryUMPushResult)    (id _Nonnull responseObj, NSError *_Nonnull error);

@interface DryUMPush : NSObject

/// @说明 向友盟注册推送
/// @注释 在didFinishLaunchingWithOptions中调用
/// @参数 launchOptions: launchOptions
/// @返回 void
+ (void)registerRemoteNotifications:(nullable NSDictionary *)launchOptions;

/// @说明 设置是否允许SDK当应用在前台运行收到Push时弹出Alert框
/// @参数 value:  是否开启(默认YES:开启状态)
/// @返回 void
+ (void)configAutoAlert:(BOOL)value;

/// @说明 设置是否允许SDK自动清空角标
/// @参数 value:  是否清楚(默认YES:清除状态)
/// @返回 void
+ (void)configBadgeClear:(BOOL)value;

/// @说明 向友盟注册该设备的deviceToken
/// @说明 获取deviceToken后调用
/// @参数 deviceToken:    APNS返回的deviceToken
/// @返回 void
+ (void)registerDeviceToken:(NSData *)deviceToken;

/// @说明 应用处于运行时（前台、后台）的消息处理
/// @参数 userInfo:   消息参数
/// @返回 void
+ (void)didReceiveRemoteNotification:(NSDictionary *)userInfo;

/// @说明 绑定一个别名至设备
/// @参数 name:   别名
/// @参数 type:   平台类型
/// @参数 resp:   回调结果
/// @返回 void
+ (void)addAlias:(NSString *)name
            type:(NSString *)type
            resp:(BlockDryUMPushResult)resp;

/// @说明 绑定一个别名至设备，并解绑这个别名曾今绑定过的设备
/// @参数 name:   别名
/// @参数 type:   平台类型
/// @参数 resp:   回调结果
/// @返回 void
+ (void)setAlias:(NSString *)name
            type:(NSString *)type
            resp:(BlockDryUMPushResult)resp;

/// @说明 删除一个设备的别名绑定
/// @参数 name:   别名
/// @参数 type:   平台类型
/// @参数 resp:   回调结果
/// @返回 void
+ (void)removeAlias:(NSString *)name
               type:(NSString *)type
               resp:(BlockDryUMPushResult)resp;

@end

NS_ASSUME_NONNULL_END

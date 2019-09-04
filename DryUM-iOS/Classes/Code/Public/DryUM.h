//
//  DryUM.h
//  DryUM
//
//  Created by Ruiying Duan on 2019/7/19.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface DryUM : NSObject

/// @说明 注册友盟所有组件产品
/// @参数 appKey:     开发者在友盟官网申请的appkey
/// @参数 channel:    渠道标识(可设置nil表示"App Store")[可选参数]
/// @返回 void
+ (void)registerWithAppKey:(NSString *)appKey channel:(nullable NSString *)channel;

@end

NS_ASSUME_NONNULL_END

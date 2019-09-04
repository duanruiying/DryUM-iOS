//
//  DryUMAnalytics.m
//  DryUM
//
//  Created by Ruiying Duan on 2019/7/19.
//

#import <UMAnalytics/MobClick.h>
#import "DryUMAnalytics.h"

@implementation DryUMAnalytics

/// 手动页面时长统计, 记录某个页面展示的时长
+ (void)logPageView:(NSString *)pageName seconds:(int)seconds {
    
    if (pageName && pageName.length && seconds > 0) {
        [MobClick logPageView:pageName seconds:seconds];
    }
}

/// 自动页面时长统计, 开始记录某个页面展示时长
+ (void)beginLogPageView:(NSString *)pageName {
    
    if (pageName && pageName.length) {
        [MobClick beginLogPageView:pageName];
    }
}

/// 自动页面时长统计, 结束记录某个页面展示时长
+ (void)endLogPageView:(NSString *)pageName {
    
    if (pageName && pageName.length) {
        [MobClick endLogPageView:pageName];
    }
}

/// 自定义事件，数量统计
+ (void)event:(NSString *)eventId {
    
    if (eventId && eventId.length) {
        [MobClick event:eventId];
    }
}

/// 自定义事件，数量统计
+ (void)event:(NSString *)eventId label:(nullable NSString *)label {
    
    if (eventId && eventId.length) {
        [MobClick event:eventId label:label];
    }
}

/// 根据用户账号统计
+ (void)profileSignInWithPUID:(NSString *)puid {
    
    if (puid && puid.length) {
        [MobClick profileSignInWithPUID:puid];
    }
}

/// 根据用户账号统计
+ (void)profileSignInWithPUID:(NSString *)puid provider:(nullable NSString *)provider {
    
    if (puid && puid.length && provider && provider.length) {
        [MobClick profileSignInWithPUID:puid provider:provider];
    }
}

/// 停止sign-in PUID的统计(退出登录时使用)
+ (void)profileSignOff {
    [MobClick profileSignOff];
}

/// 设置经纬度
+ (void)setLatitude:(double)latitude longitude:(double)longitude {
    [MobClick setLatitude:latitude longitude:longitude];
}

@end

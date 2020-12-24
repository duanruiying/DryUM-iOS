//
//  DryUM.m
//  DryUM
//
//  Created by Ruiying Duan on 2019/7/19.
//

#import <UMCommon/UMCommon.h>
#import "DryUM.h"

@implementation DryUM

/// @说明 注册友盟所有组件产品
/// @参数 appKey:     开发者在友盟官网申请的appkey
/// @参数 channel:    渠道标识(可设置nil表示"App Store")[可选参数]
/// @返回 void
+ (void)registerWithAppKey:(NSString *)appKey channel:(nullable NSString *)channel {
    
    if (appKey) {
        [UMConfigure initWithAppkey:appKey channel:channel];
    }
}

@end

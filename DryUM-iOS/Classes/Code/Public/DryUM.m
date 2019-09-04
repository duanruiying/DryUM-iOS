//
//  DryUM.m
//  DryUM
//
//  Created by Ruiying Duan on 2019/7/19.
//

#import <UMCommon/UMCommon.h>
#import <UMAnalytics/MobClick.h>
#import <UMPush/UMessage.h>
#import "DryUM.h"

@implementation DryUM

/// @说明 注册友盟所有组件产品
/// @参数 appKey:     开发者在友盟官网申请的appkey
/// @参数 channel:    渠道标识(可设置nil表示"App Store")[可选参数]
/// @返回 void
+ (void)registerWithAppKey:(NSString *)appKey channel:(nullable NSString *)channel {
    
    if (appKey) {
        
        /// 初始化友盟所有组件产品
        [UMConfigure initWithAppkey:appKey channel:channel];
        
        /// 统计场景类型
        [MobClick setScenarioType:E_UM_NORMAL];
        
        /// 开关CrashReport收集
        [MobClick setCrashReportEnabled:NO];
        
        /// 设置是否允许SDK当应用在前台运行收到Push时弹出Alert框
        [UMessage setAutoAlert:NO];
        
        /// 设置是否允许SDK自动清空角标
        [UMessage setBadgeClear:NO];
    }
}

@end

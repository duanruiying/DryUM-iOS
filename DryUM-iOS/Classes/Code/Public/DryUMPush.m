//
//  DryUMPush.m
//  DryUM
//
//  Created by Ruiying Duan on 2019/7/19.
//

#import <UMPush/UMessage.h>
#import "DryUMPush.h"

@implementation DryUMPush

/// 向友盟注册推送
+ (void)registerRemoteNotifications:(nullable NSDictionary *)launchOptions {
    
    [UMessage registerForRemoteNotificationsWithLaunchOptions:launchOptions Entity:nil completionHandler:^(BOOL granted, NSError * _Nullable error) {
        
    }];
}

/// 设置是否允许SDK当应用在前台运行收到Push时弹出Alert框
+ (void)configAutoAlert:(BOOL)value {
    [UMessage setAutoAlert:value];
}

/// 设置是否允许SDK自动清空角标
+ (void)configBadgeClear:(BOOL)value {
    [UMessage setBadgeClear:value];
}

/// 向友盟注册该设备的deviceToken
+ (void)registerDeviceToken:(NSData *)deviceToken {
    [UMessage registerDeviceToken:deviceToken];
}

/// 应用处于运行时（前台、后台）的消息处理
+ (void)didReceiveRemoteNotification:(NSDictionary *)userInfo {
    [UMessage didReceiveRemoteNotification:userInfo];
}

/// 绑定一个别名至设备
+ (void)addAlias:(NSString *)name
            type:(NSString *)type
            resp:(BlockDryUMPushResult)resp {
    
    [UMessage addAlias:name type:type response:^(id  _Nonnull responseObject, NSError * _Nonnull error) {
        
        if (resp != nil) {
            resp(responseObject, error);
        }
    }];
}

/// 绑定一个别名至设备，并解绑这个别名曾今绑定过的设备
+ (void)setAlias:(NSString *)name
            type:(NSString *)type
            resp:(BlockDryUMPushResult)resp {
    
    [UMessage setAlias:name type:type response:^(id  _Nonnull responseObject, NSError * _Nonnull error) {
        
        if (resp != nil) {
            resp(responseObject, error);
        }
    }];
}

/// 删除一个设备的别名绑定
+ (void)removeAlias:(NSString *)name
               type:(NSString *)type
               resp:(BlockDryUMPushResult)resp {
    
    [UMessage removeAlias:name type:type response:^(id  _Nonnull responseObject, NSError * _Nonnull error) {
        
        if (resp != nil) {
            resp(responseObject, error);
        }
    }];
}

@end

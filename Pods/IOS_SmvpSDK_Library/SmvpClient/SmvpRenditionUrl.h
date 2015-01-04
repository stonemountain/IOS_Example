//
//  SmvpRenditionUrl.h
//  SmvpClient
//
//  Created by julien on 14-5-7.
//  Copyright (c) 2014年 smvp. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface SmvpRenditionUrl : NSObject

@property(nonatomic, strong) NSString *url;
@property(nonatomic, assign) NSInteger expireTime;

- (instancetype) initWithJsonObject:(NSDictionary *)jsonObject;

@end

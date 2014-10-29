//
//  SmvpRendition.h
//  SmvpClient
//
//  Created by julien on 14-5-7.
//  Copyright (c) 2014年 smvp. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SmvpRenditionUrl.h"

@interface SmvpRendition : NSObject

@property(nonatomic, strong) NSString *renditionId;
@property(nonatomic, strong) NSString *entryId;
@property(nonatomic, strong) NSString *name;
@property(nonatomic, strong) NSString *status;
@property(nonatomic, strong) NSString *errorCode;
@property(nonatomic, assign) NSInteger width;
@property(nonatomic, assign) NSInteger height;
@property(nonatomic, assign) NSInteger frameRate;
@property(nonatomic, assign) NSInteger kbps;
@property(nonatomic, strong) NSDictionary *urls;

- (instancetype) initWithJsonObject:(NSDictionary *)jsonObject entryId:(NSString *) entryId;

@end

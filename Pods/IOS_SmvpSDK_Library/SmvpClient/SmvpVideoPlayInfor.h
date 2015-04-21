//
//  SmvpVideoPlayInfor.h
//  SmvpClient
//
//  Created by julien on 14-5-7.
//  Copyright (c) 2014年 smvp. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SmvpRendition.h"
#import "SmvpAPIClient.h"
#import "SmvpImage.h"
@class SmvpAPIClient;

@interface SmvpVideoPlayInfor : NSObject

@property(nonatomic, strong) NSString *videoId;
@property(nonatomic, strong) NSString *title;
@property(nonatomic, strong) NSString *playInfoDescription;
@property(nonatomic, assign) NSInteger duration;
@property(nonatomic, strong) NSArray *renditions;
@property(nonatomic, strong) NSArray *thumbnails;
@property(nonatomic, strong) NSString *pubId;
@property(nonatomic, strong) SmvpAPIClient *apiClient;

- (instancetype) initWithJsonObject:(NSDictionary *)jsonObject;

@end

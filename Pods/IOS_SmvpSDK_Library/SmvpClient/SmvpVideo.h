//
//  SmvpVideo.h
//  SmvpClient
//
//  Created by julien on 13-12-10.
//  Copyright (c) 2013年 smvp. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface SmvpVideo : NSObject

@property(nonatomic, strong) NSString *entryId;
@property(nonatomic, assign, getter=isActivated) BOOL activated;
@property(nonatomic, assign) NSInteger audioChannels;
@property(nonatomic, assign) NSInteger audioKbps;
@property(nonatomic, assign) NSInteger audioSampleRate;
@property(nonatomic, strong) NSString *status;
@property(nonatomic, strong) NSString *title;
@property(nonatomic, strong) NSString *videoDescription;
@property(nonatomic, assign) NSInteger duration;
@property(nonatomic, assign) NSInteger width;
@property(nonatomic, assign) NSInteger height;
@property(nonatomic, assign) NSInteger frameRate;
@property(nonatomic, assign) NSInteger videoKbps;
@property(nonatomic, strong) NSString *extension;
@property(nonatomic, strong) NSString *errorCode;
@property(nonatomic, strong) NSString *categoryId;
@property(nonatomic, strong) NSString *thumbnailUrl;
@property(nonatomic, strong) NSString *snapshotUrl;

- (instancetype) initWithJsonObject:(NSDictionary *)jsonObject;

@end

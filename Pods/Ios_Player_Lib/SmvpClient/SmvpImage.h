//
//  SmvpImage.h
//  SmvpClient
//
//  Created by julien on 14-5-7.
//  Copyright (c) 2014年 smvp. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface SmvpImage : NSObject

@property(nonatomic, strong) NSString *imageId;
@property(nonatomic, strong) NSString *entryId;
@property(nonatomic, strong) NSString *type;
@property(nonatomic, strong) NSString *url;
@property(nonatomic, strong) NSString *fileKey;
@property(nonatomic, assign) NSInteger fileSize;
@property(nonatomic, assign) NSInteger width;
@property(nonatomic, assign) NSInteger height;
@property(nonatomic, assign) NSInteger group;

- (instancetype) initWithJsonObject:(NSDictionary *)jsonObject;

@end

//
//  SmvpCategory.h
//  SmvpClient
//
//  Created by julien on 14-5-6.
//  Copyright (c) 2014年 smvp. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface SmvpCategory : NSObject

@property(nonatomic, strong) NSString *categoryId;
@property(nonatomic, strong) NSString *name;
@property(nonatomic, strong) NSString *parent;

- (instancetype) initWithJsonObject:(NSDictionary *)jsonObject;

@end

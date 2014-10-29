//
//  SmvpCategoriesHandler.h
//  SmvpClient
//
//  Created by julien on 14-5-6.
//  Copyright (c) 2014年 smvp. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SmvpCategory.h"

@class SmvpAPIClient;

@interface SmvpCategoriesHandler : NSObject

@property(readwrite, weak) SmvpAPIClient *apiClient;

-(instancetype) initWithAPIClient:(SmvpAPIClient *)apiClient;

- (NSDictionary *) all: (NSDictionary *)filter error:(NSError **) error;

- (SmvpCategory *) add: (NSString *) name parent:(NSString *) parent_id error:(NSError **) error;

- (SmvpCategory *) add: (NSString *) name error:(NSError **) error;

- (SmvpCategory *) get: (NSString *) idString error:(NSError **) error;

- (SmvpCategory *) update: (NSString *) idString name:(NSString *)name error:(NSError **) error;

- (NSDictionary *) deleteCategory: (NSString *) idString error:(NSError **) error;

@end

//
//  SmvpAPIClient.h
//  SmvpClient
//
//  Created by julien on 13-12-10.
//  Copyright (c) 2013年 smvp. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SmvpBasicMethod.h"
#import "SmvpPostMethod.h"
#import "SmvpMultipartMethod.h"
#import "SmvpVideo.h"
#import "SmvpEntriesHandler.h"
#import "SmvpCategoriesHandler.h"

@interface SmvpAPIClient : NSObject

@property(readwrite, strong) NSString *token;
@property(readwrite, strong) NSString *apiUrl;
@property(readwrite, strong) NSString *scope;
@property(readonly, strong) SmvpEntriesHandler *entriesHandler;
@property(readonly, strong) SmvpCategoriesHandler *categoriesHandler;

- (instancetype) initWithToken:(NSString *)token;

- (id) callAPI:(NSString *) methodName with:(NSDictionary *) parameters error:(NSError **) error;

- (SmvpHttpConnection *) uploadVideo:(NSURL *) fileURL withParamters:(NSDictionary *)parameters;

@end

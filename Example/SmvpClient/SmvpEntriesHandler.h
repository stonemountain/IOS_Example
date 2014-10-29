//
//  SmvpEntriesHandler.h
//  SmvpClient
//
//  Created by julien on 14-3-28.
//  Copyright (c) 2014年 smvp. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SmvpHttpConnection.h"
#import "SmvpVideo.h"
#import "SmvpVideoPlayInfor.h"

@class SmvpAPIClient;

@interface SmvpEntriesHandler : NSObject

@property(readwrite, weak) SmvpAPIClient *apiClient;

-(instancetype) initWithAPIClient:(SmvpAPIClient *)apiClient;

- (SmvpHttpConnection *) upload:(NSURL *) fileURL withParamters:(NSDictionary *)parameters;

- (NSDictionary *) listWithFilter: (NSDictionary *)filter InCatetory:(NSString *) category_id OrderBy:(NSString *) order_by startFrom: (NSInteger) start InSize: (NSInteger) max_size error:(NSError **) error;

- (NSDictionary *) listWithFilter: (NSDictionary *)filter InCatetory:(NSString *) category_id OrderBy:(NSString *) order_by startFrom: (NSInteger) start error:(NSError **) error;

- (NSDictionary *) listWithFilter: (NSDictionary *)filter InCatetory:(NSString *) category_id OrderBy:(NSString *) order_by InSize: (NSInteger) max_size error:(NSError **) error;

- (NSDictionary *) listWithFilter: (NSDictionary *)filter InCatetory:(NSString *) category_id OrderBy:(NSString *) order_by error:(NSError **) error;

- (SmvpVideo *) get: (NSString *) idString error:(NSError **) error;

- (SmvpVideo *) update: (NSDictionary *) entry error:(NSError **) error;

- (void) deleteEntry: (NSString *) idString error:(NSError **) error;

- (void) deleteList: (NSArray *) idArray error:(NSError **) error;

- (void) activate: (NSString *) idString error:(NSError **) error;

- (void) activateList: (NSArray *) idArray error:(NSError **) error;

- (void) deactivate: (NSString *) idString error:(NSError **) error;

- (void) deactivateList: (NSArray *) idArray error:(NSError **) error;

- (void) setCategory: (NSArray *) idArray catetory: (NSString *) category_id error:(NSError **) error;

- (void) removeCategory: (NSArray *) idArray catetory: (NSString *) category_id error:(NSError **) error;

- (NSURL *) getM3U8URL:(NSString *) idString;

- (SmvpVideoPlayInfor *) getPlayInfor:(NSString *) idString error:(NSError **) error;

- (NSArray *) getRelated:(NSString *) idString error:(NSError **) error;

@end

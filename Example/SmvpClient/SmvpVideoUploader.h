//
//  SmvpVideoUploader.h
//  SmvpClient
//
//  Created by julien on 14-1-9.
//  Copyright (c) 2014年 smvp. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SmvpAPIClient.h"
#import "SmvpHttpConnection.h"

@protocol SmvpVideoUploaderDelegate;

@interface SmvpVideoUploader : NSObject <SmvpHttpConnectionDelegate>

@property(nonatomic, weak) id<SmvpVideoUploaderDelegate> delegate;
@property(nonatomic, strong) NSURL *fileURL;
@property(nonatomic, strong) SmvpAPIClient *apiClient;
- (instancetype) initWithFile:(NSURL *) file apiClient:(SmvpAPIClient *)client delegate:(id<SmvpVideoUploaderDelegate>) uploadDelegate;
- (SmvpHttpConnection *) uploadWithParamters:(NSDictionary *)parameters;
@end

@protocol SmvpVideoUploaderDelegate <NSObject>
@optional
- (void)uploadCanceled:(SmvpHttpConnection *)connection;
- (void)uploadFinished:(NSHTTPURLResponse *)response;
- (void)uploadFailed:(NSError *)error InResponse:(NSHTTPURLResponse *)response;
- (void)uploadDidUpdate:(double) progress;
@end
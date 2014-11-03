//
//  SmvpHttpConnection.h
//  SmvpClient
//
//  Created by julien on 13-12-11.
//  Copyright (c) 2013年 smvp. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@protocol SmvpHttpConnectionDelegate;

@interface SmvpHttpConnection : NSObject<NSURLConnectionDataDelegate>

@property(nonatomic, strong) NSURLRequest *request;
@property(nonatomic, strong) id<SmvpHttpConnectionDelegate> httpDelegate;

- (instancetype)initWithRequest:(NSURLRequest *)request;
- (void)start;
- (void)cancel;

@end

@protocol SmvpHttpConnectionDelegate <NSObject>
@optional
- (void)cancel:(SmvpHttpConnection *)connection;
- (void)finishWithData:(NSMutableData *) data InResponse:(NSHTTPURLResponse *)response;
- (void)failedWithError:(NSError *)error InResponse:(NSHTTPURLResponse *)response;
- (void)uploadDidUpdate:(double) progress;

@end

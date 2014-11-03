//
//  SmvpBasicMethod.h
//  SmvpClient
//
//  Created by julien on 13-11-22.
//  Copyright (c) 2013年 smvp. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SmvpHttpResponse.h"
#import "SmvpHttpConnection.h"

@interface SmvpBasicMethod : NSObject

@property(readwrite, strong) NSMutableDictionary *params;
@property(readwrite, strong) NSMutableDictionary *headers;
@property int timeout;

-(void)addParameter:(NSString*)paramData withName:(NSString*)paramName;
-(void)addParametersFromDictionary:(NSDictionary*)dict;
-(void)addHeader:(NSString*)paramData withName:(NSString*)paramName;
-(SmvpHttpResponse *)executeMethodSynchronously:(NSURL*)methodURL methodType:(NSString*)methodType dataInBody:(bool)dataInBody contentType:(NSString*)contentType error:(NSError **)error;

-(SmvpHttpConnection *)prepareAsynchronously:(NSURL *)methodURL methodType:(NSString*)methodType dataInBody:(bool)dataInBody contentType:(NSString*)contentType delegate:(id<SmvpHttpConnectionDelegate>)delegate;
@end

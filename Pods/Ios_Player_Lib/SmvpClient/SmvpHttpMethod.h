//
//  SmvpHttpMethod.h
//  SmvpClient
//
//  Created by julien on 13-11-22.
//  Copyright (c) 2013年 smvp. All rights reserved.
//

#import "SmvpHttpResponse.h"
#import "SmvpHttpConnection.h"

@protocol SmvpHttpMethod <NSObject>

-(SmvpHttpResponse *)executeSynchronouslyAtURL:(NSURL *)methodURL error:(NSError **) error;

//-(SmvpHttpConnection *)prepareAsynchronouslyAtURL:(NSURL *)methodURL delegate:(id<SmvpHttpConnectionDelegate>)delegate;

@end

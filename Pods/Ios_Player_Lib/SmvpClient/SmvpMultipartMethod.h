//
//  SmvpMultipartMethod.h
//  SmvpClient
//
//  Created by julien on 13-11-22.
//  Copyright (c) 2013年 smvp. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SmvpPart.h"
#import "SmvpStringPart.h"
#import "SmvpFilePart.h"
#import "SmvpHttpMethod.h"
#import "SmvpBasicMethod.h"

@interface SmvpMultipartMethod : SmvpBasicMethod <SmvpHttpMethod>

@property(readwrite, strong) NSMutableArray *methodParts;

-(void)addPart:(id<SmvpPart>)newPart;
-(void)addStringPartsFromDictionary:(NSDictionary*)dict;

-(SmvpHttpConnection *)prepareAsynchronouslyAtURL:(NSURL *)methodURL;

@end

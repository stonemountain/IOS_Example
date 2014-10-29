//
//  SmvpFilePart.h
//  SmvpClient
//
//  Created by julien on 13-11-22.
//  Copyright (c) 2013年 smvp. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SmvpPart.h"

@interface SmvpFilePart : NSObject <SmvpPart>

@property(readwrite, strong) NSURL *fileURL;
@property(readwrite, strong) NSString *paramName;

-(instancetype) initWithFile:(NSURL*)fileURL withName: (NSString*)paramName;

@end

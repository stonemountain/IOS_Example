//
//  SmvpStringPart.h
//  SmvpClient
//
//  Created by julien on 13-11-22.
//  Copyright (c) 2013年 smvp. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SmvpPart.h"

@interface SmvpStringPart : NSObject <SmvpPart>

@property(readwrite, strong) NSString *name;
@property(readwrite, strong) NSString *value;

-(instancetype) initWithParameter:(NSString*)value withName:(NSString*)name;

@end

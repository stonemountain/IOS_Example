//
//  SmvpPart.h
//  SmvpClient
//
//  Created by julien on 13-11-22.
//  Copyright (c) 2013年 smvp. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol SmvpPart <NSObject>

-(void)appendData:(NSMutableData *)outputData;

@end

//
//  SmvpHelper.m
//  Example
//
//  Created by julien on 13-12-27.
//  Copyright (c) 2013年 smvp. All rights reserved.
//

#import "SmvpHelper.h"

@implementation SmvpHelper

static SmvpAPIClient *_apiClient;

+ (SmvpAPIClient *) apiClient {
    if (!_apiClient) {
        
       _apiClient = [[SmvpAPIClient alloc] initWithToken:@"SJQ-7zgT_lOwaq816PPkkZqNDfl8TlaXoARoAQxaXAE="];
    }
    return _apiClient;
}

@end

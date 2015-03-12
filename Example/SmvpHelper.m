//
//  SmvpHelper.m
//  Example
//
//  Created by julien on 13-12-27.
//  Copyright (c) 2013年 smvp. All rights reserved.
//

#import "SmvpHelper.h"
#import "SmvpVideoDownloaderManager.h"
#import "SmvpVideoUploaderManager.h"

@implementation SmvpHelper

static SmvpAPIClient *_apiClient;
static SmvpVideoDownloaderManager *_downloaderManager;
static SmvpVideoUploaderManager *_uploaderManager;

+ (SmvpAPIClient *) apiClient {
    if (!_apiClient) {
        
       _apiClient = [[SmvpAPIClient alloc] initWithToken:@"SJQ-7zgT_lOwaq816PPkkZqNDfl8TlaXoARoAQxaXAE="];
    }
    return _apiClient;
}

+ (SmvpVideoDownloaderManager *) downloaderManager {
    if (!_downloaderManager) {
        
        _downloaderManager = [[SmvpVideoDownloaderManager alloc] initWithClient:[SmvpHelper apiClient]];
    }
    return _downloaderManager;
}

+ (SmvpVideoUploaderManager *)uploaderManager
{
    if (!_uploaderManager) {
        _uploaderManager = [[SmvpVideoUploaderManager alloc] initWithClient:[SmvpHelper apiClient]];
    }
    return _uploaderManager;
}

@end

//
//  SmvpHelper.h
//  Example
//
//  Created by julien on 13-12-27.
//  Copyright (c) 2013年 smvp. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SmvpAPIClient.h"
#import "SmvpVideoDownloaderManager.h"
#import "SmvpVideoUploaderManager.h"

@interface SmvpHelper : NSObject

+ (SmvpAPIClient *) apiClient;
+ (SmvpVideoDownloaderManager *) downloaderManager;
+ (SmvpVideoUploaderManager *) uploaderManager;

@end

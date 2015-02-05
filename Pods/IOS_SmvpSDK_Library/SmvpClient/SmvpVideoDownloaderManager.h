//
//  SmvpVideoDownloadManager.h
//  SmvpClient
//
//  Created by yangfei on 1/13/15.
//  Copyright (c) 2015 smvp. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SmvpAPIClient.h"
#import "SmvpVideoDownloader.h"


@interface SmvpVideoDownloaderManager : NSObject<SmvpVideoDownloaderDelegate>

-(SmvpVideoDownloader *)download:(SmvpRendition *)rendition error:(NSError **)error;
-(void)pause;
-(void)resume;
-(void)pause:(SmvpVideoDownloader *)downloader;
-(void)resume:(SmvpVideoDownloader *)downloader;
-(void)cancel:(SmvpVideoDownloader *)downloader;
-(NSMutableArray *)getDownloaderList;
-(id)initWithClient:(SmvpAPIClient *)client;
@end

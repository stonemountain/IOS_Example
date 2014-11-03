//
//  SmvpImageDownloader.h
//  SmvpClient
//
//  Created by julien on 13-12-27.
//  Copyright (c) 2013年 smvp. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface SmvpImageDownloader : NSObject

@property (nonatomic, strong) NSString *imageUrl;
@property (nonatomic, copy) void (^completionHandler)(UIImage *);

- (void)startDownload;
- (void)cancelDownload;

@end

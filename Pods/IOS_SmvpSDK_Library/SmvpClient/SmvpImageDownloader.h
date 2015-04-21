//
//  SmvpImageDownloader.h
//  SmvpClient
//
//  Created by julien on 13-12-27.
//  Copyright (c) 2013年 smvp. All rights reserved.
//

/*!
 @header SmvpImageDownloader
 @abstract 图片加载类；
 @author smvp
 @version 1.3.1
 */
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

/*!
 @class
 @abstract 主要用于图片加载；
 */
@interface SmvpImageDownloader : NSObject

/*!
 @property
 @abstract 所加载图片地址；
 */
@property (nonatomic, strong) NSString *imageUrl;

/*!
 @property
 @abstract block代码块，用于处理所加载的图片；
 */
@property (nonatomic, copy) void (^completionHandler)(UIImage *);

/*!
 @method
 @abstract	开始下载；
 @discussion	开始下载图片，之前请设置imageUrl；
 */
- (void)startDownload;

/*!
 @method
 @abstract	取消下载；
 @discussion	取消下载；
 */
- (void)cancelDownload;

@end

//
//  SmvpPlayerViewController.h
//  SmvpClient
//
//  Created by julien on 13-12-31.
//  Copyright (c) 2013年 smvp. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "SmvpVideo.h"
#import "SmvpAPIClient.h"

@interface SmvpPlayerViewController : UIViewController

@property(nonatomic, strong) SmvpVideo *video;

- (void) play;

- (void) pause;

- (void) seek:(float) time;

- (void) prepareVideo:(SmvpVideo *)video withApiClient:(SmvpAPIClient *) apiClient andPlayerId:(NSString *) playerId inRegion:(CGRect)region;

@end

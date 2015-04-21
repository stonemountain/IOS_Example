//
//  SmvpVideoPlayerConfigurations.h
//  SmvpClient
//
//  Created by yangfei on 2/4/15.
//  Copyright (c) 2015 smvp. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface SmvpVideoPlayerConfigurations : NSObject

@property(nonatomic)BOOL auto_play;
@property(nonatomic)BOOL control_bar_auto_hide;
@property(nonatomic)BOOL download_enabled;
@property(nonatomic)BOOL enable_memorized;
@property(nonatomic)BOOL enable_subtitle;
@property(nonatomic)BOOL forbid_drag;
@property(nonatomic)BOOL loop;
@property(nonatomic)BOOL muted;
@property(nonatomic)BOOL play_button_overlay;
@property(nonatomic)BOOL show_ad_tip;
@property(nonatomic)BOOL show_advanced_settings;
@property(nonatomic)BOOL show_company_info;
@property(nonatomic)BOOL show_email_share;
@property(nonatomic)BOOL show_external_name;
@property(nonatomic)BOOL show_full_screen;
@property(nonatomic)BOOL show_menu_bar;
@property(nonatomic)BOOL show_network_tip;
@property(nonatomic)BOOL show_player_info;
@property(nonatomic)BOOL show_recommendation;
@property(nonatomic)BOOL show_rendition_selection;
@property(nonatomic)BOOL show_share_sites;
@property(nonatomic)BOOL show_title;

@property(nonatomic, strong)NSString *control_bar_auto_hide_timeout;
@property(nonatomic, strong)NSString *control_bar_mode;
@property(nonatomic, strong)NSString *playerDescription;
@property(nonatomic, strong)NSString *logo_overlay;
@property(nonatomic, strong)NSString *name;
@property(nonatomic, strong)NSString *preload_time;
@property(nonatomic, strong)NSString *scale_mode;
@property(nonatomic, strong)NSString *skin;

@property(nonatomic, strong)NSArray *own_ads;

- (instancetype) initWithJsonObject:(NSDictionary *)jsonObject;

@end

//
//  SmvpVideo+Image.m
//  Example
//
//  Created by julien on 13-12-30.
//  Copyright (c) 2013年 smvp. All rights reserved.
//

#import "SmvpVideo+Image.h"
#import <objc/runtime.h>

@implementation SmvpVideo (Image)

static char THUMBNAIL_IMAGE=0;

-(UIImage *) thumbnailImage {
    return objc_getAssociatedObject(self, &THUMBNAIL_IMAGE);
}

-(void) setThumbnailImage:(UIImage *)thumbnailImage {
    objc_setAssociatedObject(self, &THUMBNAIL_IMAGE, thumbnailImage, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
}

@end

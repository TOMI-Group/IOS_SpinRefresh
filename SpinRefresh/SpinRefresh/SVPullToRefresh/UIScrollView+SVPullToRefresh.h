//
// UIScrollView+SVPullToRefresh.h
//
// Created by Sam Vermette on 23.04.12.
// Copyright (c) 2012 samvermette.com. All rights reserved.
//
// https://github.com/samvermette/SVPullToRefresh
//

#import <UIKit/UIKit.h>
#import <AvailabilityMacros.h>
#import "SCBubbleRefreshView.h"
#import "NaRTSpinKitView.h"


@class SVPullToRefreshView;

@interface UIScrollView (SVPullToRefresh)

- (void)addPullToRefreshWithActionHandler:(void (^)(void))actionHandler;
- (void)addPullToRefreshWithActionHandler:(void (^)(void))actionHandler spin:(RTSpinKitViewStyle)style;
- (void)triggerPullToRefresh;

@property (nonatomic, strong, readonly) SVPullToRefreshView *pullToRefreshView;
@property (nonatomic, assign) BOOL showsPullToRefresh;

@end


typedef NS_ENUM(NSUInteger, SVPullToRefreshState) {
    SVPullToRefreshStateStopped = 0,
    SVPullToRefreshStateTriggered,
    SVPullToRefreshStateLoading,
    SVPullToRefreshStateAll = 10
};

@interface SVPullToRefreshView : UIView
@property (nonatomic, strong) SCBubbleRefreshView *refreshView;
@property (nonatomic, strong) NaRTSpinKitView *spinView;
@property (nonatomic, readonly) SVPullToRefreshState state;

//init
- (id)initWithFrame:(CGRect)frame style:(RTSpinKitViewStyle)style;

- (void)startAnimating;
- (void)stopAnimating;

@end

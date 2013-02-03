//
//  SSAppDelegate.h
//  SSMobileGame
//
//  Created by Robert Shoemate on 1/20/13.
//  Copyright (c) 2013 Robert Shoemate. All rights reserved.
//

#import <UIKit/UIKit.h>

@class SSViewController;

@interface SSAppDelegate : UIResponder <UIApplicationDelegate>

@property (strong, nonatomic) UIWindow *window;

@property (strong, nonatomic) SSViewController *viewController;

@end

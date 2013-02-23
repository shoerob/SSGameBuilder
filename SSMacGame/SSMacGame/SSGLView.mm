//
//  SSGLView.m
//  SSGameEditor
//
//  Created by Robert Shoemate on 1/1/13.
//  Copyright (c) 2013 Robert Shoemate. All rights reserved.
//

#import "SSGLView.h"
#import <OpenGL/OpenGL.h>
#import <OpenGL/glu.h>
#include "SSMainScene.h"
#include "RootScene.h"

//static SoftShoe::GameEngine::Director s_director;

@interface SSGLView ()

//@property SSMainScene mainScene;

@property Context_ptr context;
@property Game::RootScene_ptr rootScene;

@property (strong, nonatomic) NSTrackingArea *trackingArea;

@end

@implementation SSGLView

- (id)initWithCoder:(NSCoder *)aDecoder {
    self = [super initWithCoder:aDecoder];
    if (self) {
        self.context = Context::create();
        self.rootScene = std::make_shared<Game::RootScene>();
        SceneController_ptr scene = std::dynamic_pointer_cast<SceneController>(self.rootScene);
        self.context->setScene(scene);
        
        //s_director = SoftShoe::GameEngine::Director();
        //s_director.SetScene(&self->_mainScene);
    }
    
    return self;
}

- (id)initWithFrame:(NSRect)frameRect pixelFormat:(NSOpenGLPixelFormat *)format {
    self = [super initWithFrame:frameRect pixelFormat:format];
    if (self) {
        
    }
    
    return self;
}

- (void)idle:(NSTimer *)pTimer {
    self.context->update();
    
    //s_director.Update();
    [self drawRect:[self bounds]];
}


- (void)prepareOpenGL {
    pTimer = [NSTimer timerWithTimeInterval:(1.0/60.0) target:self selector:@selector(idle:) userInfo:nil repeats:YES];
    [[NSRunLoop currentRunLoop]addTimer:pTimer forMode: NSDefaultRunLoopMode];
    //s_director.Setup();
    self.context->Setup();
}

- (void)clearGLContext {
    // Do OpenGL Cleanup
}

- (void)reshape {
    NSRect rect = [self bounds];
//    s_director.SetViewportSize(rect.size.width, rect.size.height);
    self.context->SetViewportSize(rect.size.width, rect.size.height);
}

- (void)drawRect:(NSRect)dirtyRect {
    [self.openGLContext makeCurrentContext];
    [self reshape];
    self.context->render();
    //s_director.Render();
}

#pragma mark - Tracking

- (void)updateTrackingAreas {
    [self removeTrackingArea:self.trackingArea];
    self.trackingArea = nil;
    
    self.trackingArea = [[NSTrackingArea alloc] initWithRect:[self bounds] options:(NSTrackingMouseMoved | NSTrackingActiveInKeyWindow) owner:self userInfo:nil];
    [self addTrackingArea:self.trackingArea];
    
    //NSLog(@"Updating!");
}

- (void)mouseMoved:(NSEvent *)theEvent {
    NSPoint eyeCenter = [self convertPoint:[theEvent locationInWindow] fromView:nil];
    //NSLog(@"%@", NSStringFromPoint(eyeCenter));
    //s_director.InputServiceInstance().MouseMoved(eyeCenter.x * 640.0f / self.bounds.size.width, eyeCenter.y * 480.0f / self.bounds.size.height);
}

- (void)mouseDown:(NSEvent *)theEvent {
    NSPoint eyeCenter = [self convertPoint:[theEvent locationInWindow] fromView:nil];
    //NSLog(@"%@", NSStringFromPoint(eyeCenter));
    //s_director.InputServiceInstance().MouseDown(eyeCenter.x * 640.0f / self.bounds.size.width, eyeCenter.y * 480.0f / self.bounds.size.height);
}

- (void)mouseUp:(NSEvent *)theEvent {
    NSPoint eyeCenter = [self convertPoint:[theEvent locationInWindow] fromView:nil];
    //NSLog(@"%@", NSStringFromPoint(eyeCenter));
    //s_director.InputServiceInstance().MouseUp(eyeCenter.x * 640.0f / self.bounds.size.width, eyeCenter.y * 480.0f / self.bounds.size.height);
}

- (void)mouseDragged:(NSEvent *)theEvent {
    NSPoint eyeCenter = [self convertPoint:[theEvent locationInWindow] fromView:nil];
    //NSLog(@"%@", NSStringFromPoint(eyeCenter));
    //s_director.InputServiceInstance().MouseMoved(eyeCenter.x * 640.0f / self.bounds.size.width, eyeCenter.y * 480.0f / self.bounds.size.height);
}

@end

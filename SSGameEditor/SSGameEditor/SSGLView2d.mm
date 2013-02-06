//
//  SSGLView2d.m
//  SSGameEditor
//
//  Created by Robert Shoemate on 2/4/13.
//  Copyright (c) 2013 Robert Shoemate. All rights reserved.
//

#import "SSGLView2d.h"
#import <OpenGL/OpenGL.h>
#import <OpenGL/glu.h>
#import <Cocoa/Cocoa.h>

static SoftShoe::GameEngine::Director s_director2d;


@interface SSGLView2d ()

@property (strong, nonatomic) NSTrackingArea *trackingArea;

@end

@implementation SSGLView2d

- (id)initWithCoder:(NSCoder *)aDecoder {
    self = [super initWithCoder:aDecoder];
    if (self) {
        ////
        s_director2d = SoftShoe::GameEngine::Director();
        
        SoftShoe::GameEngine::Scene *scene = new SoftShoe::GameEngine::Scene();
        
//        SoftShoe::GameEngine::ParticleSystem *particleSystem = new SoftShoe::GameEngine::ParticleSystem();
//        particleSystem->SetCenter(SSPointMake(320.0f, 200.0f, 0.0f));
//        scene->AddActor(particleSystem);

        SoftShoe::GameEngine::TileMap *tileMap = new SoftShoe::GameEngine::TileMap();
        tileMap->Setup(16, 16, 40, 30);
        scene->AddActor(tileMap);
        
        s_director2d.SetScene(scene);
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
    s_director2d.Update();
    [self drawRect:[self bounds]];
}


- (void)prepareOpenGL {
    pTimer = [NSTimer timerWithTimeInterval:(1.0/60.0) target:self selector:@selector(idle:) userInfo:nil repeats:YES];
    [[NSRunLoop currentRunLoop]addTimer:pTimer forMode: NSDefaultRunLoopMode];
    s_director2d.Setup2d();
}

- (void)clearGLContext {
    // Do OpenGL Cleanup
}

- (void)reshape {
    NSRect rect = [self bounds];
    s_director2d.SetViewportSize(rect.size.width, rect.size.height);
    

}

- (void)drawRect:(NSRect)dirtyRect {
    [self.openGLContext makeCurrentContext];
    [self reshape];
    s_director2d.Render();
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
    NSLog(@"%@", NSStringFromPoint(eyeCenter));
    s_director2d.InputServiceInstance().MouseMoved(eyeCenter.x * 640.0f / self.bounds.size.width, eyeCenter.y * 480.0f / self.bounds.size.height);
}

@end

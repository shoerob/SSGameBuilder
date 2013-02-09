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

static SoftShoe::GameEngine::Director s_director;

@implementation SSGLView

- (id)initWithCoder:(NSCoder *)aDecoder {
    self = [super initWithCoder:aDecoder];
    if (self) {
        s_director = SoftShoe::GameEngine::Director();
        
        SoftShoe::GameEngine::Scene *scene = new SoftShoe::GameEngine::Scene();

        SoftShoe::GameEngine::ParticleSystem *particleSystem = new SoftShoe::GameEngine::ParticleSystem();
        particleSystem->SetCenter(SSPointMake(0.0f, -25.0f, 100.0f));
        scene->AddActor(particleSystem);

        s_director.SetScene(scene);
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
    s_director.Update();
    [self drawRect:[self bounds]];
}


- (void)prepareOpenGL {
    pTimer = [NSTimer timerWithTimeInterval:(1.0/60.0) target:self selector:@selector(idle:) userInfo:nil repeats:YES];
    [[NSRunLoop currentRunLoop]addTimer:pTimer forMode: NSDefaultRunLoopMode];
    s_director.Setup();
}

- (void)clearGLContext {
    // Do OpenGL Cleanup
}

- (void)reshape {
    NSRect rect = [self bounds];
    s_director.SetViewportSize(rect.size.width, rect.size.height);
}

- (void)drawRect:(NSRect)dirtyRect {
    [self.openGLContext makeCurrentContext];
    [self reshape];
    s_director.Render();
}

@end

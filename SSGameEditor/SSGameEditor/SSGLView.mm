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
        
//        for (int x = 5; x >= -5; x--) {
//            for (int y = 5; y >= -5; y--) {
//                for (int z = 5; z >= -5; z--) {
//                    SoftShoe::GameEngine::Actor *actor = new SoftShoe::GameEngine::Actor();
////                    actor->xPos = x*2;
////                    actor->yPos = y*2;
////                    actor->zPos = z*2;
//                    scene->actors.push_back(*actor);
//                }
//            }
//        }

        SoftShoe::GameEngine::ParticleSystem *particleSystem = new SoftShoe::GameEngine::ParticleSystem();
        particleSystem->setCenter(SSPointMake(0.0f, -25.0f, 0.0f));
        scene->actors.push_back(particleSystem);

//        SoftShoe::GameEngine::ParticleSystem *particleSystem2 = new SoftShoe::GameEngine::ParticleSystem();
//        particleSystem->setCenter(SSPointMake(0.0f, -25.0f, 0.0f));
//        scene->actors.push_back(particleSystem2);
        
        //        SoftShoe::GameEngine::Actor *actor2 = new SoftShoe::GameEngine::Actor();
        //        scene->actors.push_back(*actor2);
        
        s_director.setScene(scene);
    }
    
    return self;
}

- (id)initWithFrame:(NSRect)frameRect pixelFormat:(NSOpenGLPixelFormat *)format {
    self = [super initWithFrame:frameRect pixelFormat:format];
    if (self) {
        

    }
    
    return self;
}

- (void)idle:(NSTimer *)pTimer
{
    s_director.update();
    [self drawRect:[self bounds]];
}


- (void) prepareOpenGL
{
    pTimer = [NSTimer timerWithTimeInterval:(1.0/60.0) target:self
                                   selector:@selector(idle:) userInfo:nil repeats:YES];
    [[NSRunLoop currentRunLoop]addTimer:pTimer forMode: NSDefaultRunLoopMode];
    
    glClearColor(0.0f, 1.0f, 1.0f, 1.0f);
}

- (void)clearGLContext
{
    // Do OpenGL Cleanup
}

- (void)reshape
{
    NSRect rect = [self bounds];
    glViewport(0, 0, rect.size.width, rect.size.height);
    glEnable(GL_DEPTH_TEST);
}

- (void) drawRect:(NSRect)dirtyRect
{
    s_director.render();
}

@end

//
//  Director.cpp
//  SSGameEngine
//
//  Created by Robert Shoemate on 12/16/12.
//  Copyright (c) 2012 Robert Shoemate. All rights reserved.
//

#include "Director.h"
#include "Scene.h"
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>

using namespace SoftShoe::GameEngine;
using namespace SoftShoe::Services;

Director::Director() : timer() {
    srand ( (int) time(NULL) );
}

Director::~Director() {
}

void Director::SetScene(Scene *scene) {
    this->scene = scene;
    if (dynamic_cast<INotificationSubscriber *>(this->scene) != NULL) {
        std::cout << "Subcribing scene to notifications...";
        this->NotificationServiceInstance().AddSubscriber(dynamic_cast<INotificationSubscriber *>(this->scene));
    }
}

void Director::Setup() {    
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    gluPerspective(45, 1, 0.1, 1000);
    gluLookAt(0, 0, 0,    // eye
              0, 0, 1.0,      // at
              0, 1.0, 0);   // up
    
    
    glMatrixMode( GL_MODELVIEW );
    glClearColor(0.0f, 0.0f, 0.0f, 1);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    

    
}

void Director::Setup2d() {
    const int XSize = 640, YSize = 480;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, XSize, 0, YSize, 0, 1);
    glMatrixMode(GL_MODELVIEW);
    glClearColor(0.0f, 0.0f, 0.0f, 1);
    glDisable(GL_DEPTH_TEST);
}

void Director::SetViewportSize(int w, int h) {
    glViewport(0, 0, w, h);
}

void Director::Update() {
    this->scene->Update(*this, timer.Update());
}

void Director::Render() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    this->scene->Render();
    glFlush();
}

// Services
NotificationService& Director::NotificationServiceInstance() {
    static NotificationService instance;
    return instance;
}

InputService& Director::InputServiceInstance() {
    static InputService instance;
    return instance;
}

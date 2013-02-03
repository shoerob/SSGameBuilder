//
//  Director.cpp
//  SSGameEngine
//
//  Created by Robert Shoemate on 12/16/12.
//  Copyright (c) 2012 Robert Shoemate. All rights reserved.
//

#include "Director.h"
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>

using namespace SoftShoe::GameEngine;

Director::Director() : timer() {
    srand ( (int) time(NULL) );
}

Director::~Director() {
    //delete this->scene;
}

void Director::setScene(Scene *scene) {
    this->scene = scene;
}

void Director::update() {
    this->scene->update(timer.Update());
}

void Director::render() {
    
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    gluPerspective(45, 1, 0.1, 1000);
    gluLookAt(0, 0, -100.0,    // eye
              0, 0, 0,      // at
              0, 1.0, 0);   // up
    

    glMatrixMode( GL_MODELVIEW );
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    //glRotatef(45 * 3.14/180, 0.0f, 0.5f, 0.0f);

//    glLoadIdentity();
    
//    glEnable(GL_CULL_FACE);

    this->scene->render();;
    
    glFlush();
}
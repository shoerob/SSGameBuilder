//
//  Context.cpp
//  SSGameEngine
//
//  Created by Robert Shoemate on 2/18/13.
//  Copyright (c) 2013 Robert Shoemate. All rights reserved.
//

#include <iostream>
#include <memory>
#include "Context.h"
#include "Engine.h"
#include "Scene2.h"
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include "SceneController.h"

using namespace std;
using namespace SoftShoe::GameEngine;

Context::Context() : _timer() {

}

Context::~Context() {

}

Context_ptr Context::create() {
    Context_ptr context = make_shared<Context>();
    Engine::getInstance().addContext(context);
    return context;
}

void Context::setScene(SceneController_ptr sceneController) {
    if (sceneController->getScene()->context() != NULL) {
        cout << "Error: Scene can only be added to one context.";
        return;
    }

    // TODO: move this to a background thread w/a callback
    sceneController->onLoad();
    
    // hrmm...
    sceneController->getScene()->setContext(shared_from_this());
    _activeScene = sceneController->getScene();
}

void Context::Setup() {
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

void Context::Setup2d() {
    const int XSize = 640, YSize = 480;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, XSize, 0, YSize, 0, 1);
    glMatrixMode(GL_MODELVIEW);
    glClearColor(0.0f, 0.0f, 0.0f, 1);
    glDisable(GL_DEPTH_TEST);
}

void Context::SetViewportSize(int w, int h) {
    glViewport(0, 0, w, h);
}

void Context::update() {
    _activeScene->update(_timer.Update());
}

void Context::render() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    _activeScene->render();
    glFlush();
}
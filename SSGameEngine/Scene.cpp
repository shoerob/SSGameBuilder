//
//  Scene.cpp
//  SSGameEngine
//
//  Created by Robert Shoemate on 12/21/12.
//  Copyright (c) 2012 Robert Shoemate. All rights reserved.
//

#include "Scene.h"
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl.h>

using namespace SoftShoe::GameEngine;

Scene::Scene() {
    
}

Scene::~Scene() {
    
}

void Scene::onBeforeLoad() {
    
}

void Scene::onAfterLoad() {
    
}

void Scene::update(int timePassed) {
    for (std::vector<Actor*>::iterator it = actors.begin(); it != actors.end(); ++it) {
        (*it)->update(timePassed);
    }
}

void Scene::render() {
    for (std::vector<Actor*>::iterator it = actors.begin(); it != actors.end(); ++it) {
        (*it)->render();
    }
}
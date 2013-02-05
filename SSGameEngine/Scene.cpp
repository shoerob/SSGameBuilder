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

void Scene::OnBeforeLoad() {
    
}

void Scene::OnAfterLoad() {
    
}

void Scene::Update(int timePassed) {
    for (std::list<Actor*>::iterator it = actors.begin(); it != actors.end(); ++it) {
        (*it)->Update(timePassed);
    }
}

void Scene::Render() {
    for (std::list<Actor*>::iterator it = actors.begin(); it != actors.end(); ++it) {
        (*it)->Render();
    }
}

void Scene::AddActor(Actor *actor) {
    this->actors.push_back(actor);
}

void Scene::RemoveActor(Actor *actor) {
    this->actors.remove(actor);
}
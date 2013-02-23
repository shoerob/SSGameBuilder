//
//  Scene2.cpp
//  SSGameEngine
//
//  Created by Robert Shoemate on 2/22/13.
//  Copyright (c) 2013 Robert Shoemate. All rights reserved.
//

#include "Scene2.h"

using namespace SoftShoe::GameEngine;

Scene2::Scene2() {
    
}

Scene2::~Scene2() {
    
}

Scene_ptr Scene2::create() {
    return std::make_shared<Scene2>();
}

void Scene2::addObject(SSObject_ptr ssObject) {
    _objectMap[ssObject->getTag()] = ssObject;
    _objects.push_back(ssObject);
}

SSObject_ptr Scene2::getObject(int tag) {
    return _objectMap[tag];
}

void Scene2::update(int timePassed) {
    if (auto delegate = _delegate.lock()) {
        delegate->onUpdate(timePassed);
    }
}

void Scene2::render() {    
    for (std::vector<SSObject_ptr>::iterator it = _objects.begin(); it != _objects.end(); ++it) {
        (*it)->render();
    }
}
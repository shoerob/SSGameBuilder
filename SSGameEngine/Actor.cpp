//
//  SceneObject.cpp
//  SSGameEngine
//
//  Created by Robert Shoemate on 1/19/13.
//  Copyright (c) 2013 Robert Shoemate. All rights reserved.
//

#include "Actor.h"
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl.h>

using namespace SoftShoe::GameEngine;

Actor::Actor() {
    center.x = 0.0f;
    center.y = 0.0f;
    center.z = 0.0f;
}

Actor::~Actor() {
    
}
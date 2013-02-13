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

bool Actor::IsCollidingWithActor(Actor *actor) {
    SSRectF thisRect = this->GetCollisionRect();
    SSRectF actorRect = actor->GetCollisionRect();
    
    // determine if no collision is occurring
    if ((thisRect.x > actorRect.x + actorRect.width)  ||
        (thisRect.x + thisRect.width < actorRect.x)   ||
        (thisRect.y > actorRect.y + actorRect.height) ||
        (thisRect.y + thisRect.height < actorRect.y)) {
        return false;
    }
    
    // collision detected
    return true;
}
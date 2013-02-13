//
//  SceneObject.h
//  SSGameEngine
//
//  Created by Robert Shoemate on 1/19/13.
//  Copyright (c) 2013 Robert Shoemate. All rights reserved.
//

#ifndef __SSGameEngine__SceneObject__
#define __SSGameEngine__SceneObject__

#include <iostream>
#include "SSCoreTypes.h"

namespace SoftShoe {
    namespace GameEngine {
        
        class Director;
        class Scene;
        
        class Actor {
        public:
            Actor();
            ~Actor();
            
            virtual void Update(Director &director, int timePassed) = 0;
            virtual void Render() = 0;
            
            // Properties
            void SetCenter(SSPoint3F center) { this->center = center; };
            SSPoint3F GetCenter() { return this->center; };
            
            void SetScene(Scene *scene) { this->scene = scene; }; // TODO: hide this somehow...
            Scene *GetScene() { return this->scene; };
            
            void SetVisible(bool visible) { this->visible = visible; };
            bool GetVisible() { return visible; }
            
            // Basic 2d collision
            void SetCollides(bool collides) { this->collides = collides; }
            bool GetCollides() { return this->collides; }
            virtual SSRectF GetCollisionRect() { return SSRectMake(0.0f, 0.0f, 0.0f, 0.0f); };
            virtual void CollidedWith(Actor *actor) { };
            bool IsCollidingWithActor(Actor *actor);
            
        protected:
            SSPoint3F center;
            Scene *scene;
            
            bool visible = true;
            
            // basic 2d collision detection
            bool collides = false;
        };
    }
}

#endif /* defined(__SSGameEngine__SceneObject__) */

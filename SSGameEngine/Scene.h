//
//  Scene.h
//  SSGameEngine
//
//  Created by Robert Shoemate on 12/21/12.
//  Copyright (c) 2012 Robert Shoemate. All rights reserved.
//

#ifndef __SSGameEngine__Scene__
#define __SSGameEngine__Scene__

#include <iostream>
#include <list>
#include "Actor.h"

namespace SoftShoe {
    namespace GameEngine {
        
        class Director;
        
        class Scene {
        public:
            Scene();
            ~Scene();
          
            virtual void OnBeforeLoad();
            virtual void OnAfterLoad();
                
            // Scene Graph
            void Update(Director &director, int timePassed);
            virtual void Render();
            
            void AddActor(Actor *actor);
            void RemoveActor(Actor *actor);
            
        protected:
            std::list<Actor*> actors;
        };
        
    }
}

#endif /* defined(__SSGameEngine__Scene__) */

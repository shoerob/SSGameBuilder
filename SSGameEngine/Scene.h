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
#include <vector>
#include "Actor.h"

namespace SoftShoe {
    namespace GameEngine {
        
        class Scene {
        public:
            Scene();
            ~Scene();
          
            virtual void onBeforeLoad();
            virtual void onAfterLoad();
                
            // Scene Graph
            void update(int timePassed);
            void render();
            std::vector<Actor*> actors;
        };
        
    }
}

#endif /* defined(__SSGameEngine__Scene__) */

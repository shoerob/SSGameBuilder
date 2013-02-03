//
//  Director.h
//  SSGameEngine
//
//  Created by Robert Shoemate on 12/16/12.
//  Copyright (c) 2012 Robert Shoemate. All rights reserved.
//

#ifndef __SSGameEngine__Director__
#define __SSGameEngine__Director__

#include <iostream>
#include "Scene.h"
#include "Timer.h"

namespace SoftShoe {
    namespace GameEngine {
        
        class Director {
            
            public:
            Director();
            ~Director();
            
            void setScene(Scene *scene);
            
            void update();
            void render();
            
            private:
            Scene *scene;
            SoftShoe::Utility::Timer timer;
            
            };
    }
}

#endif /* defined(__SSGameEngine__Director__) */

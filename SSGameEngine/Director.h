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
#include "InputService.h"
#include "NotificationService.h"
#include "Timer.h"

namespace SoftShoe {
    namespace GameEngine {
        
        // forward class declarations
        class Scene;
        
        class Director {
            
            public:
            Director();
            ~Director();
            
            void SetScene(Scene *scene);
            
            void Setup();
            void Setup2d();
            void SetViewportSize(int w, int h);
            void Update();
            void Render();
            
            // Services
            Services::NotificationService& NotificationServiceInstance();
            Services::InputService& InputServiceInstance();
            
            private:
            Scene *scene;
            SoftShoe::Utility::Timer timer;
            
            };
    }
}

#endif /* defined(__SSGameEngine__Director__) */

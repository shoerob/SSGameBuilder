//
//  Context.h
//  SSGameEngine
//
//  Created by Robert Shoemate on 2/18/13.
//  Copyright (c) 2013 Robert Shoemate. All rights reserved.
//

#ifndef __SSGameEngine__Context__
#define __SSGameEngine__Context__

#include <iostream>
#include "SSCoreTypes.h"
#include "Timer.h"

namespace SoftShoe {
    namespace GameEngine {
        
        class Context : public std::enable_shared_from_this<Context>{
        public:
            Context();
            ~Context();
            
            /**
             * Creates a new Context using the default renderer.
             */
            static Context_ptr create();
            
            /**
             * Scenes
             */
            void setScene(SceneController_ptr scene);
            
            /// @name Platform Interop
            
            void Setup();
            void Setup2d();
            void SetViewportSize(int w, int h);
            
            // called once per frame
            void update();
            
            // called once per frame
            void render();
            
        private:
            SoftShoe::Utility::Timer _timer;
            Scene_ptr _activeScene;
        };
    }
}

#endif /* defined(__SSGameEngine__Context__) */

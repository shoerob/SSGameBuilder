//
//  SceneController.h
//  SSGameEngine
//
//  Created by Robert Shoemate on 2/22/13.
//  Copyright (c) 2013 Robert Shoemate. All rights reserved.
//

#ifndef __SSGameEngine__SceneController__
#define __SSGameEngine__SceneController__

// this is the scene... it contains a sceneGraph

#include <iostream>
#include "Scene2.h"

namespace SoftShoe {
    namespace GameEngine {
        class SceneController : public std::enable_shared_from_this<SceneController>, public ISceneDelegate {
        public:
            SceneController();
            ~SceneController();
            
            /**
             * Creates a new scene
             */
            static SceneController_ptr create();
            
            virtual void onLoad();
            virtual void onUpdate(int timePassed);
            
            Scene_ptr getScene();
            
        protected:
            Scene_ptr _scene;
        };
    }
}

#endif /* defined(__SSGameEngine__SceneController__) */

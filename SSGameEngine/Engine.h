//
//  Engine.h
//  SSGameEngine
//
//  Created by Robert Shoemate on 2/17/13.
//  Copyright (c) 2013 Robert Shoemate. All rights reserved.
//

#ifndef __SSGameEngine__Engine__
#define __SSGameEngine__Engine__

#include <iostream>
#include <vector>
#include "Context.h"

/**
 * Engine
 * This class is responsible for building context objects and binding shared
 * or instanced service implementations to them.
 */
namespace SoftShoe {
    namespace GameEngine {
        class CoreObject;
        class ServiceFactory;
        
        class Engine {
        public:
            static Engine& getInstance() {
                static Engine instance;
                return instance;
            }

            /// @name STEP 1 - Initialization
            
            // Services
            /*
             Global Services: (Shared by contexts, singletons)
             NotificationService
             ResourceManager
             AudioService
             
             Local Services: (Instance-per-context)
             InputService
             CollisionService/PhysicsService
             PathingService
             RenderService
             */
            //void installServiceFactory(std::shared_ptr<ServiceFactory> factory);
            
            /// @name STEP 2 - Context Creation
            //std::shared_ptr<Context> createContext(std::string name);
            //std::shared_ptr<GameObject> createGameObject(Context &context);
            
            void addContext(Context_ptr context);
            void removeContext(Context_ptr context);
            
        private:
            Engine() { srand ( (int) time(NULL) ); };
            Engine(Engine const&) {};
            void operator=(Engine const&) {};
        };
    }
}

#endif /* defined(__SSGameEngine__Engine__) */

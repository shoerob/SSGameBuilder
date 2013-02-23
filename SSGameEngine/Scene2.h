//
//  Scene2.h
//  SSGameEngine
//
//  Created by Robert Shoemate on 2/22/13.
//  Copyright (c) 2013 Robert Shoemate. All rights reserved.
//

#ifndef __SSGameEngine__Scene2__
#define __SSGameEngine__Scene2__

// is this the scene graph?
// should we devise an interface for this??

#include <iostream>
#include <map>
#include <vector>
#include "SSCoreTypes.h"
#include "SSObject.h"

#include "Cube.h"

namespace SoftShoe {
    namespace GameEngine {
        
        class ISceneDelegate {
        public:
            virtual ~ISceneDelegate() {}
            virtual void onUpdate(int timePassed) = 0;
        };
        
        class Scene2 : public SSObject {
        public:
            Scene2();
            ~Scene2();
            
            /**
             * Creates a new scene
             */
            static Scene_ptr create();
            
            /**
             * Adding objects to the context (TODO: this should be in Scene)
             */
            void addObject(SSObject_ptr ssObject);
            SSObject_ptr getObject(int tag);
            
            virtual void update(int timePassed);
            virtual void render();
            
            void setDelegate(ISceneDelegate_ptr_weak delegate) { this->_delegate = delegate; };
            ISceneDelegate_ptr_weak getDelegate() { return this->_delegate; };
            
        private:
            ISceneDelegate_ptr_weak _delegate;
            std::map<int, SSObject_ptr> _objectMap;
            std::vector<SSObject_ptr> _objects;
        };
    }
}

#endif /* defined(__SSGameEngine__Scene2__) */

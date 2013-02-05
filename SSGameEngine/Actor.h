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
        class Actor {
        public:
            Actor();
            ~Actor();
            
            virtual void Update(int timePassed) = 0;
            virtual void Render() = 0;
            
            // Properties
            void SetCenter(SSPoint3F center) { this->center = center; };
            SSPoint3F GetCenter() { return this->center; };
            
        protected:
            SSPoint3F center;
        };
    }
}

#endif /* defined(__SSGameEngine__SceneObject__) */

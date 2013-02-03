//
//  IPrimitive.h
//  SSGameEngine
//
//  Created by Robert Shoemate on 1/27/13.
//  Copyright (c) 2013 Robert Shoemate. All rights reserved.
//

#ifndef SSGameEngine_IPrimitive_h
#define SSGameEngine_IPrimitive_h

#include "SSCoreTypes.h"

namespace SoftShoe {
    namespace GameEngine {
        
        class IPrimitive {
        public:
            IPrimitive() {}
            ~IPrimitive() {}
            
            // Overridable
            virtual void render(SSPoint3F center, float scale) = 0;
            virtual void render(SSPoint3F center, float scale, SSColorRGBA color) = 0;
        };
    }
}

#endif

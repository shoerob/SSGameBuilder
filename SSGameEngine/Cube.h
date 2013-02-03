//
//  Cube.h
//  SSGameEngine
//
//  Created by Robert Shoemate on 1/25/13.
//  Copyright (c) 2013 Robert Shoemate. All rights reserved.
//

#ifndef __SSGameEngine__Cube__
#define __SSGameEngine__Cube__

#include <iostream>
#include "IPrimitive.h"

namespace SoftShoe {
    namespace GameEngine {
        
        class Cube : IPrimitive {
        public:
            Cube();
            ~Cube();
            
            // Overrides
            void render(SSPoint3F center, float scale);
            void render(SSPoint3F center, float scale, SSColorRGBA color);
        };
    }
}

#endif /* defined(__SSGameEngine__Cube__) */

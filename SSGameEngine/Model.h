//
//  Model.h
//  SSGameEngine
//
//  Created by Robert Shoemate on 1/30/13.
//  Copyright (c) 2013 Robert Shoemate. All rights reserved.
//

#ifndef __SSGameEngine__Model__
#define __SSGameEngine__Model__

#include <iostream>
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl.h>

#include "IPrimitive.h"

namespace SoftShoe {
    namespace GameEngine {
        
        class Model : IPrimitive {
        public:
            Model();
            ~Model();
            
            // Loading Methods
            void LoadSimpleModel();
            
            // Overrides
            void render(SSPoint3F center, float scale);
            void render(SSPoint3F center, float scale, SSColorRGBA color);
            
        private:
            int verticesCount;
            GLfloat *vertices;
            
            int indecesCount;
            GLuint *indeces;
            
        };
    }
}

#endif /* defined(__SSGameEngine__Model__) */

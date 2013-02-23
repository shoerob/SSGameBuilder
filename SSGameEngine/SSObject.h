//
//  CoreObject.h
//  SSGameEngine
//
//  Created by Robert Shoemate on 2/18/13.
//  Copyright (c) 2013 Robert Shoemate. All rights reserved.
//

#ifndef __SSGameEngine__CoreObject__
#define __SSGameEngine__CoreObject__

#include <iostream>
#include "SSCoreTypes.h"

namespace SoftShoe {
    namespace GameEngine {
        class SSObject {
        public:
            SSObject();
            SSObject(int tag);
            ~SSObject();
            
            // Creation
            static SSObject_ptr create(int tag);
            
            // Identification
            int getTag() { return _tag; };
            
            Context_ptr context();
            void setContext(Context_ptr context);
            
            // renderer
            virtual void update();
            virtual void render();
            
        private:
            Context_ptr _context;
            int _tag;
            
        };
    }
}

#endif /* defined(__SSGameEngine__CoreObject__) */

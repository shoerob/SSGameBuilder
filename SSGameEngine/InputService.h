//
//  InputReceiver.h
//  SSGameEngine
//
//  Created by Robert Shoemate on 2/5/13.
//  Copyright (c) 2013 Robert Shoemate. All rights reserved.
//

#ifndef __SSGameEngine__InputService__
#define __SSGameEngine__InputService__

#include <iostream>

namespace SoftShoe {
    namespace Services {
        
        class InputService {
        public:
            InputService();
            ~InputService();
            
            // Mouse Events
            void MouseMoved(int x, int y);
            void MouseDown(int x, int y);
            void MouseUp(int x, int y);
            
            int mouseX;
            int mouseY;
            bool isMouseDown;
    
        };
        
    }
}

#endif /* defined(__SSGameEngine__InputService__) */

//
//  Time.h
//  SSGameEngine
//
//  Created by Robert Shoemate on 1/29/13.
//  Copyright (c) 2013 Robert Shoemate. All rights reserved.
//

#ifndef __SSGameEngine__Time__
#define __SSGameEngine__Time__

#include <iostream>
#include <mach/mach_time.h>

namespace SoftShoe {
    namespace Utility {
        class Timer {
        public:
            Timer();
            ~Timer();
            
            // returns time passed in milliseconds since last called
            int Update();
            
        private:
            int GetUptimeInMilliseconds();
            
            int currentTime;
            int timePassed;
        };
    }
}

#endif /* defined(__SSGameEngine__Time__) */

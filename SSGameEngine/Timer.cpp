//
//  Time.cpp
//  SSGameEngine
//
//  Created by Robert Shoemate on 1/29/13.
//  Copyright (c) 2013 Robert Shoemate. All rights reserved.
//

#include "Timer.h"
#include <sys/time.h>

using namespace SoftShoe::Utility;

Timer::Timer() {
    currentTime = 0;
    timePassed = 0;
}

Timer::~Timer() {
    
}

int Timer::Update() {
    if (currentTime == 0) {
        currentTime = GetUptimeInMilliseconds();
        return 0;
    }
    
    int updatedCurrentTime = GetUptimeInMilliseconds();
    timePassed = updatedCurrentTime - currentTime;
    currentTime = updatedCurrentTime;
    return timePassed;
}

int Timer::GetUptimeInMilliseconds()
{
    const int64_t kOneMillion = 1000 * 1000;
    static mach_timebase_info_data_t s_timebase_info;
    
    if (s_timebase_info.denom == 0) {
        (void) mach_timebase_info(&s_timebase_info);
    }
    
    // mach_absolute_time() returns billionth of seconds,
    // so divide by one million to get milliseconds
    return (int)((mach_absolute_time() * s_timebase_info.numer) / (kOneMillion * s_timebase_info.denom));
}

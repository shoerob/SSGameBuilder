//
//  SSCoreTypes.h
//  SSGameEngine
//
//  Created by Robert Shoemate on 1/27/13.
//  Copyright (c) 2013 Robert Shoemate. All rights reserved.
//

#include <iostream>

#ifndef SSGameEngine_SSCoreTypes_h
#define SSGameEngine_SSCoreTypes_h

struct SSPoint3F {
    float x;
    float y;
    float z;
};
typedef struct SSPoint3F SSPoint3F;

struct SSColorRGBA {
    float r;
    float b;
    float g;
    float a;
};
typedef struct SSColorRGBA SSColorRGBA;

SSPoint3F SSPointMake(float x, float y, float z);

SSColorRGBA SSColorMake(float r, float g, float b, float a);

float SSRandF(float LO, float HI);

#endif

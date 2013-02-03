//
//  SSCoreTypes.c
//  SSGameEngine
//
//  Created by Robert Shoemate on 1/27/13.
//  Copyright (c) 2013 Robert Shoemate. All rights reserved.
//

#include "SSCoreTypes.h"

SSPoint3F SSPointMake(float x, float y, float z) {
    SSPoint3F point;
    point.x = x;
    point.y = y;
    point.z = z;
    return point;
}

SSColorRGBA SSColorMake(float r, float g, float b, float a) {
    SSColorRGBA color;
    color.r = r;
    color.g = g;
    color.b = b;
    color.a = a;
    return color;
}

float SSRandF(float LO, float HI) {
    return LO + (float)rand()/((float)RAND_MAX/(HI-LO));
}
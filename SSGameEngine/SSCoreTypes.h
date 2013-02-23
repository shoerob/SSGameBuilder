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

namespace SoftShoe {
    namespace GameEngine {
        class Context;
        typedef std::shared_ptr<Context> Context_ptr;
        
        class SSObject;
        typedef std::shared_ptr<SSObject> SSObject_ptr;
        
        class Scene2;
        typedef std::shared_ptr<Scene2> Scene_ptr;
        
        class SceneController;
        typedef std::shared_ptr<SceneController> SceneController_ptr;
        
        class ISceneDelegate;
        typedef std::weak_ptr<ISceneDelegate> ISceneDelegate_ptr_weak;
    }
}



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

struct SSRectF {
    float x;
    float y;
    float width;
    float height;
};
typedef struct SSRectF SSRectF;

SSPoint3F SSPointMake(float x, float y, float z);

SSColorRGBA SSColorMake(float r, float g, float b, float a);

SSRectF SSRectMake(float x, float y, float width, float height);

float SSRandF(float LO, float HI);

#endif

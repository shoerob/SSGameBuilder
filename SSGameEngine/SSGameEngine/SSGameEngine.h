//
//  SSGameEngine.h
//  SSGameEngine
//
//  Created by Robert Shoemate on 12/16/12.
//  Copyright (c) 2012 Robert Shoemate. All rights reserved.
//

#ifndef SSGameEngine_SSGameEngine_h
#define SSGameEngine_SSGameEngine_h

#include <iostream>
#include "SSCoreTypes.h"




/// OLD

// Systems
//#include "InputService.h"
#include "NotificationService.h"

// Primitive Types
#include "Director.h"
#include "Scene.h"
#include "Actor.h"

#include "Cube.h"

// Concrete Types
#include "ParticleSystem.h"
#include "TileMap.h"
#include "Model.h"

using namespace SoftShoe::Services;
using namespace SoftShoe::GameEngine;

/// NEW

#include "Engine.h"
#include "Context.h"
#include "Scene2.h"
#include "SceneController.h"

#endif

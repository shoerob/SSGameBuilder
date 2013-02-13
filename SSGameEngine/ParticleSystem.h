//
//  ParticleSystem.h
//  SSGameEngine
//
//  Created by Robert Shoemate on 1/27/13.
//  Copyright (c) 2013 Robert Shoemate. All rights reserved.
//

#ifndef __SSGameEngine__ParticleSystem__
#define __SSGameEngine__ParticleSystem__

#include <iostream>
#include "Actor.h"
#include "IPrimitive.h"
#include "Cube.h"
#include "Model.h"

#define TOTAL_PARTICLES 2000

namespace SoftShoe {
    namespace GameEngine {
        
        struct Particle {
            SSPoint3F velocity;
            SSPoint3F acceleration;
            SSPoint3F center;
            SSColorRGBA color;
            int life = -1;
        };
        typedef struct Particle Particle;
        
        class ParticleSystem : public Actor {
        public:
            ParticleSystem();
            ~ParticleSystem();
            
            virtual void Update(Director &director, int timePassed);
            virtual void Render();
            
            Cube cube;
            Model model;
            
        protected:
            Particle particles[TOTAL_PARTICLES];
        };
    }
}

#endif /* defined(__SSGameEngine__ParticleSystem__) */

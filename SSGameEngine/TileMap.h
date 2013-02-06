//
//  TileMap.h
//  SSGameEngine
//
//  Created by Robert Shoemate on 2/4/13.
//  Copyright (c) 2013 Robert Shoemate. All rights reserved.
//

#ifndef __SSGameEngine__TileMap__
#define __SSGameEngine__TileMap__

#include <iostream>
#include "Actor.h"

namespace SoftShoe {
    namespace GameEngine {
        class TileMap : public Actor {
        public:
            TileMap();
            ~TileMap();
            
            // Setup
            void Setup(int tileWidth, int tileHeight, int xCnt, int yCnt);
            
            // Overrides
            void Update(Director &director, int timePassed);
            void Render();
            
        private:
            int xHighlight = 0;
            int yHighlight = 0;
            
            int tileWidth = 0;
            int tileHeight = 0;
            int xCnt = 0;
            int yCnt = 0;
        };
    }
}

#endif /* defined(__SSGameEngine__TileMap__) */

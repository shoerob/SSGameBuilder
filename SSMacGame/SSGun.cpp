//
//  SSGun.cpp
//  SSMacGame
//
//  Created by Robert Shoemate on 2/8/13.
//  Copyright (c) 2013 SoftShoe. All rights reserved.
//

#include "SSGun.h"
#include <OpenGL/OpenGL.h>
#include <OpenGL/glu.h>

SSGun::SSGun() {
    
}

SSGun::~SSGun() {
    
}

void SSGun::Update(Director &director, int timePassed) {
    //this->SetCenter(SSPointMake(director.InputServiceInstance().mouseX, director.InputServiceInstance().mouseY, -50.0f));
    //this->SetCenter(SSPointMake(0.0f, 0.0f, -1.0f));
    
//    float xw = -(director.InputServiceInstance().mouseX - 320) * 50.0f / 100.0f;
//    //float yw = (director.InputServiceInstance().mouseY - 240) * 10.0f / 100.0f;
//    this->SetCenter(SSPointMake(xw, 0.0f, 50.0f));

//
//    //this->SetCenter(SSPointMake(0.0f, 0.0f, 10.0f));
    
//    GLint viewport[4]; //var to hold the viewport info
//    GLdouble modelview[16]; //var to hold the modelview info
//    GLdouble projection[16]; //var to hold the projection matrix info
//    GLfloat winX, winY, winZ; //variables to hold screen x,y,z coordinates
//    GLdouble worldX, worldY, worldZ; //variables to hold world x,y,z coordinates
//    
//    glGetDoublev( GL_MODELVIEW_MATRIX, modelview ); //get the modelview info
//    glGetDoublev( GL_PROJECTION_MATRIX, projection ); //get the projection matrix info
//    glGetIntegerv( GL_VIEWPORT, viewport ); //get the viewport info
//    
//	winX = (float)director.InputServiceInstance().mouseX;
//    winY = (float)viewport[3] - (float)director.InputServiceInstance().mouseY;
//	glReadPixels(winX, winY, 1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &winZ);
//
//    
//	//get the world coordinates from the screen coordinates
//    gluUnProject(winX, winY, winZ, modelview, projection, viewport, &worldX, &worldY, &worldZ);
//    
//    this->SetCenter(SSPointMake(worldX, worldY, worldZ));
    
    float x = director.InputServiceInstance().mouseX;
    float y = director.InputServiceInstance().mouseY;
    
//    GLint viewport[4];
//    GLdouble modelview[16];
//    GLdouble projection[16];
//    GLfloat winX, winY, winZ;
//    GLdouble posX, posY, posZ;
//    
//    glGetDoublev( GL_MODELVIEW_MATRIX, modelview );
//    glGetDoublev( GL_PROJECTION_MATRIX, projection );
//    glGetIntegerv( GL_VIEWPORT, viewport );
//    
//    winX = (float)x;
//    winY = (float)y;
//    glReadPixels( x, int(winY), 1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &winZ );
//    
//    gluUnProject( winX, winY, winZ, modelview, projection, viewport, &posX, &posY, &posZ);

    float xw = -(director.InputServiceInstance().mouseX - 360) * 1.5f / 75.0f;
    //return CVector3(posX, posY, posZ);
    this->SetCenter(SSPointMake(xw, -3.5f, 10.0f));
    
    //this->SetCenter(SSPointMake(0.0f, 0.0f, 10.0f));
}

void SSGun::Render() {
    this->cube.render(this->GetCenter(), 0.3f);
}
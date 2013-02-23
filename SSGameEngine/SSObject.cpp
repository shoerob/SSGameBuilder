//
//  CoreObject.cpp
//  SSGameEngine
//
//  Created by Robert Shoemate on 2/18/13.
//  Copyright (c) 2013 Robert Shoemate. All rights reserved.
//

#include "SSObject.h"

using namespace SoftShoe::GameEngine;

SSObject::SSObject() {
    _tag = 0;
}

SSObject::SSObject(int tag) {
    _tag = tag;
}


SSObject::~SSObject() {

}

SSObject_ptr SSObject::create(int tag) {
    SSObject_ptr ssObject(new SSObject(tag));
    return ssObject;
}

Context_ptr SSObject::context() {
    return _context;
}

void SSObject::setContext(Context_ptr context) {
    _context = context;
}

void SSObject::update() {
    
}

void SSObject::render() {
    
}
//
//  Shader.fsh
//  SSMobileGame
//
//  Created by Robert Shoemate on 1/20/13.
//  Copyright (c) 2013 Robert Shoemate. All rights reserved.
//

varying lowp vec4 colorVarying;

void main()
{
    gl_FragColor = colorVarying;
}

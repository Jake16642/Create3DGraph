//
//  Point.cpp
//  CreateASphere
//
//  Created by MAC on 5/11/21.
//

#include "Point.hpp"

Point::Point(float X, float Y, float Z){
    x= X;
    y= Y;
    z= Z;
}

Point::Point(int i){
    x= x*i;
    y= y*i;
    z= z*i;
}

Point::Point()
{
    x= y = z = 0;
}




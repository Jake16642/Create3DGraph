//
//  Point.hpp
//  Create3DGraph
//  
//  Created by Jake Tran on 5/11/21.
//

#ifndef Point_hpp
#define Point_hpp

#include <stdio.h>

class Point
{
    public:
        float x,y,z;
    
    Point() ;
    Point(float x,float y ,float z);
    Point(int i);
};

#endif /* Point_hpp */

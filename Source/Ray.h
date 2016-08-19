//
//  Ray.h
//  Raytracing
//
//  Created by storehouser on 7/27/16.
//  Copyright © 2016 storehouser. All rights reserved.
//

#ifndef Ray_h
#define Ray_h

#include "Vector3.h"

class Ray
{
public:
    Ray() { }
    Ray(const Vector3 a, const Vector3 b) { A = a; B = b; }
    Vector3 Origin() const      { return A; }
    Vector3 Direction() const   { return B; }
    Vector3 PointAtParam(float t) const { return A + t * B; }
    
public:
    Vector3 A;
    Vector3 B;
};

#endif /* Ray_h */

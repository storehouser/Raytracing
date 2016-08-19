//
//  Hitable.h
//  Raytracing
//
//  Created by storehouser on 8/20/16.
//  Copyright © 2016 storehouser. All rights reserved.
//

#ifndef Hitable_h
#define Hitable_h

#include "Ray.h"

struct HitRecord
{
    float   t;
    Vector3 p;
    Vector3 normal;
};

class Hitable
{
public:
    virtual bool Hit(const Ray& r, float tMin, float tMax, HitRecord& rec) const = 0;
};


#endif /* Hitable_h */

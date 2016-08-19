//
//  Sphere.h
//  Raytracing
//
//  Created by storehouser on 8/20/16.
//  Copyright © 2016 storehouser. All rights reserved.
//

#ifndef Sphere_h
#define Sphere_h

#include "Hitable.h"

class Sphere : public Hitable
{
public:
    Sphere();
    Sphere(Vector3 cen, float r) : center(cen), radius(r) { };
    virtual bool Hit(const Ray& r, float tMin, float tMax, HitRecord& rec) const override;
    Vector3     center;
    float       radius;
};

bool Sphere::Hit(const Ray& r, float tMin, float tMax, HitRecord& rec) const
{
    Vector3 oc = r.Origin() - center;
    
    float a = Dot(r.Direction(), r.Direction());
    float b = Dot(oc, r.Direction());
    float c = Dot(oc, oc) - radius * radius;
    
    float discriminant = b * b - a * c;
    
    if (discriminant > 0)
    {
        float temp = (-b - sqrt(discriminant)) / a;
        if (temp < tMax && temp > tMin)
        {
            rec.t = temp;
            rec.p = r.PointAtParam(rec.t);
            rec.normal = (rec.p - center) / radius;
            
            return true;
        }
        
        temp = (-b + sqrt(discriminant)) / a;
        if (temp < tMax && temp > tMin)
        {
            rec.t = temp;
            rec.p = r.PointAtParam(rec.t);
            rec.normal = (rec.p - center) / radius;
            
            return true;
        }
    }
    
    return false;
}


#endif /* Sphere_h */

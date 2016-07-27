//
//  main.cpp
//  Raytracing
//
//  Created by storehouser on 7/21/16.
//  Copyright © 2016 storehouser. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "Vector3.h"
#include "Ray.h"

bool HitSphere(const Vector3& center, float radius, const Ray& r)
{
    Vector3 oc = r.Origin() - center;
    float a = Dot(r.Direction(), r.Direction());
    float b = 2.0 * Dot(oc, r.Direction());
    float c = Dot(oc, oc) - radius * radius;
    float discriminant = b * b - 4 * a * c;
    
    return (discriminant > 0);
}

Vector3 Color(const Ray& r)
{
    if (HitSphere(Vector3(0, 0, -1), 0.5f, r))
    {
        return Vector3(1, 0, 0);
    }

    Vector3 UnitDirection = UnitVector(r.Direction());
    float t = 0.5f * (UnitDirection.Y() + 1.0f);
    return (1.0 - t) * Vector3(1.0f, 1.0f, 1.0f) + t * Vector3(0.5, 0.7, 1.0);
}

int main(int argc, const char * argv[])
{
    std::ofstream myFile("/Users/storehouser/Desktop/MyRayTracing.ppm");
    
    int nx = 200;
    int ny = 100;
    
    myFile << "P3\n" << nx << " " << ny << "\n255\n";
    
    Vector3 LowerleftCorner(-2.0f, -1.0f, -1.0f);
    Vector3 Horizontal(4.0f, 0.0f, 0.0f);
    Vector3 Vertical(0.0f, 2.0f, 0.0f);
    Vector3 Origin(0.0f, 0.0f, 0.0f);
    
    for (int j = ny - 1; j >= 0; --j)
    {
        for (int i = 0; i < nx; ++i)
        {
            float u = float(i) / float(nx);
            float v = float(j) / float(ny);
            
            Ray r(Origin, LowerleftCorner + u * Horizontal + v * Vertical);
            Vector3 col = Color(r);
            
            int ir = int(255.99 * col.R());
            int ig = int(255.99 * col.G());
            int ib = int(255.99 * col.B());
            
            myFile << ir << " " << ig << " " << ib << "\n";
        }
    }
    
    myFile.close();
    
    return 0;
}

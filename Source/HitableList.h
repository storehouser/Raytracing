//
//  HitableList.h
//  Raytracing
//
//  Created by storehouser on 8/20/16.
//  Copyright © 2016 storehouser. All rights reserved.
//

#ifndef HitableList_h
#define HitableList_h

#include "Hitable.h"

class HitableList : public Hitable
{
public:
    HitableList() { }
    HitableList(Hitable** l, int n) { list = l, listSize = n; }
    virtual bool Hit(const Ray& r, float tMin, float tMax, HitRecord& rec) const override;
    
public:
    Hitable** list;
    int listSize;
};

bool HitableList::Hit(const Ray& r, float tMin, float tMax, HitRecord& rec) const
{
    HitRecord tempRec;
    bool bHitAnything = false;
    double closestSoFar = tMax;
    
    for (int i = 0; i < listSize; ++i)
    {
        if (list[i]->Hit(r, tMin, closestSoFar, tempRec))
        {
            bHitAnything = true;
            closestSoFar = tempRec.t;
            rec = tempRec;
        }
    }
    
    return bHitAnything;
}


#endif /* HitableList_h */

#include <limits>
#include "box.h"

// Return whether the ray intersects this box.
bool Box::Intersection(const Ray& ray) const
{
    // return true;
    // std::cout<<lo<<"TEST"<<hi<<std::endl;
    TODO;
    float tmin, tmax, tymin, tymax, tzmin, tzmax; 
    vec3 invdir(1/ray.direction[0],1/ray.direction[1],1/ray.direction[2]);

    tmin = (lo[0] - ray.endpoint[0]) * invdir[0]; 
    tmax = (hi[0] - ray.endpoint[0]) * invdir[0]; 
    tymin = (lo[1] - ray.endpoint[1]) * invdir[1]; 
    tymax = (hi[1] - ray.endpoint[1]) * invdir[1]; 
 
    if ((tmin > tymax) || (tymin > tmax)) 
        return false; 
    if (tymin > tmin) 
        tmin = tymin; 
    if (tymax < tmax) 
        tmax = tymax; 
 
    tzmin = (lo[2] - ray.endpoint[2]) * invdir[2]; 
    tzmax = (hi[2] - ray.endpoint[2]) * invdir[2]; 
 
    if ((tmin > tzmax) || (tzmin > tmax)) 
        return false; 
    if (tzmin > tmin) 
        tmin = tzmin; 
    if (tzmax < tmax) 
        tmax = tzmax; 
 
    return true;
}

// Compute the smallest box that contains both *this and bb.
Box Box::Union(const Box& bb) const
{
    Box box;
    vec3 tempLo,tempHi;
    // if(lo<bb.lo){
    //     tempLo = bb.lo;
    // }else{
    //     tempLo = lo;
    // }
    // if(hi<bb.hi){
    //     tempHi = bb.hi;
    // }else{
    //     tempHi = hi;
    // }
    // tempLo = vec3(1,3,4);
    TODO;
    box.hi = tempHi;
    box.lo = tempLo;
    return box;
}

// Enlarge this box (if necessary) so that pt also lies inside it.
void Box::Include_Point(const vec3& pt)
{
    for(int i=0;i<3;i++){
        if(hi[i]<pt[i]){
            hi[i] = pt[i];
        }
        if(lo[i]>pt[i]){
            lo[i]=pt[i];
        }
    }
    TODO;
}

// Create a box to which points can be correctly added using Include_Point.
void Box::Make_Empty()
{
    lo.fill(std::numeric_limits<double>::infinity());
    hi=-lo;
}

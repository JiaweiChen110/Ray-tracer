#include "plane.h"
#include "ray.h"
#include <cfloat>
#include <limits>

// Intersect with the half space defined by the plane.  The plane's normal
// points outside.  If the ray starts on the "inside" side of the plane, be sure
// to record a hit with t=0 as the first entry in hits.
Hit Plane::Intersection(const Ray& ray, int part) const
{
    TODO;
    double t;
    Hit obj;
    // return obj;
    obj.object = NULL;
    obj.dist = 0;
    obj.part = 0;

    vec3 w = x1 - ray.endpoint;
    double dem = dot(ray.direction,normal);
    if(!dem){
        return obj;
    }

    t = dot(w,normal)/dem;
    if(t<small_t){
        return obj;
    }

    obj.object = this;
    obj.dist = t;

    return obj;
}

vec3 Plane::Normal(const vec3& point, int part) const
{
    return normal;
}

// There is not a good answer for the bounding box of an infinite object.
// The safe thing to do is to return a box that contains everything.
Box Plane::Bounding_Box(int part) const
{
    Box b;
    b.hi.fill(std::numeric_limits<double>::max());
    b.lo=-b.hi;
    return b;
}

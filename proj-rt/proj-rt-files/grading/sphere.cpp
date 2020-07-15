#include "sphere.h"
#include "ray.h"

// Determine if the ray intersects with the sphere
Hit Sphere::Intersection(const Ray& ray, int part) const
{
    TODO;
    Hit obj;
    // std::cout<<"SPHERE"<<radius<<"center"<<center<<"RAY"<<ray.endpoint<<"direction"<<ray.direction<<"obj.part"<<obj.part<<std::endl;
    // vec3 point = ray.endpoint - center;
    double a = dot(ray.direction, ray.direction);
    double b =  2*dot(ray.direction,ray.endpoint-center);
    double c = dot(ray.endpoint-center,ray.endpoint-center) - radius*radius;
    double discriminant = b*b - 4*a*c;

    if(discriminant<0){
        obj.dist = small_t-2;
        obj.object = NULL;
        obj.part = 0;
        return obj;
    }

    // if((-b+sqrt(discriminant)/(2*a)))
    double t1 = (-b+sqrt(discriminant))/(2*a);
    double t2 = (-b-sqrt(discriminant))/(2*a);

    if(t1<t2 && t1>= small_t){
        obj.dist = t1;
    }else if(t2 <= t1 && t2>= small_t){
        obj.dist = t2;
    }
    obj.object = this;
    // obj.dist = discriminant/(2*a);
    obj.part = part;

    // std::cout<<"TESTING!SPHERE"<<obj.dist<<"Part"<<obj.part<<std::endl;
    return obj;
}

vec3 Sphere::Normal(const vec3& point, int part) const
{
    vec3 normal;
    TODO; // compute the normal direction
    // if(part<0){
        
    // }
    // std::cout<<"RUN SPHERE NORMAL"<<std::endl;
    normal = point - center;
    return normal.normalized();
}

Box Sphere::Bounding_Box(int part) const
{
    Box box;
    TODO; // calculate bounding box
    vec3 rV(radius,radius,radius);
    box.lo = center-rV;
    box.hi = center+rV;
    // std::cout<<"SPHERE"<<std::endl;
    return box;
}

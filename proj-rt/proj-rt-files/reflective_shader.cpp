#include "reflective_shader.h"
#include "ray.h"
#include "render_world.h"

vec3 Reflective_Shader::
Shade_Surface(const Ray& ray,const vec3& intersection_point,
    const vec3& normal,int recursion_depth) const
{
    vec3 color;
    // return color;
    TODO; // determine the color
    Ray rr;
    rr.endpoint = intersection_point;
    //ray, I
    vec3 r = ray.direction - (2 * dot(ray.direction, normal) * normal);
    //rr, R
    rr.direction = r;
    // std::cout<<"RR -->"<<rr.direction<<"  end point"<<rr.endpoint<<std::endl;
    // return color;
    //reflective color
    vec3 rc = world.Cast_Ray(rr,recursion_depth+1);
    // return color;
    //light to surface color
    vec3 lc = shader->Shade_Surface(ray, intersection_point, normal,recursion_depth);
    // return color;
    color = reflectivity * rc + (1 - reflectivity) * lc;
    // std::cout<<"println reflective"<<std::endl;
    return color;
}

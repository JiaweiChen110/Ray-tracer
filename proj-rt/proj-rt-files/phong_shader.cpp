#include "light.h"
#include "phong_shader.h"
#include "ray.h"
#include "render_world.h"
#include "object.h"

vec3 Phong_Shader::
Shade_Surface(const Ray& ray,const vec3& intersection_point,
    const vec3& normal,int recursion_depth) const
{
    vec3 color,intenA, intenD,intenS;
    intenA = color_ambient * world.ambient_color * world.ambient_intensity;

    for(size_t i =0;i<world.lights.size();i++){
        vec3 l = world.lights[i]->position - intersection_point;

        Ray tl(intersection_point,l);
        Hit obj = world.Closest_Intersection(tl);
        vec3 objHit = tl.Point(obj.dist) - intersection_point;

        if(!world.enable_shadows||(!obj.object||objHit.magnitude() > l.magnitude())){
            vec3 s = (-l + 2*dot(l,normal)*normal).normalized();
            intenD += color_diffuse * world.lights[i]->Emitted_Light(l)*std::max(dot(normal,l.normalized()),0.0);
            intenS += color_specular * world.lights[i]->Emitted_Light(l)*std::pow(std::max(dot(s,-(ray.direction)),0.0),specular_power);
        }

    }
    TODO; //determine the color
    color = intenA + intenD + intenS;
    return color;
}

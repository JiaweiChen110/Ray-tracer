#include "render_world.h"
#include "flat_shader.h"
#include "object.h"
#include "light.h"
#include "ray.h"
#include "sphere.h"

extern bool disable_hierarchy;

Render_World::Render_World()
    :background_shader(0),ambient_intensity(0),enable_shadows(true),
    recursion_depth_limit(3)
{}

Render_World::~Render_World()
{
    delete background_shader;
    for(size_t i=0;i<objects.size();i++) delete objects[i];
    for(size_t i=0;i<lights.size();i++) delete lights[i];
}

// Find and return the Hit structure for the closest intersection.  Be careful
// to ensure that hit.dist>=small_t.
Hit Render_World::Closest_Intersection(const Ray& ray)
{
    Hit objHit;
    objHit.object = NULL;
    // std::cout<<objHit.object<<std::endl;
    // std::cout<<"testingSIZE"<<objects.size()<<std::endl;
    for(size_t i=0;i<objects.size();i++){
        // std::cout<<"IN"<<std::endl;
        // objects[i]->~Object.Intersection(ray,objects[i]->number_parts);
        // objects[i]->Intersection
        // std::cout<<objects[i]->center<<std::endl;
        Hit temp = objects[i]->Intersection(ray,objects[i]->number_parts);
        // std::cout<<"OUT"<<std::endl;
        // if(temp.dist>small_t){
        //     std::cout<<temp.dist<<"TESTING"<<temp.part<<std::endl;
        // }
        // std::cout<<"testing"<<temp.dist<<"part"<<temp.part<<std::endl;
        // std::cout<<objects[i]->Bounding_Box(objects[i]->number_parts).hi<<std::endl;
        // std::cout<<ray.endpoint<<"TEST"<<ray.Point(temp.dist)<<"DIRECTION"<<ray.direction<<std::endl;
        if(temp.dist>=small_t){
            if(objHit.object == NULL){
                objHit = temp;
                // std::cout<<"crash?TEST1111"<<std::endl;
                // objHit.part = temp.part;
            }else{
                if(objHit.dist > temp.dist){
                    objHit = temp;
                    // objHit.part = temp.part;
                }
            }
        }
    }
    TODO;
    // if(objHit.object!=NULL)
    // std::cout<<"TESTING AGAIN"<<objHit.dist<<"part"<<objHit.part<<std::endl;
    // if(objHit)
    return objHit;
}

// set up the initial view ray and call
void Render_World::Render_Pixel(const ivec2& pixel_index)
{
    TODO; // set up the initial view ray here
    // std::cout<<"TESTING"<<std::endl;
    Ray ray;
    ray.endpoint = camera.position;

    ray.direction = (camera.World_Position(pixel_index)-camera.position).normalized();
    vec3 color=Cast_Ray(ray,1);
    // if(color[0] == 1 && color[1] == 0 && color[2] == 0){
    //     std::cout<<"COLOR"<<std::endl;
    // }
    // if(pixel_index=)
    // std::cout<<Pixel_Color(color)<<"COLOR"<<std::endl;
    // vec3 color(0,2,4);
    // std::cout<<Pixel_Color(color)<<"TESt"<<std::endl;
    // if(pixel_index[0] == 350 && pixel_index[1] == 240){
    //     std::cout<<Pixel_Color(color)<<"COLOR"<<std::endl;
    // }
    camera.Set_Pixel(pixel_index,Pixel_Color(color));
}

void Render_World::Render()
{
    if(!disable_hierarchy)
        Initialize_Hierarchy();

    for(int j=0;j<camera.number_pixels[1];j++)
        for(int i=0;i<camera.number_pixels[0];i++)
            Render_Pixel(ivec2(i,j));

    // std::cout<<"DONE"<<std::endl;
}

// cast ray and return the color of the closest intersected surface point,
// or the background color if there is no object intersection
vec3 Render_World::Cast_Ray(const Ray& ray,int recursion_depth)
{
    vec3 color;
    if(recursion_depth > recursion_depth_limit) {
        vec3 noV;
        color = background_shader->Shade_Surface(ray, noV, noV, recursion_depth);
        return color;
    }
    // Hit temp2;
    // std::cout<<"crash?222"<<std::endl;
    Hit obj = Closest_Intersection(ray);
    if(obj.object!=NULL){
        //get the object color
        // std::cout<<"crash?"<<obj.dist<<"Part"<<obj.part<<std::endl;
        
        vec3 inters = ray.Point(obj.dist);
        // std::cout<<"crash?66666666"<<std::endl;
        vec3 n = obj.object->Normal(inters,obj.part);
        // std::cout<<"crash?777777"<<std::endl;
        n = n.normalized();
        // std::cout<<"crash?"<<n<<std::endl;
        color = obj.object->material_shader->Shade_Surface(ray,inters,n,recursion_depth);
        // std::cout<<Pixel_Color(color)<<"TESt"<<std::endl;
        // vec3 t(0.2,1.4,4);
        // return color;
    }else{
        //get background color
        vec3 defaultC;
        color = background_shader->Shade_Surface(ray,defaultC,defaultC, recursion_depth);
        // std::cout<<Pixel_Color(color)<<"TESt"<<std::endl;
    }
    
    // std::cout<<"DONE"<<std::endl;
    // std::cout<<"crash?"<<obj.dist<<"Part"<<obj.part<<std::endl;
    // std::cout<<"crash?1000000"<<ray.Point(obj.dist)<<"END"<<ray.endpoint<<std::endl;
    // if(obj.object!=NULL){
    //     // std::cout<<"crash?4444"<<std::endl;
    //     vec3 inters = ray.Point(obj.dist);
    //     // std::cout<<"crash?66666666"<<std::endl;
    //     vec3 n = obj.object->Normal(inters,obj.part);
    //     // std::cout<<"crash?777777"<<std::endl;
    //     n = n.normalized();
    //     // std::cout<<"crash?555555"<<std::endl;
    //     color = obj.object->material_shader->Shade_Surface(ray,inters,n,recursion_depth);
    // }else{
    //     vec3 inters;
	//     color = background_shader->Shade_Surface(ray, inters, inters, recursion_depth);
    // }
    TODO; // determine the color here
    // std::cout<<color<<"COLOR"<<std::endl;
    
    return color;
}

void Render_World::Initialize_Hierarchy()
{
    TODO; // Fill in hierarchy.entries; there should be one entry for
    // each part of each object.
    // adsadasdsad

    // std::cout<<"TESITNG"<<std::endl;
    // if(!hierarchy.entries.empty()){
        // Box test = hierarchy.entries.at(0).box;
        // std::cout<<"RUN HIERARCHY"<<objects.size()<<std::endl;
    // }
    for(size_t i=0;i<objects.size();i++){
        // temp = 
        // temp
        Entry temp;
        temp.obj = objects.at(i);
        temp.part = objects.at(i)->number_parts;
        temp.box = objects.at(i)->Bounding_Box(temp.part);
        // hierarchy.entries.at(i).obj = 
        // hierarchy.entries.at(i).part = objects.at(i)->number_parts;
        // hierarchy.entries.at(i).box = objects.at(i)->Bounding_Box(objects.at(i)->number_parts);
        hierarchy.entries.push_back(temp);
        // std::cout<<hierarchy.entries.at(i).box.lo<<std::endl;
    }


    hierarchy.Reorder_Entries();
    hierarchy.Build_Tree();
}


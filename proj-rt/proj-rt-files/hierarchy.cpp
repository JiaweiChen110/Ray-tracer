#include <algorithm>
#include "hierarchy.h"

// Reorder the entries vector so that adjacent entries tend to be nearby.
// You may want to implement box.cpp first.
void Hierarchy::Reorder_Entries()
{
    if(!entries.size()) return;
    
    // for(size_t i=0;i<entries.size();i++){
    //     std::cout<<entries.at(i).box.lo<<std::endl;
    // }
    std::sort(entries.begin(),entries.end(),[](const Entry&a, const Entry&b) -> bool{
        // int count =0;
        // if(b.box.lo[0]<a.box.lo[0]){
        //     count++;
        // }
        // if(b.box.lo[1]<a.box.lo[1]){
        //     count++;
        // }
        // if(b.box.lo[2]<a.box.lo[2]){
        //     count++;
        // }
        // if(count>1){
        //     return true;
        // }else{
        //     return false;
        // }
        if(b.box.lo[0]>a.box.lo[0]){
            // if(b.box.lo[1]>a.box.lo[1])
            return true;
        }
        if(b.box.lo[0]==a.box.lo[0] && b.box.lo[1]>a.box.lo[1]){
            return true;
        }
        return false;
    });

    // std::sort(entries.begin(),entries.end(),[](const Entry&a, const Entry&b) -> bool{
    //     if(b.box.lo[1]>a.box.lo[1]){
    //         return true;
    //     }
    //     return false;
    // });
    // entries.
    // // std::cout<<entries[0].box.lo<<"TESTING HERE"<<entries[0].box.hi<<std::endl;
    // for(size_t i=0;i<entries.size();i++){
    //     std::cout<<entries.at(i).box.lo<<std::endl;
    // }
    // std::vector<Entry> temp;
    // for(size_t i=0;i<entries.size();i++){
    //     size_t curClosest = i;
    //     if(temp.size==0){
    //         temp.push_back(entries.at(curClosest));
    //     }else{
    //         int small=0;
    //         double smallDis= dot(entries.at(i).box.lo*entries.at(i).box.lo,temp.at(0).box.lo*temp.at(0).box.lo)+dot(entries.at(i).box.hi*entries.at(i).box.hi,temp.at(0).box.hi*temp.at(0).box.hi);
    //         for(size_t j=1;j<temp.size();j++){
    //             double sDis = sqrt(dot(entries.at(i).box.lo*entries.at(i).box.lo,temp.at(j).box.lo*temp.at(j).box.lo)+dot(entries.at(i).box.hi*entries.at(i).box.hi,temp.at(j).box.hi*temp.at(j).box.hi));
    //             if(sDis < smallDis){
                    
    //             }
    //         }
    //     }
        
    // }
    TODO;
}

// Populate tree from entries.
void Hierarchy::Build_Tree()
{
    // std::cout<<"RUN"<<std::endl;
    if(!entries.size()) return;
    // std::cout<<"RUN"<<std::endl;
    for(size_t i=0;i<entries.size();i++){
        tree.push_back(entries.at(i).box);
        // std::cout<<entries.at(i).box.lo<<std::endl;
    }
    TODO;
}

// Return a list of candidates (indices into the entries list) whose
// bounding boxes intersect the ray.
void Hierarchy::Intersection_Candidates(const Ray& ray, std::vector<int>& candidates) const
{
    // for(size_t i=0;i<tree.size();i++){
    //     std::cout<<tree.at(i).Intersection(ray)<<std::endl;
    // }
    
    TODO;
}

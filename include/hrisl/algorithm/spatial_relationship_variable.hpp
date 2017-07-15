#ifndef SPATIAL_RELATIONSHIP_VARIABLE_HPP_
#define SPATIAL_RELATIONSHIP_VARIABLE_HPP_

#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <math.h>

using namespace std;

namespace hrisl {
    
class Entity {
public:
    int id;
    std::stirng name;
    double dir;
    vector<double> center;
    vector<double> p3d;
}
    
class SRV{
public:
    int id;
    std::string type;
    Entity entRef;
    Entity entObj;
    vector<double> hofXY;
    vector<double> hofXYZ;
    
    vector<double>  insideDirWeights;
    vector<double> outsideDirWeights;
    vector<double>       DistWeights;
};

class WorldStateFeature {
    std::set<std::string> 
};
    
};

#endif
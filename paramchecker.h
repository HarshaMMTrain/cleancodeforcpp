#include <string>
#include <vector>

struct vitalParam
{
    std::string name;
    float value;
};

struct vitalResult
{
    std::string name;
    bool vOk;
};

int vitalsOk(std::vector<struct vitalParam> &vitalsArray);

int vitalsOkEx(std::vector<struct vitalParam> &vitalsArray,
               std::vector<struct vitalResult> *vResult);


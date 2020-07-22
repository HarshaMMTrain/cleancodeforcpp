#include <string>
#include <vector>

struct vitalParam
{
    std::string name;
    float value;
};
int vitalsOk(std::vector<struct vitalParam> &vitalsArray);

bool vitalsAreOk(float bpm, float spo2, float respRate);

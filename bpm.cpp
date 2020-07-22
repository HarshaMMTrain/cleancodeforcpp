#include "bpm.hpp"
#include "paramValidator.hpp"
#include "dbregister.hpp"

REGISTER_TODB(bpm, "bpm")

bool
bpm::paramOk(float param)
{
    paramValidator bpmValidator(70, 150);
    return bpmValidator.paramOk(param);
}



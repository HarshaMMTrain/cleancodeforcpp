#include "spo.hpp"
#include "paramValidator.hpp"
#include "dbregister.hpp"

REGISTER_TODB(spo, "spo")

bool
spo::paramOk(float param)
{
    paramValidator spoValidator(80, -1);
    return spoValidator.paramOk(param);
}



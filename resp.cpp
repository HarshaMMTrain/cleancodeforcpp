#include "resp.hpp"
#include "paramValidator.hpp"
#include "dbregister.hpp"

REGISTER_TODB(resp, "resp")

bool
resp::paramOk(float param)
{
    paramValidator respValidator(30, 60);
    return respValidator.paramOk(param);
}



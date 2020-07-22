#include "paramchecker.h"
#include "vitalsdb.hpp"
#include <iostream>

static int vitalOk(IVital *vital, float value)
{
    int ret = -1;
    if (NULL != vital)
        ret = (int)(!vital->paramOk(value));
    return ret;
}

int vitalsOk(std::vector<struct vitalParam> &vitalsArray)
{
    int ret = 0;
    vitalsdb* pDb = vitalsdb::getvitalsdb();
    std::vector<struct vitalParam>::iterator iter = vitalsArray.begin();

    for (;(iter != vitalsArray.end()) && (ret == 0); ++iter)
    {
        IVital *pVital = pDb->getVital(iter->name);
        ret = vitalOk(pVital, iter->value);
        pDb->putVital(pVital);
    }

    return ret;
}

static void
storeResult(const std::string &vName, int result,
            std::vector<struct vitalResult> *vResult)
{
    if (NULL != vResult)
    {
        struct vitalResult resVital = {vName, (result == 0)};
        vResult->push_back(resVital);
    }
}

int vitalsOkEx(std::vector<struct vitalParam> &vitalsArray,
              std::vector<struct vitalResult> *vResult)
{
    int ret = 0;
    vitalsdb* pDb = vitalsdb::getvitalsdb();
    std::vector<struct vitalParam>::iterator iter = vitalsArray.begin();

    for (;(iter != vitalsArray.end()); ++iter)
    {
        IVital *pVital = pDb->getVital(iter->name);
        ret |= vitalOk(pVital, iter->value);
        storeResult(iter->name, ret, vResult);
        pDb->putVital(pVital);
    }
    
    return ret;
}

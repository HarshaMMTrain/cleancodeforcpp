
#include "vitalsdb.hpp"

vitalsdb* vitalsdb::pVitalsdb = nullptr;

vitalsdb*
vitalsdb::getvitalsdb()
{
    if (nullptr == pVitalsdb)
        pVitalsdb = new vitalsdb();
    return pVitalsdb;
}

void
vitalsdb::registerVital(const std::string &name, IVallocator *vitalAlloc)
{
    vitalMap[name] = vitalAlloc;
}

IVital*
vitalsdb::getVital(const std::string &vName)
{
    IVital* vital = nullptr;
    std::map<const std::string, IVallocator*>::iterator iter = vitalMap.find(vName);

    if (iter != vitalMap.end())
        vital = (iter->second)->allocV();

    return vital;
}

void
vitalsdb::putVital(IVital *vital)
{
    delete vital;
}

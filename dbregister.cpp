#include "dbregister.hpp"
#include "vitalsdb.hpp"


dbregister::dbregister(const std::string &&vitalName, IVallocator *vitalAlloc)
{
    vitalsdb *pDb = vitalsdb::getvitalsdb();
    if (nullptr != pDb)
        pDb->registerVital(vitalName, vitalAlloc);
}


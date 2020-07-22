#ifndef VITALSDB_HPP
#define VITALSDB_HPP 1

#include "IVital.hpp"
#include "IVallocator.hpp"
#include <map>
#include <string>

typedef IVital* (*vitalAllocator)(void);

class vitalsdb;

class vitalsdb
{
public:
    virtual ~vitalsdb() { pVitalsdb =  nullptr; }
    static vitalsdb* getvitalsdb();
    void registerVital(const std::string &name, IVallocator *vitalAlloc);
    IVital* getVital(const std::string &name);
    void putVital(IVital *vital);
    
private:
    static vitalsdb* pVitalsdb;
    std::map<const std::string, IVallocator *> vitalMap;
    vitalsdb() : vitalMap() { }
};

#endif

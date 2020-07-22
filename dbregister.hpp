#ifndef DBREGISTER_HPP
#define DBREGISTER_HPP 1

#include "IVital.hpp"
#include "IVallocator.hpp"
#include <string>

template<typename T>
class Valloc : public IVallocator
{
public:
    Valloc() { }
    virtual ~Valloc() { }
    virtual IVital * allocV() { return new T(); }
};

class dbregister
{
public:
    dbregister(const std::string &&vitalName, IVallocator *vitalAlloc);
    virtual ~dbregister() { }
};

#define REGISTER_TODB(className, name)                 \
    static Valloc<className> className##Alloc;         \
    static dbregister regVital(std::string(name), &className##Alloc);


#endif

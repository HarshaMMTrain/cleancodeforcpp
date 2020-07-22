#ifndef SPO_HPP
#define SPO_HPP 1

#include "IVital.hpp"

class spo : public IVital
{
public:
    spo() { }
    virtual ~spo() { }
    virtual bool paramOk(float param);
};

#endif

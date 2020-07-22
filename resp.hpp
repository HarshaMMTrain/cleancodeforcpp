#ifndef RESP_HPP
#define RESP_HPP 1

#include "IVital.hpp"

class resp : public IVital
{
public:
    resp() { }
    virtual ~resp() { }
    virtual bool paramOk(float param);
};

#endif

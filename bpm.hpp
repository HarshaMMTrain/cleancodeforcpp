#ifndef BPM_HPP
#define BPM_HPP 1

#include "IVital.hpp"

class bpm : public IVital
{
public:
    bpm() { }
    virtual ~bpm() { }
    virtual bool paramOk(float param);
};

#endif

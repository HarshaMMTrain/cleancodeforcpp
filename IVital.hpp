#ifndef IVITAL_HPP
#define IVITAL_HPP 1

class IVital
{
public:
    IVital() { }
    virtual ~IVital() { }
    virtual bool paramOk(float param) = 0;
};

#endif

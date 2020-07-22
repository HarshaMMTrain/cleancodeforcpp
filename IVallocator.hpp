#ifndef IVALLOCATOR_HPP
#define IVALLOCATOR_HPP 1

class IVallocator
{
public:
    IVallocator() { }
    virtual ~IVallocator() { };
    virtual IVital * allocV(void) = 0;
};

#endif

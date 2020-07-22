#ifndef PARAMVALIDATOR_HPP
#define PARAMVALIDATOR_HPP 1

class paramValidator
{
public:
    paramValidator(float lower = -1, float upper = -1) : max(upper), min(lower) { }
    virtual ~paramValidator() { };
    
    bool paramOk(float param)
    {
        return (upperLimitOk(param) && lowerLimitOk(param));
    };
private:
    float max;
    bool upperLimitOk(float param) { return ((-1 == max) || (param <= max)); }
    float min;
    bool lowerLimitOk(float param) { return ((-1 == min) || (param >= min)); }
};

#endif


class paramValidator
{
public:
    paramValidator(float lower = -1, float upper = -1) : min(lower), max(upper) { }
    virtual ~paramValidator() { };
    
    bool paramOk(float param)
    {
        return (upperLimitOk(param) && lowerLimitOk(param));
    };
protected:
    float min;
    float max;

    bool upperLimitOk(float param) { return ((-1 == max) || (param <= max)); }
    bool lowerLimitOk(float param) { return ((-1 == min) || (param >= min)); }
};



bool bmpOk(float bpm)
{
    paramValidator bpmValidator(70, 150);
    return bpmValidator.paramOk(bpm);
}

bool spoOk(float spo2)
{
    paramValidator spoValidator(80, -1);
    return spoValidator.paramOk(spo2);
}

bool respRateOk(float respRate)
{
    paramValidator respValidator(30, 60);
    return respValidator.paramOk(respRate);
}

bool vitalsAreOk(float bpm, float spo2, float respRate)
{
    return (bmpOk(bpm) && spoOk(spo2) && respRateOk(respRate));
}

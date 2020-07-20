
bool bmpOk(float bpm)
{
  bool ret = true;
  if(bpm < 70 || bpm > 150) {
      ret = false;
  }
  return ret;
}

bool spoOk(float spo2)
{
  bool ret = true;
  if(spo2 < 80) {
      ret = false;
  }
  return ret;
}

bool respRateOk(float respRate)
{
    bool ret = true;
    if(respRate < 30 || respRate > 60)
    {
        ret = false;
    }
    return ret;
}

bool vitalsAreOk(float bpm, float spo2, float respRate)
{
    bool ret = bmpOk(bpm);
    if (ret)
        ret = spoOk(spo2);
    if (ret)
        ret = respRateOk(respRate);
    return ret;
}

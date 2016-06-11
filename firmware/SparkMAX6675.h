// this library is public domain. enjoy!
// www.ladyada.net/learn/sensors/thermocouple

#include "application.h"

class MAX6675 {
 public:
  MAX6675(int8_t sclk_pin, int8_t cs_pin, int8_t miso_pin);

  double readInternal(void);
  double readCelsius(void);
  double readFarenheit(void);
  //  uint8_t readError();
 private:
  int8_t _sclk, _miso, _cs;
  uint8_t spiread8(void);
};



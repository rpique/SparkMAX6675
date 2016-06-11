// this library is public domain. enjoy!
// www.ladyada.net/learn/sensors/thermocouple

#include "math.h"
#include "SparkMAX5575.h"

MAX6675::MAX6675(int8_t sclk_pin, int8_t cs_pin, int8_t miso_pin) {
  _sclk = sclk_pin;
  _cs = cs_pin;
  _miso = miso_pin;

  //define pin modes
  pinMode(_cs, OUTPUT);
  pinMode(_sclk, OUTPUT); 
  pinMode(_miso, INPUT);

  digitalWrite(_cs, HIGH);
}

double MAX6675::readCelsius(void) {

  uint16_t v;

  digitalWrite(_cs, LOW);
  _delay_ms(1);

  v = spiread();
  v <<= 8;
  v |= spiread();

  digitalWrite(_cs, HIGH);

  if (v & 0x4) {
    // uh oh, no thermocouple attached!
    return NAN; 
    //return -100;
  }

  v >>= 3;

  return v*0.25;
}

double MAX6675::readFarenheit(void) {
  return readCelsius() * 9.0/5.0 + 32;
}


byte MAX6675::spiread(void) { 
  int i;
  byte d = 0;

  for (i=7; i>=0; i--)
  {
    digitalWrite(_sclk, LOW);
    _delay_ms(1);
    if (digitalRead(_miso)) {
      //set the bit to 0 no matter what
      d |= (1 << i);
    }

    digitalWrite(_sclk, HIGH);
    _delay_ms(1);
    //Use delay(1)???
  }

  return d;
}


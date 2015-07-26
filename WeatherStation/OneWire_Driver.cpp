
#include "WeatherStation.h"
#include "OneWire_Driver.h"



OneWire_Driver::OneWire_Driver() :ds(10) {
    //OneWire ds(10);  // on pin 10

    device_enum devices[7];
    
    
    OneWire_Driver::enumerate_onewire();

    //for (byte i =0; i<=7; i++) {
    //  Serial.print(i);
    //  Serial.print("   ");
    //  for (byte j=0; j< 8; j++) {
    //    Serial.print(devices[i].addr[j], HEX);
    //  }
    //  Serial.print("\n");
    //}
}


uint8_t OneWire_Driver::enumerate_onewire() {
  uint8_t index = 0;
  uint8_t addr[8];
  
  while (ds.search(addr)) {
    memcpy(devices[index].addr, addr, 8);
    // the first ROM byte indicates which chip
    switch (addr[0]) {
      case 0x10:
        devices[index].type = DS18S20;
        break;
      case 0x28:
        devices[index].type = DS18B20;
        break;
      case 0x22:
        devices[index].type = DS1822;
        break;
      case 0x30:
        devices[index].type = DS2760;
        break;
    };
    index++;
    if (index > sizeof(devices)) {
      break;
    }
  }
  
  // found all devices. Reset the bus for future searches
  ds.reset_search();
  delay(250);
  return(index);
}


void OneWire_Driver::send_command(uint8_t id, uint8_t cmd) {
  if (ds.reset()) {
    ds.select(devices[id].addr);
    ds.write(cmd, 1);         // start conversion, with parasite power on at the end
  
    delay(1000);     // maybe 750ms is enough, maybe not
    // we might do a ds.depower() here, but the reset will take care of it.
  }
}


//byte *read_data(byte id) {
//  byte data[12];
//  
//  if (ds.reset()) {
//    ds.select(devices[id].addr);    
//    ds.write(0xBE);         // Read Scratchpad
//
//    for (byte i = 0; i < 9; i++) {           // we need 9 bytes
//      data[i] = ds.read();
//    }
//
//    //Serial.print(OneWire::crc8(data, 8), HEX);
//  }
//}


uint8_t OneWire_Driver::read_byte() {
  return(ds.read());
}


device_type OneWire_Driver::get_device_type(uint8_t id) {
  return(devices[id].type);
}


float OneWire_Driver::getTemp(uint8_t id) {
  uint8_t data[9];
  uint8_t i;
  
  send_command(id, 0xBE);
  for (i=0; i<9; i++) {
    data[i] = read_byte();
  }
  
  unsigned int raw = (data[1] << 8) | data[0];
  if (get_device_type(id) == DS18S20) {
    raw = raw << 3; // 9 bit resolution default
    if (data[7] == 0x10) {
      // count remain gives full 12 bit resolution
      raw = (raw & 0xFFF0) + 12 - data[6];
    }
  } else {
    byte cfg = (data[4] & 0x60);
    if (cfg == 0x00) raw = raw << 3;  // 9 bit resolution, 93.75 ms
    else if (cfg == 0x20) raw = raw << 2; // 10 bit res, 187.5 ms
    else if (cfg == 0x40) raw = raw << 1; // 11 bit res, 375 ms
    // default is 12 bit resolution, 750 ms conversion time
  }
  return((float)raw / 16.00);
  
}


void OneWire_Driver::DS1820_readTemps(void) {
  float celsius; 
  uint8_t i;
  
  for (i=0; i<=7; i++) {
    if (get_device_type(i) == DS18B20) {
      celsius = getTemp(i);
      Serial.print(i);
      Serial.print("   ");
      Serial.print(celsius);
      Serial.print("\n");
    }
  }
}
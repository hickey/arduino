
#include <inttypes.h>

typedef enum {
  DS18B20, DS18S20, DS1822, DS2760, Unknown
} device_type;


typedef struct {
  uint8_t addr[8];
  device_type type;
} device_enum;

/* ZB_Proto.cpp */
extern void ZB_ProtoInitialize(void);


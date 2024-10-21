#ifndef INC_EEPROM_H_
#define INC_EEPROM_H_

#define MEM_SIZE 0

#include <inttypes.h>

enum Address {
	//variables here
	AddrSpeed
};

struct Variable {
	enum Address name;
	uint16_t min;
	uint16_t max;
};

void Memory_Init(void);

#ifdef __cplusplus
extern "C" {
#endif
uint16_t Memory_GetMin(enum Address name);
uint16_t Memory_GetMax(enum Address name);

uint16_t Memory_Read(enum Address name);
void Memory_Write(enum Address name, uint16_t);
//ensure not writing over page gap (every 64 bytes)
void Memory_Toggle(enum Address name);

void Memory_Evaluate(void);

void Memory_ResetAll(void);
#ifdef __cplusplus
}
#endif

#endif

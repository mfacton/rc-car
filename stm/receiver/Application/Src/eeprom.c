#include "eeprom.h"
#include "lib/i2c_eeprom.h"
#include "main.h"
#include <string.h>
#include <stdlib.h>

static struct Variable variables[] = {
	{AddrSpeed, 1, 20}
		//define edit variable bounds
};

static uint8_t var_addr[MEM_SIZE];
static uint16_t mem_buf[MEM_SIZE];

void Memory_Init(void) {
	const uint8_t size = sizeof(variables)/sizeof(struct Variable);
	for (uint8_t i = 0; i < size; i++) {
		var_addr[variables[i].name] = i;
	}

	eeprom_random_read(0, (uint8_t*)mem_buf, MEM_SIZE*2);
	Memory_Evaluate();
}

uint16_t Memory_GetMin(enum Address name) {
	return variables[var_addr[name]].min;
}

uint16_t Memory_GetMax(enum Address name) {
	return variables[var_addr[name]].max;
}

uint16_t Memory_Read(enum Address name) {
	return mem_buf[name];
}

void Memory_Write(enum Address name, uint16_t value) {
	if (value == mem_buf[name]) {
		return;
	}
	uint8_t buf[2] = {value&0xff, value>>8};
	memcpy(mem_buf+name, buf, 2);
	eeprom_write(name<<1, buf, 2);
	HAL_Delay(2);
}

void Memory_Toggle(enum Address name) {
	Memory_Write(name, !mem_buf[name]);
}

void Memory_Evaluate(void) {

}

void Memory_ResetAll(void) {
}


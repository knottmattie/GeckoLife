#include <msp430.h> 
#include <stdint.h>
#include "sensor_Read.h"

/*
 * main.c
 */
int main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer
    PM5CTL0 &= ~LOCKLPM5;

    uint8_t slaveAddress = 0x40;
    uint8_t registerAddress = 0xE0;

    init_i2c ();

    read_Sensor (slaveAddress, registerAddress);
	
	return 0;
}

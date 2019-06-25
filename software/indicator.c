#include "Board.h"
#include "driverlib.h"
#include "indicator.h"

void indicator_init(void) {
    GPIO_setAsOutputPin(GPIO_PORT_MUX_ENABLE, GPIO_PIN_MUX_ENABLE);
}

void indicator_set(bool on) {
    // Set indicator LED on/off accordingly
    on ? GPIO_setOutputHighOnPin(GPIO_PORT_INDICATOR, GPIO_PIN_INDICATOR) : GPIO_setOutputLowOnPin(GPIO_PORT_INDICATOR, GPIO_PIN_INDICATOR);
}

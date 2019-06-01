#include "mux.h"
#include "Board.h"
#include "driverlib.h"

void mux_init(void) {
    // Initiate mux select lines
    GPIO_setAsOutputPin(GPIO_PORT_MUX_SELECT0, GPIO_PIN_MUX_SELECT0);
    GPIO_setOutputLowOnPin(GPIO_PORT_MUX_SELECT0, GPIO_PIN_MUX_SELECT0);

    GPIO_setAsOutputPin(GPIO_PORT_MUX_SELECT1, GPIO_PIN_MUX_SELECT1);
    GPIO_setOutputLowOnPin(GPIO_PORT_MUX_SELECT1, GPIO_PIN_MUX_SELECT1);

    GPIO_setAsOutputPin(GPIO_PORT_MUX_SELECT2, GPIO_PIN_MUX_SELECT2);
    GPIO_setOutputLowOnPin(GPIO_PORT_MUX_SELECT2, GPIO_PIN_MUX_SELECT2);

    // Enable the mux
    GPIO_setAsOutputPin(GPIO_PORT_MUX_ENABLE, GPIO_PIN_MUX_ENABLE);
    GPIO_setOutputHighOnPin(GPIO_PORT_MUX_ENABLE, GPIO_PIN_MUX_ENABLE);
}

void mux_select(mux_ref_resistor resistor) {
    switch(resistor) {
        case MUX_REF_RESISTOR_100_OHM:
            GPIO_setOutputLowOnPin(GPIO_PORT_MUX_SELECT0, GPIO_PIN_MUX_SELECT0);
            GPIO_setOutputLowOnPin(GPIO_PORT_MUX_SELECT1, GPIO_PIN_MUX_SELECT1);
            GPIO_setOutputLowOnPin(GPIO_PORT_MUX_SELECT2, GPIO_PIN_MUX_SELECT2);
            break;
        case MUX_REF_RESISTOR_1_KOHM:
            GPIO_setOutputLowOnPin(GPIO_PORT_MUX_SELECT0, GPIO_PIN_MUX_SELECT0);
            GPIO_setOutputLowOnPin(GPIO_PORT_MUX_SELECT1, GPIO_PIN_MUX_SELECT1);
            GPIO_setOutputHighOnPin(GPIO_PORT_MUX_SELECT2, GPIO_PIN_MUX_SELECT2);
            break;
        case MUX_REF_RESISTOR_1_MOHM:
            break;
        default:
            break;
    }
}

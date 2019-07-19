#include "mux.h"
#include "Board.h"
#include "driverlib.h"
#include "resistance.h"

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
    GPIO_setOutputLowOnPin(GPIO_PORT_MUX_ENABLE, GPIO_PIN_MUX_ENABLE);
}

void mux_select(mux_ref_resistor resistor) {
    switch(resistor) {
        case MUX_REF_RESISTOR_1120_KOHM:
            GPIO_setOutputLowOnPin(GPIO_PORT_MUX_SELECT0, GPIO_PIN_MUX_SELECT0);
            GPIO_setOutputLowOnPin(GPIO_PORT_MUX_SELECT1, GPIO_PIN_MUX_SELECT1);
            GPIO_setOutputLowOnPin(GPIO_PORT_MUX_SELECT2, GPIO_PIN_MUX_SELECT2);
            break;
        case MUX_REF_RESISTOR_560_KOHM:
            GPIO_setOutputHighOnPin(GPIO_PORT_MUX_SELECT0, GPIO_PIN_MUX_SELECT0);
            GPIO_setOutputLowOnPin(GPIO_PORT_MUX_SELECT1, GPIO_PIN_MUX_SELECT1);
            GPIO_setOutputLowOnPin(GPIO_PORT_MUX_SELECT2, GPIO_PIN_MUX_SELECT2);
            break;
        case MUX_REF_RESISTOR_100_KOHM:
            GPIO_setOutputLowOnPin(GPIO_PORT_MUX_SELECT0, GPIO_PIN_MUX_SELECT0);
            GPIO_setOutputHighOnPin(GPIO_PORT_MUX_SELECT1, GPIO_PIN_MUX_SELECT1);
            GPIO_setOutputLowOnPin(GPIO_PORT_MUX_SELECT2, GPIO_PIN_MUX_SELECT2);
            break;
        case MUX_REF_RESISTOR_10_KOHM:
            GPIO_setOutputHighOnPin(GPIO_PORT_MUX_SELECT0, GPIO_PIN_MUX_SELECT0);
            GPIO_setOutputHighOnPin(GPIO_PORT_MUX_SELECT1, GPIO_PIN_MUX_SELECT1);
            GPIO_setOutputLowOnPin(GPIO_PORT_MUX_SELECT2, GPIO_PIN_MUX_SELECT2);
            break;
        case MUX_REF_RESISTOR_1_KOHM:
            GPIO_setOutputLowOnPin(GPIO_PORT_MUX_SELECT0, GPIO_PIN_MUX_SELECT0);
            GPIO_setOutputLowOnPin(GPIO_PORT_MUX_SELECT1, GPIO_PIN_MUX_SELECT1);
            GPIO_setOutputHighOnPin(GPIO_PORT_MUX_SELECT2, GPIO_PIN_MUX_SELECT2);
            break;
        case MUX_REF_RESISTOR_470_OHM:
            GPIO_setOutputHighOnPin(GPIO_PORT_MUX_SELECT0, GPIO_PIN_MUX_SELECT0);
            GPIO_setOutputLowOnPin(GPIO_PORT_MUX_SELECT1, GPIO_PIN_MUX_SELECT1);
            GPIO_setOutputHighOnPin(GPIO_PORT_MUX_SELECT2, GPIO_PIN_MUX_SELECT2);
            break;
        case MUX_REF_RESISTOR_100_OHM:
            GPIO_setOutputLowOnPin(GPIO_PORT_MUX_SELECT0, GPIO_PIN_MUX_SELECT0);
            GPIO_setOutputHighOnPin(GPIO_PORT_MUX_SELECT1, GPIO_PIN_MUX_SELECT1);
            GPIO_setOutputHighOnPin(GPIO_PORT_MUX_SELECT2, GPIO_PIN_MUX_SELECT2);
            break;
        case MUX_REF_RESISTOR_33_OHM:
            GPIO_setOutputHighOnPin(GPIO_PORT_MUX_SELECT0, GPIO_PIN_MUX_SELECT0);
            GPIO_setOutputHighOnPin(GPIO_PORT_MUX_SELECT1, GPIO_PIN_MUX_SELECT1);
            GPIO_setOutputHighOnPin(GPIO_PORT_MUX_SELECT2, GPIO_PIN_MUX_SELECT2);
            break;
        default:
            break;
    }
}

uint32_t mux_convert_resistance(mux_ref_resistor resistor) {
    switch(resistor) {
        case MUX_REF_RESISTOR_33_OHM:
            return 33;
        case MUX_REF_RESISTOR_100_OHM:
            return 100;
        case MUX_REF_RESISTOR_470_OHM:
            return 470;
        case MUX_REF_RESISTOR_1_KOHM:
            return 1000;
        case MUX_REF_RESISTOR_10_KOHM:
            return 10000;
        case MUX_REF_RESISTOR_100_KOHM:
            return 100000;
        case MUX_REF_RESISTOR_560_KOHM:
            return 560000;
        case MUX_REF_RESISTOR_1120_KOHM:
            return 1120000;
        default:
            // Return an invalid 0 on error
            return 0;
    }
}

void mux_terminate(void) {
    GPIO_setOutputLowOnPin(GPIO_PORT_MUX_SELECT0, GPIO_PIN_MUX_SELECT0);
    GPIO_setOutputLowOnPin(GPIO_PORT_MUX_SELECT1, GPIO_PIN_MUX_SELECT1);
    GPIO_setOutputLowOnPin(GPIO_PORT_MUX_SELECT2, GPIO_PIN_MUX_SELECT2);
    GPIO_setHighLowOnPin(GPIO_PORT_MUX_ENABLE, GPIO_PIN_MUX_ENABLE);
}

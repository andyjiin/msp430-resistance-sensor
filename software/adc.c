#include "driverlib.h"
#include "Board.h"
#include "adc.h"

static volatile uint16_t adc_reading = 0;

void adc_init(void) {
    // ADC set-up
     GPIO_setAsPeripheralModuleFunctionInputPin(GPIO_PORT_ADC8, GPIO_PIN_ADC8, GPIO_FUNCTION_ADC8);

     PMM_unlockLPM5();

     ADC_init(ADC_BASE, ADC_SAMPLEHOLDSOURCE_SC, ADC_CLOCKSOURCE_ADCOSC, ADC_CLOCKDIVIDER_1);
     ADC_enable(ADC_BASE);
     // Timer trigger needed to start every ADC conversion
     ADC_setupSamplingTimer(ADC_BASE, ADC_CYCLEHOLD_16_CYCLES, ADC_MULTIPLESAMPLESDISABLE);
     ADC_configureMemory(ADC_BASE, ADC_INPUT_A8, ADC_VREFPOS_INT, ADC_VREFNEG_AVSS);
     // Bit mask of the interrupt flags to be cleared- for new conversion data in the memory buffer
     ADC_clearInterrupt(ADC_BASE, ADC_COMPLETED_INTERRUPT);
     // Enable source to reflected to the processor interrupt
     ADC_enableInterrupt(ADC_BASE, ADC_COMPLETED_INTERRUPT);

     // Wait for PPM Ready
     while (PMM_REFGEN_NOTREADY == PMM_getVariableReferenceVoltageStatus());

     // Enable internal reference voltage
     PMM_enableInternalReference();

     __bis_SR_register(GIE);
}

uint16_t adc_read(void) {
    ADC_startConversion(ADC_BASE, ADC_SINGLECHANNEL);
    return adc_reading;
}

#pragma vector=ADC_VECTOR
__interrupt void ADC_ISR (void) {
    switch (__even_in_range(ADCIV,12)){     // interrupt vector register never has a value that is odd or larger than 12 (stated)
        case  0: break; //No interrupt
        case  2: break; //conversion result overflow
        case  4: break; //conversion time overflow
        case  6: break; //ADCHI
        case  8: break; //ADCLO
        case 10: break; //ADCIN
        case 12:        //ADCIFG0 is ADC interrupt flag
            adc_reading = ADC_getResults(ADC_BASE);
            break;
        default: break;
    }
}

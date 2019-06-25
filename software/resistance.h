#ifndef RESISTANCE_H_
#define RESISTANCE_H_

// From V = IR (Ohm's Law) we can derive the equation for unknown resistance
// due to this setup being a simple voltage divider
// R = (VR')/(3.3 - V) where R' is the reference resistor and R is the unknown
#define RESISTANCE_CALCULATE(voltage, ref) \
    (((((uint32_t)(voltage)) * ((uint32_t)(ref))))/(3300 - ((uint32_t)(voltage))))

#endif /* RESISTANCE_H_ */

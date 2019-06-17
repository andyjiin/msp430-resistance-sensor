#ifndef MUX_H_
#define MUX_H_

typedef enum {
    MUX_REF_RESISTOR_100_OHM = 0,
    MUX_REF_RESISTOR_1_KOHM,
    MUX_REF_RESISTOR_1_MOHM,
    NUM_MUX_REF_RESISTORS,
} mux_ref_resistor;

void mux_init(void);

void mux_select(mux_ref_resistor resistor);

#endif /* MUX_H_ */

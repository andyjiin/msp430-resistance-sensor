/*
 * @file: mux.h
 *
 * @brief: This module is written to control the 74HC4051 8-channel analog multiplexer. The datasheet
 * can be found here: https://cdn.sparkfun.com/assets/learn_tutorials/5/5/3/74HC_HCT4051.pdf
 *
 * @author: a4jin@uwaterloo.ca
 */
#ifndef MUX_H_
#define MUX_H_

#include <stdint.h>

#define MUX_REF_RESISTOR_33_OHM_UPPER_BOUND 20
#define MUX_REF_RESISTOR_100_OHM_UPPER_BOUND 60
#define MUX_REF_RESISTOR_470_OHM_UPPER_BOUND 300
#define MUX_REF_RESISTOR_1_KOHM_UPPER_BOUND 600
#define MUX_REF_RESISTOR_10_KOHM_UPPER_BOUND 6000
#define MUX_REF_RESISTOR_100_KOHM_UPPER_BOUND 60000
#define MUX_REF_RESISTOR_560_KOHM_UPPER_BOUND 300000
#define MUX_REF_RESISTOR_1120_KOHM_UPPER_BOUND 1120000

// Reference resistors available
typedef enum {
    MUX_REF_RESISTOR_33_OHM = 0,
    MUX_REF_RESISTOR_100_OHM,
    MUX_REF_RESISTOR_470_OHM,
    MUX_REF_RESISTOR_1_KOHM,
    MUX_REF_RESISTOR_10_KOHM,
    MUX_REF_RESISTOR_100_KOHM,
    MUX_REF_RESISTOR_560_KOHM,
    MUX_REF_RESISTOR_1120_KOHM,
    NUM_MUX_REF_RESISTORS,
} mux_ref_resistor;

/*
 * @brief: Initializes the multiplexer module for selecting reference resistors
 */
void mux_init(void);

/*
 * @brief: Converts reference resistance to value in Ohms
 *
 * @param resistor: The reference resistor to convert
 *
 * @return: The value of the reference resistance in Ohms
 */
uint32_t mux_convert_resistance(mux_ref_resistor resistor);

/*
 * @brief: Selects the appropriate reference resistor on the mux
 *
 * @param resistor: The reference resistor to select
 */
void mux_select(mux_ref_resistor resistor);

#endif /* MUX_H_ */

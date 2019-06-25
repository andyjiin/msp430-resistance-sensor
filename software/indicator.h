/*
 * @file: indicator.h
 *
 * @brief: This module is written to handle the displaying of errors to the user. It
 * uses external LEDs mapped to indicator pins defined in Board.h
 *
 * @author: a4jin@uwaterloo.ca
 */

#ifndef INDICATOR_H_
#define INDICATOR_H_

#include <stdbool.h>

/*
 * @brief: Initializes the indicator module for displaying errors to the user
 */
void indicator_init(void);

/*
 * @brief: Sets the indicator LED accordingly
 *
 * @param on: True to turn the indicator LED on and False to turn it off
 */
void indicator_set(bool on);

#endif /* INDICATOR_H_ */

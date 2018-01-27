
#ifndef ERRORS_H
#define ERRORS_H


#define NO_ERROR 0

/* Program errors, unexpected events, 1 to 999 */


/* Sensors and motors errors, 1000 to 1999 */

// Motors errors, 1100 to 1199
#define ERR_PWM 1110
#define ERR_PWM_OVERVALUE 1111
#define ERR_DIRECTION 1120
#define ERR_DIRECTION_VALUE 1121

/* Communication errors, 2000 to 2999 */

// PS2 errors, 2100 to 2199
#define ERR_PS2 2100
#define ERR_PS2_RECEPT 2110
#define ERR_PS2_RECEPT_INIT 2111
#define ERR_PS2_RECEPT_END 2112
#define ERR_PS2_RECEPT_TIMEOUT 2113
#define ERR_PS2_SEND 2120
#define ERR_PS2_SEND_INIT 2121
#define ERR_PS2_SEND_END 2122
#define ERR_PS2_SEND_TIMEOUT 2123
#define ERR_PS2_SEND_REQUEST 2124


#endif

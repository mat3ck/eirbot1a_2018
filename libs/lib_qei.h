//
// Created by copperbot on 08/01/18.
//

/**
 * NOTES CONCERNANT LES CODEURS utilisés :
 *  - Vert  => Voie A       => PD12 (gauche) et PA0 (droite)
 *  - Jaune => Voie B       => PD13 (gauche) et PB3 (droite)
 *  - Blanc => Masse (0V)
 *  - Brun  => Vcc 5V (pas en dessous !)
 */


#ifndef TEST_NUCLEO_MARKI_LINUX_LIB_QEI_H
#define TEST_NUCLEO_MARKI_LINUX_LIB_QEI_H

#endif //TEST_NUCLEO_MARKI_LINUX_LIB_QEI_H

#define CODEUR_LEFT 1
#define CODEUR_RIGHT 2

void init_qei_left();
void init_qei_right();
void start_codeurs();
int get_codeur(int code);
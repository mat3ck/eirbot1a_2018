//
// Created by copperbot on 08/01/18.
//

#include "lib_qei.h"
#include "mbed.h"
#include "common.h"

// Déclarations des objets TIMER utilisés par la librairie
TIM_HandleTypeDef htim4;
TIM_HandleTypeDef htim2;

/**
 * Fonction qui configure et démarre les deux QEIs
 */
void start_codeurs(){

    init_qei_left();
    init_qei_right();
}

/**
 * Fonction d'initialisation de l'interface encodeur gauche (commenté)
 */
void init_qei_left(){


    __HAL_RCC_TIM4_CLK_ENABLE(); //Nécessaire de le démarrer avant toutes modification du timer (à étudier)

    //Déclaration des objets de configuration
    TIM_Encoder_InitTypeDef sConfig;
    TIM_MasterConfigTypeDef sMasterConfig;


    htim4.Instance = TIM4; //Choix du timer, 3 ou 4 dans notre cas.
    htim4.Init.Prescaler = 0;//A laisser tel quel
    htim4.Init.CounterMode = TIM_COUNTERMODE_UP; //On compte normalement, pas en inversé
    htim4.Init.Period = 0xFFFF; //Modification de ARR, valeur max de comptage de la variable 16bits
    htim4.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1; //A laisser tel quel

    sConfig.EncoderMode = TIM_ENCODERMODE_TI12; //SMS =011 : on utiliser les deux sorties de l'encodeur incrémental

    //DATASHEET
    sConfig.IC1Polarity = TIM_ICPOLARITY_RISING;
    sConfig.IC1Selection = TIM_ICSELECTION_DIRECTTI;
    sConfig.IC1Prescaler = TIM_ICPSC_DIV1;
    sConfig.IC1Filter = 5; //Valeur du filtre, de 0 à 16.

    sConfig.IC2Polarity = TIM_ICPOLARITY_RISING;
    sConfig.IC2Selection = TIM_ICSELECTION_DIRECTTI;
    sConfig.IC2Prescaler = TIM_ICPSC_DIV1;
    sConfig.IC2Filter = 5;

    //Tentative d'initialisation de la config
    if (HAL_TIM_Encoder_Init(&htim4, &sConfig) != HAL_OK) {
        Error_Handler(1);
    }

    //DATASHEET
    sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
    sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
    if (HAL_TIMEx_MasterConfigSynchronization(&htim4, &sMasterConfig) != HAL_OK) {
        Error_Handler(1);
    }

    //Nouvelle structure GPIO, propre aux pins utilisés par l'encodeur
    GPIO_InitTypeDef GPIO_InitStruct;
    if(htim4.Instance==TIM4) {

        __HAL_RCC_GPIOD_CLK_ENABLE();//On active le périphérique (Visiblement nécessaire, sinon marche po :'( )

        /**TIM4 GPIO Configuration
        PD12     ------> TIM4_CH1 ---> Encodeur Voie A
        PD13     ------> TIM4_CH2 ---> Encodeur Voie B
        */

        GPIO_InitStruct.Pin = GPIO_PIN_12|GPIO_PIN_13;
        GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
        GPIO_InitStruct.Pull = GPIO_PULLUP; // à revoir, PULLUP préféré dans le cas d'une éventuelle déco des pins.
        GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH; //à revoir
        GPIO_InitStruct.Alternate = GPIO_AF2_TIM4;

        HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

    } else
        Error_Handler(1);


    //Démarrage du timer
    HAL_TIM_Encoder_Start(&htim4,TIM_CHANNEL_ALL);

    //intialisation éventuelle du compteur
    TIM4->CNT=0;

}

/**
 * Fonction d'initialisation de l'interface encodeur droit
 */
void init_qei_right(){

    __HAL_RCC_TIM2_CLK_ENABLE(); //Nécessaire de le démarrer avant toutes modification du timer (à étudier)

    //Déclaration des objets de configuration
    TIM_Encoder_InitTypeDef sConfig;
    TIM_MasterConfigTypeDef sMasterConfig;


    htim2.Instance = TIM2;
    htim2.Init.Prescaler = 0;
    htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
    htim2.Init.Period = 0xFFFF;
    htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;

    sConfig.EncoderMode = TIM_ENCODERMODE_TI12;

    sConfig.IC1Polarity = TIM_ICPOLARITY_RISING;
    sConfig.IC1Selection = TIM_ICSELECTION_DIRECTTI;
    sConfig.IC1Prescaler = TIM_ICPSC_DIV1;
    sConfig.IC1Filter = 5;

    sConfig.IC2Polarity = TIM_ICPOLARITY_RISING;
    sConfig.IC2Selection = TIM_ICSELECTION_DIRECTTI;
    sConfig.IC2Prescaler = TIM_ICPSC_DIV1;
    sConfig.IC2Filter = 5;

    if (HAL_TIM_Encoder_Init(&htim2, &sConfig) != HAL_OK) {
        Error_Handler(1);
    }

    sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
    sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
    if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK) {
        Error_Handler(1);
    }


    GPIO_InitTypeDef GPIO_InitStruct;
    if(htim2.Instance==TIM2)
    {

        __HAL_RCC_GPIOA_CLK_ENABLE();
        __HAL_RCC_GPIOB_CLK_ENABLE();

        /**TIM2 GPIO Configuration
        PA0/WKUP     ------> TIM2_CH1 ---> Encodeur Voie A
        PB3          ------> TIM2_CH2 ---> Encodeur Voie B
        */
        GPIO_InitStruct.Pin = GPIO_PIN_0;
        GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
        GPIO_InitStruct.Pull = GPIO_PULLUP;
        GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
        GPIO_InitStruct.Alternate = GPIO_AF1_TIM2;
        HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

        GPIO_InitStruct.Pin = GPIO_PIN_3;
        GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
        GPIO_InitStruct.Pull = GPIO_PULLUP;
        GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
        GPIO_InitStruct.Alternate = GPIO_AF1_TIM2;
        HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

    } else
        Error_Handler(1);


    //Démarrage du timer
    HAL_TIM_Encoder_Start(&htim2,TIM_CHANNEL_ALL);

    //intialisation éventuelle du compteur
    TIM2->CNT=0;

}

/**
 * Fonction simple qui retourne la valeur actuelle du QEI
 * @param code : CODEUR_LEFT ou CODEUR_RIGHT
 * @return la valeur du QEI comprise entre 0 et ARR (voir "htimX.Init.Period" dans les initialisations)
 */
int get_codeur(int code){

    if (code==CODEUR_LEFT)
        return (int)TIM4->CNT;

    else if (code==CODEUR_RIGHT)
        return (int)TIM2->CNT;

    else
        return 0;
}


void toursQeiRefresh(){

    static int anciennevaleurQEI_G=0; //Static => est reservé pour la fonction, n'est pas réinit à 0
    static int anciennevaleurQEI_D=0; //Static => est reservé pour la fonction
    int nouvellevaleurQEI_G=get_codeur(CODEUR_LEFT);
    int nouvellevaleurQEI_D=get_codeur(CODEUR_RIGHT);

    int dq_G=nouvellevaleurQEI_G-anciennevaleurQEI_G;
    int dq_D=nouvellevaleurQEI_D-anciennevaleurQEI_D;

    if(dq_G>32000){
        dq_G=dq_G-65536;//depassement negatif
    }
    else if(dq_G<-32000){
        dq_G=dq_G+65536;
    }

    if(dq_D>32000){
        dq_D=dq_D-65536;//depassement negatif
    }
    else if(dq_D<-32000){
        dq_D=dq_D+65536;
    }

    QEI_G=QEI_G+dq_G;
    QEI_D=QEI_D+dq_D;

    anciennevaleurQEI_G=nouvellevaleurQEI_G;
    anciennevaleurQEI_D=nouvellevaleurQEI_D;
}

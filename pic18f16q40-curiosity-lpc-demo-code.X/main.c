 /*
 * MAIN Generated Driver File
 * 
 * @file main.c
 * 
 * @defgroup main MAIN
 * 
 * @brief This is the generated driver implementation file for the MAIN driver.
 *
 * @version MAIN Driver Version 1.0.0
*/

/*
� [2023] Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip 
    software and any derivatives exclusively with Microchip products. 
    You are responsible for complying with 3rd party license terms  
    applicable to your use of 3rd party software (including open source  
    software) that may accompany Microchip software. SOFTWARE IS ?AS IS.? 
    NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS 
    SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,  
    MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT 
    WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY 
    KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF 
    MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE 
    FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP?S 
    TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT 
    EXCEED AMOUNT OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR 
    THIS SOFTWARE.
*/
#include "mcc_generated_files/system/system.h"
#include "./labs.h"
#include "labs.h"

void checkButtonS1(void);
void nextLab(void);
/*
                         Main application
 */
int main(void)
{
    // Initialize the device
    SYSTEM_Initialize();
    
    //Disable the PWM Output (for other labs)
    PWM_Output_D7_Disable();
    
    // Disable the pre-enabled interrupts of MCC    
    INTERRUPT_TMR0InterruptDisable();
    
    while (1) {
        checkButtonS1();
        switch (labNumber) {
            case 1: HelloWorld();
                break;
            case 2: Blink();
                break;
            case 3: Rotate();
                break;
            case 4: ADC();
                break;
            case 5: VSR();
                break;
            case 6: PWM();
                break;
            case 7: Timer1_Lab();
                break;
            case 8: Interrupt();
                break;
            case 9: SleepWakeUp();
                break;
            case 10: EEPROM();
                break;
        }

        if (switchEvent) {
            nextLab();
        }
    }
    return 0;
}

void checkButtonS1(void) {
    if (btnState == NOT_PRESSED) {
        if (SWITCH_S1_PORT == LOW) {
            __delay_ms(100);
            btnState = PRESSED;
        }
    } else if (SWITCH_S1_PORT == HIGH) {
        btnState = NOT_PRESSED;
        switchEvent = 1;
    }
}

void nextLab(void) {
    switchEvent = 0;
    labNumber++;

    if (labNumber > 10) {
        labNumber = 1;
    }
}
/**
 End of File
 */
/*
 * File:   newmain.c
 * Author: triet
 *
 * Created on May 5, 2020, 9:49 AM
 */

// PIC16F1509 Configuration Bit Settings

// 'C' source line config statements

// CONFIG1
#pragma config FOSC = INTOSC    // Oscillator Selection Bits (INTOSC oscillator: I/O function on CLKIN pin)
#pragma config WDTE = OFF       // Watchdog Timer Enable (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable (PWRT disabled)
#pragma config MCLRE = ON       // MCLR Pin Function Select (MCLR/VPP pin function is MCLR)
#pragma config CP = OFF         // Flash Program Memory Code Protection (Program memory code protection is disabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable (Brown-out Reset disabled)
#pragma config CLKOUTEN = OFF   // Clock Out Enable (CLKOUT function is disabled. I/O or oscillator function on the CLKOUT pin)
#pragma config IESO = OFF       // Internal/External Switchover Mode (Internal/External Switchover Mode is disabled)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enable (Fail-Safe Clock Monitor is disabled)

// CONFIG2
#pragma config WRT = OFF        // Flash Memory Self-Write Protection (Write protection off)
#pragma config STVREN = OFF     // Stack Overflow/Underflow Reset Enable (Stack Overflow or Underflow will not cause a Reset)
#pragma config BORV = LO        // Brown-out Reset Voltage Selection (Brown-out Reset Voltage (Vbor), low trip point selected.)
#pragma config LPBOR = OFF      // Low-Power Brown Out Reset (Low-Power BOR is disabled)
#pragma config LVP = ON         // Low-Voltage Programming Enable (Low-voltage programming enabled)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.
#define _XTAL_FREQ 1000000   // 1Mhz
#include <xc.h>

// S1_LED  -- RC4
// S2_LED  -- RC5
// S3_LED  -- RC6
// S4_LED  -- RC7
#define S1_LED  LATCbits.LATC4  
#define S2_LED  LATCbits.LATC5  
#define S3_LED  LATCbits.LATC6  
#define S4_LED  LATCbits.LATC7  

void main(void) { // main code

    // output = LAT
    TRISCbits.TRISC4 = 0; // 0 -> output ([0]-0V, [1]-5V)
    TRISCbits.TRISC5 = 0; // 0 -> output ([0]-0V, [1]-5V)
    TRISCbits.TRISC6 = 0; // 0 -> output ([0]-0V, [1]-5V)
    TRISCbits.TRISC7 = 0; // 0 -> output ([0]-0V, [1]-5V)
    
    ANSELBbits.ANSB4 = 0; // Digital I/O
    ANSELBbits.ANSB5 = 0; // Digital I/O
    
    // input = PORT
    TRISBbits.TRISB7 = 1; // 1 -> input S4 ([0]-0V, [1]-5V) 
    TRISBbits.TRISB6 = 1; // 1 -> input S3 ([0]-0V, [1]-5V) 
    TRISBbits.TRISB5 = 1; // 1 -> input S2 ([0]-0V, [1]-5V) 
    TRISBbits.TRISB4 = 1; // 1 -> input S1 ([0]-0V, [1]-5V) 
    

    S1_LED = 0; // [1]-> 5V; [0]-> 0V
    S2_LED = 0; // [1]-> 5V; [0]-> 0V
    S3_LED = 0; // [1]-> 5V; [0]-> 0V
    S4_LED = 0; // [1]-> 5V; [0]-> 0V
    
    while (1) { // infinity loop here
        if (PORTBbits.RB4 == 1) S1_LED = 0; // sang LED
        else S1_LED = 1; // sang LED
        
        if (PORTBbits.RB5 == 1) S2_LED = 0; // sang LED
        else S2_LED = 1; // sang LED
        
        if (PORTBbits.RB6 == 1) S3_LED = 0; // sang LED
        else S3_LED = 1; // sang LED
        
        if (PORTBbits.RB7 == 1) S4_LED = 0; // sang LED
        else S4_LED = 1; // sang LED
        
    }
    return;
}

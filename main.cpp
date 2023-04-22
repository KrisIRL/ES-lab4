#include "mbed.h"

// Initialize analog inputs and PWM outputs
AnalogIn pot1(p19);
AnalogIn pot2(p20);
PwmOut red(p23);
PwmOut green(p24);

// Initialize serial interface
Serial pc(USBTX, USBRX);

int main() {
    // Main program loop
    while(1) {
        // Read analog values of the pots and invert them
        float red_val = 1.0 - pot1.read();
        float green_val = 1.0 - pot2.read();
        
        // Set PWM output for red and green LEDs
        red.write(red_val);
        green.write(green_val);
        
        // Print potentiometer values to serial monitor
        pc.printf("Potentiometer values - Red: %f, Green: %f\r\n", pot1.read(), pot2.read());
        
        // Wait for 50ms before repeating the loop
        wait(0.05);
    }
}

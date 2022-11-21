#include "mbed.h"
#include <stdio.h>

DigitalOut myled(LED_RED); // fonctionne aussi avec PTB18 ou LED1

int main() {
    int i=0;
    while(1) {
        myled = 0;
        wait(1);
        myled = 1;
        wait(0.2);
        printf("cpt=%d\n",i++);
    }
}
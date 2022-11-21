#include "mbed.h"
#include "TSISensor.h"

TSISensor tsi;
DigitalOut vert(LED_GREEN);
DigitalOut rouge(LED_RED);

int main(void) {
  float valueTSI;
  vert = 1;
  rouge = 1;
  float SEUIL = 0.01;
  float SEUIL2 =  0.5;
  printf("DEBUT\n");
  while (true) {
    do {
      valueTSI = tsi.readPercentage();
      printf("%lf", valueTSI);
    } while (valueTSI < SEUIL); // on attend l'appui
    
    do {
      valueTSI = tsi.readPercentage();
      printf("%lf", valueTSI);
    } while (valueTSI > SEUIL); // wait relachement
    
    if (SEUIL2 > tsi.readPercentage())
    {
        rouge = 0;
    }
    else
    {
        vert = 0;
    }

    do {
      valueTSI = tsi.readPercentage();
      printf("%lf", valueTSI);
    } while (valueTSI < SEUIL); // on attend l'appui
    
    do {
      valueTSI = tsi.readPercentage();
      printf("%lf", valueTSI);
    } while (valueTSI > SEUIL); // wait relachement
    rouge = 1; // on eteind
    vert = 1;
    wait(0.1);
  }
}

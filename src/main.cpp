#include <Arduino.h>

#if defined(GD32F30x) || defined(GD32E50X)
  #define LED PB2
#elif defined(GD32F3x0) || defined(GD32F1x0)
    #define LED PC13  
#endif


#define BUTTON_PIN PB11

volatile unsigned flag=0;

void button_isr() {
if(flag)
  flag=0;
else 
  flag=1;
}

void setup()
{
  attachInterrupt(BUTTON_PIN, &button_isr, FALLING);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(LED, OUTPUT);


}

void loop()
{

 delay(50);
 digitalWrite(LED,flag);

}

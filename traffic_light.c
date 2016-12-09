#include <stdio.h>    // Used for printf() statements
#include <wiringPi.h> // Include WiringPi library!

// Pin number declarations. We're using the Broadcom chip pin numbers.
const int ledPin2 = 18; // PWM LED - Broadcom pin 18, P1 pin 12
const int ledPin = 23; // Regular LED - Broadcom pin 23, P1 pin 16
const int led2Pin = 24;
const int led2Pin2 = 25;
const int butPin = 17; // Active-low button - Broadcom pin 17, P1 pin 11

const int pwmValue = 75; // Use this to set an LED brightness

int laikas = 1;
int trysS;

int main(void)
{
    wiringPiSetupGpio(); 

	
    pinMode(ledPin2, OUTPUT); 
    pinMode(ledPin, OUTPUT);
    pinMode(led2Pin2, OUTPUT); 
    pinMode(led2Pin, OUTPUT);
         
    pinMode(butPin, INPUT);      
    pullUpDnControl(butPin, PUD_UP); 

    printf("Blinker is running! Press CTRL+C to quit.\n");

    while(1)
    {
		digitalWrite(ledPin2, LOW); // Raudona masinu sviesoforas
        digitalWrite(led2Pin2, HIGH); // Zalia zmoniu sviesoforas
        delay(5000);    
        digitalWrite(ledPin2, HIGH); // Geltona masinu sviesoforas
        digitalWrite(led2Pin2, LOW); // zmoniu sviesoforas
        digitalWrite(led2Pin, HIGH); // Raudona zmoniu sviesoforas
        delay(1000); 
        digitalWrite(ledPin, LOW);  // Zalia masinu sviesoforas
        trysS = 3000;
        laikas = 0;
        while(laikas < 5000) {
			if(digitalRead(butPin)){
				laikas = laikas + 1;
				delay(1);
				
			}
			else{
				laikas = laikas + trysS;
				trysS = 0;
				laikas = laikas + 1;
				delay(1);
				
			}
			
		}
        
        digitalWrite(ledPin, HIGH); // Geltona masinu sviesoforas
        delay(1000); 
        digitalWrite(led2Pin, LOW); // zmoniu sviesoforas
        
/*	
			digitalWrite(ledPin, LOW);
			digitalWrite(ledPin2, LOW);
			digitalWrite(led2Pin, LOW);
			digitalWrite(led2Pin2, LOW);
			delay(5000);
         */ 
            
        
    }

    return 0;
}

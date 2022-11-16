#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>

/* PWM Raspberry Pi 4 model B */

// motor 1
int enA = 26; //BCM 12 || Physical 32
int inA1 = 4; //BCM 23 || Physical 16
int inA2 = 5; //BCM 24 || Physical 18

//motor 2
int enB = 23; //BCM 13 || Pysical 33
int inB1 = 0; //BCM 17 || Pysical 11
int inB2 = 2; //BCM 27 || Pysical 13

void config(void);

int main() {

config();
  printf ("Start:\n");
    
    while (1)
    {
      //Direction ONE M1
      digitalWrite(inA1, HIGH);
      digitalWrite(inA2, LOW);

      //Direction ONE M2
      digitalWrite(inB1, HIGH);
      digitalWrite(inB2, LOW);


      for (size_t i = 200; i < 1023; i++)
      {
        pwmWrite(enA, i);
        pwmWrite(enB, i);
        delay(5);
      }

        //Change direction M1
        digitalWrite(inA1, LOW);
        digitalWrite(inA2, HIGH);

        //Change direction M2
        digitalWrite(inB1, LOW);
        digitalWrite(inB2, HIGH);

      for (size_t i = 1023; i > 200; i--)
      {
        pwmWrite(enA, i);
        pwmWrite(enB, i);
        delay(5);
      }
    }
}


void config(void)
{
    wiringPiSetup();	/* initialize wiringPi setup */

    //Motor 1
    pinMode(enA,PWM_OUTPUT);	/*set GPIO as output */
    pinMode(inA1,OUTPUT);
    pinMode(inA2,OUTPUT);

    //Motor 2
    pinMode(enB,PWM_OUTPUT);	/*set GPIO as output */
    pinMode(inB1,OUTPUT);
    pinMode(inB2,OUTPUT);
}


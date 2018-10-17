#include <boarddefs.h>
#include <IRremote.h>
#include <IRremoteInt.h>
#include <ir_Lego_PF_BitStreamEncoder.h>

//FFE21D = 3
//FF629D = 2
//FF22DD = 4
//FF38C7 = OK

#include <Stepper.h> 

int RECV_PIN = 13;  
float armazenavalor;

int btn1 = 7;
int btn2 = 6;
int leitura1 = 0;
int leitura2 = 0;
const int stepsPerRevolution = 500; 
  
//Inicializa a biblioteca utilizando as portas de 8 a 11 para 
//ligacao ao motor 
Stepper myStepper(stepsPerRevolution, 8,10,9,11); 

IRrecv irrecv(RECV_PIN);  
decode_results results; 
  
void setup() 
{ 
  pinMode(btn1, INPUT);
  pinMode(btn2, INPUT);
 //Determina a velocidade inicial do motor 
 myStepper.setSpeed(60);

 Serial.begin(9600);  
irrecv.enableIRIn(); // Inicializa o receptor IR
} 
  
void loop() 
{
 if (irrecv.decode(&results))  
  {  
  
   armazenavalor = (results.value);
 //Gira o motor no sentido horario a 90 graus
 // leitura1 = digitalRead(btn2);
// if ( armazenavalor )
 // if (leitura1 != 0){


 //Gira o motor no sentido horario a 90 graus 2° Andar
 if (armazenavalor == 0xff629d){
     for (int i = 0; i<=26; i++)
     {
     myStepper.step(-512);     
     }
  }

   //Gira o motor no sentido horario a 90 graus 3° Andar
 if (armazenavalor == 0xffe21d){
     for (int i = 0; i<=50; i++)
     {
     myStepper.step(-512);     
     }
  }
  
     //Gira o motor no sentido horario a 90 graus 4° Andar
 if (armazenavalor == 0xff22dd){
     for (int i = 0; i<=70; i++)
     {
     myStepper.step(-512);     
     }
  }

  
  //Gira o motor no sentido anti-horario a 120 graus -1° Andar
  if ( armazenavalor == 0xffa25d ){    
     for (int i = 0; i<=26; i++) //i=i++)
     {
     myStepper.step(512);    
     }    
  }

 /* if ( armazenavalor == 0xff38c7 ){
   for (int i = 0; i<=1; i++)
     {
     myStepper.step(-2); 
     //delay(5000);
    
     }
  }
// delay(5000);

 //Gira o motor no sentido anti-horario a 120 graus
/* leitura2 = digitalRead(btn1);
  if (leitura2 != 0){*/
  

/*
 //Gira o motor no sentido horario, aumentando a
 //velocidade gradativamente
 for (int i = 10; i<=60; i=i+10)
 {
 myStepper.setSpeed(i);
 myStepper.step(40*i);
 }
//delay(2000);*/
irrecv.resume();
}
}

////////// IR REMOTE CODES //////////
#define F 16736925  // FORWARD
#define B 16754775  // BACK
#define L 16720605  // LEFT
#define R 16761405  // RIGHT
//#define S 16712445  // STOP
#define UNKNOWN_F 5316027     // FORWARD
#define UNKNOWN_B 2747854299  // BACK
#define UNKNOWN_L 1386468383  // LEFT
#define UNKNOWN_R 553536955   // RIGHT
#define UNKNOWN_S 3622325019  // STOP



#define decButton 16728765//button on the left * symbol
#define incButton 16732845//button on the right, # symbol
#define okButton 16712445 //Switches to which digit is displayed



/////////////7 SEG/////////////////

int digi = 1;
int counter = 0;
int latch = A0; //latch
int cs = A1; //clock
int data = A2; //sends information
int dPins[4] = {13, 12, A5, A4};// on 4 digit - 4321
const byte digits[10] = { // pin combinations do display a number
  B00111111,//0
  B00000110,//1
  B01011011,//2
  B01001111,//3
  B01100110,//4
  B01101101,//5
  B01111101,//6
  B0000111,//7
  B01111111,//8
  B01101111,//9
};
//////////MOTOR PINS//////////////

#define Aa 7
#define Ab 5
#define Ba 8
#define Bb 6

/////////////IR//////////////////

#include <IRremote.h>

int RECV_PIN = 9;

IRrecv irrecv(RECV_PIN);
decode_results results;

/////////////MILIIS FUNCTION/////////////////
unsigned long val;
unsigned long preMillis;
//////////////////////////////////////////////




void setup() {

 
  pinMode(3, 1);
  digitalWrite(3, OUTPUT);

  for (int i = 0; i < 14; i++) {
    pinMode (i, OUTPUT);

    move( 1, 0, 1, 0);//stop, mkaes sure the cars stationary
    irrecv.enableIRIn(); //starts receiver

     pinMode(A0,OUTPUT);
    pinMode(A1,OUTPUT);
    pinMode(A2,OUTPUT);
    pinMode(A4,OUTPUT);
    pinMode(A5,OUTPUT);
Serial.begin(9600);
  }
}

void loop() {
  if (irrecv.decode(&results)) {
    preMillis = millis();
    val = results.value;
    irrecv.resume();
   
    switch (val) {
      case F:
      case UNKNOWN_F: move( 1, 100, 1, 100); break; //forward
      case B:
      case UNKNOWN_B: move( 0, 100, 0, 100); break; //backward
      case L:
      case UNKNOWN_L: move( 1, 100, 0, 100); break; // left
      case R:
      case UNKNOWN_R: move( 0, 100, 1, 100); break; //right
//      case S:
//      case UNKNOWN_S: move( 1, 0, 1, 0); break; //stop

/*
      case okButton:
       digi = (digi == 1) ? 4 : 1;

      case incButton: counter++; show(counter, digi);break; 

      case decButton: counter--; show(counter, digi); break;
      
   
      

      break;
*/
      default: break;

     

    }





  }
  else {
    if (millis() - preMillis > 500) {
      move( 1, 0, 1, 0);//stop
      preMillis = millis();
    }
  }

show1(2);

show2(7);

show3(4);

show4(9);
}


void move ( bool a, int b, bool c, int d) {

  digitalWrite(Aa, a);
  digitalWrite(Ba, c);

  analogWrite(Ab, b);
  analogWrite(Bb, d);
}

/*void show(int x, int y) {

  switch(y){
    case 1:
  digitalWrite(13, HIGH);
  digitalWrite(12, HIGH);
  digitalWrite(A5, HIGH);
  digitalWrite(A4, LOW);
  break;

   case 4:
  digitalWrite(13, LOW);
  digitalWrite(12, HIGH);
  digitalWrite(A5, HIGH);
  digitalWrite(A4, HIGH);
  break;

  default: break;

  }  

  digitalWrite(latch, LOW);
  shiftOut(data, cs, MSBFIRST, digits[x]);
  digitalWrite(latch, HIGH);
}
*/




void show1(int x) {

  
  digitalWrite(13, HIGH);
  digitalWrite(12, HIGH);
  digitalWrite(A5, HIGH);
  digitalWrite(A4, LOW);
  
  digitalWrite(latch, LOW);
  shiftOut(data, cs, MSBFIRST, digits[x]);
  digitalWrite(latch, HIGH);
}

void show2(int x) {

  
  digitalWrite(13, HIGH);
  digitalWrite(12, HIGH);
  digitalWrite(A5, LOW);
  digitalWrite(A4, HIGH);
  
  digitalWrite(latch, LOW);
  shiftOut(data, cs, MSBFIRST, digits[x]);
  digitalWrite(latch, HIGH);
}

void show3(int x) {

  
  digitalWrite(13, HIGH);
  digitalWrite(12, LOW);
  digitalWrite(A5, HIGH);
  digitalWrite(A4, HIGH);
  
  digitalWrite(latch, LOW);
  shiftOut(data, cs, MSBFIRST, digits[x]);
  digitalWrite(latch, HIGH);
}

void show4(int x) {

  
  digitalWrite(13, LOW);
  digitalWrite(12, HIGH);
  digitalWrite(A5, HIGH);
  digitalWrite(A4, HIGH);
  
  digitalWrite(latch, LOW);
  shiftOut(data, cs, MSBFIRST, digits[x]);
  digitalWrite(latch, HIGH);
}

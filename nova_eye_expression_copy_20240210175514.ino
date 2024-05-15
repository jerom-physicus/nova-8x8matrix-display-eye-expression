#include "LedControl.h"
int DIN = 8;
int CS =  7;
int CLK = 6;
LedControl lc=LedControl(DIN,CLK,CS,0);

const int addrL = 0;  // first LED matrix - Left robot eye
const int addrR = 1;  // second LED matrix - Right robot eye

void setup() {
  Serial.begin(9600);
  /*The MAX72XX is in power-saving mode on startup*/
  lc.shutdown(addrL,false);
  lc.shutdown(addrR,false);
  /* Set the brightness to max values */
  lc.setIntensity(addrL,10);
  lc.setIntensity(addrR,10);
  /* and clear the display */
  lc.clearDisplay(addrL);
  lc.clearDisplay(addrR);

  // turn on all LEDs for a test
//   for(int row=0;row<8;row++) {
//     lc.setRow(addrL, row, 255);
//     lc.setRow(addrR, row, 255);
//     delay(100);
//   }
//   delay(300);
}


void showNeutral() {
  byte left[8] = {
0b00111100,
  0b01111110,
  0b01111110,
  0b01100110,
  0b01100110,
  0b01111110,
  0b01111110,
  0b00111100};

  displayEmotion(left, left);
}
void showblink() {
  byte left[8]= {0b00111100,
  0b01111110,
  0b01111110,
  0b01100110,
  0b01100110,
  0b01111110,
  0b01111110,
  0b00111100};displayEmotion(left, left);}
void F_showblink_1() {  
  byte left[8]= {0b00000000,
  0b01111110,
  0b01111110,
  0b01100110,
  0b01100110,
  0b01111110,
  0b01111110,
  0b00111100};displayEmotion(left, left);}
void F_showblink_2() {   
  byte left[8] ={ 0b00000000,
  0b01111110,
  0b01111110,
  0b01100110,
  0b01100110,
  0b01111110,
  0b01111110,
  0b00111100};displayEmotion(left, left);}
void F_showblink_3() {   
  byte left[8] ={0b00000000,
  0b00000000,
  0b00000000,
  0b01100110,
  0b01100110,
  0b01111110,
  0b01111110,
  0b00111100};displayEmotion(left, left);}
void F_showblink_4() {   
  byte left[8] ={0b00000000,
  0b00000000,
  0b00000000,
  0b00000000,
  0b01100110,
  0b01111110,
  0b01111110,
  0b00111100};displayEmotion(left, left);}  
void F_showblink_5() {   
  byte left[8] ={0b00000000,
  0b00000000,
  0b00000000,
  0b00000000,
  0b00000000,
  0b01111110,
  0b01111110,
  0b00111100};displayEmotion(left, left);}  
void F_showblink_6() {   
  byte left[8] ={0b00000000,
  0b00000000,
  0b00000000,
  0b00000000,
  0b00000000,
  0b00000000,
  0b01111110,
  0b00111100};displayEmotion(left, left);}  
void F_showblink_7() {   
  byte left[8] ={0b00000000,
  0b00000000,
  0b00000000,
  0b00000000,
  0b00000000,
  0b00000000,
  0b00000000,
  0b00111100};displayEmotion(left, left);}  


void displayEmotion(byte left[8], byte right[8]) {
  //lc.clearDisplay(addrL);
  //lc.clearDisplay(addrR);
  for(int row=0;row<8;row++) {
    lc.setRow(addrL,row,left[row]);
    lc.setRow(addrR,row,right[row]);
  }
}

void right_eye() {   
  byte left[8] ={0b00111100,
  0b01111110,
  0b01111110,
  0b01001110,
  0b01001110,
  0b01111110,
  0b01111110,
  0b00111100};displayEmotion(left, left);
}
void right_eye_down() {   
  byte left[8] ={ 0b00111100,
  0b01111110,
  0b01111110,
  0b01111110,
  0b01001110,
  0b01001110,
  0b01111110,
  0b00111100};displayEmotion(left, left);
}
void left_eye() {   
  byte left[8] ={0b00111100,
  0b01111110,
  0b01111110,
  0b01110010,
  0b01110010,
  0b01111110,
  0b01111110,
  0b00111100};displayEmotion(left, left);

}
void left_eye_down() {   
  byte left[8] ={ 0b00111100,
  0b01111110,
  0b01111110,
  0b01111110,
  0b01110010,
  0b01110010,
  0b01111110,
  0b00111100};displayEmotion(left, left);

}
void forward_blink() {
  showNeutral();


  F_showblink_1();
  
  F_showblink_2();
  
  F_showblink_3();
  
  F_showblink_4();
  
  F_showblink_5();

  F_showblink_6();

  F_showblink_7();

  F_showblink_6();

  F_showblink_5();

  F_showblink_4();
  
  F_showblink_3();
  
  F_showblink_2();
  
  F_showblink_1();
  
  showblink();
  
}
void loop(){
  forward_blink();
  delay(2000);
  right_eye();
  delay(2000);
  left_eye();
  delay(2000);
  forward_blink();
  delay(2000);
  right_eye_down();
  delay(2000);
  }

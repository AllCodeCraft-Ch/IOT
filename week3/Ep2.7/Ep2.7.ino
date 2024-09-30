#include "Arduino_LED_Matrix.h"
Arduino_LED_Matrix matrix;

void setup(){
  matrix.begin();
}

uint8_t frame[8][12]= {
  {0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0}
};

void loop(){
  int i,j;

  for (i=0; i<12; i++) {
    for (j=0; j<8; j++){
    frame[j] [i]=1;
    matrix.randerBitmap(frame,8,12);
    delay(500);
    frame[j] [i]=1;
    matrix.randerBitmap(frame,8,12);
    delay(500);
    }
  }
}
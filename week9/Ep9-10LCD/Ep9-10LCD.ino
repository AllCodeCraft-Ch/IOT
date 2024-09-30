#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;

const int colorR = 128; //0 - 255
const int colorG = 0;
const int colorB = 128;

void setup() {
    // set up the LCD's number of columns and rows:
    lcd.begin(16, 2);

    lcd.setRGB(colorR, colorG, colorB);

    // Print a message to the LCD.
    //lcd.print("hello, world!");

    delay(1000);
}

void loop() {
    // set the cursor to column 0, line 1
    // (note: line 1 is the second row, since counting begins with 0):
    lcd.setCursor(0, 0); //พิมพ์หรือไม่พิมก็ได้เพราะเป็น Defaul
    lcd.print("University of Phayao");

    lcd.setCursor(0, 1); //ตัวเเรกเป็นกำหนดตำแหน่งตัวอักษร 
    // print the number of seconds since reset:
    //lcd.print(millis() / 1000);
    lcd.print("Group EngineerKa");

    delay(100);
}
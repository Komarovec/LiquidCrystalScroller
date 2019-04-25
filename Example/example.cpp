#include <Arduino.h>
#include "LiquidCrystalScroller.hpp"

//Initialize display
LiquidCrystalScroller lcd = LiquidCrystalScroller(0x27,20,4);

void setup() {
  //Begin communication with the display
  lcd.begin();

  //Scroll your precious text :)
  lcd.scrollRow("Really long text that will definitelly overflow your display :)", 0);
  lcd.scrollRow("Short txt noscroll", 1);
  
  //Using methods from LiquidCrystalDisplay_I2C
  /*
  lcd.lcd.setCursor(0,3);
  lcd.lcd.print("Nice text here!")
  */
}

void loop() {
  //Keep this very loopy...
  lcd.scrollLoop();
}

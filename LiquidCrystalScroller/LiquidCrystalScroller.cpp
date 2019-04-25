#include "LiquidCrystalScroller.hpp"

LiquidCrystalScroller::LiquidCrystalScroller() {
    this->lcd = LiquidCrystal_I2C(0x27, 20, 4);
}

LiquidCrystalScroller::LiquidCrystalScroller(int add, int col, int row) {
    this->lcd = LiquidCrystal_I2C(add, col, row);
}

//Begin the comunnication with the display
void LiquidCrystalScroller::begin() {
    this->lcd.init();
}

//LCD SCROLLER LOGIC
void LiquidCrystalScroller::scrollLoop() {
  //Wait until next timeframe --> scrollSpeed dependent
  if(!(this->rowScrollWait < millis())) {
      return;
  }
  this->rowScrollWait = millis() + this->rowScrollSpeed;

  for(int i = 0; i < 4; i++) {
    if(this->rowScroll[i] && this->rowMsgs[i].length() > 0) {
      this->lcd.setCursor(0,i);
      if(this->rowMsgs[i].length() < 21) {
        this->lcd.print(this->rowMsgs[i]);
        continue;
      }

      if(this->rowIndexes[i]+20 >= this->rowMsgs[i].length() + this->disWait) {
        this->rowIndexes[i] = -this->disWait;
        this->lcd.print("                    ");
      }
      else if(this->rowIndexes[i] < 0) {
        this->lcd.print(this->rowMsgs[i].substring(0,20));
      }
      else if(this->rowIndexes[i]+20 <= this->rowMsgs[i].length()) {
        this->lcd.print(this->rowMsgs[i].substring(this->rowIndexes[i],20+this->rowIndexes[i]));
      }
      this->rowIndexes[i]++;
    }
  }
}

//Clear all rows
void LiquidCrystalScroller::scrollClearAll() {
  for(int i = 0; i < 4; i++) {
    this->rowIndexes[i] = -3;
    this->rowScroll[i] = false;
    this->lcd.clear();
  }
}

//Pause scroll on all rows
void LiquidCrystalScroller::scrollPause() {
  for(int i = 0; i < 4; i++) {
    this->rowScroll[i] = false;
  }
}

//Start scroll on selected rows 
void LiquidCrystalScroller::scrollStart(bool a, bool b, bool c, bool d) {
  this->rowScroll[0] = a;
  this->rowScroll[1] = b;
  this->rowScroll[2] = c;
  this->rowScroll[3] = d;
}

//Clear one row
void LiquidCrystalScroller::scrollClearRow(int row) {
  this->rowIndexes[row] = -3;
  this->rowScroll[row] = false;
  this->lcd.setCursor(0,row);
  this->lcd.print("                    ");
}

//Start scrolling on selected row
void LiquidCrystalScroller::scrollRow(String txt, int row) {
    this->scrollClearRow(row);
    this->rowScroll[row] = true;
    this->rowMsgs[row] = txt;
}

//Set the scroll speed
bool LiquidCrystalScroller::setRowScrollSpeed(int speed) {
    if(speed > 0) {
        this->rowScrollSpeed = speed;
        return true;
    }
    return false;
}
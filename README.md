# LiquidCrystalScroller
Arduino library for non-blocking scrolling on alphanumeric LCD.

# How To Use
This library is an extension for LiquidCrystalDisplay_I2C library.
I2C only and it is tested only on 20x4 LCDisplay.

1. Initialize class
LiquidCrystalScroller lcd = LiquidCrystalScroller(0x27,20,4);

2. Begin com. with display
lcd.begin();

3. In your loop function use:
lcd.scrollLoop();
// You MUST run your loop as frequent as you can!

4. Use included methods!
lcd.scrollRow(0, "This is long scrollable text, that will definitely overflow.");

#Method description
scrollRow((int)<row>, (String)<text to print>):
  Automaticly clears the desired row and starts printing on it.
  This function MUST be called only once for each row, otherwise
  the scroll index would be zeroed every time and text would be static.
  
scrollLoop():
  Checks if it is time for moving the text on the display.
  Dependent on the scrollSpeed
  
setRowScrollSpeed():
  Sets the speed of scrolling.
  
scrollClearRow/All((int)<row>/):
  Clears the desired row and stops scrolling on it.
  
scrollPause/Start((bool)<row1>,(bool)<row2>,(bool)<row3>,(bool)<row4>):
  Pauses scrolling and keeps the msg and scroll index --> start continues scrolling.
  EXPERIMENTAL AND NOT TESTED YET!
  

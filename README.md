# LiquidCrystalScroller
Arduino library for non-blocking scrolling on alphanumeric LCD.<br>
Print any text on the row of LCD.<br>
If the text is shorter than length of the row it will behave just like regular LCD library,<br>
but if the text is longer, then it will automaticly start the scrolling procces.<br>

You can always reference original LiquidCrystal object through lcd.lcd.METHOD();

# How To Use
This library is an extension for LiquidCrystalDisplay_I2C library.<br>
I2C only and it is tested only on 20x4 LCDisplay.<br>

### 0. Requirements!
library --> LiquidCrystalDisplay_I2C ==> PlatformIO id: 576

### 1. Initialize class
LiquidCrystalScroller lcd = LiquidCrystalScroller(0x27,20,4);<br>

### 2. Begin com. with display
lcd.begin();

### 3. In your loop function use:
lcd.scrollLoop();
// You MUST run your loop as frequent as you can!

### 4. Use included methods!
lcd.scrollRow("This is long scrollable text, that will definitely overflow.",0);

# Method description
### scrollRow((String)text to print,(int)row):
  Automaticly clears the desired row and starts printing on it.<br>
  This function MUST be called only once for each row, otherwise<br>
  the scroll index would be zeroed every time and text would be static.<br>
  
### scrollLoop():
  Checks if it is time for moving the text on the display.<br>
  Dependent on the scrollSpeed
  
### setRowScrollSpeed():
  Sets the speed of scrolling.
  
### scrollClearRow/All((int)row/):
  Clears the desired row and stops scrolling on it.
  
### scrollPause/Start((bool)row1,(bool)row2,(bool)row3,(bool)row4):
  Pauses scrolling and keeps the msg and scroll index --> start continues scrolling.<br>
  EXPERIMENTAL AND NOT TESTED YET!
  

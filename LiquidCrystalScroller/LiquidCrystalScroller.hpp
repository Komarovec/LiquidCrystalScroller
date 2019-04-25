#ifndef LiquidCrystalScroller_h
#define LiquidCrystalScroller_h

#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

class LiquidCrystalScroller {
public:
    LiquidCrystalScroller();
    LiquidCrystalScroller(int,int,int);
    void begin();
    void scrollClearAll();
    void scrollLoop();
    void scrollClearRow(int);
    void scrollRow(String, int);
    void scrollPause();
    void scrollStart(bool, bool, bool, bool);

    LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0,0,0);

    bool setRowScrollSpeed(int);
private:
    int rowScrollSpeed = 300;
    unsigned long rowScrollWait = 0;
    int disWait = 5;
    String rowMsgs[4] = {"","","",""}; 
    int rowIndexes[4] = {-disWait,-disWait,-disWait,-disWait}; //4 Indexy pro 4 radky na displaji
    bool rowScroll[4] = {false,false,false,false}; //Testovani skrolu

    int toDec(int, int);
};

#endif
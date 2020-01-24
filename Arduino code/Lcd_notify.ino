/*
 * lcd 16*2
 * rs  8
 * en  9 
 * D7  7 
 * D6  6
 * D5  5
 * D4  4
----------------------------------------------------------------------------------------
 *             MFRC522      Arduino       Arduino   Arduino    Arduino          Arduino
 *             Reader/PCD   Uno/101       Mega      Nano v3    Leonardo/Micro   Pro Micro
 * Signal      Pin          Pin           Pin       Pin        Pin              Pin
 * -----------------------------------------------------------------------------------------
 * RST/Reset   RST          9             5         D9         RESET/ICSP-5     RST
 * SPI SS      SDA(SS)      10            53        D10        10               10
 * SPI MOSI    MOSI         11 / ICSP-4   51        D11        ICSP-4           16
 * SPI MISO    MISO         12 / ICSP-1   50        D12        ICSP-1           14
 * SPI SCK     SCK          13 / ICSP-3   52        D13        ICSP-3           15
 */

//#include "talkie.h"

#include <LiquidCrystal.h>
int BAL=0;
const int rs = 8, en = 9, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

unsigned char incomingByte =0;

void setup() {
    Serial.begin(9600);
    
     
      
      lcd.setCursor(0, 0);
      lcd.print("BALANCE ");
      lcd.print(BAL);
      lcd.print(" Rs"); 
      
    
}

void loop() {
if (Serial.available() > 0) {
    incomingByte = Serial.read();

    if(incomingByte=='Q')
    {lcd.clear();
      lcd.setCursor(0, 1);
      lcd.print("    HOSPITAL");
      delay(1000);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("BALANCE ");
      lcd.print(BAL);
      lcd.print(" Rs"); 
    }
    else if(incomingByte=='R')
    {lcd.clear();
      lcd.setCursor(0, 1);
      lcd.print("BALANCE ADD");
      BAL=BAL+100;
      lcd.setCursor(0, 0);
      lcd.print("BALANCE ");
      lcd.print(BAL);
      lcd.print(" Rs"); 
      delay(1000);
      
    }
     else if(incomingByte=='1')
    {lcd.clear();
     BAL=BAL-20;
      lcd.setCursor(0, 0);
      lcd.print("BALANCE ");
      lcd.print(BAL);
      lcd.print(" Rs");
      delay(1000);
    }
      else if(incomingByte=='2')
    {lcd.clear();
      BAL=BAL-10;
      lcd.setCursor(0, 0);
      lcd.print("BALANCE ");
      lcd.print(BAL);
      lcd.print(" Rs");
      delay(1000);
    }

    else if(incomingByte=='S')
    {lcd.clear();
      lcd.setCursor(0, 1);
      lcd.print("no parking 10 Rs");
      delay(1000);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("BALANCE ");
      lcd.print(BAL);
      lcd.print(" Rs"); 
      
    }
     else if(incomingByte=='T')
    {lcd.clear();
      lcd.setCursor(0, 1);
      lcd.print("working progress");
      delay(1000);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("BALANCE ");
      lcd.print(BAL);
      lcd.print(" Rs"); 
    }
    else if(incomingByte=='U')
    {lcd.clear() ;
      lcd.setCursor(0, 1);
      lcd.print("speed limit 20Rs");
      delay(1000);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("BALANCE ");
      lcd.print(BAL);
      lcd.print(" Rs"); 
      
    }
    else if(incomingByte=='V')
    {lcd.clear();
      lcd.setCursor(0, 1);
      lcd.print("speed limit end");
      delay(1000);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("BALANCE ");
      lcd.print(BAL);
      lcd.print(" Rs"); 
      
    }
    else if(incomingByte=='W')
    {lcd.clear();
      lcd.setCursor(0, 1);
      lcd.print("speed limit warn");
      delay(1000);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("BALANCE ");
      lcd.print(BAL);
      lcd.print(" Rs"); 
     
}
else
{     lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("BALANCE ");
      lcd.print(BAL);
      lcd.print(" Rs");
      delay(1000);
}
}
}

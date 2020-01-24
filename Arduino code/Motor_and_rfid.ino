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

#include "SPI.h"
#include "MFRC522.h"

#define ENA_m1 2        // Enable/speed motor Front Right 2
#define ENB_m1 3        // Enable/speed motor Back Right  1
#define ENA_m2 4       // Enable/speed motor Front Left  4
#define ENB_m2 5       // Enable/speed motor Back Left   3

#define IN_11  6        // L298N #1 in 1 motor Front Right
#define IN_12  7        // L298N #1 in 2 motor Front Right
#define IN_13  8        // L298N #1 in 3 motor Back Right
#define IN_14  9        // L298N #1 in 4 motor Back Right

#define IN_21  10        // L298N #2 in 1 motor Front Left
#define IN_22  11        // L298N #2 in 2 motor Front Left
#define IN_23  20       // L298N #2 in 3 motor Back Left
#define IN_24  21       // L298N #2 in 4 motor Back Left

#define SS_PIN 53
#define RST_PIN 48
//#define LED_PIN 13

int incomingByte = 0, sl=0, sn=0, ot=0, np=0;

MFRC522 rfid(SS_PIN, RST_PIN);

MFRC522::MIFARE_Key key;


void setup() {
  // put your setup code here, to run once:
    pinMode(ENA_m1, OUTPUT);
    pinMode(ENB_m1, OUTPUT);
    pinMode(ENA_m2, OUTPUT);
    pinMode(ENB_m2, OUTPUT);
  
    pinMode(IN_11, OUTPUT);
    pinMode(IN_12, OUTPUT);
    pinMode(IN_13, OUTPUT);
    pinMode(IN_14, OUTPUT);
    
    pinMode(IN_21, OUTPUT);
    pinMode(IN_22, OUTPUT);
    pinMode(IN_23, OUTPUT);
    pinMode(IN_24, OUTPUT);

    //pinMode(LED_PIN, OUTPUT);
    
    Serial.begin(9600);
    SPI.begin();
    rfid.PCD_Init();
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0) {
                // read the incoming byte:
                incomingByte = Serial.read();
                if(incomingByte=='S' || incomingByte=='s' )
                {
                  digitalWrite(IN_11, LOW);
                  digitalWrite(IN_12, HIGH);       
                  //digitalWrite(ENA_m1, HIGH);
                  
                  digitalWrite(IN_13, HIGH);
                  digitalWrite(IN_14, LOW); 
                  //digitalWrite(ENB_m1, HIGH);

                  digitalWrite(IN_21, LOW);
                  digitalWrite(IN_22, HIGH);
                  //digitalWrite(ENA_m2, HIGH);

                  digitalWrite(IN_23, HIGH);
                  digitalWrite(IN_24, LOW);
                  //digitalWrite(ENB_m2, HIGH);
                // delay(200);
                }
                else if(incomingByte=='W' || incomingByte=='w' )
                {
                  digitalWrite(IN_12, LOW);
                  digitalWrite(IN_11, HIGH);       
                  //digitalWrite(ENA_m1, HIGH);
                  
                  digitalWrite(IN_14, HIGH);
                  digitalWrite(IN_13, LOW); 
                  //digitalWrite(ENB_m1, HIGH);

                  digitalWrite(IN_22, LOW);
                  digitalWrite(IN_21, HIGH);
                  //digitalWrite(ENA_m2, HIGH);

                  digitalWrite(IN_24, HIGH);
                  digitalWrite(IN_23, LOW);
                  //digitalWrite(ENB_m2, HIGH);
                // delay(200);
                }

                else if(incomingByte=='D' || incomingByte=='d' )
                {

                  digitalWrite(IN_11, LOW);
                  digitalWrite(IN_12, HIGH);       
                  //digitalWrite(ENA_m1, HIGH);
                  
                  digitalWrite(IN_13, HIGH);
                  digitalWrite(IN_14, LOW); 
                  //digitalWrite(ENB_m1, HIGH);

                  digitalWrite(IN_22, LOW);
                  digitalWrite(IN_21, HIGH);
                  //digitalWrite(ENA_m2, HIGH);

                  digitalWrite(IN_24, HIGH);
                  digitalWrite(IN_23, LOW);
                  //digitalWrite(ENB_m2, 255);
                  
                // delay(200);
                }

                else if(incomingByte=='A' || incomingByte=='a' )
                {

                  digitalWrite(IN_12, LOW);
                  digitalWrite(IN_11, HIGH);       
                  //digitalWrite(ENA_m1, HIGH);
                  
                  digitalWrite(IN_14, HIGH);
                  digitalWrite(IN_13, LOW); 
                  //digitalWrite(ENB_m1, HIGH);


                  digitalWrite(IN_21, LOW);
                  digitalWrite(IN_22, HIGH);
                  //digitalWrite(ENA_m2, HIGH);



                  digitalWrite(IN_23, HIGH);
                  digitalWrite(IN_24, LOW);
                  //digitalWrite(ENB_m2, HIGH);
                  
                // delay(200);
                }
                
                else if(incomingByte=='1')
                {
                  analogWrite(ENA_m1, 0);
                  analogWrite(ENB_m1, 0);
                  analogWrite(ENA_m2, 0);
                  analogWrite(ENB_m2, 0);
                  sn=0;
                  
                }
                else if(incomingByte=='2')
                {
                  analogWrite(ENA_m1, 80);
                  analogWrite(ENB_m1, 80);
                  analogWrite(ENA_m2, 80);
                  analogWrite(ENB_m2, 80);  
                  sn=2;                
                }
                else if(incomingByte=='3')
                {
                  analogWrite(ENA_m1, 100);
                  analogWrite(ENB_m1, 100);
                  analogWrite(ENA_m2, 100);
                  analogWrite(ENB_m2, 100);
                  sn=3;                  
                }
                else if(incomingByte=='4')
                {
                  analogWrite(ENA_m1, 115);
                  analogWrite(ENB_m1, 115);
                  analogWrite(ENA_m2, 115);
                  analogWrite(ENB_m2, 115);  
                  sn=4;                
                }
                else if(incomingByte=='5')
                {
                  analogWrite(ENA_m1, 143);
                  analogWrite(ENB_m1, 143);
                  analogWrite(ENA_m2, 143);
                  analogWrite(ENB_m2, 143);
                  sn=5;                  
                }
                else if(incomingByte=='6')
                {
                  analogWrite(ENA_m1, 171);
                  analogWrite(ENB_m1, 171);
                  analogWrite(ENA_m2, 171);
                  analogWrite(ENB_m2, 171);
                  sn=6;                  
                }
                else if(incomingByte=='7')
                {
                  analogWrite(ENA_m1, 199);
                  analogWrite(ENB_m1, 199);
                  analogWrite(ENA_m2, 199);
                  analogWrite(ENB_m2, 199); 
                  sn=7;                 
                }
                else if(incomingByte=='8')
                {
                  analogWrite(ENA_m1, 227);
                  analogWrite(ENB_m1, 227);
                  analogWrite(ENA_m2, 227);
                  analogWrite(ENB_m2, 227);
                  sn=8;                  
                }
                else if(incomingByte=='9')
                {
                  analogWrite(ENA_m1, 255);
                  analogWrite(ENB_m1, 255);
                  analogWrite(ENA_m2, 255);
                  analogWrite(ENB_m2, 255); 
         
                  sn=9;

                  if(sl==1 && sn==9)
                {
                 // delay(1000);
                 Serial.print('1'); //speed limit cut 10 Rs
                 delay(10);
                }
                               
                }
              else if(incomingByte==' ')
                {
                  digitalWrite(IN_11, LOW);
                  digitalWrite(IN_12, LOW);       
                  //digitalWrite(ENA_m1, HIGH);
                  
                  digitalWrite(IN_13, LOW);
                  digitalWrite(IN_14, LOW); 
                  //digitalWrite(ENB_m1, HIGH);


                  digitalWrite(IN_21, LOW);
                  digitalWrite(IN_22, LOW);
                  //digitalWrite(ENA_m2, HIGH);



                  digitalWrite(IN_23, LOW);
                  digitalWrite(IN_24, LOW);   
                  sn=0;   
                                
                }

             

}

               
  
                if(np==1 && sn==0)
                {
                 // delay(1000);
                 Serial.print('2'); //speed limit cut 10 Rs
                 np=0;
                 delay(10);
                }

 if (!rfid.PICC_IsNewCardPresent() || !rfid.PICC_ReadCardSerial())
    return;
      // Serial.print(F("PICC type: "));
  MFRC522::PICC_Type piccType = rfid.PICC_GetType(rfid.uid.sak);
  // Serial.println(rfid.PICC_GetTypeName(piccType));

  // Check is the PICC of Classic MIFARE type
  if (piccType != MFRC522::PICC_TYPE_MIFARE_MINI &&
    piccType != MFRC522::PICC_TYPE_MIFARE_1K &&
    piccType != MFRC522::PICC_TYPE_MIFARE_4K) {
   // Serial.println(F("Your tag is not of type MIFARE Classic."));
    return;
  }

  String strID = "";
  for (byte i = 0; i < 4; i++) {
    strID +=
    (rfid.uid.uidByte[i] < 0x10 ? "0" : "") +
    String(rfid.uid.uidByte[i], HEX) +
    (i!=3 ? ":" : "");
  }
  strID.toUpperCase();

 // Serial.print("Tap card key: ");
 // Serial.println(strID);
  /////////////////////////////////////////////////////////////////
  if (strID.indexOf("E9:B0:54:2B") >= 0) //1
  {
    Serial.print('Q'); // hospital warning
   // delay(10);
    
  } 
  if (strID.indexOf("02:F5:53:83") >= 0) //key
  {
    Serial.print('R'); // balance add
    //delay(10);
  }
  if (strID.indexOf("23:0F:EC:1B") >= 0) //2
  {
    Serial.print('S'); //no parking
    np=1;
    //delay(3000);  
    //delay(10);
    for(int p=0;p<=2000;p++)
    {
    if(np==1 && sn==0)
                {
                 // delay(1000);
                 Serial.print('2'); //speed limit cut 10 Rs
                 np=0;
                 delay(10);
                 p=2001;
                }
                if(p==1999)
                {
                  np=0;
                }
                delay(1);
  } }
  if (strID.indexOf("13:D3:EE:1B") >= 0) //3
  {
    Serial.print('T'); //working progree
   // delay(10);
  }
   if (strID.indexOf("23:28:70:1B") >= 0) //4
  {
    Serial.print('U'); //speed limit 20 Rs 
    sl=1;
   // delay(2);
   if(sl==1 && sn==9)
      {
       // delay(1000);
       Serial.print('1'); //speed limit cut 10 Rs
       delay(10);
      }
  }
   if (strID.indexOf("23:D8:18:1B") >= 0) //5
  {
    Serial.print('V'); // speed limit end
    sl=0;
    //delay(10);
  }
   if (strID.indexOf("23:F5:8E:1B") >= 0) //6
  {
    Serial.print('W'); // speed limit warning
    ot=0;
    sl=0;
   // delay(10);
  }

  
  

  rfid.PICC_HaltA();
  rfid.PCD_StopCrypto1();

  
}

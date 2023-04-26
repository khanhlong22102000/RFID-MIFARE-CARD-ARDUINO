#include <SPI.h>
#include <MFRC522.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define RST_PIN         9
#define SS_PIN          10
#define readPin         A0
#define button          4

LiquidCrystal_I2C lcd(0X3F,20,4);   // màn hình 20 cột, 4 hàng
MFRC522 mfrc522(SS_PIN, RST_PIN);
MFRC522::MIFARE_Key key;
MFRC522::StatusCode status;

int readVal = 0;
int buttonstt;
int ADCV = 0;
int k = 0;
byte block1 = 1;
byte buffer1[18];
byte len1 = sizeof(buffer1);
byte trailerBlock = 3;
byte valueBlock1 [] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, block1, ~block1, block1, ~block1};
byte VBlock0 [] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, block1, ~block1, block1, ~block1};
byte VBlock1 [] = {1, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, block1, ~block1, block1, ~block1};
byte VBlock2 [] = {1, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, block1, ~block1, block1, ~block1};
byte VBlock3 [] = {1, 2, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, block1, ~block1, block1, ~block1};
byte VBlock4 [] = {1, 2, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, block1, ~block1, block1, ~block1};
byte VBlock5 [] = {1, 2, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, block1, ~block1, block1, ~block1};
byte VBlock6 [] = {1, 2, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, block1, ~block1, block1, ~block1};
byte VBlock7 [] = {1, 2, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, block1, ~block1, block1, ~block1};
byte VBlock8 [] = {1, 2, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, block1, ~block1, block1, ~block1};
byte VBlock9 [] = {1, 2, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, block1, ~block1, block1, ~block1};
byte VBlock10 [] = {1, 2, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, block1, ~block1, block1, ~block1};
byte VBlock11 [] = {1, 2, 11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, block1, ~block1, block1, ~block1};
byte VBlock12 [] = {1, 2, 12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, block1, ~block1, block1, ~block1};
byte VBlock13 [] = {1, 2, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, block1, ~block1, block1, ~block1};
byte VBlock14 [] = {1, 2, 14, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, block1, ~block1, block1, ~block1};
byte VBlock15 [] = {1, 2, 15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, block1, ~block1, block1, ~block1};
byte VBlock16 [] = {1, 2, 16, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, block1, ~block1, block1, ~block1};
byte VBlock17 [] = {1, 2, 17, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, block1, ~block1, block1, ~block1};
byte VBlock18 [] = {1, 2, 18, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, block1, ~block1, block1, ~block1};
byte VBlock19 [] = {1, 2, 19, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, block1, ~block1, block1, ~block1};
byte VBlock20 [] = {1, 2, 20, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, block1, ~block1, block1, ~block1};
byte VBlock21 [] = {1, 2, 21, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, block1, ~block1, block1, ~block1}; // Master
int a = 0;

void setup() 
{
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);   
  SPI.begin();
  pinMode(readPin,INPUT);
  pinMode(button,INPUT_PULLUP);   
  mfrc522.PCD_Init();
  for (byte i = 0; i < 6; i++)
  {
    key.keyByte[i] = 0xFF;
    }  
}

void sendtoLCD()
{
  
}

// Code 
void loop()
{
  readVal = analogRead(readPin);
  ADCV = round(readVal * 0.021);
  buttonstt = digitalRead(button); 
  if(buttonstt==LOW){k = ADCV;}
  if(ADCV<10)
  {
    lcd.setCursor(0,0);
    lcd.print("STT DIEU CHINH");
    lcd.setCursor(14,0);
    lcd.print(":");
    lcd.setCursor(15,0);
    lcd.print(" ");    
    lcd.setCursor(16,0);
    lcd.print(ADCV);
  }
  if(ADCV>9)
  {
    lcd.setCursor(0,0);
    lcd.print("STT DIEU CHINH");
    lcd.setCursor(14,0);
    lcd.print(":");
    lcd.setCursor(15,0);
    lcd.print(ADCV);  
  }
  
    if(k<10)
  {
    lcd.setCursor(0,1);
    lcd.print("STT CHON");
    lcd.setCursor(14,1);
    lcd.print(":");
    lcd.setCursor(15,1);
    lcd.print(" ");
    lcd.setCursor(16,1);
    lcd.print(k); 
  }
  if(k>9)
  {
    lcd.setCursor(0,1);
    lcd.print("STT CHON");
    lcd.setCursor(14,1);
    lcd.print(":");
    lcd.setCursor(15,1);
    lcd.print(k); 
  }      
  lcd.setCursor(0,2);
  lcd.print("TINH TRANG:");

  if(k==1)
  {
    if ( ! mfrc522.PICC_IsNewCardPresent()) {return;}
    if ( ! mfrc522.PICC_ReadCardSerial()) {return;}
    status = mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, trailerBlock, &key, &(mfrc522.uid));
    status = mfrc522.MIFARE_Write(block1, VBlock1, 16);
    mfrc522.PICC_HaltA();
    mfrc522.PCD_StopCrypto1();
    lcd.setCursor(0,3);
    lcd.print("DA CHEP THE 1");
    k = 0;
    delay(1000);
    lcd.setCursor(0,3);
    lcd.print("             ");         
  }

  if(k==2)
  {
    if ( ! mfrc522.PICC_IsNewCardPresent()) {return;}
    if ( ! mfrc522.PICC_ReadCardSerial()) {return;}
    status = mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, trailerBlock, &key, &(mfrc522.uid));
    status = mfrc522.MIFARE_Write(block1, VBlock2, 16);
    mfrc522.PICC_HaltA();
    mfrc522.PCD_StopCrypto1();
    lcd.setCursor(0,3);
    lcd.print("DA CHEP THE 2");
    k = 0;
    delay(1000);
    lcd.setCursor(0,3);
    lcd.print("             ");         
  }

  if(k==3)
  {
    if ( ! mfrc522.PICC_IsNewCardPresent()) {return;}
    if ( ! mfrc522.PICC_ReadCardSerial()) {return;}
    status = mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, trailerBlock, &key, &(mfrc522.uid));
    status = mfrc522.MIFARE_Write(block1, VBlock3, 16);
    mfrc522.PICC_HaltA();
    mfrc522.PCD_StopCrypto1();
    lcd.setCursor(0,3);
    lcd.print("DA CHEP THE 3");
    k = 0;
    delay(1000);
    lcd.setCursor(0,3);
    lcd.print("             ");         
  }
  
  if(k==4)
  {
    if ( ! mfrc522.PICC_IsNewCardPresent()) {return;}
    if ( ! mfrc522.PICC_ReadCardSerial()) {return;}
    status = mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, trailerBlock, &key, &(mfrc522.uid));
    status = mfrc522.MIFARE_Write(block1, VBlock4, 16);
    mfrc522.PICC_HaltA();
    mfrc522.PCD_StopCrypto1();
    lcd.setCursor(0,3);
    lcd.print("DA CHEP THE 4");
    k = 0;
    delay(1000);
    lcd.setCursor(0,3);
    lcd.print("             ");         
  }

  if(k==5)
  {
    if ( ! mfrc522.PICC_IsNewCardPresent()) {return;}
    if ( ! mfrc522.PICC_ReadCardSerial()) {return;}
    status = mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, trailerBlock, &key, &(mfrc522.uid));
    status = mfrc522.MIFARE_Write(block1, VBlock5, 16);
    mfrc522.PICC_HaltA();
    mfrc522.PCD_StopCrypto1();
    lcd.setCursor(0,3);
    lcd.print("DA CHEP THE 5");
    k = 0;
    delay(1000);
    lcd.setCursor(0,3);
    lcd.print("             ");         
  }

  if(k==6)
  {
    if ( ! mfrc522.PICC_IsNewCardPresent()) {return;}
    if ( ! mfrc522.PICC_ReadCardSerial()) {return;}
    status = mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, trailerBlock, &key, &(mfrc522.uid));
    status = mfrc522.MIFARE_Write(block1, VBlock6, 16);
    mfrc522.PICC_HaltA();
    mfrc522.PCD_StopCrypto1();
    lcd.setCursor(0,3);
    lcd.print("DA CHEP THE 6");
    k = 0;
    delay(1000);
    lcd.setCursor(0,3);
    lcd.print("             ");         
  }

  if(k==7)
  {
    if ( ! mfrc522.PICC_IsNewCardPresent()) {return;}
    if ( ! mfrc522.PICC_ReadCardSerial()) {return;}
    status = mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, trailerBlock, &key, &(mfrc522.uid));
    status = mfrc522.MIFARE_Write(block1, VBlock7, 16);
    mfrc522.PICC_HaltA();
    mfrc522.PCD_StopCrypto1();
    lcd.setCursor(0,3);
    lcd.print("DA CHEP THE 7");
    k = 0;
    delay(1000);
    lcd.setCursor(0,3);
    lcd.print("             ");         
  }

  if(k==8)
  {
    if ( ! mfrc522.PICC_IsNewCardPresent()) {return;}
    if ( ! mfrc522.PICC_ReadCardSerial()) {return;}
    status = mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, trailerBlock, &key, &(mfrc522.uid));
    status = mfrc522.MIFARE_Write(block1, VBlock8, 16);
    mfrc522.PICC_HaltA();
    mfrc522.PCD_StopCrypto1();
    lcd.setCursor(0,3);
    lcd.print("DA CHEP THE 8");
    k = 0;
    delay(1000);
    lcd.setCursor(0,3);
    lcd.print("             ");         
  }

  if(k==9)
  {
    if ( ! mfrc522.PICC_IsNewCardPresent()) {return;}
    if ( ! mfrc522.PICC_ReadCardSerial()) {return;}
    status = mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, trailerBlock, &key, &(mfrc522.uid));
    status = mfrc522.MIFARE_Write(block1, VBlock9, 16);
    mfrc522.PICC_HaltA();
    mfrc522.PCD_StopCrypto1();
    lcd.setCursor(0,3);
    lcd.print("DA CHEP THE 9");
    k = 0;
    delay(1000);
    lcd.setCursor(0,3);
    lcd.print("             ");         
  }

  if(k==10)
  {
    if ( ! mfrc522.PICC_IsNewCardPresent()) {return;}
    if ( ! mfrc522.PICC_ReadCardSerial()) {return;}
    status = mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, trailerBlock, &key, &(mfrc522.uid));
    status = mfrc522.MIFARE_Write(block1, VBlock10, 16);
    mfrc522.PICC_HaltA();
    mfrc522.PCD_StopCrypto1();
    lcd.setCursor(0,3);
    lcd.print("DA CHEP THE 10");
    k = 0;
    delay(1000);
    lcd.setCursor(0,3);
    lcd.print("              ");         
  }

  if(k==11)
  {
    if ( ! mfrc522.PICC_IsNewCardPresent()) {return;}
    if ( ! mfrc522.PICC_ReadCardSerial()) {return;}
    status = mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, trailerBlock, &key, &(mfrc522.uid));
    status = mfrc522.MIFARE_Write(block1, VBlock11, 16);
    mfrc522.PICC_HaltA();
    mfrc522.PCD_StopCrypto1();
    lcd.setCursor(0,3);
    lcd.print("DA CHEP THE 11");
    k = 0;
    delay(1000);
    lcd.setCursor(0,3);
    lcd.print("              ");         
  }

  if(k==12)
  {
    if ( ! mfrc522.PICC_IsNewCardPresent()) {return;}
    if ( ! mfrc522.PICC_ReadCardSerial()) {return;}
    status = mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, trailerBlock, &key, &(mfrc522.uid));
    status = mfrc522.MIFARE_Write(block1, VBlock12, 16);
    mfrc522.PICC_HaltA();
    mfrc522.PCD_StopCrypto1();
    lcd.setCursor(0,3);
    lcd.print("DA CHEP THE 12");
    k = 0;
    delay(1000);
    lcd.setCursor(0,3);
    lcd.print("              ");         
  }

  if(k==13)
  {
    if ( ! mfrc522.PICC_IsNewCardPresent()) {return;}
    if ( ! mfrc522.PICC_ReadCardSerial()) {return;}
    status = mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, trailerBlock, &key, &(mfrc522.uid));
    status = mfrc522.MIFARE_Write(block1, VBlock13, 16);
    mfrc522.PICC_HaltA();
    mfrc522.PCD_StopCrypto1();
    lcd.setCursor(0,3);
    lcd.print("DA CHEP THE 13");
    k = 0;
    delay(1000);
    lcd.setCursor(0,3);
    lcd.print("              ");         
  }

  if(k==14)
  {
    if ( ! mfrc522.PICC_IsNewCardPresent()) {return;}
    if ( ! mfrc522.PICC_ReadCardSerial()) {return;}
    status = mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, trailerBlock, &key, &(mfrc522.uid));
    status = mfrc522.MIFARE_Write(block1, VBlock14, 16);
    mfrc522.PICC_HaltA();
    mfrc522.PCD_StopCrypto1();
    lcd.setCursor(0,3);
    lcd.print("DA CHEP THE 14");
    k = 0;
    delay(1000);
    lcd.setCursor(0,3);
    lcd.print("              ");         
  }

  if(k==15)
  {
    if ( ! mfrc522.PICC_IsNewCardPresent()) {return;}
    if ( ! mfrc522.PICC_ReadCardSerial()) {return;}
    status = mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, trailerBlock, &key, &(mfrc522.uid));
    status = mfrc522.MIFARE_Write(block1, VBlock15, 16);
    mfrc522.PICC_HaltA();
    mfrc522.PCD_StopCrypto1();
    lcd.setCursor(0,3);
    lcd.print("DA CHEP THE 15");
    k = 0;
    delay(1000);
    lcd.setCursor(0,3);
    lcd.print("              ");         
  }

  if(k==16)
  {
    if ( ! mfrc522.PICC_IsNewCardPresent()) {return;}
    if ( ! mfrc522.PICC_ReadCardSerial()) {return;}
    status = mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, trailerBlock, &key, &(mfrc522.uid));
    status = mfrc522.MIFARE_Write(block1, VBlock16, 16);
    mfrc522.PICC_HaltA();
    mfrc522.PCD_StopCrypto1();
    lcd.setCursor(0,3);
    lcd.print("DA CHEP THE 16");
    k = 0;
    delay(1000);
    lcd.setCursor(0,3);
    lcd.print("              ");         
  }

  if(k==17)
  {
    if ( ! mfrc522.PICC_IsNewCardPresent()) {return;}
    if ( ! mfrc522.PICC_ReadCardSerial()) {return;}
    status = mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, trailerBlock, &key, &(mfrc522.uid));
    status = mfrc522.MIFARE_Write(block1, VBlock17, 16);
    mfrc522.PICC_HaltA();
    mfrc522.PCD_StopCrypto1();
    lcd.setCursor(0,3);
    lcd.print("DA CHEP THE 17");
    k = 0;
    delay(1000);
    lcd.setCursor(0,3);
    lcd.print("              ");         
  }
  
  if(k==18)
  {
    if ( ! mfrc522.PICC_IsNewCardPresent()) {return;}
    if ( ! mfrc522.PICC_ReadCardSerial()) {return;}
    status = mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, trailerBlock, &key, &(mfrc522.uid));
    status = mfrc522.MIFARE_Write(block1, VBlock18, 16);
    mfrc522.PICC_HaltA();
    mfrc522.PCD_StopCrypto1();
    lcd.setCursor(0,3);
    lcd.print("DA CHEP THE 18");
    k = 0;
    delay(1000);
    lcd.setCursor(0,3);
    lcd.print("              ");         
  }

  if(k==19)
  {
    if ( ! mfrc522.PICC_IsNewCardPresent()) {return;}
    if ( ! mfrc522.PICC_ReadCardSerial()) {return;}
    status = mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, trailerBlock, &key, &(mfrc522.uid));
    status = mfrc522.MIFARE_Write(block1, VBlock19, 16);
    mfrc522.PICC_HaltA();
    mfrc522.PCD_StopCrypto1();
    lcd.setCursor(0,3);
    lcd.print("DA CHEP THE 19");
    k = 0;
    delay(1000);
    lcd.setCursor(0,3);
    lcd.print("              ");         
  }

  if(k==20)
  {
    if ( ! mfrc522.PICC_IsNewCardPresent()) {return;}
    if ( ! mfrc522.PICC_ReadCardSerial()) {return;}
    status = mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, trailerBlock, &key, &(mfrc522.uid));
    status = mfrc522.MIFARE_Write(block1, VBlock20, 16);
    mfrc522.PICC_HaltA();
    mfrc522.PCD_StopCrypto1();
    lcd.setCursor(0,3);
    lcd.print("DA CHEP THE 20");
    k = 0;
    delay(1000);
    lcd.setCursor(0,3);
    lcd.print("              ");         
  }

  if(k==21)
  {
    if ( ! mfrc522.PICC_IsNewCardPresent()) {return;}
    if ( ! mfrc522.PICC_ReadCardSerial()) {return;}
    status = mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, trailerBlock, &key, &(mfrc522.uid));
    status = mfrc522.MIFARE_Write(block1, VBlock21, 16);
    mfrc522.PICC_HaltA();
    mfrc522.PCD_StopCrypto1();
    lcd.setCursor(0,3);
    lcd.print("DA CHEP THE 21");
    k = 0;
    delay(1000);
    lcd.setCursor(0,3);
    lcd.print("              ");         
  }      
}

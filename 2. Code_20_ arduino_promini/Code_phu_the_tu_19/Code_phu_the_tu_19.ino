#include <SPI.h>
#include <MFRC522.h>

//#define RST_PIN         5
//#define SS_PIN          53

#define RST_PIN         9
#define SS_PIN          10
#define BUZZ            2

MFRC522 mfrc522(SS_PIN, RST_PIN);
MFRC522::MIFARE_Key key;
MFRC522::StatusCode status;

unsigned char stt = 0;
unsigned char check0 = 0;
unsigned char check1 = 0;
unsigned char check2 = 0;

byte block = 1;
byte trailerBlock = 3;
byte buffer1[18];
byte len = sizeof(buffer1);

void setup() 
{
  Serial.begin(9600);  
  SPI.begin();
  pinMode(BUZZ,OUTPUT);
  digitalWrite(BUZZ,LOW);    
  mfrc522.PCD_Init();
  for (byte i = 0; i < 6; i++)
  {
    key.keyByte[i] = 0xFF;
    }  
}

void loop()
{
  // Code đọc thẻ
  if ( ! mfrc522.PICC_IsNewCardPresent()) {
    return;
  }
  if ( ! mfrc522.PICC_ReadCardSerial()) {
    return;
  }
  status = mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, trailerBlock, &key, &(mfrc522.uid));
  status = mfrc522.MIFARE_Read(block, buffer1, &len);
  
  mfrc522.PICC_HaltA();
  mfrc522.PCD_StopCrypto1();

  // Code so sánh thẻ
  check0 = buffer1[0];
  check1 = buffer1[1];
  check2 = buffer1[2];
  if(check0==1 && check1==2)
  {
    stt = check2;    
    if(stt==1){Serial.write(19);Serial.write(1);digitalWrite(BUZZ,HIGH);delay(200);digitalWrite(BUZZ,LOW);}else{digitalWrite(BUZZ,LOW);}
    if(stt==2){Serial.write(19);Serial.write(2);digitalWrite(BUZZ,HIGH);delay(200);digitalWrite(BUZZ,LOW);}else{digitalWrite(BUZZ,LOW);}
    if(stt==3){Serial.write(19);Serial.write(3);digitalWrite(BUZZ,HIGH);delay(200);digitalWrite(BUZZ,LOW);}else{digitalWrite(BUZZ,LOW);}
    if(stt==4){Serial.write(19);Serial.write(4);digitalWrite(BUZZ,HIGH);delay(200);digitalWrite(BUZZ,LOW);}else{digitalWrite(BUZZ,LOW);}
    if(stt==5){Serial.write(19);Serial.write(5);digitalWrite(BUZZ,HIGH);delay(200);digitalWrite(BUZZ,LOW);}else{digitalWrite(BUZZ,LOW);}
    if(stt==6){Serial.write(19);Serial.write(6);digitalWrite(BUZZ,HIGH);delay(200);digitalWrite(BUZZ,LOW);}else{digitalWrite(BUZZ,LOW);}
    if(stt==7){Serial.write(19);Serial.write(7);digitalWrite(BUZZ,HIGH);delay(200);digitalWrite(BUZZ,LOW);}else{digitalWrite(BUZZ,LOW);}
    if(stt==8){Serial.write(19);Serial.write(8);digitalWrite(BUZZ,HIGH);delay(200);digitalWrite(BUZZ,LOW);}else{digitalWrite(BUZZ,LOW);}
    if(stt==9){Serial.write(19);Serial.write(9);digitalWrite(BUZZ,HIGH);delay(200);digitalWrite(BUZZ,LOW);}else{digitalWrite(BUZZ,LOW);}
    if(stt==10){Serial.write(19);Serial.write(10);digitalWrite(BUZZ,HIGH);delay(200);digitalWrite(BUZZ,LOW);}else{digitalWrite(BUZZ,LOW);}
    if(stt==11){Serial.write(19);Serial.write(11);digitalWrite(BUZZ,HIGH);delay(200);digitalWrite(BUZZ,LOW);}else{digitalWrite(BUZZ,LOW);}
    if(stt==12){Serial.write(19);Serial.write(12);digitalWrite(BUZZ,HIGH);delay(200);digitalWrite(BUZZ,LOW);}else{digitalWrite(BUZZ,LOW);}
    if(stt==13){Serial.write(19);Serial.write(13);digitalWrite(BUZZ,HIGH);delay(200);digitalWrite(BUZZ,LOW);}else{digitalWrite(BUZZ,LOW);}
    if(stt==14){Serial.write(19);Serial.write(14);digitalWrite(BUZZ,HIGH);delay(200);digitalWrite(BUZZ,LOW);}else{digitalWrite(BUZZ,LOW);} 
    if(stt==15){Serial.write(19);Serial.write(15);digitalWrite(BUZZ,HIGH);delay(200);digitalWrite(BUZZ,LOW);}else{digitalWrite(BUZZ,LOW);} 
    if(stt==16){Serial.write(19);Serial.write(16);digitalWrite(BUZZ,HIGH);delay(200);digitalWrite(BUZZ,LOW);}else{digitalWrite(BUZZ,LOW);} 
    if(stt==17){Serial.write(19);Serial.write(17);digitalWrite(BUZZ,HIGH);delay(200);digitalWrite(BUZZ,LOW);}else{digitalWrite(BUZZ,LOW);} 
    if(stt==18){Serial.write(19);Serial.write(18);digitalWrite(BUZZ,HIGH);delay(200);digitalWrite(BUZZ,LOW);}else{digitalWrite(BUZZ,LOW);} 
    if(stt==19){Serial.write(19);Serial.write(19);digitalWrite(BUZZ,HIGH);delay(200);digitalWrite(BUZZ,LOW);}else{digitalWrite(BUZZ,LOW);} 
    if(stt==20){Serial.write(19);Serial.write(20);digitalWrite(BUZZ,HIGH);delay(200);digitalWrite(BUZZ,LOW);}else{digitalWrite(BUZZ,LOW);}
    if(stt==21){Serial.write(19);Serial.write(21);digitalWrite(BUZZ,HIGH);delay(200);digitalWrite(BUZZ,LOW);}else{digitalWrite(BUZZ,LOW);}                                     
  }

  stt=0;
  for(uint8_t b=0;b<16;b++){buffer1[b]=0;}
    
}

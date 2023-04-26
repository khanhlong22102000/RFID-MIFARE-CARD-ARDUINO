#include <SPI.h>
//#include <MFRC522.h>
#include <TimerOne.h> // UNO hoặc MEGA
//#include <DueTimer.h>   // DUE
#include <Ethernet.h>

#define out1 31
#define out2  30
#define out3  33
#define out4  32
#define out5  35
#define out6  34
#define out7  37
#define out8  36
#define out9  39
#define out10 38
#define out11 41
#define out12 40

#define out13 42
#define out14 43
#define out15 44
#define out16 45
#define out17 46
#define out18 47
#define out19 48
#define out20 49

int r=0,c=0,z=0;

int k1=0,k2=0,k3=0,k4=0,k5=0,k6=0,k7=0,k8=0,k9=0,k10=0,k11=0,k12=0,k13=0,k14=0,k15=0,k16=0,k17=0,k18=0,k19=0,k20=0;
int f1=0,f2=0,f3=0,f4=0,f5=0,f6=0,f7=0,f8=0,f9=0,f10=0,f11=0,f12=0,f13=0,f14=0,f15=0,f16=0,f17=0,f18=0,f19=0,f20=0;
int z1=0,z2=0,z3=0,z4=0,z5=0,z6=0,z7=0,z8=0,z9=0,z10=0,z11=0,z12=0,z13=0,z14=0,z15=0,z16=0,z17=0,z18=0,z19=0,z20=0;


byte data[2];

int t1=0,t2=0,t3=0,t4=0,t5=0,t6=0,t7=0,t8=0,t9=0,t10=0,t11=0,t12=0,t13=0,t14=0,t15=0,t16=0,t17=0,t18=0,t19=0,t20=0; // 1: bắt đầu đếm thời gian, 0: ngưng đếm thời gian
uint32_t h1=0,h2=0,h3=0,h4=0,h5=0,h6=0,h7=0,h8=0,h9=0,h10=0,h11=0,h12=0,h13=0,h14=0,h15=0,h16=0,h17=0,h18=0,h19=0,h20=0; // Giờ
uint32_t m1=0,m2=0,m3=0,m4=0,m5=0,m6=0,m7=0,m8=0,m9=0,m10=0,m11=0,m12=0,m13=0,m14=0,m15=0,m16=0,m17=0,m18=0,m19=0,m20=0; // Phút 
uint32_t s1=0,s2=0,s3=0,s4=0,s5=0,s6=0,s7=0,s8=0,s9=0,s10=0,s11=0,s12=0,s13=0,s14=0,s15=0,s16=0,s17=0,s18=0,s19=0,s20=0; // Giây

byte mac[] = { 0xCE, 0xAD, 0xBE, 0xEF, 0xFE, 0xEF };   // Mac cho sheild (không đổi)
byte ip[] = { 192, 168, 1, 200 };                      // Ip web side cho dự án (192.168.1.200:88)
byte gateway[] = { 192, 168, 1, 1 };                   // Gateway trong máy
byte subnet[] = { 255, 255, 255, 0 };                  // Subnet trong máy
EthernetServer server(88);                             // server port (Số đuôi 88 trong IP web)     
String readString;

void setup() 
{
  Timer1.initialize(1000000); // Calls every 1s (MEGA,UNO)
  //Timer1.start(1000000); // Calls every 1s (DUE)
  Timer1.attachInterrupt(MyHandler);
  pinMode(out1,OUTPUT);
  pinMode(out2,OUTPUT);
  pinMode(out3,OUTPUT);
  pinMode(out4,OUTPUT);
  pinMode(out5,OUTPUT);
  pinMode(out6,OUTPUT);
  pinMode(out7,OUTPUT);
  pinMode(out8,OUTPUT);
  pinMode(out9,OUTPUT);
  pinMode(out10,OUTPUT);
  pinMode(out11,OUTPUT);
  pinMode(out12,OUTPUT);
  pinMode(out13,OUTPUT);
  pinMode(out14,OUTPUT);
  pinMode(out15,OUTPUT);
  pinMode(out16,OUTPUT);
  pinMode(out17,OUTPUT);
  pinMode(out18,OUTPUT);
  pinMode(out19,OUTPUT);
  pinMode(out20,OUTPUT);
  
  digitalWrite(out1,HIGH);
  digitalWrite(out2,HIGH);
  digitalWrite(out3,HIGH);
  digitalWrite(out4,HIGH);
  digitalWrite(out5,HIGH);
  digitalWrite(out6,HIGH);
  digitalWrite(out7,HIGH);
  digitalWrite(out8,HIGH);
  digitalWrite(out9,HIGH);
  digitalWrite(out10,HIGH);
  digitalWrite(out11,HIGH);
  digitalWrite(out12,HIGH);
  digitalWrite(out13,HIGH);
  digitalWrite(out14,HIGH);
  digitalWrite(out15,HIGH);
  digitalWrite(out16,HIGH);
  digitalWrite(out17,HIGH);
  digitalWrite(out18,HIGH);
  digitalWrite(out19,HIGH);
  digitalWrite(out20,HIGH);

  Serial.begin(9600);
  Serial2.begin(9600);   
  SPI.begin();    
   while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }
  Ethernet.begin(mac, ip, gateway, subnet);
  server.begin();
  Serial.print("server is at ");
  Serial.println(Ethernet.localIP());
   
}

// Code đếm thời gian
void MyHandler()
{
  if (t1 == 1){s1++;}   
  if (t2 == 1){s2++;}
  if (t3 == 1){s3++;}
  if (t4 == 1){s4++;}
  if (t5 == 1){s5++;}
  if (t6 == 1){s6++;}
  if (t7 == 1){s7++;}
  if (t8 == 1){s8++;}
  if (t9 == 1){s9++;}
  if (t10 == 1){s10++;}
  if (t11 == 1){s11++;}
  if (t12 == 1){s12++;}
  if (t13 == 1){s13++;}
  if (t14 == 1){s14++;}
  if (t15 == 1){s15++;}
  if (t16 == 1){s16++;}
  if (t17 == 1){s17++;}
  if (t18 == 1){s18++;}
  if (t19 == 1){s19++;}
  if (t20 == 1){s20++;}      
}

// Code quy đổi ra giờ,phút
void quy_doi()
{
  h1=s1/3600;m1=(s1%3600)/60;
  h2=s2/3600;m2=(s2%3600)/60;
  h3=s3/3600;m3=(s3%3600)/60;
  h4=s4/3600;m4=(s4%3600)/60;
  h5=s5/3600;m5=(s5%3600)/60;
  h6=s6/3600;m6=(s6%3600)/60;
  h7=s7/3600;m7=(s7%3600)/60;
  h8=s8/3600;m8=(s8%3600)/60;
  h9=s9/3600;m9=(s9%3600)/60;
  h10=s10/3600;m10=(s10%3600)/60;
  h11=s11/3600;m11=(s11%3600)/60;
  h12=s12/3600;m12=(s12%3600)/60;
  h13=s13/3600;m13=(s13%3600)/60;
  h14=s14/3600;m14=(s14%3600)/60;
  h15=s15/3600;m15=(s15%3600)/60;
  h16=s16/3600;m16=(s16%3600)/60;
  h17=s17/3600;m17=(s17%3600)/60;
  h18=s18/3600;m18=(s18%3600)/60;
  h19=s19/3600;m19=(s19%3600)/60;
  h20=s20/3600;m20=(s20%3600)/60;
}

// Code giao tiếp nút xóa trên màn hình
void xoa_internet()
{
  if (readString.indexOf("?button1") >0){t1=s1=m1=h1=0;}
  if (readString.indexOf("?button2") >0){t2=s2=m2=h2=0;}
  if (readString.indexOf("?button3") >0){t3=s3=m3=h3=0;}           
  if (readString.indexOf("?button4") >0){t4=s4=m4=h4=0;}    
  if (readString.indexOf("?button5") >0){t5=s5=m5=h5=0;}
  if (readString.indexOf("?button6") >0){t6=s6=m6=h6=0;}
  if (readString.indexOf("?button7") >0){t7=s7=m7=h7=0;}
  if (readString.indexOf("?button8") >0){t8=s8=m8=h8=0;}
  if (readString.indexOf("?button9") >0){t9=s9=m9=h9=0;}           
  if (readString.indexOf("?button10") >0){t10=s10=m10=h10=0;}    
  if (readString.indexOf("?button11") >0){t11=s11=m11=h11=0;}
  if (readString.indexOf("?button12") >0){t12=s12=m12=h12=0;}
  if (readString.indexOf("?button13") >0){t13=s13=m13=h13=0;}
  if (readString.indexOf("?button14") >0){t14=s14=m14=h14=0;}
  if (readString.indexOf("?button15") >0){t15=s15=m15=h15=0;}
  if (readString.indexOf("?button16") >0){t16=s16=m16=h16=0;}
  if (readString.indexOf("?button17") >0){t17=s17=m17=h17=0;}
  if (readString.indexOf("?button18") >0){t18=s18=m18=h18=0;}
  if (readString.indexOf("?button19") >0){t19=s19=m19=h19=0;}
  if (readString.indexOf("?button20") >0){t20=s20=m20=h20=0;}  
}

// Code nhận tín hiệu từ UART đọc thẻ
void doc_the()
{
  if (Serial2.available()> 1)
  {
    data[0] = Serial2.read();
    data[1] = Serial2.read();
    z = data[0];   
    c = data[1];
    
// Phân biệt thứ tự thẻ
    if(c==1)
      {
       if(z1==0 && f1==0){r=c;z1=z;f1=c;c=0;z=0;}
       if(z1==z && f1==c){r=c;z1=0;f1=0;c=0;z=0;}
      }
    if(c==2)
      {
       if(z2==0 && f2==0){r=c;z2=z;f2=c;c=0;z=0;}
       if(z2==z && f2==c){r=c;z2=0;f2=0;c=0;z=0;}
      }   
    if(c==3)
      {
       if(z3==0 && f3==0){r=c;z3=z;f3=c;c=0;z=0;}
       if(z3==z && f3==c){r=c;z3=0;f3=0;c=0;z=0;}
      }
    if(c==4)
      {
       if(z4==0 && f4==0){r=c;z4=z;f4=c;c=0;z=0;}
       if(z4==z && f4==c){r=c;z4=0;f4=0;c=0;z=0;}
      }
    if(c==5)
      {
       if(z5==0 && f5==0){r=c;z5=z;f5=c;c=0;z=0;}
       if(z5==z && f5==c){r=c;z5=0;f5=0;c=0;z=0;}
      }  
    if(c==6)
      {
       if(z6==0 && f6==0){r=c;z6=z;f6=c;c=0;z=0;}
       if(z6==z && f6==c){r=c;z6=0;f6=0;c=0;z=0;}
      } 
    if(c==7)
      {
       if(z7==0 && f7==0){r=c;z7=z;f7=c;c=0;z=0;}
       if(z7==z && f7==c){r=c;z7=0;f7=0;c=0;z=0;}
      }
    if(c==8)
      {
       if(z8==0 && f8==0){r=c;z8=z;f8=c;c=0;z=0;}
       if(z8==z && f8==c){r=c;z8=0;f8=0;c=0;z=0;}
      }
    if(c==9)
      {
       if(z9==0 && f9==0){r=c;z9=z;f9=c;c=0;z=0;}
       if(z9==z && f9==c){r=c;z9=0;f9=0;c=0;z=0;}
      }
    if(c==10)
      {
       if(z10==0 && f10==0){r=c;z10=z;f10=c;c=0;z=0;}
       if(z10==z && f10==c){r=c;z10=0;f10=0;c=0;z=0;}
      }
    if(c==11)
      {
       if(z11==0 && f11==0){r=c;z11=z;f11=c;c=0;z=0;}
       if(z11==z && f11==c){r=c;z11=0;f11=0;c=0;z=0;}
      }
    if(c==12)
      {
       if(z12==0 && f12==0){r=c;z12=z;f12=c;c=0;z=0;}
       if(z12==z && f12==c){r=c;z12=0;f12=0;c=0;z=0;}
      }
    if(c==13)
      {
       if(z13==0 && f13==0){r=c;z13=z;f13=c;c=0;z=0;}
       if(z13==z && f13==c){r=c;z13=0;f13=0;c=0;z=0;}
      }
    if(c==14)
      {
       if(z14==0 && f14==0){r=c;z14=z;f14=c;c=0;z=0;}
       if(z14==z && f14==c){r=c;z14=0;f14=0;c=0;z=0;}
      }
    if(c==15)
      {
       if(z15==0 && f15==0){r=c;z15=z;f15=c;c=0;z=0;}
       if(z15==z && f15==c){r=c;z15=0;f15=0;c=0;z=0;}
      } 
    if(c==16)
      {
       if(z16==0 && f16==0){r=c;z16=z;f16=c;c=0;z=0;}
       if(z16==z && f16==c){r=c;z16=0;f16=0;c=0;z=0;}
      }            
    if(c==17)
      {
       if(z17==0 && f17==0){r=c;z17=z;f17=c;c=0;z=0;}
       if(z17==z && f17==c){r=c;z17=0;f17=0;c=0;z=0;}
      } 
    if(c==18)
      {
       if(z18==0 && f18==0){r=c;z18=z;f18=c;c=0;z=0;}
       if(z18==z && f18==c){r=c;z18=0;f18=0;c=0;z=0;}
      } 
    if(c==19)
      {
       if(z19==0 && f19==0){r=c;z19=z;f19=c;c=0;z=0;}
       if(z19==z && f19==c){r=c;z19=0;f19=0;c=0;z=0;}
      } 
    if(c==20)
      {
       if(z20==0 && f20==0){r=c;z20=z;f20=c;c=0;z=0;}
       if(z20==z && f20==c){r=c;z20=0;f20=0;c=0;z=0;}
      }
      
// Thẻ master tắt        
    if(c==21)
      {
       if(z==1 && c==21){r=c;z1=0;f1=0;z=0;c=0;}
       if(z==2 && c==21){r=c;z2=0;f2=0;z=0;c=0;}
       if(z==3 && c==21){r=c;z3=0;f3=0;z=0;c=0;}
       if(z==4 && c==21){r=c;z4=0;f4=0;z=0;c=0;}
       if(z==5 && c==21){r=c;z5=0;f5=0;z=0;c=0;}
       if(z==6 && c==21){r=c;z6=0;f6=0;z=0;c=0;}
       if(z==7 && c==21){r=c;z7=0;f7=0;z=0;c=0;}
       if(z==8 && c==21){r=c;z8=0;f8=0;z=0;c=0;}
       if(z==9 && c==21){r=c;z9=0;f9=0;z=0;c=0;}
       if(z==10 && c==21){r=c;z10=0;f10=0;z=0;c=0;}
       if(z==11 && c==21){r=c;z11=0;f11=0;z=0;c=0;}
       if(z==12 && c==21){r=c;z12=0;f12=0;z=0;c=0;}
       if(z==13 && c==21){r=c;z13=0;f13=0;z=0;c=0;}
       if(z==14 && c==21){r=c;z14=0;f14=0;z=0;c=0;}
       if(z==15 && c==21){r=c;z15=0;f15=0;z=0;c=0;}
       if(z==16 && c==21){r=c;z16=0;f16=0;z=0;c=0;}
       if(z==17 && c==21){r=c;z17=0;f17=0;z=0;c=0;}
       if(z==18 && c==21){r=c;z18=0;f18=0;z=0;c=0;}
       if(z==19 && c==21){r=c;z19=0;f19=0;z=0;c=0;}
       if(z==20 && c==21){r=c;z20=0;f20=0;z=0;c=0;}
      }    

// Phân biệt thứ tự máy quẹt thẻ 
    if(data[0]==1) // Chỗ quẹt 1
    {
      if(r==21)
      {
        if(t1==0 && r==21)
        {t1=1;k1=0;r=0;}
        if(t1==1 && r==21)
        {t1=0;k1=0;r=0;}
      }
      if(r==1 || r==2 || r==3 || r==4 || r==5 || r==6 || r==7 || r==8 || r==9 || r==10 || r==11 || r==12 || r==13 || r==14 || r==15 || r==16 || r==17 || r==18 || r==19 || r==20)
      {
        if(k1==0){t1=1;k1=r;r=0;}
        if(k1!=r)
        {
          if(r==1){z1=0;f1=0;r=0;}
          if(r==2){z2=0;f2=0;r=0;}
          if(r==3){z3=0;f3=0;r=0;}
          if(r==4){z4=0;f4=0;r=0;}
          if(r==5){z5=0;f5=0;r=0;}
          if(r==6){z6=0;f6=0;r=0;}
          if(r==7){z7=0;f7=0;r=0;}
          if(r==8){z8=0;f8=0;r=0;}
          if(r==9){z9=0;f9=0;r=0;}
          if(r==10){z10=0;f10=0;r=0;}
          if(r==11){z11=0;f11=0;r=0;}
          if(r==12){z12=0;f12=0;r=0;}
          if(r==13){z13=0;f13=0;r=0;}
          if(r==14){z14=0;f14=0;r=0;}
          if(r==15){z15=0;f15=0;r=0;}
          if(r==16){z16=0;f16=0;r=0;}
          if(r==17){z17=0;f17=0;r=0;}
          if(r==18){z18=0;f18=0;r=0;}
          if(r==19){z19=0;f19=0;r=0;}
          if(r==20){z20=0;f20=0;r=0;}
        }
        if(k1==r){t1=0;k1=0;r=0;}  
      }
    }

    if(data[0]==2) // Chỗ quẹt 2
    {
      if(r==21)
      {
        if(t2==0 && r==21)
        {t2=1;k2=0;r=0;}
        if(t2==1 && r==21)
        {t2=0;k2=0;r=0;}
      }
      if(r==1 || r==2 || r==3 || r==4 || r==5 || r==6 || r==7 || r==8 || r==9 || r==10 || r==11 || r==12 || r==13 || r==14 || r==15 || r==16 || r==17 || r==18 || r==19 || r==20)
      { 
        if(k2==0){t2=1;k2=r;r=0;}
        if(k2!=r)
        {
          if(r==1){z1=0;f1=0;r=0;}
          if(r==2){z2=0;f2=0;r=0;}
          if(r==3){z3=0;f3=0;r=0;}
          if(r==4){z4=0;f4=0;r=0;}
          if(r==5){z5=0;f5=0;r=0;}
          if(r==6){z6=0;f6=0;r=0;}
          if(r==7){z7=0;f7=0;r=0;}
          if(r==8){z8=0;f8=0;r=0;}
          if(r==9){z9=0;f9=0;r=0;}
          if(r==10){z10=0;f10=0;r=0;}
          if(r==11){z11=0;f11=0;r=0;}
          if(r==12){z12=0;f12=0;r=0;}
          if(r==13){z13=0;f13=0;r=0;}
          if(r==14){z14=0;f14=0;r=0;}
          if(r==15){z15=0;f15=0;r=0;}
          if(r==16){z16=0;f16=0;r=0;}
          if(r==17){z17=0;f17=0;r=0;}
          if(r==18){z18=0;f18=0;r=0;}
          if(r==19){z19=0;f19=0;r=0;}
          if(r==20){z20=0;f20=0;r=0;}
        }
        if(k2==r){t2=0;k2=0;r=0;}  
      }
    }

    if(data[0]==3) // Chỗ quẹt 3
    {
      if(r==21)
      {
        if(t3==0 && r==21)
        {t3=1;k3=0;r=0;}
        if(t3==1 && r==21)
        {t3=0;k3=0;r=0;}
      }
      if(r==1 || r==2 || r==3 || r==4 || r==5 || r==6 || r==7 || r==8 || r==9 || r==10 || r==11 || r==12 || r==13 || r==14 || r==15 || r==16 || r==17 || r==18 || r==19 || r==20)
      { 
        if(k3==0){t3=1;k3=r;r=0;}
        if(k3!=r)
        {
          if(r==1){z1=0;f1=0;r=0;}
          if(r==2){z2=0;f2=0;r=0;}
          if(r==3){z3=0;f3=0;r=0;}
          if(r==4){z4=0;f4=0;r=0;}
          if(r==5){z5=0;f5=0;r=0;}
          if(r==6){z6=0;f6=0;r=0;}
          if(r==7){z7=0;f7=0;r=0;}
          if(r==8){z8=0;f8=0;r=0;}
          if(r==9){z9=0;f9=0;r=0;}
          if(r==10){z10=0;f10=0;r=0;}
          if(r==11){z11=0;f11=0;r=0;}
          if(r==12){z12=0;f12=0;r=0;}
          if(r==13){z13=0;f13=0;r=0;}
          if(r==14){z14=0;f14=0;r=0;}
          if(r==15){z15=0;f15=0;r=0;}
          if(r==16){z16=0;f16=0;r=0;}
          if(r==17){z17=0;f17=0;r=0;}
          if(r==18){z18=0;f18=0;r=0;}
          if(r==19){z19=0;f19=0;r=0;}
          if(r==20){z20=0;f20=0;r=0;}
        }
        if(k3==r){t3=0;k3=0;r=0;}  
      }
    }

    if(data[0]==4) // Chỗ quẹt 4
    {
      if(r==21)
      {
        if(t4==0 && r==21)
        {t4=1;k4=0;r=0;}
        if(t4==1 && r==21)
        {t4=0;k4=0;r=0;}
      }
      if(r==1 || r==2 || r==3 || r==4 || r==5 || r==6 || r==7 || r==8 || r==9 || r==10 || r==11 || r==12 || r==13 || r==14 || r==15 || r==16 || r==17 || r==18 || r==19 || r==20)
      { 
        if(k4==0){t4=1;k4=r;r=0;}
        if(k4!=r)
        {
          if(r==1){z1=0;f1=0;r=0;}
          if(r==2){z2=0;f2=0;r=0;}
          if(r==3){z3=0;f3=0;r=0;}
          if(r==4){z4=0;f4=0;r=0;}
          if(r==5){z5=0;f5=0;r=0;}
          if(r==6){z6=0;f6=0;r=0;}
          if(r==7){z7=0;f7=0;r=0;}
          if(r==8){z8=0;f8=0;r=0;}
          if(r==9){z9=0;f9=0;r=0;}
          if(r==10){z10=0;f10=0;r=0;}
          if(r==11){z11=0;f11=0;r=0;}
          if(r==12){z12=0;f12=0;r=0;}
          if(r==13){z13=0;f13=0;r=0;}
          if(r==14){z14=0;f14=0;r=0;}
          if(r==15){z15=0;f15=0;r=0;}
          if(r==16){z16=0;f16=0;r=0;}
          if(r==17){z17=0;f17=0;r=0;}
          if(r==18){z18=0;f18=0;r=0;}
          if(r==19){z19=0;f19=0;r=0;}
          if(r==20){z20=0;f20=0;r=0;}
        }
        if(k4==r){t4=0;k4=0;r=0;}  
      }
    }

    if(data[0]==5) // Chỗ quẹt 5
    {
      if(r==21)
      {
        if(t5==0 && r==21)
        {t5=1;k5=0;r=0;}
        if(t5==1 && r==21)
        {t5=0;k5=0;r=0;}
      }
      if(r==1 || r==2 || r==3 || r==4 || r==5 || r==6 || r==7 || r==8 || r==9 || r==10 || r==11 || r==12 || r==13 || r==14 || r==15 || r==16 || r==17 || r==18 || r==19 || r==20)
      { 
        if(k5==0){t5=1;k5=r;r=0;}
        if(k5!=r)
        {
          if(r==1){z1=0;f1=0;r=0;}
          if(r==2){z2=0;f2=0;r=0;}
          if(r==3){z3=0;f3=0;r=0;}
          if(r==4){z4=0;f4=0;r=0;}
          if(r==5){z5=0;f5=0;r=0;}
          if(r==6){z6=0;f6=0;r=0;}
          if(r==7){z7=0;f7=0;r=0;}
          if(r==8){z8=0;f8=0;r=0;}
          if(r==9){z9=0;f9=0;r=0;}
          if(r==10){z10=0;f10=0;r=0;}
          if(r==11){z11=0;f11=0;r=0;}
          if(r==12){z12=0;f12=0;r=0;}
          if(r==13){z13=0;f13=0;r=0;}
          if(r==14){z14=0;f14=0;r=0;}
          if(r==15){z15=0;f15=0;r=0;}
          if(r==16){z16=0;f16=0;r=0;}
          if(r==17){z17=0;f17=0;r=0;}
          if(r==18){z18=0;f18=0;r=0;}
          if(r==19){z19=0;f19=0;r=0;}
          if(r==20){z20=0;f20=0;r=0;}
        }
        if(k5==r){t5=0;k5=0;r=0;}  
      }
    }

    if(data[0]==6) // Chỗ quẹt 6
    {
      if(r==21)
      {
        if(t6==0 && r==21)
        {t6=1;k6=0;r=0;}
        if(t6==1 && r==21)
        {t6=0;k6=0;r=0;}
      }
      if(r==1 || r==2 || r==3 || r==4 || r==5 || r==6 || r==7 || r==8 || r==9 || r==10 || r==11 || r==12 || r==13 || r==14 || r==15 || r==16 || r==17 || r==18 || r==19 || r==20)
      { 
        if(k6==0){t6=1;k6=r;r=0;}
        if(k6!=r)
        {
          if(r==1){z1=0;f1=0;r=0;}
          if(r==2){z2=0;f2=0;r=0;}
          if(r==3){z3=0;f3=0;r=0;}
          if(r==4){z4=0;f4=0;r=0;}
          if(r==5){z5=0;f5=0;r=0;}
          if(r==6){z6=0;f6=0;r=0;}
          if(r==7){z7=0;f7=0;r=0;}
          if(r==8){z8=0;f8=0;r=0;}
          if(r==9){z9=0;f9=0;r=0;}
          if(r==10){z10=0;f10=0;r=0;}
          if(r==11){z11=0;f11=0;r=0;}
          if(r==12){z12=0;f12=0;r=0;}
          if(r==13){z13=0;f13=0;r=0;}
          if(r==14){z14=0;f14=0;r=0;}
          if(r==15){z15=0;f15=0;r=0;}
          if(r==16){z16=0;f16=0;r=0;}
          if(r==17){z17=0;f17=0;r=0;}
          if(r==18){z18=0;f18=0;r=0;}
          if(r==19){z19=0;f19=0;r=0;}
          if(r==20){z20=0;f20=0;r=0;}
        }
        if(k6==r){t6=0;k6=0;r=0;}  
      }
    }

    if(data[0]==7) // Chỗ quẹt 7
    {
      if(r==21)
      {
        if(t7==0 && r==21)
        {t7=1;k7=0;r=0;}
        if(t7==1 && r==21)
        {t7=0;k7=0;r=0;}
      }
      if(r==1 || r==2 || r==3 || r==4 || r==5 || r==6 || r==7 || r==8 || r==9 || r==10 || r==11 || r==12 || r==13 || r==14 || r==15 || r==16 || r==17 || r==18 || r==19 || r==20)
      { 
        if(k7==0){t7=1;k7=r;r=0;}
        if(k7!=r)
        {
          if(r==1){z1=0;f1=0;r=0;}
          if(r==2){z2=0;f2=0;r=0;}
          if(r==3){z3=0;f3=0;r=0;}
          if(r==4){z4=0;f4=0;r=0;}
          if(r==5){z5=0;f5=0;r=0;}
          if(r==6){z6=0;f6=0;r=0;}
          if(r==7){z7=0;f7=0;r=0;}
          if(r==8){z8=0;f8=0;r=0;}
          if(r==9){z9=0;f9=0;r=0;}
          if(r==10){z10=0;f10=0;r=0;}
          if(r==11){z11=0;f11=0;r=0;}
          if(r==12){z12=0;f12=0;r=0;}
          if(r==13){z13=0;f13=0;r=0;}
          if(r==14){z14=0;f14=0;r=0;}
          if(r==15){z15=0;f15=0;r=0;}
          if(r==16){z16=0;f16=0;r=0;}
          if(r==17){z17=0;f17=0;r=0;}
          if(r==18){z18=0;f18=0;r=0;}
          if(r==19){z19=0;f19=0;r=0;}
          if(r==20){z20=0;f20=0;r=0;}
        }
        if(k7==r){t7=0;k7=0;r=0;}  
      }
    }

    if(data[0]==8) // Chỗ quẹt 8
    {
      if(r==21)
      {
        if(t8==0 && r==21)
        {t8=1;k8=0;r=0;}
        if(t8==1 && r==21)
        {t8=0;k8=0;r=0;}
      }
      if(r==1 || r==2 || r==3 || r==4 || r==5 || r==6 || r==7 || r==8 || r==9 || r==10 || r==11 || r==12 || r==13 || r==14 || r==15 || r==16 || r==17 || r==18 || r==19 || r==20)
      { 
        if(k8==0){t8=1;k8=r;r=0;}
        if(k8!=r)
        {
          if(r==1){z1=0;f1=0;r=0;}
          if(r==2){z2=0;f2=0;r=0;}
          if(r==3){z3=0;f3=0;r=0;}
          if(r==4){z4=0;f4=0;r=0;}
          if(r==5){z5=0;f5=0;r=0;}
          if(r==6){z6=0;f6=0;r=0;}
          if(r==7){z7=0;f7=0;r=0;}
          if(r==8){z8=0;f8=0;r=0;}
          if(r==9){z9=0;f9=0;r=0;}
          if(r==10){z10=0;f10=0;r=0;}
          if(r==11){z11=0;f11=0;r=0;}
          if(r==12){z12=0;f12=0;r=0;}
          if(r==13){z13=0;f13=0;r=0;}
          if(r==14){z14=0;f14=0;r=0;}
          if(r==15){z15=0;f15=0;r=0;}
          if(r==16){z16=0;f16=0;r=0;}
          if(r==17){z17=0;f17=0;r=0;}
          if(r==18){z18=0;f18=0;r=0;}
          if(r==19){z19=0;f19=0;r=0;}
          if(r==20){z20=0;f20=0;r=0;}
        }
        if(k8==r){t8=0;k8=0;r=0;}  
      }
    }

    if(data[0]==9) // Chỗ quẹt 9
    {
      if(r==21)
      {
        if(t9==0 && r==21)
        {t9=1;k9=0;r=0;}
        if(t9==1 && r==21)
        {t9=0;k9=0;r=0;}
      }
      if(r==1 || r==2 || r==3 || r==4 || r==5 || r==6 || r==7 || r==8 || r==9 || r==10 || r==11 || r==12 || r==13 || r==14 || r==15 || r==16 || r==17 || r==18 || r==19 || r==20)
      { 
        if(k9==0){t9=1;k9=r;r=0;}
        if(k9!=r)
        {
          if(r==1){z1=0;f1=0;r=0;}
          if(r==2){z2=0;f2=0;r=0;}
          if(r==3){z3=0;f3=0;r=0;}
          if(r==4){z4=0;f4=0;r=0;}
          if(r==5){z5=0;f5=0;r=0;}
          if(r==6){z6=0;f6=0;r=0;}
          if(r==7){z7=0;f7=0;r=0;}
          if(r==8){z8=0;f8=0;r=0;}
          if(r==9){z9=0;f9=0;r=0;}
          if(r==10){z10=0;f10=0;r=0;}
          if(r==11){z11=0;f11=0;r=0;}
          if(r==12){z12=0;f12=0;r=0;}
          if(r==13){z13=0;f13=0;r=0;}
          if(r==14){z14=0;f14=0;r=0;}
          if(r==15){z15=0;f15=0;r=0;}
          if(r==16){z16=0;f16=0;r=0;}
          if(r==17){z17=0;f17=0;r=0;}
          if(r==18){z18=0;f18=0;r=0;}
          if(r==19){z19=0;f19=0;r=0;}
          if(r==20){z20=0;f20=0;r=0;}
        }
        if(k9==r){t9=0;k9=0;r=0;}  
      }
    }

    if(data[0]==10) // Chỗ quẹt 10
    {
      if(r==21)
      {
        if(t10==0 && r==21)
        {t10=1;k10=0;r=0;}
        if(t10==1 && r==21)
        {t10=0;k10=0;r=0;}
      }
      if(r==1 || r==2 || r==3 || r==4 || r==5 || r==6 || r==7 || r==8 || r==9 || r==10 || r==11 || r==12 || r==13 || r==14 || r==15 || r==16 || r==17 || r==18 || r==19 || r==20)
      { 
        if(k10==0){t10=1;k10=r;r=0;}
        if(k10!=r)
        {
          if(r==1){z1=0;f1=0;r=0;}
          if(r==2){z2=0;f2=0;r=0;}
          if(r==3){z3=0;f3=0;r=0;}
          if(r==4){z4=0;f4=0;r=0;}
          if(r==5){z5=0;f5=0;r=0;}
          if(r==6){z6=0;f6=0;r=0;}
          if(r==7){z7=0;f7=0;r=0;}
          if(r==8){z8=0;f8=0;r=0;}
          if(r==9){z9=0;f9=0;r=0;}
          if(r==10){z10=0;f10=0;r=0;}
          if(r==11){z11=0;f11=0;r=0;}
          if(r==12){z12=0;f12=0;r=0;}
          if(r==13){z13=0;f13=0;r=0;}
          if(r==14){z14=0;f14=0;r=0;}
          if(r==15){z15=0;f15=0;r=0;}
          if(r==16){z16=0;f16=0;r=0;}
          if(r==17){z17=0;f17=0;r=0;}
          if(r==18){z18=0;f18=0;r=0;}
          if(r==19){z19=0;f19=0;r=0;}
          if(r==20){z20=0;f20=0;r=0;}
        }
        if(k10==r){t10=0;k10=0;r=0;}  
      }
    }

    if(data[0]==11) // Chỗ quẹt 11
    {
      if(r==21)
      {
        if(t11==0 && r==21)
        {t11=1;k11=0;r=0;}
        if(t11==1 && r==21)
        {t11=0;k11=0;r=0;}
      }
      if(r==1 || r==2 || r==3 || r==4 || r==5 || r==6 || r==7 || r==8 || r==9 || r==10 || r==11 || r==12 || r==13 || r==14 || r==15 || r==16 || r==17 || r==18 || r==19 || r==20)
      { 
        if(k11==0){t11=1;k11=r;r=0;}
        if(k11!=r)
        {
          if(r==1){z1=0;f1=0;r=0;}
          if(r==2){z2=0;f2=0;r=0;}
          if(r==3){z3=0;f3=0;r=0;}
          if(r==4){z4=0;f4=0;r=0;}
          if(r==5){z5=0;f5=0;r=0;}
          if(r==6){z6=0;f6=0;r=0;}
          if(r==7){z7=0;f7=0;r=0;}
          if(r==8){z8=0;f8=0;r=0;}
          if(r==9){z9=0;f9=0;r=0;}
          if(r==10){z10=0;f10=0;r=0;}
          if(r==11){z11=0;f11=0;r=0;}
          if(r==12){z12=0;f12=0;r=0;}
          if(r==13){z13=0;f13=0;r=0;}
          if(r==14){z14=0;f14=0;r=0;}
          if(r==15){z15=0;f15=0;r=0;}
          if(r==16){z16=0;f16=0;r=0;}
          if(r==17){z17=0;f17=0;r=0;}
          if(r==18){z18=0;f18=0;r=0;}
          if(r==19){z19=0;f19=0;r=0;}
          if(r==20){z20=0;f20=0;r=0;}
        }
        if(k11==r){t11=0;k11=0;r=0;}  
      }
    }

    if(data[0]==12) // Chỗ quẹt 12
    {
      if(r==21)
      {
        if(t12==0 && r==21)
        {t12=1;k12=0;r=0;}
        if(t12==1 && r==21)
        {t12=0;k12=0;r=0;}
      }
      if(r==1 || r==2 || r==3 || r==4 || r==5 || r==6 || r==7 || r==8 || r==9 || r==10 || r==11 || r==12 || r==13 || r==14 || r==15 || r==16 || r==17 || r==18 || r==19 || r==20)
      {  
        if(k12==0){t12=1;k12=r;r=0;}
        if(k12!=r)
        {
          if(r==1){z1=0;f1=0;r=0;}
          if(r==2){z2=0;f2=0;r=0;}
          if(r==3){z3=0;f3=0;r=0;}
          if(r==4){z4=0;f4=0;r=0;}
          if(r==5){z5=0;f5=0;r=0;}
          if(r==6){z6=0;f6=0;r=0;}
          if(r==7){z7=0;f7=0;r=0;}
          if(r==8){z8=0;f8=0;r=0;}
          if(r==9){z9=0;f9=0;r=0;}
          if(r==10){z10=0;f10=0;r=0;}
          if(r==11){z11=0;f11=0;r=0;}
          if(r==12){z12=0;f12=0;r=0;}
          if(r==13){z13=0;f13=0;r=0;}
          if(r==14){z14=0;f14=0;r=0;}
          if(r==15){z15=0;f15=0;r=0;}
          if(r==16){z16=0;f16=0;r=0;}
          if(r==17){z17=0;f17=0;r=0;}
          if(r==18){z18=0;f18=0;r=0;}
          if(r==19){z19=0;f19=0;r=0;}
          if(r==20){z20=0;f20=0;r=0;}
        }
        if(k12==r){t12=0;k12=0;r=0;}  
      }
    }

    if(data[0]==13) // Chỗ quẹt 13
    {
      if(r==21)
      {
        if(t13==0 && r==21)
        {t13=1;k13=0;r=0;}
        if(t13==1 && r==21)
        {t13=0;k13=0;r=0;}
      }
      if(r==1 || r==2 || r==3 || r==4 || r==5 || r==6 || r==7 || r==8 || r==9 || r==10 || r==11 || r==12 || r==13 || r==14 || r==15 || r==16 || r==17 || r==18 || r==19 || r==20)
      {        
        if(k13==0){t13=1;k13=r;r=0;}
        if(k13!=r)
        {
          if(r==1){z1=0;f1=0;r=0;}
          if(r==2){z2=0;f2=0;r=0;}
          if(r==3){z3=0;f3=0;r=0;}
          if(r==4){z4=0;f4=0;r=0;}
          if(r==5){z5=0;f5=0;r=0;}
          if(r==6){z6=0;f6=0;r=0;}
          if(r==7){z7=0;f7=0;r=0;}
          if(r==8){z8=0;f8=0;r=0;}
          if(r==9){z9=0;f9=0;r=0;}
          if(r==10){z10=0;f10=0;r=0;}
          if(r==11){z11=0;f11=0;r=0;}
          if(r==12){z12=0;f12=0;r=0;}
          if(r==13){z13=0;f13=0;r=0;}
          if(r==14){z14=0;f14=0;r=0;}
          if(r==15){z15=0;f15=0;r=0;}
          if(r==16){z16=0;f16=0;r=0;}
          if(r==17){z17=0;f17=0;r=0;}
          if(r==18){z18=0;f18=0;r=0;}
          if(r==19){z19=0;f19=0;r=0;}
          if(r==20){z20=0;f20=0;r=0;}
        }
        if(k13==r){t13=0;k13=0;r=0;}  
      }
    }

    if(data[0]==14) // Chỗ quẹt 14
    {
      if(r==21)
      {
        if(t14==0 && r==21)
        {t14=1;k14=0;r=0;}
        if(t14==1 && r==21)
        {t14=0;k14=0;r=0;}
      }
      if(r==1 || r==2 || r==3 || r==4 || r==5 || r==6 || r==7 || r==8 || r==9 || r==10 || r==11 || r==12 || r==13 || r==14 || r==15 || r==16 || r==17 || r==18 || r==19 || r==20)
      {  
        if(k14==0){t14=1;k14=r;r=0;}
        if(k14!=r)
        {
          if(r==1){z1=0;f1=0;r=0;}
          if(r==2){z2=0;f2=0;r=0;}
          if(r==3){z3=0;f3=0;r=0;}
          if(r==4){z4=0;f4=0;r=0;}
          if(r==5){z5=0;f5=0;r=0;}
          if(r==6){z6=0;f6=0;r=0;}
          if(r==7){z7=0;f7=0;r=0;}
          if(r==8){z8=0;f8=0;r=0;}
          if(r==9){z9=0;f9=0;r=0;}
          if(r==10){z10=0;f10=0;r=0;}
          if(r==11){z11=0;f11=0;r=0;}
          if(r==12){z12=0;f12=0;r=0;}
          if(r==13){z13=0;f13=0;r=0;}
          if(r==14){z14=0;f14=0;r=0;}
          if(r==15){z15=0;f15=0;r=0;}
          if(r==16){z16=0;f16=0;r=0;}
          if(r==17){z17=0;f17=0;r=0;}
          if(r==18){z18=0;f18=0;r=0;}
          if(r==19){z19=0;f19=0;r=0;}
          if(r==20){z20=0;f20=0;r=0;}
        }
        if(k14==r){t14=0;k14=0;r=0;}  
      }
    }

    if(data[0]==15) // Chỗ quẹt 15
    {
      if(r==21)
      {
        if(t15==0 && r==21)
        {t15=1;k15=0;r=0;}
        if(t15==1 && r==21)
        {t15=0;k15=0;r=0;}
      }
      if(r==1 || r==2 || r==3 || r==4 || r==5 || r==6 || r==7 || r==8 || r==9 || r==10 || r==11 || r==12 || r==13 || r==14 || r==15 || r==16 || r==17 || r==18 || r==19 || r==20)
      {            
        if(k15==0){t15=1;k15=r;r=0;}
        if(k15!=r)
        {
          if(r==1){z1=0;f1=0;r=0;}
          if(r==2){z2=0;f2=0;r=0;}
          if(r==3){z3=0;f3=0;r=0;}
          if(r==4){z4=0;f4=0;r=0;}
          if(r==5){z5=0;f5=0;r=0;}
          if(r==6){z6=0;f6=0;r=0;}
          if(r==7){z7=0;f7=0;r=0;}
          if(r==8){z8=0;f8=0;r=0;}
          if(r==9){z9=0;f9=0;r=0;}
          if(r==10){z10=0;f10=0;r=0;}
          if(r==11){z11=0;f11=0;r=0;}
          if(r==12){z12=0;f12=0;r=0;}
          if(r==13){z13=0;f13=0;r=0;}
          if(r==14){z14=0;f14=0;r=0;}
          if(r==15){z15=0;f15=0;r=0;}
          if(r==16){z16=0;f16=0;r=0;}
          if(r==17){z17=0;f17=0;r=0;}
          if(r==18){z18=0;f18=0;r=0;}
          if(r==19){z19=0;f19=0;r=0;}
          if(r==20){z20=0;f20=0;r=0;}
        }
        if(k15==r){t15=0;k15=0;r=0;}  
      }
    }

    if(data[0]==16) // Chỗ quẹt 16
    {
      if(r==21)
      {
        if(t16==0 && r==21)
        {t16=1;k16=0;r=0;}
        if(t16==1 && r==21)
        {t16=0;k16=0;r=0;}
      }
      if(r==1 || r==2 || r==3 || r==4 || r==5 || r==6 || r==7 || r==8 || r==9 || r==10 || r==11 || r==12 || r==13 || r==14 || r==15 || r==16 || r==17 || r==18 || r==19 || r==20)
      {         
        if(k16==0){t16=1;k16=r;r=0;}
        if(k16!=r)
        {
          if(r==1){z1=0;f1=0;r=0;}
          if(r==2){z2=0;f2=0;r=0;}
          if(r==3){z3=0;f3=0;r=0;}
          if(r==4){z4=0;f4=0;r=0;}
          if(r==5){z5=0;f5=0;r=0;}
          if(r==6){z6=0;f6=0;r=0;}
          if(r==7){z7=0;f7=0;r=0;}
          if(r==8){z8=0;f8=0;r=0;}
          if(r==9){z9=0;f9=0;r=0;}
          if(r==10){z10=0;f10=0;r=0;}
          if(r==11){z11=0;f11=0;r=0;}
          if(r==12){z12=0;f12=0;r=0;}
          if(r==13){z13=0;f13=0;r=0;}
          if(r==14){z14=0;f14=0;r=0;}
          if(r==15){z15=0;f15=0;r=0;}
          if(r==16){z16=0;f16=0;r=0;}
          if(r==17){z17=0;f17=0;r=0;}
          if(r==18){z18=0;f18=0;r=0;}
          if(r==19){z19=0;f19=0;r=0;}
          if(r==20){z20=0;f20=0;r=0;}
        }
        if(k16==r){t16=0;k16=0;r=0;}  
      }
    }

    if(data[0]==17) // Chỗ quẹt 17
    {
      if(r==21)
      {
        if(t17==0 && r==21)
        {t17=1;k17=0;r=0;}
        if(t17==1 && r==21)
        {t17=0;k17=0;r=0;}
      }
      if(r==1 || r==2 || r==3 || r==4 || r==5 || r==6 || r==7 || r==8 || r==9 || r==10 || r==11 || r==12 || r==13 || r==14 || r==15 || r==16 || r==17 || r==18 || r==19 || r==20)
      {       
        if(k17==0){t17=1;k17=r;r=0;}
        if(k17!=r)
        {
          if(r==1){z1=0;f1=0;r=0;}
          if(r==2){z2=0;f2=0;r=0;}
          if(r==3){z3=0;f3=0;r=0;}
          if(r==4){z4=0;f4=0;r=0;}
          if(r==5){z5=0;f5=0;r=0;}
          if(r==6){z6=0;f6=0;r=0;}
          if(r==7){z7=0;f7=0;r=0;}
          if(r==8){z8=0;f8=0;r=0;}
          if(r==9){z9=0;f9=0;r=0;}
          if(r==10){z10=0;f10=0;r=0;}
          if(r==11){z11=0;f11=0;r=0;}
          if(r==12){z12=0;f12=0;r=0;}
          if(r==13){z13=0;f13=0;r=0;}
          if(r==14){z14=0;f14=0;r=0;}
          if(r==15){z15=0;f15=0;r=0;}
          if(r==16){z16=0;f16=0;r=0;}
          if(r==17){z17=0;f17=0;r=0;}
          if(r==18){z18=0;f18=0;r=0;}
          if(r==19){z19=0;f19=0;r=0;}
          if(r==20){z20=0;f20=0;r=0;}
        }
        if(k17==r){t17=0;k17=0;r=0;}  
      }
    }

    if(data[0]==18) // Chỗ quẹt 18
    {
      if(r==21)
      {
        if(t18==0 && r==21)
        {t18=1;k18=0;r=0;}
        if(t18==1 && r==21)
        {t18=0;k18=0;r=0;}
      }
      if(r==1 || r==2 || r==3 || r==4 || r==5 || r==6 || r==7 || r==8 || r==9 || r==10 || r==11 || r==12 || r==13 || r==14 || r==15 || r==16 || r==17 || r==18 || r==19 || r==20)
      {      
        if(k18==0){t18=1;k18=r;r=0;}
        if(k18!=r)
        {
          if(r==1){z1=0;f1=0;r=0;}
          if(r==2){z2=0;f2=0;r=0;}
          if(r==3){z3=0;f3=0;r=0;}
          if(r==4){z4=0;f4=0;r=0;}
          if(r==5){z5=0;f5=0;r=0;}
          if(r==6){z6=0;f6=0;r=0;}
          if(r==7){z7=0;f7=0;r=0;}
          if(r==8){z8=0;f8=0;r=0;}
          if(r==9){z9=0;f9=0;r=0;}
          if(r==10){z10=0;f10=0;r=0;}
          if(r==11){z11=0;f11=0;r=0;}
          if(r==12){z12=0;f12=0;r=0;}
          if(r==13){z13=0;f13=0;r=0;}
          if(r==14){z14=0;f14=0;r=0;}
          if(r==15){z15=0;f15=0;r=0;}
          if(r==16){z16=0;f16=0;r=0;}
          if(r==17){z17=0;f17=0;r=0;}
          if(r==18){z18=0;f18=0;r=0;}
          if(r==19){z19=0;f19=0;r=0;}
          if(r==20){z20=0;f20=0;r=0;}
        }
        if(k18==r){t18=0;k18=0;r=0;}   
      }
    }

    if(data[0]==19) // Chỗ quẹt 19
    {
      if(r==21)
      {
        if(t19==0 && r==21)
        {t19=1;k19=0;r=0;}
        if(t19==1 && r==21)
        {t19=0;k19=0;r=0;}
      }
      if(r==1 || r==2 || r==3 || r==4 || r==5 || r==6 || r==7 || r==8 || r==9 || r==10 || r==11 || r==12 || r==13 || r==14 || r==15 || r==16 || r==17 || r==18 || r==19 || r==20)
      {
        if(k19==0){t19=1;k19=r;r=0;}
        if(k19!=r)
        {
          if(r==1){z1=0;f1=0;r=0;}
          if(r==2){z2=0;f2=0;r=0;}
          if(r==3){z3=0;f3=0;r=0;}
          if(r==4){z4=0;f4=0;r=0;}
          if(r==5){z5=0;f5=0;r=0;}
          if(r==6){z6=0;f6=0;r=0;}
          if(r==7){z7=0;f7=0;r=0;}
          if(r==8){z8=0;f8=0;r=0;}
          if(r==9){z9=0;f9=0;r=0;}
          if(r==10){z10=0;f10=0;r=0;}
          if(r==11){z11=0;f11=0;r=0;}
          if(r==12){z12=0;f12=0;r=0;}
          if(r==13){z13=0;f13=0;r=0;}
          if(r==14){z14=0;f14=0;r=0;}
          if(r==15){z15=0;f15=0;r=0;}
          if(r==16){z16=0;f16=0;r=0;}
          if(r==17){z17=0;f17=0;r=0;}
          if(r==18){z18=0;f18=0;r=0;}
          if(r==19){z19=0;f19=0;r=0;}
          if(r==20){z20=0;f20=0;r=0;}
        }
        if(k19==r){t19=0;k19=0;r=0;}
      }  
    }

    if(data[0]==20) // Chỗ quẹt 20
    {
      if(r==21)
      {
        if(t20==0 && r==21)
        {t20=1;k20=0;r=0;}
        if(t20==1 && r==21)
        {t20=0;k20=0;r=0;}
      }
      if(r==1 || r==2 || r==3 || r==4 || r==5 || r==6 || r==7 || r==8 || r==9 || r==10 || r==11 || r==12 || r==13 || r==14 || r==15 || r==16 || r==17 || r==18 || r==19 || r==20)
      {
        if(k20==0){t20=1;k20=r;r=0;}
        if(k20!=r)
        {
          if(r==1){z1=0;f1=0;r=0;}
          if(r==2){z2=0;f2=0;r=0;}
          if(r==3){z3=0;f3=0;r=0;}
          if(r==4){z4=0;f4=0;r=0;}
          if(r==5){z5=0;f5=0;r=0;}
          if(r==6){z6=0;f6=0;r=0;}
          if(r==7){z7=0;f7=0;r=0;}
          if(r==8){z8=0;f8=0;r=0;}
          if(r==9){z9=0;f9=0;r=0;}
          if(r==10){z10=0;f10=0;r=0;}
          if(r==11){z11=0;f11=0;r=0;}
          if(r==12){z12=0;f12=0;r=0;}
          if(r==13){z13=0;f13=0;r=0;}
          if(r==14){z14=0;f14=0;r=0;}
          if(r==15){z15=0;f15=0;r=0;}
          if(r==16){z16=0;f16=0;r=0;}
          if(r==17){z17=0;f17=0;r=0;}
          if(r==18){z18=0;f18=0;r=0;}
          if(r==19){z19=0;f19=0;r=0;}
          if(r==20){z20=0;f20=0;r=0;}
        }
        if(k20==r){t20=0;k20=0;r=0;}  
      }
    }    
  }
  
  data[0] = 0;
  data[1] = 0;
}

// Code on/off out relay
void out()
{
  if(t1==1){digitalWrite(out1,LOW);}else {digitalWrite(out1,HIGH);}
  if(t2==1){digitalWrite(out2,LOW);}else {digitalWrite(out2,HIGH);}
  if(t3==1){digitalWrite(out3,LOW);}else {digitalWrite(out3,HIGH);}
  if(t4==1){digitalWrite(out4,LOW);}else {digitalWrite(out4,HIGH);}
  if(t5==1){digitalWrite(out5,LOW);}else {digitalWrite(out5,HIGH);}
  if(t6==1){digitalWrite(out6,LOW);}else {digitalWrite(out6,HIGH);}
  if(t7==1){digitalWrite(out7,LOW);}else {digitalWrite(out7,HIGH);}
  if(t8==1){digitalWrite(out8,LOW);}else {digitalWrite(out8,HIGH);}
  if(t9==1){digitalWrite(out9,LOW);}else {digitalWrite(out9,HIGH);}
  if(t10==1){digitalWrite(out10,LOW);}else {digitalWrite(out10,HIGH);}
  if(t11==1){digitalWrite(out11,LOW);}else {digitalWrite(out11,HIGH);}
  if(t12==1){digitalWrite(out12,LOW);}else {digitalWrite(out12,HIGH);}
  if(t13==1){digitalWrite(out13,LOW);}else {digitalWrite(out13,HIGH);}
  if(t14==1){digitalWrite(out14,LOW);}else {digitalWrite(out14,HIGH);}
  if(t15==1){digitalWrite(out15,LOW);}else {digitalWrite(out15,HIGH);}
  if(t16==1){digitalWrite(out16,LOW);}else {digitalWrite(out16,HIGH);}
  if(t17==1){digitalWrite(out17,LOW);}else {digitalWrite(out17,HIGH);}
  if(t18==1){digitalWrite(out18,LOW);}else {digitalWrite(out18,HIGH);}
  if(t19==1){digitalWrite(out19,LOW);}else {digitalWrite(out19,HIGH);}
  if(t20==1){digitalWrite(out20,LOW);}else {digitalWrite(out20,HIGH);}
}

// Code Webser
void websever()
{
  EthernetClient client = server.available();
  if (client)
  {
    while (client.connected()) {   
      if (client.available()) {
        char c = client.read();
     
        //read char by char HTTP request
        if (readString.length() < 100) {
          //store characters to string
          readString += c;
          //Serial.print(c);
         }

         //if HTTP request has ended
         if (c == '\n') 
         {          
           Serial.println(readString); //print to serial monitor for debuging
           client.println("HTTP/1.1 200 OK"); //send new page
           client.println("Content-Type: text/html");            
           client.println();     
           client.println("<HTML>");
           client.println("<HEAD>");
           client.println("<meta name='apple-mobile-web-app-capable' content='yes' />");
           client.println("<meta name='apple-mobile-web-app-status-bar-style' content='black-translucent' />");
           client.println("<link rel='stylesheet' type='text/css' href='http://randomnerdtutorials.com/ethernetcss.css' />");
           client.println("<TITLE>Man hinh quet the</TITLE>");
           client.println("</HEAD>");
           client.println("<BODY>");
           client.println("<H1>20 VI TRI</H1>");
           //client.println("<br />");  
           //client.println("<H2>20 vị tri      </H2>");
           //client.println("<br />");
           client.println("<a href=\"/Resfresh\"\">CAP NHAT THOI GIAN</a>");

           //client.println("Refresh: 1");
    
           client.println("<br />");
           client.println("<br />");
           client.print("<a href=\"/?button1\"\">XOA 1</a>");
           client.print(" ");client.print(" ");client.print(" ");
           client.print(" THOI GIAN 1 la: ");
           client.print(" ");client.print(" ");client.print(" ");
           client.print(h1);
           client.print(" : ");
           client.print(m1);

     
           client.println("<br />");
           client.println("<br />");
           client.print("<a href=\"/?button2\"\">XOA 2</a>");
           client.print(" ");client.print(" ");client.print(" ");
           client.print(" THOI GIAN 2 la: ");
           client.print(" ");client.print(" ");client.print(" ");
           client.print(h2);
           client.print(" : ");
           client.print(m2);
           
     
           client.println("<br />");
           client.println("<br />");
           client.print("<a href=\"/?button3\"\">XOA 3</a>");
           client.print(" ");client.print(" ");client.print(" ");
           client.print(" THOI GIAN 3 la: ");
           client.print(" ");client.print(" ");client.print(" ");
           client.print(h3);
           client.print(" : ");
           client.print(m3);
                     
  
           client.println("<br />");
           client.println("<br />");
           client.print("<a href=\"/?button4\"\">XOA 4</a>");
           client.print(" ");client.print(" ");client.print(" ");
           client.print(" THOI GIAN 4 la: ");
           client.print(" ");client.print(" ");client.print(" ");
           client.print(h4);
           client.print(" : ");
           client.print(m4);
        
    
           client.println("<br />");
           client.println("<br />");
           client.print("<a href=\"/?button5\"\">XOA 5</a>");
           client.print(" ");client.print(" ");client.print(" ");
           client.print(" THOI GIAN 5 la: ");
           client.print(" ");client.print(" ");client.print(" ");
           client.print(h5);
           client.print(" : ");
           client.print(m5);
   
   
           client.println("<br />");
           client.println("<br />");
           client.print("<a href=\"/?button6\"\">XOA 6</a>");
           client.print(" ");client.print(" ");client.print(" ");          
           client.print(" THOI GIAN 6 la: ");
           client.print(" ");client.print(" ");client.print(" ");  
           client.print(h6);
           client.print(" : ");
           client.print(m6);
  
 
           client.println("<br />");
           client.println("<br />");
           client.print("<a href=\"/?button7\"\">XOA 7</a>");
           client.print(" ");client.print(" ");client.print(" ");
           client.print(" THOI GIAN 7 la: ");
           client.print(" ");client.print(" ");client.print(" ");
           client.print(h7);
           client.print(" : ");
           client.print(m7);
   
  
           client.println("<br />");
           client.println("<br />");
           client.print("<a href=\"/?button8\"\">XOA 8</a>");
           client.print(" ");client.print(" ");client.print(" ");
           client.print(" THOI GIAN 8 la: ");
           client.print(" ");client.print(" ");client.print(" ");
           client.print(h8);
           client.print(" : ");
           client.print(m8);
        
   
           client.println("<br />");
           client.println("<br />");
           client.print("<a href=\"/?button9\"\">XOA 9</a>");
           client.print(" ");client.print(" ");client.print(" ");
           client.print(" THOI GIAN 9 la: ");
           client.print(" ");client.print(" ");client.print(" ");
           client.print(h9);
           client.print(" : ");
           client.print(m9);
         
   
           client.println("<br />");
           client.println("<br />");
           client.print("<a href=\"/?button10\"\">XOA 10</a>");
           client.print(" ");client.print(" ");client.print(" ");
           client.print(" THOI GIAN 10 la: ");
           client.print(" ");client.print(" ");client.print(" ");
           client.print(h10);
           client.print(" : ");
           client.print(m10);
         
    
           client.println("<br />");
           client.println("<br />");
           client.print("<a href=\"/?button11\"\">XOA 11</a>");
           client.print(" ");client.print(" ");client.print(" ");
           client.print(" THOI GIAN 11 la: ");
           client.print(" ");client.print(" ");client.print(" ");
           client.print(h11);
           client.print(" : ");
           client.print(m11);
                                             
    
           client.println("<br />");
           client.println("<br />");
           client.print("<a href=\"/?button12\"\">XOA 12</a>");
           client.print(" ");client.print(" ");client.print(" ");
           client.print(" THOI GIAN 12 la: ");
           client.print(" ");client.print(" ");client.print(" ");
           client.print(h12);
           client.print(" : ");
           client.print(m12);

   
           client.println("<br />");
           client.println("<br />");
           client.print("<a href=\"/?button13\"\">XOA 13</a>");
           client.print(" ");client.print(" ");client.print(" ");
           client.print(" THOI GIAN 13 la: ");
           client.print(" ");client.print(" ");client.print(" ");
           client.print(h13);
           client.print(" : ");
           client.print(m13);

   
           client.println("<br />");
           client.println("<br />");
           client.print("<a href=\"/?button14\"\">XOA 14</a>");
           client.print(" ");client.print(" ");client.print(" ");
           client.print(" THOI GIAN 14 la: ");
           client.print(" ");client.print(" ");client.print(" ");
           client.print(h14);
           client.print(" : ");
           client.print(m14);


           client.println("<br />");
           client.println("<br />");
           client.print("<a href=\"/?button15\"\">XOA 15</a>");
           client.print(" ");client.print(" ");client.print(" ");
           client.print(" THOI GIAN 15 la: ");
           client.print(" ");client.print(" ");client.print(" ");
           client.print(h15);
           client.print(" : ");
           client.print(m15);
           

           client.println("<br />");
           client.println("<br />");
           client.print("<a href=\"/?button16\"\">XOA 16</a>");
           client.print(" ");client.print(" ");client.print(" ");
           client.print(" THOI GIAN 16 la: ");
           client.print(" ");client.print(" ");client.print(" ");
           client.print(h16);
           client.print(" : ");
           client.print(m16);
           

           client.println("<br />");
           client.println("<br />");
           client.print("<a href=\"/?button17\"\">XOA 17</a>");
           client.print(" ");client.print(" ");client.print(" ");
           client.print(" THOI GIAN 17 la: ");
           client.print(" ");client.print(" ");client.print(" ");
           client.print(h17);
           client.print(" : ");
           client.print(m17);


           client.println("<br />");
           client.println("<br />");
           client.print("<a href=\"/?button18\"\">XOA 18</a>");
           client.print(" ");client.print(" ");client.print(" ");
           client.print(" THOI GIAN 18 la: ");
           client.print(" ");client.print(" ");client.print(" ");
           client.print(h18);
           client.print(" : ");
           client.print(m18);
           

           client.println("<br />");
           client.println("<br />");
           client.print("<a href=\"/?button19\"\">XOA 19</a>");
           client.print(" ");client.print(" ");client.print(" ");
           client.print(" THOI GIAN 19 la: ");
           client.print(" ");client.print(" ");client.print(" ");
           client.print(h19);
           client.print(" : ");
           client.print(m19);
           

           client.println("<br />");
           client.println("<br />");
           client.print("<a href=\"/?button20\"\">XOA 20</a>");
           client.print(" ");client.print(" ");client.print(" ");
           client.print(" THOI GIAN 20 la: ");
           client.print(" ");client.print(" ");client.print(" ");
           client.print(h20);
           client.print(" : ");
           client.print(m20);

           client.println("</BODY>");
           client.println("</HTML>");
     
           delay(1);
           //stopping client
           client.stop();
           xoa_internet();
           readString = "";
         }
      }
    }
  }
}

void loop() 
{  
  websever();
  doc_the();
  quy_doi();
  out();
}

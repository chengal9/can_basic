/*this is .c file for can sanding and receving data.
test for branch 
*/
#include "mcp_can.h"
#include <SPI.h>

const int SPI_CS_PIN = 9;
MCP_CAN CAN(SPI_CS_PIN); //cs pin 9 
void door_lock();
void singledoor();
void setup() {
  DDRC=0x00;
  //PORTB=0x00;
  // put your setup code here, to run once:
  Serial.begin(115200);
   while (CAN_OK != CAN.begin(CAN_500KBPS))              // init can bus : baudrate = 500k
    {
        Serial.println("CAN BUS Shield init fail");
        Serial.println(" Init CAN BUS Shield again");
        delay(100);
    }
    Serial.println("CAN BUS Shield init ok!");
pinMode(2,INPUT);

//digitalWrite(2,LOW,HIGH)

// how are you
}

unsigned char opened[]={'1','2'};
unsigned char closed = 0;

//# define closed 0
//char closed='0';
int temp1=0;
int temp2=0;
int temp3=0;
int temp4=0;
void loop() {
  // put your main code here, to run repeatedly:
      //      ( id , standard/extended, data_length, data)
      //                 0       1
//door_lock();
singledoor();
delay(1000);
      
}

void singledoor()
{

if((digitalRead(2)==0)&&(temp1==0))
{
CAN.sendMsgBuf(0x01, 0, 1, opened);

  temp1=1;
  }

  else if((digitalRead(2)!=0)&&(temp1==1))
  {
CAN.sendMsgBuf(0x01, 0, 1, &closed);

  temp1=0;
  
        
    }

  
  }

/*void door_lock()
{
 // Door_status# 1 
if(((PINB&(1<<0))==0)&&(temp1==0))
{
CAN.sendMsgBuf(0x01, 0, 1, &opened);

  temp1=1;
  }

  else if(((PINB&(1<<0))!=0)&&(temp1==1))
  {
CAN.sendMsgBuf(0x01, 0, 1, &closed);

  temp1=0;
        
    }
// Door_status# 2

if(((PINB&(1<<1))==0)&&(temp2==0))
{
CAN.sendMsgBuf(0x02, 0, 1, &opened);

  temp2=1;
  }

  else if(((PINB&(1<<1))!=0)&&(temp2==1))
  {
CAN.sendMsgBuf(0x02, 0, 1, &closed);

  temp2=0;
        
    }

 
if(((PINB&(1<<2))==0)&&(temp3==0))
{
CAN.sendMsgBuf(0x03, 0, 1, &opened);

  temp3=1;
  }

  else if(((PINB&(1<<2))!=0)&&(temp3==1))
  {
CAN.sendMsgBuf(0x03, 0, 1, &closed);

  temp3=0;
        
    }
// Door_status# 4

if(((PINB&(1<<3))==0)&&(temp4==0))
{
CAN.sendMsgBuf(0x04, 0, 1, &opened);

  temp4=1;
  }

  else if(((PINB&(1<<3))!=0)&&(temp4==1))
  {
CAN.sendMsgBuf(0x04, 0, 1, &closed);

  temp4=0;
        
    }

    
}  

*/

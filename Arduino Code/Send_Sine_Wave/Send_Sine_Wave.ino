/*
Code writed to send hardcoded data to android device for testing
*/
#include <SoftwareSerial.h>
SoftwareSerial BTSerial(10, 11); // RX | TX
#define nPoints 16
#define rawnPoints 32
unsigned char data[2 * nPoints] = {0,0,3,255,3,255,0,0,0,0,3,255,3,255,0,0,0,0,3,255,3,255,0,0,0,0,3,255,3,255,0,0};
int samples[nPoints];

void setup()
{
  Serial.begin(9600); 
  BTSerial.begin(115200);  
}

void loop()
{
  // Feed any data from bluetooth to Terminal.
  if (BTSerial.available()) {
   if (BTSerial.read() == 't') {
      for(unsigned char x = 0; x<rawnPoints; x++) {
      Serial.print("In the loop ");
      Serial.println(x);
      BTSerial.write(data[x]);
      }  
   }
  }


}
































  //Populate array like ABBAABBAAB
//  for(unsigned char x = 0; x<32; x++) {
// 
//  if(x>1)
//  {
//    if((data[x-1] == 255 && data[x-3] == 0)||(data[x-1] == 0 && data[x-2] == 0))
//    {
//      data[x] = 3;
//      data[x+1] = 255;
//      x++;
//    }
//    
//    else if ((data[x-1] == 0 && data[x-2] == 255)||(data[x-1] == 0 && data[x-2] == 255))
//    {
//      data[x] = 0;
//      data[x+1] = 0;
//      x++;     
//    }
//
//  }
//  else
//  {
//      data[x] = 0;
//      data[x+1] = 0;
//      x++;   
//  }
//  Serial.println(data[x]);
//  }

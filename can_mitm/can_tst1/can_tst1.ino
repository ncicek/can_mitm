// naeems's Bench
// 1st CAN Network - CAN TRANSMIT

#include <mcp_can.h>
#include <SPI.h>


const int SPI_CS_PIN = 9;
const int SPI_CS_PINrx = 10;

// Build an ID or PGN

long unsigned int txID = 0x1881ABBA; // This format is typical of a 29 bit identifier.. the most significant digit is never greater than one.
//unsigned char stmp[8] = {0x0E, 0x00, 0xFF, 0x22, 0xE9, 0xFA, 0xDD, 0x51};
unsigned char stmp[8] = {0xAA, 0xBB, 0xCC, 0xFF, 0xFF, 0xFF, 0xDD, 0xEE};

unsigned char len = 0;
unsigned char buf[8];
byte a = 0;
//Construct a MCP_CAN Object and set Chip Select to 10.

MCP_CAN CAN(SPI_CS_PIN);                            
MCP_CAN CANRX(SPI_CS_PINrx);                            

void setup()
{
    Serial.begin(115200);

    while (CAN_OK != CAN.begin(CAN_250KBPS))              // init can bus : baudrate = 250K
    {
         Serial.println("CAN BUS Module Failed to Initialized");
        Serial.println("Retrying....");
        delay(200);
        
    }
    Serial.println("CAN BUS Shield init ok!");
}


void loop()
{   //Serial.println("In loop");

    // send the data:  id = 0x00, Extended Frame, data len = 8, stmp: data buf
    // Extended Frame = 1.
    
    CAN.sendMsgBuf(txID,1, 8, stmp);    
    delay(10);    // send data every 500mS
    CANRX.readMsgBuf(&len, buf);    // read data,  len: data length, buf: data buf
    delay(10);    // send data every 500mS
    //Serial.println(len);
    for(int i = 0; i<len; i++)    // print the data
    {
        if(buf[i] > 15){
          Serial.print("0x");
          Serial.print(buf[i], HEX);    
        }
      else{
          Serial.print("0x0");
          Serial.print(buf[i], HEX);
      }  
        
        //Serial.print("0x");
        //Serial.print(buf[i], HEX);
        
        Serial.print("\t");            
    }

    if (len>0)
    {
      Serial.println("");
    }
    //Serial.println(buf);
}

#include <SoftwareSerial.h>
#include <Conceptinetics.h>

#define DMX_MASTER_CHANNELS 100 
#define RXEN_PIN 2

DMX_Master dmx_master ( DMX_MASTER_CHANNELS, RXEN_PIN );

SoftwareSerial serial(10, 11);

void setup() {
  dmx_master.enable();
  serial.begin(9600);
  //Serial.begin(9600);
}
void loop() {
  if (serial.available()) {
    String data = serial.readStringUntil(';');
    int commaIndex = data.indexOf(',');
    if(commaIndex > -1) {
      int channel = data.substring(0, commaIndex).toInt();
      int value = data.substring(commaIndex + 1).toInt();
      dmx_master.setChannelValue ( channel, value );
    }
    
  }
}
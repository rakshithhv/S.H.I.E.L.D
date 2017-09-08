#include <VirtualWire.h>
const char *message = "X" ;
int PushButton = 9; // PushButton to activate RF PushButton

void setup() {
pinMode(PushButton,INPUT);

vw_set_ptt_inverted(true); // either transmitting or receiving
vw_set_tx_pin(10); // set transmitter pin
vw_setup(4000);// speed of data transfer Kbps
}

void loop(){
  
if (digitalRead(PushButton) == HIGH)
{  
vw_send((uint8_t *)message, strlen(message)); // send the message
}
}

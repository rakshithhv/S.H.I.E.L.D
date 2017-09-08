#include <VirtualWire.h>
int buzzer = 9;      

void setup()
{
  pinMode(buzzer,OUTPUT);
  vw_set_ptt_inverted(true); //either transmitting or receiving 
  vw_set_rx_pin(10); // set receiver pin
  vw_setup(4000);  // Bits per sec
  vw_rx_start();       // Start listening to the receiver
}
    void loop()
{
  digitalWrite(buzzer,LOW);
  uint8_t buf[VW_MAX_MESSAGE_LEN]; // message length
  uint8_t buflen = VW_MAX_MESSAGE_LEN;

  if (vw_get_message(buf, &buflen)) { // if message received
    if(buf[0]=='X'){  // if the first letter in message array is X 
       
      for(int i=0;i<15;i++){        // loop to blink LED (Temporary setup instead of buzzer)
        digitalWrite(buzzer,LOW);
        delay(300);
        digitalWrite(buzzer,HIGH);
        delay(300);
        }
     }  
    }
}
 

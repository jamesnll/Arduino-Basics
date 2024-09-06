/**
 * Program to read and display input using an IR remote and receiver.
 */

#include <IRremote.h>

static const int receiver_pin = 11; // Signal pin of the IR receiver
IRrecv irrecv(receiver_pin); // create instance of irrecv
uint32_t last_decodedRawData = 0; // store the last decodedRawData

/**
 * Function to take action based on the IR code received.
 */
void translateIR() {

  // Check if it is a repeat IR code
  if (irrecv.decodedIRData.flags) {

    // Set the current decodedRawData to the last decodedRawData
    irrecv.decodedIRData.decodedRawData = last_decodedRawData;
    Serial.println("Repeat IR code.");
  } else {

    // Output the IR code on the serial monitor
    Serial.println("IR code:0x");
    Serial.println(irrecv.decodedIRData.decodedRawData, HEX);
  }

  // Map the IR code to the remote key
  switch (irrecv.decodedIRData.decodedRawData) {
    case 0xBA45FF00: Serial.println("POWER");         break;
    case 0xB847FF00: Serial.println("FUNC/STOP");     break;
    case 0xB946FF00: Serial.println("VOL+");          break;
    case 0xBB44FF00: Serial.println("FAST BACK");     break;
    case 0xBF40FF00: Serial.println("PAUSE");         break;
    case 0xBC43FF00: Serial.println("FAST FORWARD");  break;
    case 0xF807FF00: Serial.println("DOWN");          break;
    case 0xEA15FF00: Serial.println("VOL-");          break;
    case 0xF609FF00: Serial.println("UP");            break;
    case 0xE619FF00: Serial.println("EQ");            break;
    case 0xF20DFF00: Serial.println("ST/REPT");       break;
    case 0xE916FF00: Serial.println("0");             break;
    case 0xF30CFF00: Serial.println("1");             break;
    case 0xE718FF00: Serial.println("2");             break;
    case 0xA15EFF00: Serial.println("3");             break;
    case 0xF708FF00: Serial.println("4");             break;
    case 0xE31CFF00: Serial.println("5");             break;
    case 0xA55AFF00: Serial.println("6");             break;
    case 0xBD42FF00: Serial.println("7");             break;
    case 0xAD52FF00: Serial.println("8");             break;
    case 0xB54AFF00: Serial.println("9");             break;
    default:
      Serial.println(" other button");
  }

  // Store the last decodedRawData
  last_decodedRawData = irrecv.decodedIRData.decodedRawData;
  // Add a 1 second delay
  delay(1000);
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("IR Receiver Button Decode");
  // Start the receiver
  irrecv.enableIRIn();
}

void loop() {
  // Check if an IR signal was received
  if (irrecv.decode()) {
    translateIR();
    // Receive the next value
    irrecv.resume();
  } 
}

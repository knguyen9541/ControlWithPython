const int LED{14};

const int S_OK{0xaa};
const int S_ERR{0xff};

// callback for when an RX event is raised
void on_receive(void* event_handler_arg, esp_event_base_t event_base, int32_t event_id, void* event_data) {
  // read one byte
  int state = USBSerial.read();

  // guard byte is valid LED state
  if (!(state == LOW || state == HIGH)) {
    // invalid byte received
    // report error
    USBSerial.write(S_ERR);
    return;
  }

  // update LED with valid state
  digitalWrite(LED, state);
  USBSerial.write(S_OK);
}

void setup() {
  pinMode(LED, OUTPUT);

  // register "on_receive" as callback for RX event
  USBSerial.onEvent(ARDUINO_HW_CDC_RX_EVENT, on_receive);
  USBSerial.begin(9600);
}

// nothing to do in mainloop, everything is interrupt driven!
void loop() { }

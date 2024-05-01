const int LED1{17};
const int LED2{18};

const int S_OK{0xaa};
const int S_ERR{0xff};

void on_receive(void* event_handler_arg, esp_event_base_t event_base, int32_t event_id, void* event_data) {
    int state = USBSerial.read();

    if (!(state == LOW || state == HIGH)) {
      USBSerial.write(S_ERR);
      digitalWrite(LED2, HIGH);
      delay(100);
      digitalWrite(LED2, LOW);
    return;
    }

    digitalWrite(LED1, state);
    USBSerial.write(S_OK);
}

void setup() {
    pinMode(LED1, OUTPUT);
    pinMode(LED2, OUTPUT);

    USBSerial.onEvent(ARDUINO_HW_CDC_RX_EVENT, on_receive);
    USBSerial.begin(9600);
}

void loop(){}

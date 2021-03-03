const unsigned int LED_PIN = 13;
const unsigned int BUTTON_PIN = 8;
unsigned int buttonReading = HIGH;
unsigned int lastButtonState = HIGH;

// debounce vars
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;


void setup() {
  // put your setup code here, to run once:
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  Serial.begin(57600);
}

void loop() {
  
  buttonReading = digitalRead(BUTTON_PIN);

  // If the switch changed, due to noise or pressing:
  if (buttonReading != lastButtonState) {
    // reset the debouncing timer
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    // whatever the reading is at, it's been there for longer than the debounce
    // delay, so take it as the actual current state:
    if(buttonReading == LOW) {
      digitalWrite(LED_PIN, HIGH);  
    }
    else {
      digitalWrite(LED_PIN, LOW);
    }
    Serial.println(buttonReading);
  }

  lastButtonState = buttonReading;
}

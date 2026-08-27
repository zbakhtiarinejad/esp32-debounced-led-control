// Define pin numbers for your ESP32 setup
const int LED1 = 4;
const int LED2 = 23;
const int BUTTON = 2;

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(BUTTON, INPUT_PULLUP);
}

void loop() {
  int buttonState = digitalRead(BUTTON); // Added missing semicolon

  if (buttonState == LOW) {
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
  } else {
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
  } 
}



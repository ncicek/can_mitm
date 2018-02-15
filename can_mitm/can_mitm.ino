#define MUX_SELECT_PIN 12

void setup() {
  pinMode(MUX_SELECT_PIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second
}

void mux_control(bool status){
  if (status)
    digitalWrite(MUX_SELECT_PIN, HIGH);
  else
    digitalWrite(MUX_SELECT_PIN, LOW);
}

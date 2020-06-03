#define LIGHT 3
#define SIGNAL 9
#define SWITCH 12

long timeOfPress = 0;
bool on = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(SWITCH, INPUT);
  pinMode(LIGHT, OUTPUT);
  pinMode(SIGNAL, OUTPUT);

  digitalWrite(LIGHT, LOW);
  digitalWrite(SIGNAL, LOW);

  Serial.begin(9600);
}

void loop() {
  // debounce
  if (millis() - timeOfPress < 1000)
    return;

  if (digitalRead(SWITCH) == HIGH) {
    Serial.println("Pressed");
    timeOfPress = millis();

    on = !on;

    // we manage the state of the light
    digitalWrite(LIGHT, on ? HIGH : LOW);

    Serial.print("Turning light ");
    Serial.println(on ? "on" : "off");

    // the signal pin is a toggle, so we just emulate one
    digitalWrite(SIGNAL, HIGH);
    delay(1000);
    digitalWrite(SIGNAL, LOW);
  }
}

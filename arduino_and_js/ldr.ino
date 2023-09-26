const int LEDPin = 11; // Initialize Pin 11 for LED
const int LDRPin = A0; // Initialize LDR Pin A0
void setup() {
  Serial.begin(9600);
  pinMode(LEDPin, OUTPUT); // Define pin as output
  pinMode(LDRPin, INPUT);  // Define LDR pin as input
}
void loop() {
  int ldrStatus = analogRead(LDRPin); // Read LDR light intensity as analog value
  Serial.println(ldrStatus);
  // Control based on LDR light intensity
  if (ldrStatus <= 500) {
    digitalWrite(LEDPin, HIGH); // Turn LED on
    Serial.print(" LIGHT ON : ");
    Serial.println(ldrStatus);
  } else {
    digitalWrite(LEDPin, LOW); // Turn LED off
    Serial.print("LIGHT OFF: ");
    Serial.println(ldrStatus); // Print LDR analog value on the serial port
  }
}

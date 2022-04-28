int led = 13;
int pirsen = 2;
int in1 = 1;
int in2 = 0;

int pirState = LOW;

void setup() {
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(led, OUTPUT);
  pinMode(pirsen, INPUT);
  Serial.begin(9600);
}

void loop() {
  if (digitalRead(pirsen) == HIGH) {
    Serial.println("Motion Detected!");
    digitalWrite(led, HIGH);

    if (pirState == LOW) {
      Serial.println("......................Motor Run {Door Opening start}...............");
      digitalWrite(in1, HIGH); // motor
      digitalWrite(in2, LOW);  // motor
      pirState = HIGH;
      delay(2000);
      Serial.println("......................Motor Run {Door is Open}...............");
    }
  }
  else{
    Serial.println("Motion Ended!");
    digitalWrite(led, LOW);
    if(pirState == HIGH){
      Serial.println("......................Motor Run {Door Closing start}...............");
      digitalWrite(in1, LOW); // motor
      digitalWrite(in2, HIGH);  // motor
      pirState = LOW;
      delay(2000);
      Serial.println("......................Motor Run {Door is Close}...............");
      }
    }
    Serial.println("......................Motor Stop...............");
    digitalWrite(in1, LOW); // motor
    digitalWrite(in2, LOW);  // motor
}

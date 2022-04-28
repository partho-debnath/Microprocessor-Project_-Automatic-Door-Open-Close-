int led = 13;
int pirsen = 2;
int in1 = 7;
int in2 = 8;

int pirState = 0;

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
    

    if (pirState == 0) {
      digitalWrite(led, HIGH);
      Serial.println("......................Motor Run {Door Opening start}...............");
      digitalWrite(in1, HIGH); // motor
      digitalWrite(in2, LOW);  // motor
      pirState = 1;
      delay(1000);
      Serial.println("......................Motor Run {Door is Open}...............");
    }
    Serial.println("......................{Door is Open}...............");
  }
  else{
    Serial.println("Motion Ended!");
    
    if(pirState == 1){
      delay(5000);
      Serial.println("......................Motor Run {Door Closing start}...............");
      digitalWrite(in1, LOW); // motor
      digitalWrite(in2, HIGH);  // motor
      pirState = 0;
      delay(1000);
      Serial.println("......................Motor Run {Door is Close}...............");
      digitalWrite(led, LOW);
      }
    Serial.println("......................{Door is Close}...............");
    }
    Serial.println("......................Motor Stop...............");
    digitalWrite(in1, LOW); // motor
    digitalWrite(in2, LOW);  // motor
}

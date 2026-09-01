#define TRIG_PIN 9
#define ECHO_PIN 10
#define BUZZER_PIN 11
#define LED_PIN 2
#define MQ3_PIN A0

#define ALCOHOL_THRESHOLD 400
#define MAX_DISTANCE 150

bool driverWasPresent = false;
unsigned long buzzerTimer = 0;
bool isBuzzerBeeping = false;

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
}

long getDistance() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  long duration = pulseIn(ECHO_PIN, HIGH);
  return duration * 0.034 / 2;
}

void loop() {
  int alcoholLevel = analogRead(MQ3_PIN);
  long distance = getDistance();
  
  bool driverIsPresent = (distance > 0 && distance <= MAX_DISTANCE);

  Serial.print("Alcohol: ");
  Serial.print(alcoholLevel);
  Serial.print(" | Distance: ");
  Serial.print(distance);
  Serial.print(" cm | Driver: ");
  Serial.println(driverIsPresent ? "Present" : "Absent");

  if (driverIsPresent != driverWasPresent) {
    driverWasPresent = driverIsPresent;
    isBuzzerBeeping = true;
    buzzerTimer = millis();
  }

  if (alcoholLevel >= ALCOHOL_THRESHOLD) {
    digitalWrite(BUZZER_PIN, HIGH);
    digitalWrite(LED_PIN, LOW); 
  } else {
    digitalWrite(LED_PIN, HIGH);
    
    if (isBuzzerBeeping) {
      if (millis() - buzzerTimer >= 500) {
        isBuzzerBeeping = false;
        digitalWrite(BUZZER_PIN, LOW);
      } else {
        digitalWrite(BUZZER_PIN, HIGH);
      }
    } else {
      digitalWrite(BUZZER_PIN, LOW);
    }
  }

  delay(50);
}
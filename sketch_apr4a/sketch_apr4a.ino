#define trigPin 2
#define echoPin 3

int lr=9;
int lv=8;

long duration;
long distance;

void setup() {
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);

  pinMode(lr, OUTPUT);
  pinMode(lv, OUTPUT);

  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  distance = duration * 0.034 / 2;

  Serial.print("Distance = ");
  Serial.print(distance);
  Serial.print(" cm");
  delay(50);

  if(distance <= 5 || distance >= 10)
  {
    digitalWrite(lr, HIGH);
    digitalWrite(lv, LOW);
  }
  else
  {
    digitalWrite(lv, HIGH);
    digitalWrite(lr, LOW);
  }

}

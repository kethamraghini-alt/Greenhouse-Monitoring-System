int sensorPin = A0;
int ledPin = 9;
int buzzerPin = 8;

int sensorValue;
float voltage;
float temperature;

void setup()
{
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  sensorValue = analogRead(sensorPin);

  voltage = sensorValue * (5.0 / 1023.0);

  temperature = (voltage - 0.5) * 100;

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" C");

  if (temperature > 30)
  {
    digitalWrite(ledPin, HIGH);
    tone(buzzerPin, 1000);
  }
  else
  {
    digitalWrite(ledPin, LOW);
    noTone(buzzerPin);
  }

  delay(1000);
}
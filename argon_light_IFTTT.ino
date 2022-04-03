/** Task & REFERENCES
 SIT210 3.2C: Sense light and trigger an IFTTT function to send email when light or dark.
 Code put together and modified from the following sources:
 * https://docs.particle.io/tutorials/integrations/ifttt/
 * https://docs.particle.io/tutorials/hardware-projects/hardware-examples/#read-your-photo-sensor-function-and-variable
*/

int led = D7;
int photoresistor = A0;
int analogValue;
bool sunlight = false;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(photoresistor, INPUT);
}

void loop() {
  analogValue = analogRead(photoresistor);
  if(analogValue > 15 and not(sunlight)) {
      digitalWrite(led, LOW);
      sunlight = true;
      Particle.publish("Sun_State", "sunny");
  } 
  if(analogValue < 15 and sunlight) {
      digitalWrite(led, HIGH);
      sunlight = false;
      Particle.publish("Sun_State", "shady");
  }
  delay(60000); // wait one minute
}

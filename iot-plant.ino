/*
 * Project: IoT Plant
 * Description: A moisture sensor reads the moisture in the flower pot. If it's too dry, it tweets.
 * Author: @tdnvl
 * Date: 2017-05-20
 */


 int moisturePin = A0;
 int led1 = D7;
 int tweeted = 0;

 void setup() {
 // initialize serial communication at 9600 bits per second:

 Serial.begin(9600);
 pinMode(led1, OUTPUT);
 pinMode(moisturePin, INPUT);

 }

 void loop() {

 int moisturePin = analogRead(A0);

//  Serial.println(moisturePin);

 if (moisturePin < 1000 && tweeted == 0) {
     // Generic copy for the tweet
     String data = "Hey, @tdnvl! I need some water! #";
     // Twitter won't post identical tweets. I generate a random integer between 1 and 30 and append it.
     data += random(30);
     // Trigger the integration
     Particle.publish("tweet", data, PRIVATE);
     // Set tweeted variable to 1
     tweeted = 1;
     // Wait 60 seconds
     delay(60000);
 }

 else if (moisturePin < 1000 && tweeted != 0){
   // Let's blink the D7 LED, in case I missed the tweet
   digitalWrite(led1, HIGH);
   delay(1000);
   digitalWrite(led1, LOW);
   delay(1000);
 }

 else {
 // Moisture is OK, let's set the tweeted variable to 0
 tweeted = 0;
 // Let's wait for another 10 minutes before reading A0 again
 delay(600000);
 }

 }

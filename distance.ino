// LiquidCrystal I2C - Version: Latest
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // set the LCD address to 0x27 for a 16 chars and 2 line display

// defines pins numbers
const int trigPin = 9;
const int echoPin = 10;
const int greenLed = 11;
// defines variables
long duration;
int distance;
void setup()
{
    lcd.init();
    lcd.backlight();
    pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
    pinMode(echoPin, INPUT);  // Sets the echoPin as an Input
    pinMode(greenLed, OUTPUT);
    Serial.begin(9600); // Starts the serial communication
}
void loop()
{

    // Clears the trigPin
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    // Sets the trigPin on HIGH state for 10 micro seconds
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    // Reads the echoPin, returns the sound wave travel time in microseconds
    duration = pulseIn(echoPin, HIGH);
    // Calculating the distance
    distance = duration * 0.034 / 2;
    // Prints the distance on the Serial Monitor
    Serial.print("Distance: ");
    Serial.println(distance);
    lcd.setCursor(0, 0);
    lcd.print("Distance: ");
    lcd.print(distance);
    lcd.print("cm");
    delay(10);
    if (distance > 100)
    {
        digitalWrite(greenLed, HIGH);
        delay(1000);
        digitalWrite(greenLed, LOW);
        delay(1000);
        lcd.clear();
    }
}

#include <Wire.h>
#include <Keypad.h>


// Sensor pins
const int pirPin = 2;
const int ledPin = 5;
const int soundSensorPin = 3;  // Sound sensor digital output


// Keypad setup
const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}};
byte rowPins[ROWS] = {6, 7, 8, 9};
byte colPins[COLS] = {10, 11, 12, 13};
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);


// Messages for keypad inputs
String messages[10] = {
    "Hello", "I need help", "How are you", "I am hard of hearing",
    "Bathroom", "Emergency", "I am fine", "Thank you",
    "Where are you?", "Goodbye"};


void setup() {
    pinMode(pirPin, INPUT);
    pinMode(ledPin, OUTPUT);
    pinMode(soundSensorPin, INPUT);
    Serial.begin(9600);
    Serial.println("System Ready");
}


void loop() {
    // Check PIR sensor
    if (digitalRead(pirPin) == HIGH) {
        Serial.println("Motion Detected!");
        digitalWrite(ledPin, HIGH);
        delay(500);
        digitalWrite(ledPin, LOW);
    }


    // Check sound sensor
    if (digitalRead(soundSensorPin) == HIGH) {
        Serial.println("Sound Detected!");
        delay(500);
    }


    // Check keypad input
    char key = keypad.getKey();
    if (key) {
        Serial.print("Key Pressed: ");
        Serial.println(key);
        if (key >= '0' && key <= '9') {
            Serial.println(messages[key - '0']);
        } else {
            Serial.println("Invalid Key");
        }
        delay(2000);
    }
}

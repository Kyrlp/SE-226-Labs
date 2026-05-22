#include <LiquidCrystal.h>

// LCD initialization: RS, EN, D4, D5, D6, D7
LiquidCrystal lcd(36, 37, 26, 27, 28, 29);

// 7 segment pins
const int aPin  = 22;
const int bPin  = 23;
const int cPin  = 24;
const int dPin  = 25;
const int ePin  = 26;
const int fPin  = 27;
const int gPin  = 28;
const int dpPin = 29;

const int segmentPins[8] = {
  aPin, bPin, cPin, dPin, ePin, fPin, gPin, dpPin
};

// Digit pins
const int dig1Pin = 33; // rightmost
const int dig2Pin = 34;
const int dig3Pin = 35;
const int dig4Pin = 36; // leftmost

const int digitPins[4] = {
  dig4Pin, dig3Pin, dig2Pin, dig1Pin
};

// Counter digits
int dig1 = 0;
int dig2 = 0;
int dig3 = 0;
int dig4 = 0;

unsigned long previousSecond = 0;
unsigned long previousMultiplex = 0;

int currentDigit = 0;

// IMPORTANT:
// Segment pins: HIGH = ON, LOW = OFF
// Digit pins:   HIGH = ACTIVE, LOW = PASSIVE

const byte numbers[10][8] = {
  // A     B     C     D     E     F     G     DP
  {HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, LOW,  LOW}, // 0
  {LOW,  HIGH, HIGH, LOW,  LOW,  LOW,  LOW,  LOW}, // 1
  {HIGH, HIGH, LOW,  HIGH, HIGH, LOW,  HIGH, LOW}, // 2
  {HIGH, HIGH, HIGH, HIGH, LOW,  LOW,  HIGH, LOW}, // 3
  {LOW,  HIGH, HIGH, LOW,  LOW,  HIGH, HIGH, LOW}, // 4
  {HIGH, LOW,  HIGH, HIGH, LOW,  HIGH, HIGH, LOW}, // 5
  {HIGH, LOW,  HIGH, HIGH, HIGH, HIGH, HIGH, LOW}, // 6
  {HIGH, HIGH, HIGH, LOW,  LOW,  LOW,  LOW,  LOW}, // 7
  {HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, LOW}, // 8
  {HIGH, HIGH, HIGH, HIGH, LOW,  HIGH, HIGH, LOW}  // 9
};

void setup() {
  for (int i = 0; i < 8; i++) {
    pinMode(segmentPins[i], OUTPUT);
    digitalWrite(segmentPins[i], LOW);
  }

  for (int i = 0; i < 4; i++) {
    pinMode(digitPins[i], OUTPUT);
    digitalWrite(digitPins[i], LOW);
  }

  lcd.begin(16, 2);
  lcd.print("Counter:");
  updateLCD();
}

void loop() {
  multiplexDisplay();

  if (millis() - previousSecond >= 1000) {
    previousSecond = millis();

    incrementCounter();
    updateLCD();
  }
}

void incrementCounter() {
  dig1++;

  if (dig1 >= 10) {
    dig1 = 0;
    dig2++;
  }

  if (dig2 >= 10) {
    dig2 = 0;
    dig3++;
  }

  if (dig3 >= 10) {
    dig3 = 0;
    dig4++;
  }

  if (dig4 >= 10) {
    dig4 = 0;
  }
}

void multiplexDisplay() {
  if (millis() - previousMultiplex >= 4) {
    previousMultiplex = millis();

    turnOffAllDigits();

    int digitValues[4] = {
      dig4, dig3, dig2, dig1
    };

    showNumber(digitValues[currentDigit]);

    digitalWrite(digitPins[currentDigit], HIGH);

    currentDigit++;

    if (currentDigit >= 4) {
      currentDigit = 0;
    }
  }
}

void showNumber(int number) {
  for (int i = 0; i < 8; i++) {
    digitalWrite(segmentPins[i], numbers[number][i]);
  }
}

void turnOffAllDigits() {
  for (int i = 0; i < 4; i++) {
    digitalWrite(digitPins[i], LOW);
  }
}

void updateLCD() {
  lcd.setCursor(0, 0);
  lcd.print("Counter: ");

  lcd.print(dig4);
  lcd.print(dig3);
  lcd.print(dig2);
  lcd.print(dig1);

  lcd.print("   ");
}
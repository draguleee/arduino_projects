const int analogPin = A0;   // pinul la care este atasat potentiometrul
const int ledCount = 10;    // numarul de leduri de pe breadboard

int ledPins[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11};   // vectorul care contine numarul pinilor care sunt atasati


void setup() {
  // ciclare in vectorul de pini ledPins[] și setarea tuturor pinilor ca iesire
  for (int thisLed = 0; thisLed < ledCount; thisLed++) {
    pinMode(ledPins[thisLed], OUTPUT);
  }
  
  // sau se mai poate proceda astfel (metoda mai costisitoare ca timp):
  /* 
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  */ 
}

void loop() {
  // citirea potentiometrului:
  int sensorReading = analogRead(analogPin);
  // afisare rezultat de la 0 la numarul de leduri conectate:
  int ledLevel = map(sensorReading, 0, 1023, 0, ledCount);

  // ciclare in vectorul de pini ledPins[]
  for (int thisLed = 0; thisLed < ledCount; thisLed++) {
    // daca indicele elementului din vector este mai mic decât ledLevel, se porneste pinul pentru acest element:
    if (thisLed < ledLevel) {
      digitalWrite(ledPins[thisLed], HIGH);
    }
    // stingerea tuturor ledurilor mai mari decat ledLevel:
    else {
      digitalWrite(ledPins[thisLed], LOW);
    }
  }
}

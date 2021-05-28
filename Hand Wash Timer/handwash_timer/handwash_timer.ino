/*
HandWashTimer, un dispozitiv util in pandemie de COVID_19!
Acest proiect este dedicat in totalitate promovarii sanatatii si a igienei adecvate!
Acest proiect reprezinta un timer care numara pana la 20 de secunde pentru tine, timp in care te speli pe maini corect.
Schema acestui proiect consta intr-o placa Arduino UNO, un senzor ultrasonic, un breadboard, fire de conexiune si 6 LED-uri, dintre care unul rosu, patru albastre si unul verde.
Principiul de functionare a acestui proiect este urmatorul;
* Pentru o functionalitate completa, dispozitivul ar trebui sa fie montat langa dispenserul de sapun, insa versiunea rudimentara nu permite acest lucru.
* Senzorul ultrasonic detecteaza mainile in miscare, care se afla langa dispenserul de sapun, si se va aprinde LED-ul rosu.
* Cand acest LED se aprinde, inseamna ca numaratoarea a inceput.
* LED-urile celelalte se vor aprinde progesiv, pana cand becul verde se aprinde, iar cel rosu se stinge, insemnand ca numaratoarea a luat sfarsit.
*/

int echoPin = 11;       // Pinul ECHO al senzorului ultrasonic este conectat la pinul 11 al placii Arduino UNO
int trigPin = 12;       // Pinul TRIG al senzorului ultrasonic este conectat la pinul 12 al placii Arduino UNO
long duration;          // Durata 
int distance;           // Distanta de la care masoara senzorul ultrasonic

// Rutina setup(), care ruleaza o singura data
void setup() {
  for (int i = 2; i <= 7; i++) {      // Setarea pinilor 2-7 (pinii la care sunt conectate LED-urile) ca iesiri
    pinMode (i, OUTPUT);
  }
  /* O alta metoda pentru a seta pinii 2-7 ca iesiri este urmatoarea:
   * pinMode(2, OUTPUT);
   * pinMode(3, OUTPUT); 
   * pinMode(4, OUTPUT); 
   * pinMode(5, OUTPUT); 
   * pinMode(6, OUTPUT); 
   * pinMode(7, OUTPUT); 
   */
  pinMode (trigPin, OUTPUT);          // Setarea pinului 12 (trigPin) ca iesire
  pinMode (echoPin, INPUT);           // Setarea pinului 11 (echoPin) ca intrare
}

// Rutina loop(), care ruleaza pana cand placa nu mai este alimentata
void loop() {
  // Masurarea distantei si citirea informatiilor preluate
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration * .0343) / 2;

  // Detectarea obiectelor pe o raza de 30 de centimetri
  if (distance > 0 && distance <= 30) {
    ledtimer();
  }
}

// Rutina ledtimer(), care va implementa un "cronometru" utilizand pinii la care sunt conectate cele 6 LED-uri
void ledtimer() {
  digitalWrite (7, HIGH);           // Aprindere LED rosu, conectat la pinul 7
  delay(4000);                      // Asteapta 4 secunde
  for (int i = 6; i >= 2; i--) {    // Parcurgerea celorlalti pini, la care sunt conectate celelalte LED-uri ramase
    digitalWrite (i, HIGH);         // Setarea lor in starea HIGH
    if (i == 2) {                   // Daca LED-ul verde (corespunzator pinului 2), este aprins...
      digitalWrite (7, LOW);        // ... LED-ul rosu (corespunzator pinului 7) va fi stins.
    } 
    delay(4000);                    // Asteapta 4 secunde
  }
  for (int i = 7; i >= 2; i--) {
    digitalWrite (i, LOW);

  }
}

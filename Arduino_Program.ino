#include <DFPlayer_Mini_Mp3.h>
#include <SoftwareSerial.h>
#include <Servo.h>

Servo myServo;
SoftwareSerial mySerial(10, 14); // RX, TX

#define sin0 34
#define sin30 33
#define sin45 30
#define cos360 29
#define tan120 32
#define sec180 31
#define cosec60 28
#define sec120 27
#define sec45 26
#define cot60 25
#define cos120 24
#define cos30 21
#define tan90 22
#define cosec30 23

#define BTN_nol 40
#define BTN_satuperdua 39
#define BTN_negatifakartiga 38
#define BTN_negatifsatu 37
#define BTN_negatifsatuperdua 36
#define BTN_takhingga 35
#define BTN_akarduaperdua 46
#define BTN_satuperakartiga 45
#define BTN_dua 44
#define BTN_akartigaperdua 43
#define BTN_akardua 42
#define BTN_negatifdua 41
#define BTN_satu 48
#define BTN_duaperakartiga 47

#define LED_nol A5
#define LED_satuperdua A4
#define LED_negatifakartiga A3
#define LED_negatifsatu A2
#define LED_negatifsatuperdua A1
#define LED_takhingga A0
#define LED_akarduaperdua A11
#define LED_satuperakartiga A10
#define LED_dua A9
#define LED_akartigaperdua A8
#define LED_akardua A7
#define LED_negatifdua A6
#define LED_satu A15
#define LED_duaperakartiga A12

#define LED_benar A14
#define LED_salah A13

#define servoPin 5

#define ditekan LOW
int pos = 0;

int cektombolJawaban[] = {
  BTN_nol, BTN_satuperdua, BTN_negatifakartiga, BTN_negatifsatu, BTN_negatifsatuperdua, BTN_takhingga,
  BTN_akarduaperdua, BTN_satuperakartiga, BTN_dua, BTN_akartigaperdua, BTN_akardua, BTN_negatifdua,
  BTN_satu, BTN_duaperakartiga
};

int LED_Jawaban[] = {
  LED_nol, LED_satuperdua, LED_negatifakartiga, LED_negatifsatu, LED_negatifsatuperdua, LED_takhingga,
  LED_akarduaperdua, LED_satuperakartiga, LED_dua, LED_akartigaperdua, LED_akardua, LED_negatifdua,
  LED_satu, LED_duaperakartiga
};

int indexJawaban_MP3[] = {
  15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28
};

String stringJawaban[] = {
  "nol", "satuperdua", "negatifakartiga", "negatifsatu", "negatifsatuperdua", "takhingga",
  "akarduaperdua", "satuperakartiga", "dua", "akartigaperdua", "akardua", "negatifdua",
  "satu", "duaperakartiga"
};

void setup() {

  Serial.begin(9600);
  mySerial.begin(9600);
  mp3_set_serial (mySerial);
  mp3_set_volume (15);

  myServo.attach(servoPin);

  pinMode(sin0, INPUT_PULLUP);
  pinMode(sin30, INPUT_PULLUP);
  pinMode(sin45, INPUT_PULLUP);
  pinMode(cos360, INPUT_PULLUP);
  pinMode(tan120, INPUT_PULLUP);
  pinMode(sec180, INPUT_PULLUP);
  pinMode(cosec60, INPUT_PULLUP);
  pinMode(sec120, INPUT_PULLUP);
  pinMode(sec45, INPUT_PULLUP);
  pinMode(cot60, INPUT_PULLUP);
  pinMode(cos120, INPUT);
  pinMode(cos30, INPUT_PULLUP);
  pinMode(tan90, INPUT_PULLUP);
  pinMode(cosec30, INPUT_PULLUP);

  pinMode(BTN_nol, INPUT_PULLUP);
  pinMode(BTN_satuperdua, INPUT_PULLUP);
  pinMode(BTN_negatifakartiga, INPUT_PULLUP);
  pinMode(BTN_negatifsatu, INPUT_PULLUP);
  pinMode(BTN_negatifsatuperdua, INPUT_PULLUP);
  pinMode(BTN_takhingga, INPUT_PULLUP);
  pinMode(BTN_akarduaperdua, INPUT_PULLUP);
  pinMode(BTN_satuperakartiga, INPUT_PULLUP);
  pinMode(BTN_dua, INPUT_PULLUP);
  pinMode(BTN_akartigaperdua, INPUT_PULLUP);
  pinMode(BTN_akardua, INPUT_PULLUP);
  pinMode(BTN_negatifdua, INPUT_PULLUP);
  pinMode(BTN_satu, INPUT_PULLUP);
  pinMode(BTN_duaperakartiga, INPUT_PULLUP);

  pinMode(LED_nol, OUTPUT);
  pinMode(LED_satuperdua, OUTPUT);
  pinMode(LED_negatifakartiga, OUTPUT);
  pinMode(LED_negatifsatu, OUTPUT);
  pinMode(LED_negatifsatuperdua, OUTPUT);
  pinMode(LED_takhingga, OUTPUT);
  pinMode(LED_akarduaperdua, OUTPUT);
  pinMode(LED_satuperakartiga, OUTPUT);
  pinMode(LED_dua, OUTPUT);
  pinMode(LED_akartigaperdua, OUTPUT);
  pinMode(LED_akardua, OUTPUT);
  pinMode(LED_negatifdua, OUTPUT);
  pinMode(LED_satu, OUTPUT);
  pinMode(LED_duaperakartiga, OUTPUT);

  pinMode(LED_benar, OUTPUT);
  pinMode(LED_salah, OUTPUT);

  resetLED();
  myServo.write(0);
}

void loop() {

    if (digitalRead(BTN_nol) == ditekan) Serial.println("BTN_nol");
    if (digitalRead(BTN_satuperdua) == ditekan) Serial.println("BTN_satuperdua");
    if (digitalRead(BTN_negatifakartiga) == ditekan) Serial.println("BTN_negatifakartiga");
    if (digitalRead(BTN_negatifsatu) == ditekan) Serial.println("BTN_negatifsatu");
    if (digitalRead(BTN_negatifsatuperdua) == ditekan) Serial.println("BTN_negatifsatuperdua");
    if (digitalRead(BTN_takhingga) == ditekan) Serial.println("BTN_takhingga");
    if (digitalRead(BTN_akarduaperdua) == ditekan) Serial.println("BTN_akarduaperdua");
    if (digitalRead(BTN_satuperakartiga) == ditekan) Serial.println("BTN_satuperakartiga");
    if (digitalRead(BTN_dua) == ditekan) Serial.println("BTN_dua");
    if (digitalRead(BTN_akartigaperdua) == ditekan) Serial.println("BTN_akartigaperdua");
    if (digitalRead(BTN_akardua) == ditekan) Serial.println("BTN_akardua");
    if (digitalRead(BTN_negatifdua) == ditekan) Serial.println("BTN_negatifdua");
    if (digitalRead(BTN_satu) == ditekan) Serial.println("BTN_satu");
    if (digitalRead(BTN_duaperakartiga) == ditekan) Serial.println("BTN_duaperakartiga");

  if (digitalRead(cos120) == ditekan) {
    Serial.println("Cos 120?");
    mp3_play(11);
    tungguJawaban(BTN_negatifsatuperdua, LED_negatifsatuperdua);
  }

  else if (digitalRead(sin30) == ditekan) {
    Serial.println("Sin 30?");
    mp3_play(2);
    tungguJawaban(BTN_satuperdua, LED_satuperdua);
  }

  else if (digitalRead(sin0) == ditekan) {
    Serial.println("Sin 0?");
    mp3_play(1);
    tungguJawaban(BTN_nol, LED_nol);
  }

  else if (digitalRead(sin45) == ditekan) {
    Serial.println("Sin 45?");
    mp3_play(5);
    tungguJawaban(BTN_akarduaperdua, LED_akarduaperdua);
  }

  else if (digitalRead(cos360) == ditekan) {
    Serial.println("Cos 360?");
    mp3_play(6);
    tungguJawaban(BTN_satu, LED_satu);
  }

  else if (digitalRead(tan120) == ditekan) {
    Serial.println("Tan 120?");
    mp3_play(3);
    tungguJawaban(BTN_negatifakartiga, LED_negatifakartiga);
  }

  else if (digitalRead(sec180) == ditekan) {
    Serial.println("Sec 180?");
    mp3_play(4);
    tungguJawaban(BTN_negatifsatu, LED_negatifsatu);
  }

  else if (digitalRead(cosec60) == ditekan) {
    Serial.println("Cosec 60?");
    mp3_play(7);
    tungguJawaban(BTN_duaperakartiga, LED_duaperakartiga);
  }

  else if (digitalRead(cosec30) == ditekan) {
    Serial.println("Cosec 30?");
    mp3_play(12);
    tungguJawaban(BTN_dua, LED_dua);
  }

  else if (digitalRead(sec120) == ditekan) {
    Serial.println("Sec 120?");
    mp3_play(8);
    tungguJawaban(BTN_negatifdua, LED_negatifdua);
  }

  else if (digitalRead(sec45) == ditekan) {
    Serial.println("Sec 45?");
    mp3_play(9);
    tungguJawaban(BTN_akardua, LED_akardua);
  }

  else if (digitalRead(cot60) == ditekan) {
    Serial.println("Cot 60?");
    mp3_play(10);
    tungguJawaban(BTN_satuperakartiga, LED_satuperakartiga);
  }

  else if (digitalRead(cos30) == ditekan) {
    Serial.println("Cos 30?");
    mp3_play(14);
    tungguJawaban(BTN_akartigaperdua, LED_akartigaperdua);
  }

  else if (digitalRead(tan90) == ditekan) {
    Serial.println("Tan 90?");
    mp3_play(13);
    tungguJawaban(BTN_takhingga, LED_takhingga);
  }

  resetLED();
  delay(100);
}

void tungguJawaban(int pinJawabanBenar, int pinLEDJawaban) {
  bool sudahJawab = false;

  while (!sudahJawab) {
    for (int i = 0; i < sizeof(cektombolJawaban) / sizeof(cektombolJawaban[0]); i++) {
      int pin = cektombolJawaban[i];
      Serial.println("Index i: " + String(i));

      if (digitalRead(pin) == ditekan) {
        if (pin == pinJawabanBenar) {
          resetLED();
          digitalWrite(pinLEDJawaban, HIGH);
          digitalWrite(LED_benar, HIGH);
          mp3_play(indexJawaban_MP3[i]);
          delay(2000);
          mp3_play(29);
          delay(2000);
          resetLED();
          sudahJawab = true;
          break;
        } 
        
        else {
          // Jawaban salah
          resetLED();
          digitalWrite(LED_Jawaban[i], HIGH);
          digitalWrite(pinLEDJawaban, LOW);
          digitalWrite(LED_salah, HIGH);
          mp3_play(indexJawaban_MP3[i]);
          delay(2000);
          mp3_play(30);

          // Servo bergerak halus ke 180
          for (int pos = 0; pos <= 90; pos++) {
            myServo.write(pos);
            delay(10);
            Serial.println("Angle: " + String(pos));
          }

          // Tunggu sampai user menjawab benar
          while (true) {
            bool benarDitekan = false;

            for (int j = 0; j < sizeof(cektombolJawaban) / sizeof(cektombolJawaban[0]); j++) {
              int pin = cektombolJawaban[j];
              Serial.println("Index j: " + String(i));

              if (digitalRead(pin) == ditekan) {
                if (pin == pinJawabanBenar) {
                  resetLED();
                  digitalWrite(pinLEDJawaban, HIGH);
                  digitalWrite(LED_benar, HIGH);
                  mp3_play(indexJawaban_MP3[j]);
                  delay(2000);
                  mp3_play(29);
                  delay(1000);

                  // Servo kembali halus ke 0
                  for (int pos = 90; pos >= 0; pos--) {
                    myServo.write(pos);
                    delay(10);
                    Serial.println("Angle: " + String(pos));
                  }

                  resetLED();
                  sudahJawab = true;
                  benarDitekan = true;
                  break; // keluar dari for
                }
              }
              delay(50);
            }

            if (benarDitekan) break; // keluar dari while(true)
          }
        }
      }
      if (sudahJawab) break; // keluar dari for utama
      delay(50);
    }
  }
}

void resetLED() {
  digitalWrite(LED_nol, LOW);
  digitalWrite(LED_satuperdua, LOW);
  digitalWrite(LED_negatifakartiga, LOW);
  digitalWrite(LED_negatifsatu, LOW);
  digitalWrite(LED_negatifsatuperdua, LOW);
  digitalWrite(LED_takhingga, LOW);
  digitalWrite(LED_akarduaperdua, LOW);
  digitalWrite(LED_satuperakartiga, LOW);
  digitalWrite(LED_dua, LOW);
  digitalWrite(LED_akartigaperdua, LOW);
  digitalWrite(LED_akardua, LOW);
  digitalWrite(LED_negatifdua, LOW);
  digitalWrite(LED_satu, LOW);
  digitalWrite(LED_duaperakartiga, LOW);

  digitalWrite(LED_benar, LOW);
  digitalWrite(LED_salah, LOW);
}

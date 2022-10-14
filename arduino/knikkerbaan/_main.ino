#include <Arduino_JSON.h>

KnikkerPoort poortBoven = KnikkerPoort();
Teller tellerA = Teller(TELLER_A_PIN);

void setup() {
  Serial.begin(9600);
  poortBoven.begin(BOVEN_POORT_PIN, 0, 90);

  poortBoven.open();
}


void loop() {
  // laat de teller detecteren:
  tellerA.update();

}

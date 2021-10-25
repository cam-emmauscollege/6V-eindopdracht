class Teller {
  private:
    int pin;
    bool wasOnderbroken;
    unsigned long laatstOnderbroken = 0;
    const int DEBOUNCE_TIME = 10;

    bool isOnderbroken() {
      return !digitalRead(pin);
    }

    bool wordtOnderbroken() {
      return (wasOnderbroken == false && isOnderbroken() == true);
    }

    int teller = 0;

  public:
    Teller(int _pin) {
      pinMode(_pin, INPUT_PULLUP);
      pin = _pin;
      wasOnderbroken = false;
    }

    void update() {
      //Serial.println(digitalRead(pin));
      if (wordtOnderbroken()) {
        if (millis() - laatstOnderbroken > DEBOUNCE_TIME) {
          verhoogTeller();
          Serial.println(teller);
        } 
      }

      wasOnderbroken = isOnderbroken();
    }

    void verhoogTeller() {
      teller++;
    }

    int getTeller() {
      return teller;
    }
};
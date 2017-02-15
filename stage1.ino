#include "RelayBoard.h"

RelayBoard relays(3, 4, 5, 6, 7);

struct values {
    uint8_t pins[5];
    uint16_t values[5];
} readings = { .pins = { A0, A1, A2, A3, A4 }};

void read_value(uint8_t pin, struct values *v, RelayBoard *r);

void setup()
{
    Serial.begin(9600);
}

void loop()
{
    for (int i = 0; i < RelayBoard::PINS; i++) {
        relays.select(i);
        delay(3000);
        read_value(i, &readings, &relays);
        Serial.print("Reading from ");
        Serial.print(i);
        Serial.print(": ");
        Serial.println(readings.values[i] * (5.0/1023.0));
    }
    Serial.println("");
}

void read_value(uint8_t pin, struct values *v, RelayBoard *r)
{
    r->select(pin);
    v->values[pin] = analogRead(v->pins[pin]);
}

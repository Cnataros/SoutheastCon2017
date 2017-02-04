#ifndef RELAYBOARD_H
#define RELAYBOARD_H

class RelayBoard {
private:
    uint8_t pin[5];
public:
    RelayBoard();
    RelayBoard(uint8_t, uint8_t, uint8_t, uint8_t, uint8_t);
    ~RelayBoard();
    void select(uint8_t);
    static const uint8_t PINS = 5;
};

#endif /* RELAYBOARD_H */

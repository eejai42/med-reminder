#ifndef ARDUINO_H
#define ARDUINO_H

#include <stdint.h>

// Define constants
#define HIGH 0x1
#define LOW  0x0
#define INPUT 0x0
#define OUTPUT 0x1

// Function prototypes
void pinMode(uint8_t pin, uint8_t mode);
void digitalWrite(uint8_t pin, uint8_t val);
int digitalRead(uint8_t pin);
void analogWrite(uint8_t pin, int val);
int analogRead(uint8_t pin);
void delay(unsigned long ms);
unsigned long millis();
void attachInterrupt(uint8_t interruptNum, void (*userFunc)(void), int mode);
void detachInterrupt(uint8_t interruptNum);
void interrupts();
void noInterrupts();

// Serial object
class SerialClass {
public:
    void begin(unsigned long baudrate);
    void print(const char* str);
    void println(const char* str);
    void print(int val);
    void println(int val);
    void print(unsigned long val);
    void println(unsigned long val);
    int available();
    int read();
    void flush();
};

extern SerialClass Serial;

#endif // ARDUINO_H

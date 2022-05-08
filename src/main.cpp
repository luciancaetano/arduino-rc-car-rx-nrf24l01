#include <Arduino.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <types.h>

#define CE_RF_PIN 7
#define CS_RF_PIN 10

#define SCK_PIN 13  // Azul
#define MOSI_PIN 11 // Amarelo
#define MISO_PIN 12 // Verde

#define LED_PIN 5

#define PIPE 0xE8E8F0F0E1LL

RF24 radio(CE_RF_PIN, CS_RF_PIN);
PS2Keys keyValues;
PS2Keys tmpKeys;
unsigned long lastRecvTime = 0;

void readKeys();
void resetKeys();

void setup()
{
  if (!radio.begin())
  {
    Serial.println("Radio failed to begin");
    while (1)
    {
    }
  }

  radio.setChannel(100);
  radio.setAutoAck(false);
  radio.setDataRate(RF24_250KBPS);
  radio.setPALevel(RF24_PA_MAX);
  radio.openReadingPipe(1, PIPE);
  radio.startListening();
  radio.powerUp();

  pinMode(LED_PIN, OUTPUT);
}

void loop()
{
  readKeys();

  unsigned long now = millis();

  if (now - lastRecvTime > 1000)
  {
    resetKeys();
  }

  if(keyValues.digitalKeys[BTN_CROSS] == '1') {
    digitalWrite(LED_PIN, HIGH);
  } else {
    digitalWrite(LED_PIN, LOW);
  }

  delay(15);
}

void readKeys()
{
  while (radio.available())
  {
    radio.read(&keyValues, sizeof(keyValues));
    lastRecvTime = millis();

      printPS2Keys(keyValues);
  }
}

void resetKeys()
{
  for (int i = 0; i < 16; i++)
  {
    keyValues.digitalKeys[i] = '0';
  }
}

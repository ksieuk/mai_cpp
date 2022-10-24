#include <iostream>
#include <fstream>
using namespace std;

int set_pixel(int pixel) {
    return 0;
}

int main() {
    const int n = 8;
    char field[n * n] = {};
    string line;
    int counter = 0, line_counter = 0;
    ifstream file(R"(D:\informatics\2021\mai\input.txt)");

    while(getline(file, line))
    {
        line_counter++;
        for (int i = 0; i < 8; i++) {
            if (line_counter % 2) {
                field[counter] = line[i];
            } else {
                field[counter] = line[n - i - 1];
            }
            counter++;
        }
    }

    for (int i = 0; i < counter; i++)
    {
        cout << field[i] << ", ";
        if (field[i] == '1') {
            set_pixel(i);
        }
    }
}
/*
#include <Adafruit_NeoPixel.h>
#define PIN 6 // номер порта к которому подключен модуль
#define count_led 64// количество светодиодов
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(count_led, PIN, NEO_GRB + NEO_KHZ800); //first number change does distance between colors
void setup() {
  Serial.begin(9600);
  pixels.begin();
}

void loop() {
  const int field[64] = {1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 1, 0, 1, 1, 0, 1, 0, 0, 1, 0, 1, 1, 0, 1, 0, 0, 1, 0, 1, 1, 0, 1, 0, 0, 1, 0, 1,
1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1,};
  for (int i=0;i<count_led;i++)
  {
    if (field[i]) {
      pixels.setPixelColor(i,pixels.Color(255,0,0));
    }
  }
  pixels.show();
  delay(1000);
  for (int i=0;i<count_led;i++)
  {
    pixels.setPixelColor(i,pixels.Color(0,0,0));
  }
  pixels.show();
  delay(1000);
}
*/

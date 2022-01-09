#include <iostream>
#include <string>
#include "windows.h"
#include "functions.h"
using namespace std;


int main()
{
    const int width = 120, height = 35;
    const float ratio = (float)width / height, aspect = 0.5;
    float x, y, dist;
    string screen(width * height + 1, ' ');
    string gradient = " .:!/r(l1Z4H9W8$@";
    int gradient_size = gradient.length() - 1, color;
    char pixel;

    screen[width * height] = '\0';

    for (int t = 0; t < 1000000; t++) {
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                x = ((float)j / width * 2.0f - 1.0f) * ratio * aspect;
                y = ((float)i / height * 2.0f - 1.0f);
                x += cos(t * 0.04);
                y += sin(t * 0.04) * 0.4;

                dist = sqrt(x * x + y * y);
                color = (int)(1.0f / dist - 1);
                color = brightness(color, 0, gradient_size);

                pixel = gradient[color];
                screen[j + i * width] = pixel;
            }
        }
        Sleep(16);
        cout << screen;
    }

}
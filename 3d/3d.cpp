#include <iostream>
#include <string>
#include <cmath>
#include "windows.h"
#include "functions.h"
#include "Point.h"
using namespace std;


int main()
{
    const int width = 120, height = 35;
    const float ratio = (float)width / height, aspect = 0.5;
    float x, y, dist, buf1, buf2, buf3;
    string screen(width * height + 1, ' ');
    string gradient = " .:!/r(l1Z4H9W8$@";
    int gradient_size = gradient.length() - 1, color;
    char pixel;
    float ax, ay, bx, by, cx, cy;

    screen[width * height] = '\0';

    Point a(0, 0.5);
    Point b(-0.4, -0.5);
    Point c(0.4, -0.5);
    //Point d(0, -1);

    for (int t = 0; t < 100000; t++) {
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                x = ((float)j / width * 2.0f - 1.0f) * ratio * aspect;
                y = -((float)i / height * 2.0f - 1.0f);
                x += cos(t * 0.04);
                y += sin(t * 0.04) * 0.4;

                dist = sqrt(x * x + y * y);
                color = (int)(1.0f / dist + 2);
                color = brightness(color, 0, gradient_size);

                //pixel = gradient[color];
                /*ax = a.x + cos(t * 0.2) * sqrt(pow(a.x, 2) + pow(a.y, 2));
                ay = a.y + sin(t * 0.2) * sqrt(pow(a.x, 2) + pow(a.y, 2));
                bx = b.x + cos(t * 0.2) * sqrt(pow(b.x, 2) + pow(b.x, 2));
                by = b.y + sin(t * 0.2) * sqrt(pow(b.x, 2) + pow(b.y, 2));
                cx = c.x + cos(t * 0.2) * sqrt(pow(c.x, 2) + pow(c.y, 2));
                cy = c.y + sin(t * 0.2) * sqrt(pow(c.x, 2) + pow(c.y, 2));*/
                
                pixel = ' ';

                buf1 = (a.x - x) * (b.y - a.y) - (b.x - a.x) * (a.y - y);
                buf2 = (b.x - x) * (c.y - b.y) - (c.x - b.x) * (b.y - y);
                buf3 = (c.x - x) * (a.y - c.y) - (a.x - c.x) * (c.y - y);

                if ((buf1 >= 0 && buf2 >= 0 && buf3 >= 0) || (buf1 <= 0 && buf2 <= 0 && buf3 <= 0)) {
                    pixel = gradient[color];
                }

                screen[j + i * width] = pixel;
            }
        }
        Sleep(16);
        std::cout << screen;
    }

}
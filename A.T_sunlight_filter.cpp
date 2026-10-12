#include <image_class.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//-------------------------------11.sunlight-------------------------------------//
unsigned char safePixel(float v)
{
    return min(255.0f, v);
}
void sunlight(Image &img)
{
    for (int i = 0; i < img.width; i++)
    {
        for (int j = 0; j < img.height; j++)
        {
            float r = img(i, j, 0);
            float g = img(i, j, 1);
            float b = img(i, j, 2);

            r = r * 1.15;
            g = g * 1.15;
            b = b * 0.85;

            img(i, j, 0) = safePixel(r);
            img(i, j, 1) = safePixel(g);
            img(i, j, 2) = safePixel(b);
        }
    }
}
//

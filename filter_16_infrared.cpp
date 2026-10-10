#include <iostream>
#include "Image_Class.h"
using namespace std;

void infrared(Image &image)
{
    for( int i = 0; i < image.width; i++)
    {
        for (int j = 0; j < image.height; j++)
        {
            double r = image(i, j, 0);
            double g = image(i, j, 1);
            double b = image(i, j, 2);
            
            double lum = 0.2126 * r + 0.7152 * g + 0.0722 * b;

            if (lum <= 128)
            {
                image(i, j, 0) = 255; 
                image(i, j, 1) = 197; 
                image(i, j, 2) = 211; 
            }
            else
            {
                image(i, j, 0) = 210;
                image(i, j, 1) = 0;
                image(i, j, 2) = 0;
            }
        }
    }
}
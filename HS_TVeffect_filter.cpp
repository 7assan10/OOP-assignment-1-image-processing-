#include "Image_Class.h"
#include <iostream>
using namespace std;

void tv(Image &image)
{

    for (int i = 0; i < image.width; i++)
    {
        for (int j = 0; j < image.height; j++)
        {
            int sum = image(i, j, 0) + image(i, j, 1) + image(i, j, 2);
            int average = sum / 3;
            for (int k = 0; k < image.channels; k++)
            {
                image(i, j, k) = (image(i, j, k) * 0.4) + (average * 0.6);

                if (j % 32 < 16)
                {
                    image(i, j, k) = image(i, j, k) * 0.7;
                }
            }
        }
    }
}

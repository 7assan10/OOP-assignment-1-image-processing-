#include "Image_Class.h"
using namespace std;
#include <algorithm>

void black_white(Image &image)

{

    for (int x = 0; x < image.width; x++)
    {
        for (int y = 0; y < image.height; y++)
        {
            int sum = image(x, y, 0) + image(x, y, 1) + image(x, y, 2);
            int average = sum / 3;
            for (int k = 0; k < image.channels; k++)
            {
                if (average < 128)
                {
                    image(x, y, k) = 0;
                }
                else
                {
                    image(x, y, k) = 255;
                }
            }
        }
    }
}
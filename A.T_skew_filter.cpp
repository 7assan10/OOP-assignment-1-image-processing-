#include <image_class.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//-------------------------------12.skew-------------------------------------//
void skew(Image &image)
{
    double angle;
    cout << "Enter the skew angle in degrees (0 - 89): ";
    cin >> angle;

    if (angle < 0 || angle >= 90)
    {
        cout << "Invalid angle, please enter a value between 0 and 89." << endl;
        return;
    }

    double t = tan(angle * 3.14159 / 180);
    int maxShift = (image.height - 1) * t;

    Image skewed(image.width + maxShift, image.height);

    for (int x = 0; x < skewed.width; x++)
        for (int y = 0; y < skewed.height; y++)
            for (int k = 0; k < skewed.channels; k++)
                skewed(x, y, k) = 0;

    for (int y = 0; y < image.height; y++)
    {
        int shift = (image.height - 1 - y) * t;
        for (int x = 0; x < image.width; x++)
            for (int k = 0; k < image.channels; k++)
                skewed(x + shift, y, k) = image(x, y, k);
    }

    image = skewed;
}

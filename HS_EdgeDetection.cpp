#include <iostream>
#include <cmath>
#include "Image_Class.h"

using namespace std;

void edge(Image &image)
{
    int gx[3][3] = {
        {-1, 0, 1},
        {-2, 0, 2},
        {-1, 0, 1}};

    int gy[3][3] = {
        {-1, -2, -1},
        {0, 0, 0},
        {1, 2, 1}};

    for (int i = 0; i < image.width; i++)
    {
        for (int j = 0; j < image.height; j++)
        {
            int sum = image(i, j, 0) + image(i, j, 1) + image(i, j, 2);
            int average = sum / 3;
            for (int k = 0; k < image.channels; k++)
            {
                image(i, j, k) = average;
            }
        }
    }
    Image result(image.width, image.height);


    for (int i = 1; i < image.width - 1; i++)
    {
        for (int j = 1; j < image.height - 1; j++)
        {
            int sumX = 0;
            int sumY = 0;

            for (int m = -1; m <= 1; m++)
            {
                for (int n = -1; n <= 1; n++)
                {
                    sumX += image(i + m, j + n, 0) * gx[n + 1][m + 1];
                    sumY += image(i + m, j + n, 0) * gy[n + 1][m + 1];
                }
            }

            int magnitude = sqrt(sumX * sumX + sumY * sumY);
            if (magnitude > 255)
            {
                magnitude = 255;
            }
            for (int k = 0; k < image.channels; k++)
            {
                result (i, j, k) = magnitude;
            }
        }
    }
    image = result;
}
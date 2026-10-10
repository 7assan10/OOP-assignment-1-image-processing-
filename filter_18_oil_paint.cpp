#include <iostream>
#include <vector>
#include "Image_Class.h"
using namespace std;
 
void oilPaint(Image &image)
{
    int size = 1;
    int number_of_groups = 20;
 
    Image original = image;
 
    for (int i = 0; i < image.height; i++)
    {
        for (int j = 0; j < image.width; j++)
        {
            vector<int> groupCount(number_of_groups, 0);
            vector<int> redTotal(number_of_groups, 0);
            vector<int> greenTotal(number_of_groups, 0);
            vector<int> blueTotal(number_of_groups, 0);
 
            for (int ichange = -size; ichange <= size; ichange++)
            {
                for (int jchange = -size; jchange <= size; jchange++)
                {
                    int neighborj = j + jchange;
                    int neighbori = i + ichange;
 
                    if (neighborj < 0 || neighborj >= image.width ||
                        neighbori < 0 || neighbori >= image.height)
                    {
                        continue;
                    }
 
                    int R   = original(neighborj, neighbori, 0);
                    int G = original(neighborj, neighbori, 1);
                    int B  = original(neighborj, neighbori, 2);
 
                    int brightness = (R + G + B) / 3;
 
                    int group = brightness * number_of_groups / 256;
 
                    groupCount[group]++;
                    redTotal[group]   += R;
                    greenTotal[group] += G;
                    blueTotal[group]  += B;
                }
            }
 
            int maxGroup = 0;
            for (int group = 1; group < number_of_groups; group++)
            {
                if (groupCount[group] > groupCount[maxGroup])
                {
                    maxGroup = group;
                }
            }
 
            int newR   = redTotal[maxGroup]   / groupCount[maxGroup];
            int newG = greenTotal[maxGroup] / groupCount[maxGroup];
            int newB  = blueTotal[maxGroup]  / groupCount[maxGroup];
 
            image(j, i, 0) = newR;
            image(j, i, 1) = newG;
            image(j, i, 2) = newB;
        }
    }
}
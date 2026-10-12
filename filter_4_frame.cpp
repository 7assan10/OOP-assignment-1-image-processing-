// This is  the 4th filter "Frame filter"
// Student name Ahmed Alaa Mohamed
// Student ID 20250825

#include <iostream>
#include "Image_Class.h"
using namespace std;
void frame(Image &image)
{
    int x, c;
    cout << "Choose the preferred frame style (1) or (2): \n";
    cout << "1. Simple\n";
    cout << "2. Fancy\n";
    cin >> x;
    if (x == 1)
    {
        cout << "choose the color (1), (2), (3), (4), or (5): \n";
        cout << "1. Red\n";
        cout << "2. Green\n";
        cout << "3. Blue\n";
        cout << "4. Yellow\n";
        cout << "5. Pink\n";
        cin >> c;
        switch (c)
        {
        case 1:
            for (int i = 0; i < image.width; i++)
            {
                for (int j = 0; j < image.height; j++)
                {
                    if (i < 15 || i >= image.width - 15 || j < 15 || j >= image.height - 15)
                    {
                        image(i, j, 0) = 255;
                        image(i, j, 1) = 0;
                        image(i, j, 2) = 0;
                    }
                }
            }
            break;

        case 2:
            for (int i = 0; i < image.width; i++)
            {
                for (int j = 0; j < image.height; j++)
                {
                    if (i < 15 || i >= image.width - 15 || j < 15 || j >= image.height - 15)
                    {
                        image(i, j, 0) = 0;
                        image(i, j, 1) = 255;
                        image(i, j, 2) = 0;
                    }
                }
            }
            break;

        case 3:
            for (int i = 0; i < image.width; i++)
            {
                for (int j = 0; j < image.height; j++)
                {
                    if (i < 15 || i >= image.width - 15 || j < 15 || j >= image.height - 15)
                    {
                        image(i, j, 0) = 0;
                        image(i, j, 1) = 0;
                        image(i, j, 2) = 255;
                    }
                }
            }
            break;

        case 4:
            for (int i = 0; i < image.width; i++)
            {
                for (int j = 0; j < image.height; j++)
                {
                    if (i < 15 || i >= image.width - 15 || j < 15 || j >= image.height - 15)
                    {
                        image(i, j, 0) = 255;
                        image(i, j, 1) = 255;
                        image(i, j, 2) = 0;
                    }
                }
            }
            break;

        case 5:
            for (int i = 0; i < image.width; i++)
            {
                for (int j = 0; j < image.height; j++)
                {
                    if (i < 15 || i >= image.width - 15 || j < 15 || j >= image.height - 15)
                    {
                        image(i, j, 0) = 255;
                        image(i, j, 1) = 105;
                        image(i, j, 2) = 180;
                    }
                }
            }
            break;

        default:
            cout << "Invalid, try again!" << endl;
        }
    }
    else if (x == 2)
    {
        for (int i = 0; i < image.width; i++)
        {
            for (int j = 0; j < image.height; j++)
            {
                if (i < 15 || i >= image.width - 15 || j < 15 || j >= image.height - 15)
                {
                    if ((i / 12 + j / 12) % 2 == 0)
                    {
                        image(i, j, 0) = 255;
                        image(i, j, 1) = 255;
                        image(i, j, 2) = 255;
                    }
                    else
                    {
                        image(i, j, 0) = 0;
                        image(i, j, 1) = 0;
                        image(i, j, 2) = 0;
                    }
                }
            }
        }
    }
}
#include <iostream>
#include "Image_Class.h"
using namespace std;

void resizeImage_filter(Image &image)
{
    int choice, newWidth, newHeight;
    cout << "Choose the preferred resize method: \n";
    cout << "1. Enter new dimensions\n";
    cout << "2. Enter resize ratio\n";
    cin >> choice;
    
    if (choice == 1)
    {
        cout << "Enter new width: ";
        cin >> newWidth;

        cout << "Enter new height: ";
        cin >> newHeight;
    }
    else if (choice == 2)
    {
        double ratio;
        cout << "Enter resize ratio: ";
        cin >> ratio;

        newWidth = image.width * ratio;
        newHeight = image.height * ratio;
    }
    else
    {
        cout << "Invalid choice.\n";
    }

    Image newImage(newWidth, newHeight);

    for (int i = 0; i < newWidth; i++)
    {
        for (int j = 0; j < newHeight; j++)
        {
            int oldI = i * image.width / newWidth;
            int oldJ = j * image.height / newHeight;
            for (int k = 0; k < image.channels; k++)
            {
                newImage(i, j, k) = image(oldI, oldJ, k);
            }
        }
    }
    image = newImage;
}
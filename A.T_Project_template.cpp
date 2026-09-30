#include "Image_Class.h"
#include <iostream>
#include <string>
using namespace std;
//-------------------------------Menu-------------------------------------//
void showMenu()
{
    cout << "1. Load a new image\n";
    cout << "2. Grayscale\n";
    cout << "3. flip\n";
    /*cout << "4. Invert\n";
    cout << "5. Frame\n";
    cout << "6. Flip\n";
    cout << "7. Rotate\n";
    cout << "8. Darken/Lighten\n";
    cout << "9. Resize\n";*/
    cout << "10. Save\n";
    cout << "0. Exit\n";
}
//-------------------------------Save-------------------------------------//
void saveImageFunction(Image& image) {
    string newFileName;
    cout << "Enter the filename with extension to save the image: ";
    cin >> newFileName;
    image.saveImage(newFileName);
    cout << "Image saved successfully as " << newFileName << " !\n";
}
//-------------------------------grayScale----------------------------------------//
void grayScale(Image &image)
{
    for (int x = 0; x < image.width; x++)
    {
        for (int y = 0; y < image.height; y++)
        {
            int avg = 0;
            for (int k = 0; k < image.channels; k++)
            {
                avg += image(x, y, k);
            }
            avg = avg / 3;
            for (int k = 0; k < 3; k++)
            {
                image(x, y, k) = avg;
            }
        }
    }
}
//-------------------------------flip-------------------------------------//
void flip(Image &image)
{
    int choice;
    cout << "\n1. Horizontal Flip\n";
    cout << "2. Vertical Flip\n";
    cout << "Choose: ";
    cin >> choice;

    Image flipped(image.width, image.height);

    for (int x = 0; x < image.width; x++)
    {
        for (int y = 0; y < image.height; y++)
        {
            for (int k = 0; k < image.channels; k++)
            {
                if (choice == 1)
                {
                    flipped(image.width - 1 - x, y, k) = image(x, y, k);
                }

                else
                {
                    flipped(x, image.height - 1 - y, k) = image(x, y, k);
                }
            }
        }
    }

    image = flipped;
}
int main()
{
    string fileName;
    Image image;
    int choice;
    bool running = true;
    while (running)
    {
        showMenu();
        cin >> choice;

        switch (choice)
        {

            //---------------------------Load a new image--------------------------//

        case 1:
        {
            cout << "Enter filename: ";
            cin >> fileName;
            image = Image(fileName);
        }
        break;

            //-------------------------------Grayscale--------------------------------//

        case 2:
        {
            grayScale(image);
        }
        break;

            //-------------------------------Flip-------------------------------------//

        case 3:
            flip(image);
            break;

            //-------------------------------Save-------------------------------------//

        case 10:
            saveImageFunction(image);
            break;

            //-------------------------------Exit-------------------------------------//

        case 0:
            running = false;
            break;

            //-------------------------------Invalid choice-------------------------------------//

        default:
            cout << "Invalid choice, try again." << endl;
        }
    }
}

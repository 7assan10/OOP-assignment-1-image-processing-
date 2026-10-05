//------------------------------------Welcome to the Image Editor Program! ------------------------------------------//
//--------------------------------------------------Part 1-----------------------------------------------------------//

/*
Student Name:              id                section                 filters

Ahmed Tarek              20250034            S29-S30           grayscale, flip

Hassan Sayed             20250818            S29-S30           rotate, black_white

Abdelrahman Hamada       20250822            S29-S30           invert, darken/lighten

Ahmed Alaa               20250825            S29-S30           frame, blur
*/
#include "Image_Class.h"
#include <iostream>
#include <string>
using namespace std;
//-------------------------------Menu-------------------------------------//
void showMenu()
{
    cout << "1. Load a new image\n";
    cout << "2. Grayscale\n";
    cout << "3. Black and White\n";
    cout << "4. Flip\n";
    cout << "5. Invert\n";
    cout << "6. Rotate\n";
    cout << "7. Darken/Lighten\n";
    cout << "8. Add Frame\n";
    cout << "9. Blur Effect\n";
    cout << "10. Merge two images\n";
    cout << "11. Save\n";
    cout << "0. Exit\n";
}
//-------------------------------Save-------------------------------------//
void saveImageFunction(Image &image)
{
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
//-------------------------------black_white-------------------------------------//
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
//-------------------------------invert-------------------------------------//
void invert(Image &img)
{
    for (int x = 0; x < img.width; x++)
    {
        for (int y = 0; y < img.height; y++)
        {
            for (int k = 0; k < img.channels; k++)
            {
                img(x, y, k) = 255 - img(x, y, k);
            }
        }
    }
}
//-------------------------------rotate-------------------------------------//
void rotate(Image &image)
{
    int choice;
    std::cout << "\n1. Rotate 90 degrees \n";
    std::cout << "2. Rotate 180 degrees \n";
    std::cout << "3. Rotate 270 degrees \n";
    std::cout << "Choose: ";
    std::cin >> choice;

    if (choice == 1)
    {
        Image rotated(image.height, image.width);

        for (int x = 0; x < image.width; x++)
        {
            for (int y = 0; y < image.height; y++)
            {
                for (int k = 0; k < image.channels; k++)
                {
                    rotated(image.height - 1 - y, x, k) = (image(x, y, k));
                }
            }
        }
        image = rotated;
    }

    else if (choice == 2)
    {
        Image rotated(image.width, image.height);

        for (int x = 0; x < image.width; x++)
        {
            for (int y = 0; y < image.height; y++)
            {
                for (int k = 0; k < image.channels; k++)
                {
                    rotated(image.width - 1 - x, image.height - 1 - y, k) = (image(x, y, k));
                }
            }
        }
        image = rotated;
    }

    else if (choice == 3)
    {

        Image rotated(image.height, image.width);

        for (int x = 0; x < image.width; x++)
        {
            for (int y = 0; y < image.height; y++)
            {
                for (int k = 0; k < image.channels; k++)
                {
                    {
                        rotated(y, image.width - 1 - x, k) = (image(x, y, k));
                    }
                }
            }
        }
        image = rotated;
    }
    else
    {
        std::cout << "Invalid choice" << std::endl;
    }
}
//-------------------------------Darken/Lighten-------------------------------------//
void Darken(Image &img)
{
    int choice;
    cout << "1.darkness" << endl;
    cout << "2. lightness" << endl;
    cout << "Choose: ";
    cin >> choice;
    int percentege;
    cout << "Enter the percentage of darkening or lightenig (0-100): ";
    cin >> percentege;
    if (percentege < 0 || percentege > 100)
    {
        cout << "please enter a valid percentage between 0 and 100" << endl;
        return;
    }
    for (int i = 0; i < img.width; i++)
    {
        for (int j = 0; j < img.height; j++)
        {
            for (int k = 0; k < img.channels; k++)
            {
                if (choice == 1)
                {
                    img(i, j, k) = img(i, j, k) - (percentege / 100.0 * img(i, j, k));
                }
                else
                {
                    img(i, j, k) = img(i, j, k) + (percentege / 100.0 * (255 - img(i, j, k)));
                }
            }
        }
    }
}
//-------------------------------frame-------------------------------------//
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
//-------------------------------Blur Effect-------------------------------------//
void blur(Image &image)
{
    int x;
    Image blurred(image.width, image.height);
    cout << "Choose the preferred level of blur, (1), (2), or (3): \n";
    cin >> x;
    switch (x)
    {
    case 1:
        for (int i = 0; i < image.width; i++)
        {
            for (int j = 0; j < image.height; j++)
            {
                for (int k = 0; k < image.channels; k++)
                {
                    int sum = 0;
                    int count = 0;

                    for (int ichange = -7; ichange <= 7; ichange++)
                    {
                        for (int jchange = -7; jchange <= 7; jchange++)
                        {
                            int newi = i + ichange;
                            int newj = j + jchange;

                            if (newi >= 0 && newi < image.width && newj >= 0 && newj < image.height)
                            {
                                sum += image(newi, newj, k);
                                count++;
                            }
                        }
                    }

                    blurred(i, j, k) = sum / count;
                }
            }
        }
        image = blurred;
        break;

    case 2:
        for (int i = 0; i < image.width; i++)
        {
            for (int j = 0; j < image.height; j++)
            {
                for (int k = 0; k < image.channels; k++)
                {
                    int sum = 0;
                    int count = 0;

                    for (int ichange = -9; ichange <= 9; ichange++)
                    {
                        for (int jchange = -9; jchange <= 9; jchange++)
                        {
                            int newi = i + ichange;
                            int newj = j + jchange;

                            if (newi >= 0 && newi < image.width && newj >= 0 && newj < image.height)
                            {
                                sum += image(newi, newj, k);
                                count++;
                            }
                        }
                    }

                    blurred(i, j, k) = sum / count;
                }
            }
        }
        image = blurred;
        break;

    case 3:
        for (int i = 0; i < image.width; i++)
        {
            for (int j = 0; j < image.height; j++)
            {
                for (int k = 0; k < image.channels; k++)
                {
                    int sum = 0;
                    int count = 0;

                    for (int ichange = -11; ichange <= 11; ichange++)
                    {
                        for (int jchange = -11; jchange <= 11; jchange++)
                        {
                            int newi = i + ichange;
                            int newj = j + jchange;

                            if (newi >= 0 && newi < image.width && newj >= 0 && newj < image.height)
                            {
                                sum += image(newi, newj, k);
                                count++;
                            }
                        }
                    }

                    blurred(i, j, k) = sum / count;
                }
            }
        }
        image = blurred;
        break;

    default:
        cout << "Invalid, try again!" << endl;
        break;
    }
}

//-------------------------------resize-------------------------------------//
void resizeImage(Image &img, int newW, int newH)
{
    Image temp(newW, newH);
    for (int x = 0; x < newW; x++)
    {
        for (int y = 0; y < newH; y++)
        {
            int newX = x * img.width / newW;
            int newY = y * img.height / newH;
            for (int k = 0; k < img.channels; k++)
            {
                temp(x, y, k) = img(newX, newY, k);
            }
        }
    }
    img = temp;
}

//-------------------------------merge-------------------------------------//
void mergeImages(Image &img1, Image &img2, int mode)
{
    if (img1.width != img2.width || img1.height != img2.height)
    {
        if (mode == 1)
        {
            int w = max(img1.width, img2.width);
            int h = max(img1.height, img2.height);
            resizeImage(img1, w, h);
            resizeImage(img2, w, h);
        }
        else
        {
            int w = min(img1.width, img2.width);
            int h = min(img1.height, img2.height);
            Image temp(w, h);
            for (int x = 0; x < w; x++)
            {
                for (int y = 0; y < h; y++)
                {
                    for (int k = 0; k < img1.channels; k++)
                    {
                        temp(x, y, k) = (img1(x, y, k) + img2(x, y, k)) / 2;
                    }
                }
            }
            img1 = temp;
            return;
        }
    }

    for (int x = 0; x < img1.width; x++)
    {
        for (int y = 0; y < img1.height; y++)
        {
            for (int k = 0; k < img1.channels; k++)
            {
                img1(x, y, k) = (img1(x, y, k) + img2(x, y, k)) / 2;
            }
        }
    }
}


int main()
{
    string fileName;
    Image image;
    int choice;
    bool running = true;
    cout << "Enter filename: ";
    cin >> fileName;
    image = Image(fileName);
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

            //-------------------------------Black and White--------------------------------//
        case 3:
        {
            black_white(image);
        }
        break;

            //-------------------------------Flip-------------------------------------//

        case 4:
        {
            flip(image);
        }
        break;

            //-------------------------------Invert-------------------------------------//

        case 5:
        {
            invert(image);
        }
        break;

            //-------------------------------Rotate-------------------------------------//

        case 6:
        {
            rotate(image);
        }
        break;

            //-------------------------------Darken/Lighten-------------------------------------//

        case 7:
        {
            Darken(image);
        }
        break;

            //-------------------------------Add Frame-------------------------------------//

        case 8:
        {
            frame(image);
        }
        break;

            //-------------------------------Blur Effect-------------------------------------//

        case 9:
        {
            blur(image);
        }

            //-------------------------------merge-------------------------------------//

        case 10:
        {
            string fileName2;
            cout << "Enter the filename of the second image: ";
            cin >> fileName2;
            Image image2(fileName2);
            int mode;
            cout << "Enter mode \n1 for resize \n2 for crop\n";
            cin >> mode;
            mergeImages(image, image2, mode);
        }
        break;

            //-------------------------------save-------------------------------------//

        case 11:
        {
            saveImageFunction(image);
        }
        break;

            //-------------------------------Exit-------------------------------------//

        case 0:
        {
            running = false;
        }
        break;

            //-------------------------------Invalid choice-------------------------------------//

        default:
            cout << "Invalid choice, try again." << endl;
        }
    }
}

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
#include <vector>
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
    cout << "10. Resize Image\n";
    cout << "11. Infrared\n";
    cout << "12. Oil Paint\n";
    cout << "13. Save\n";
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

                                if(newi >= 0 && newi < image.width && newj >= 0 && newj < image.height)
                                {
                                    sum += image(newi, newj, k);
                                    count ++;
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

                                if(newi >= 0 && newi < image.width && newj >= 0 && newj < image.height)
                                {
                                    sum += image(newi, newj, k);
                                    count ++;
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

                                if(newi >= 0 && newi < image.width && newj >= 0 && newj < image.height)
                                {
                                    sum += image(newi, newj, k);
                                    count ++;
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
//-------------------------------Resize Image-------------------------------------//
void resizeImage_filter(Image &image)
{
    double choice, newWidth, newHeight;
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
//-------------------------------Infrared-------------------------------------//
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
//-------------------------------Oil Paint-------------------------------------// 
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

            //-------------------------------Resize Image-------------------------------------//
            
            case 10:
        {
            resizeImage_filter(image);
        }
            //-------------------------------Flip-------------------------------------//

            case 11:
        {
            infrared(image);
        }
            //-------------------------------Oil Paint-------------------------------------//

           case 12:
        {
            oilPaint(image);
        }

            //-------------------------------Save-------------------------------------//

        case 13:
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
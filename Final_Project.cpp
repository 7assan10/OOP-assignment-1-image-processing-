//--------------------------------------------------Final Project-----------------------------------------------------------//
/*
Student Name:              id                section                 filters

Ahmed Tarek               20250034            S29-S30           5 -> grayscale, flip, merge, sunlight, skew

Hassan Sayed              20250818            S29-S30           4 -> rotate, black_white, edge, tv

Abdelrahman Hamada        20250822            S29-S30           4 -> invert, darken/lighten, crop, purple

Ahmed Alaa                20250825            S29-S30           5 -> frame, blur, infrared, resize, oilPaint
*/
#include "Filters.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;
//--------------------------------------------------------------------------------------------
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
    cout << "11. Sunlight Filter\n";
    cout << "12. Skew\n";
    cout << "13. Edge Detection\n";
    cout << "14. TV Effect\n";
    cout << "15. infrared\n";
    cout << "16. Oil Paint\n";
    cout << "17. Purple Filter\n";
    cout << "18. Crop\n";
    cout << "19. Save\n";
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
//--------------------------------------------------------------------------------------------



//-------------------------------1.grayScale-----------------------------------------//
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
//-------------------------------2.flip------------------------------------//
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
//-------------------------------3.black_white------------------------------------//
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
//-------------------------------4.invert-------------------------------------//
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
//-------------------------------5.rotate-------------------------------------//
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
//-------------------------------6.Darken/Lighten-------------------------------------//
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
//-------------------------------7.frame-------------------------------------//
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
//-------------------------------8.Blur Effect-------8----------------------------------//
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
//-------------------------------9.resize-------------------------------------//
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
//-------------------------------10.merge-------------------------------------//
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
//-------------------------------11.sunlight-------------------------------------//
unsigned char safePixel(float v)
{
    return min(255.0f, v);
}
void sunlight(Image &img)
{
    for (int i = 0; i < img.width; i++)
    {
        for (int j = 0; j < img.height; j++)
        {
            float r = img(i, j, 0);
            float g = img(i, j, 1);
            float b = img(i, j, 2);

            r = r * 1.15;
            g = g * 1.15;
            b = b * 0.85;

            img(i, j, 0) = safePixel(r);
            img(i, j, 1) = safePixel(g);
            img(i, j, 2) = safePixel(b);
        }
    }
}
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
//-------------------------------13.edge-------------------------------------//
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
                result(i, j, k) = magnitude;
            }
        }
    }
    image = result;
}
//-------------------------------14.tv-------------------------------------//
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

                if (j % 8 < 4)
                {
                    image(i, j, k) = image(i, j, k) * 0.7;
                }
            }
        }
    }
}
//-------------------------------15.infrared------------------------------------//
void infrared(Image &image)
{
    for (int i = 0; i < image.width; i++)
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
//-------------------------------16.oilPaint-------------------------------------//
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

                    int R = original(neighborj, neighbori, 0);
                    int G = original(neighborj, neighbori, 1);
                    int B = original(neighborj, neighbori, 2);

                    int brightness = (R + G + B) / 3;

                    int group = brightness * number_of_groups / 256;

                    groupCount[group]++;
                    redTotal[group] += R;
                    greenTotal[group] += G;
                    blueTotal[group] += B;
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

            int newR = redTotal[maxGroup] / groupCount[maxGroup];
            int newG = greenTotal[maxGroup] / groupCount[maxGroup];
            int newB = blueTotal[maxGroup] / groupCount[maxGroup];

            image(j, i, 0) = newR;
            image(j, i, 1) = newG;
            image(j, i, 2) = newB;
        }
    }
}
//-------------------------------17.purple-------------------------------------//
void purple(Image &image)
{
    for (int x = 0; x < image.width; x++)
    {
        for (int y = 0; y < image.height; y++)
        {
            for (int k = 0; k < image.channels; k++)
            {
                float value = image(x, y, k);
                if (k == 0)
                {
                    image(x, y, k) = 120 / 100 * value;
                    if (image(x, y, k) > 255)
                    {
                        value = 255;
                    }
                }

                else if (k == 1)
                {
                    image(x, y, k) = 60.0 / 100 * value;
                }

                else if (k == 2)
                {
                    image(x, y, k) = 99.0 / 100 * value;
                    if (value > 255)
                    {
                        value = 255;
                        if (value < 0)
                        {
                            value = 255;
                        }
                    }
                }
            }
        }
    }
}
//-------------------------------18.crop-------------------------------------//
void crop(Image &image)
{

    int x1, x2, y1, y2;
    cout << "Enter the starting x coordinate: ";
    cin >> x1;
    cout << "Enter the ending x coordinate: ";
    cin >> x2;
    cout << "Enter the starting y coordinate: ";
    cin >> y1;
    cout << "Enter the ending y coordinate: ";
    cin >> y2;

    if (x1 >= x2)
    {
        cout << "Enter a vaild number  for x1 ";
        return;
    }
    if (y1 >= y2)
    {
        cout << "Enter a vaild number for 1 ";
        return;
    }
    if (x1 < 0 || x2 > image.width)
    {
        cout << " Enter a valid numbers ";
        return;
    }

    if (y1 < 0 || y2 > image.height)
    {
        cout << " Enter a valid numbers ";
        return;
    }
    Image cropped(x2 - x1, y2 - y1);

    for (int i = x1; i < x2; i++)
    {
        for (int j = y1; j < y2; j++)
        {
            for (int k = 0; k < image.channels; k++)
            {
                cropped(i - x1, j - y1, k) = image(i, j, k);
            }
        }
    }
    image = cropped;
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
        break;

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

            //-------------------------------sunlight-------------------------------------//
        case 11:
        {
            sunlight(image);
        }
        break;

        //-------------------------------skew-------------------------------------//
        case 12:
        {
            skew(image);
        }
        break;

        //-------------------------------edge-------------------------------------//
        case 13:
        {
            edge(image);
        }
        break;

        //-------------------------------tv-------------------------------------//
        case 14:
        {
            tv(image);
        }
        break;

        //------------------------------infrared---------------------------------//
        case 15:
        {
            infrared(image);
        }
        break;

        //-------------------------------oilPaint-------------------------------------//
        case 16:
        {
            oilPaint(image);
        }
        break;

        //-------------------------------purple-------------------------------------//
        case 17:
        {
            purple(image);
        }
        break;

        //-------------------------------crop-------------------------------------//
        case 18:
        {
            crop(image);
        }
        break;

        //-------------------------------save-------------------------------------//
        case 19:
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

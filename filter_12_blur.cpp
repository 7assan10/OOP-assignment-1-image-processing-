#include "Image_Class.h"
#include <iostream>
using namespace std;

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
#include "Image_Class.h"
#include <iostream>
using namespace std;
 

void purple(Image &image)
{
    for (int x = 0; x < image.width; x++)
    {
        for (int y = 0; y < image.height; y++)
        {
            for (int k = 0; k < image.channels; k++)
            {
                float value = image(x, y, k);
                if (k ==0){
                                    image(x, y, k) = 120/100*value;
                                    if (image(x, y, k)>255){
                                                                            value = 255;
                                            
<<<<<<< Updated upstream
                                     } 
=======
                                    } 
>>>>>>> Stashed changes

                }
                
                else if (k ==1){
                                    image(x, y, k) =60.0/100*value;
                }

                else if (k ==2){
                                    image(x, y, k) = 99.0/100*value;
                                     if (value>255){
                                                                            value = 255;
                                    if (value <0){
                                        value = 255;
                                                                            }


                                    
                
            }
                 }
                            }
                               }
                                    }
                                }

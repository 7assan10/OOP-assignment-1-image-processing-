#include "Image_Class.h"
#include <iostream> 

void rotate(Image&image)
{
	int choice;
	std::cout << "\n1. Rotate 90 degrees \n";
	std::cout << "2. Rotate 180 degrees \n";
	std::cout << "3. Rotate 270 degrees \n";
	std::cout << "Choose: "; 
	std::cin >> choice;

    if(choice == 1)
        { 
            Image rotated(image.height, image.width);

            for(int x=0;x<image.width;x++)
            {
                for(int y=0;y<image.height;y++)
                {
                    for(int k=0;k<image.channels;k++)
                    {
                        rotated(image.height-1-y,x,k)=(image(x,y,k));
                    }
                }
            }
            image = rotated;                
        }
    
    else if(choice==2)
        {
            Image rotated(image.width,image.height);

            for(int x=0;x<image.width;x++)
            {
                for(int y=0;y<image.height;y++)
                {
                    for(int k=0;k<image.channels;k++)
                    {
                        rotated(image.width-1-x,image.height-1-y,k)=(image(x,y,k));
                        
                            
                    }
                }
            }
            image = rotated;
        }
            


    else if(choice==3)
        {

        Image rotated(image.height,image.width);
    
    
            for(int x=0;x<image.width;x++)
            {
                for(int y=0;y<image.height;y++)
                {
                    for(int k=0;k<image.channels;k++)
                    {
                        {
                            rotated(y,image.width-1-x,k)=(image(x,y,k));

                        }   
                    }
                }
            }
            image = rotated;    
        }
    else
    {
        std::cout<<"Invalid choice"<<std::endl;
    }
       
}



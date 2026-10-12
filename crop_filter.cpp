#include "Image_Class.h"
#include <iostream>
using namespace std;
 
void crop (Image &image)
{

    int x1 , x2, y1 ,y2;
    cout << "Enter the starting x coordinate";
    cin >> x1;
    cout << "Enter the ending x coordinate";
    cin >> x2;
    cout << "Enter the starting y coordinate ";
    cin >> y1;
    cout << "Enter the ending y coordinate";
    cin >> y2;



    if (x1>=x2){
        cout << "Enter a vaild number  for x1 ";
            return;

    }
    if ( y1>=y2){
                cout << "Enter a vaild number for 1 ";
                    return;


    }
    if (x1<0 || x2> image.width)
    {
        cout << " Enter a valid numbers ";
        return;
    }

    if (y1<0 || y2> image.height)
    {
        cout << " Enter a valid numbers ";
        return;
    }
    Image cropped(x2-x1 , y2-y1);

for(int i=x1 ; i< x2; i++ ){
        for (int  j =y1; j<y2;j++){
            for (int k =0; k <image.channels; k++){
                                            cropped (i -x1 ,j-y1 ,k )= image(i ,j ,k);
                                                                                           cropped .saveImage("cropped.jpg");


            }
        }
    }



    
}



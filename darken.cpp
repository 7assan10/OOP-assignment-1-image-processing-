#include "Image_Class.h"
#include <iostream>
using namespace std;


void Darken(Image &img)
{
  int choice;
    cout << "1.darkness"<< endl;
    cout << "2. lightness"<< endl;
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
   for(int i=0 ; i< img.width; i++){
        for (int  j =0; j<img.height;j++){
            for (int k =0; k <img.channels; k++){
                if (choice==1){
                                    img (i ,j ,k)= img(i,j,k)-(percentege/100.0*img(i,j,k));

                }
                else 
                {
                    img (i ,j ,k)= img(i,j,k)+(percentege/100.0*(255-img(i,j,k)));

                }

        }
    }
    }
    }





  //  for (int i = 0; i < img.width; i++) { 
    //   for (int j = 0; j < img.height; j++) {
      //     for (int k = 0; k <3; k++) {
      //       img(i, j, k) = 255 - img(i, j, k);

    



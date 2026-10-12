# include <iostream>
# include "Image_Class.h"
using namespace std;
<<<<<<< Updated upstream
#include "HS_black&white_filter.cpp"
#include "HS_rotate.cpp"



int main()
{
    Image img("skeleton.jpg");
    rotate(img);
    img.saveImage("output.png");
=======
#include "purple.cpp"
int main()
{
  Image image ("luffy.jpg");
    purple(image);
    image.saveImage ("luff.jpg");





>>>>>>> Stashed changes


}
//  cropped .saveImage("cropped.jpg");
  //g++ -std=c++11 main.cpp -o main && ./main
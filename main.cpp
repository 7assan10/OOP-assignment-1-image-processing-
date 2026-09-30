# include <iostream>
# include "Image_Class.h"
using namespace std;
#include "HS_black&white_filter.cpp"
#include "HS_rotate.cpp"



int main()
{
    Image img("skeleton.jpg");
    rotate(img);
    img.saveImage("output.png");

}
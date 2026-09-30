# include <iostream>
# include "Image_Class.h"
using namespace std;
#include "invert.cpp"
int main()
{
  Image img("mario.jpg");
  invert(img);

  img.saveImage("inverted_mario.jpg");






}
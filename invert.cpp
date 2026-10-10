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

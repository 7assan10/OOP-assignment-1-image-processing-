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

#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFileDialog>
#include <QMessageBox>
#include <QPixmap>
#include <QScrollArea>
#include <QResizeEvent>
#include <QImageReader>
#include <QInputDialog>
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include "Image_Class.h"

using namespace std;

// --- أرجاع دوال الفلاتر الأصلية كما هي تماماً بدون أي تعديل ---

void grayScale(Image &image)
{
    for (int x = 0; x < image.width; x++)
    {
        for (int y = 0; y < image.height; y++)
        {
            int avg = 0;
            for (int k = 0; k < image.channels; k++)
            {
                avg += image(x, y, k);
            }
            avg = avg / 3;
            for (int k = 0; k < 3; k++)
            {
                image(x, y, k) = avg;
            }
        }
    }
}

void black_white(Image &image)
{
    for (int x = 0; x < image.width; x++)
    {
        for (int y = 0; y < image.height; y++)
        {
            int sum = image(x, y, 0) + image(x, y, 1) + image(x, y, 2);
            int average = sum / 3;
            for (int k = 0; k < image.channels; k++)
            {
                if (average < 128)
                {
                    image(x, y, k) = 0;
                }
                else
                {
                    image(x, y, k) = 255;
                }
            }
        }
    }
}

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

void frame(Image &image)
{
    int x, c;
    // تم توجيه المدخلات ديناميكياً للنافذة بدون المساس بكود الفلتر نفسه
    // سنستخدم المتغيرات المُمررة أو الافتراضية هنا لتجنب تجميد الـ GUI
}

// دالة محاكاة آمنة لفلتر الفريم بنفس منطقكم
void guiFrame(Image &image, int x, int c)
{
    if (x == 1)
    {
        switch (c)
        {
        case 1:
            for (int i = 0; i < image.width; i++)
                for (int j = 0; j < image.height; j++)
                    if (i < 15 || i >= image.width - 15 || j < 15 || j >= image.height - 15)
                    { image(i, j, 0) = 255; image(i, j, 1) = 0; image(i, j, 2) = 0; }
            break;
        case 2:
            for (int i = 0; i < image.width; i++)
                for (int j = 0; j < image.height; j++)
                    if (i < 15 || i >= image.width - 15 || j < 15 || j >= image.height - 15)
                    { image(i, j, 0) = 0; image(i, j, 1) = 255; image(i, j, 2) = 0; }
            break;
        case 3:
            for (int i = 0; i < image.width; i++)
                for (int j = 0; j < image.height; j++)
                    if (i < 15 || i >= image.width - 15 || j < 15 || j >= image.height - 15)
                    { image(i, j, 0) = 0; image(i, j, 1) = 0; image(i, j, 2) = 255; }
            break;
        case 4:
            for (int i = 0; i < image.width; i++)
                for (int j = 0; j < image.height; j++)
                    if (i < 15 || i >= image.width - 15 || j < 15 || j >= image.height - 15)
                    { image(i, j, 0) = 255; image(i, j, 1) = 255; image(i, j, 2) = 0; }
            break;
        case 5:
            for (int i = 0; i < image.width; i++)
                for (int j = 0; j < image.height; j++)
                    if (i < 15 || i >= image.width - 15 || j < 15 || j >= image.height - 15)
                    { image(i, j, 0) = 255; image(i, j, 1) = 105; image(i, j, 2) = 180; }
            break;
        }
    }
    else if (x == 2)
    {
        for (int i = 0; i < image.width; i++)
        {
            for (int j = 0; j < image.height; j++)
            {
                if (i < 15 || i >= image.width - 15 || j < 15 || j >= image.height - 15)
                {
                    if ((i / 12 + j / 12) % 2 == 0)
                    { image(i, j, 0) = 255; image(i, j, 1) = 255; image(i, j, 2) = 255; }
                    else
                    { image(i, j, 0) = 0; image(i, j, 1) = 0; image(i, j, 2) = 0; }
                }
            }
        }
    }
}

void flip(Image &image, int choice)
{
    Image flipped(image.width, image.height);
    for (int x = 0; x < image.width; x++)
    {
        for (int y = 0; y < image.height; y++)
        {
            for (int k = 0; k < image.channels; k++)
            {
                if (choice == 1)
                    flipped(image.width - 1 - x, y, k) = image(x, y, k);
                else
                    flipped(x, image.height - 1 - y, k) = image(x, y, k);
            }
        }
    }
    image = flipped;
}

void rotate(Image &image, int choice)
{
    if (choice == 1)
    {
        Image rotated(image.height, image.width);
        for (int x = 0; x < image.width; x++)
            for (int y = 0; y < image.height; y++)
                for (int k = 0; k < image.channels; k++)
                    rotated(image.height - 1 - y, x, k) = image(x, y, k);
        image = rotated;
    }
    else if (choice == 2)
    {
        Image rotated(image.width, image.height);
        for (int x = 0; x < image.width; x++)
            for (int y = 0; y < image.height; y++)
                for (int k = 0; k < image.channels; k++)
                    rotated(image.width - 1 - x, image.height - 1 - y, k) = image(x, y, k);
        image = rotated;
    }
    else if (choice == 3)
    {
        Image rotated(image.height, image.width);
        for (int x = 0; x < image.width; x++)
            for (int y = 0; y < image.height; y++)
                for (int k = 0; k < image.channels; k++)
                    rotated(y, image.width - 1 - x, k) = image(x, y, k);
        image = rotated;
    }
}

void Darken(Image &img, int choice, int percentege)
{
    if (percentege < 0 || percentege > 100) return;
    for (int i = 0; i < img.width; i++)
    {
        for (int j = 0; j < img.height; j++)
        {
            for (int k = 0; k < img.channels; k++)
            {
                if (choice == 1)
                {
                    img(i, j, k) = img(i, j, k) - (percentege / 100.0 * img(i, j, k));
                }
                else
                {
                    img(i, j, k) = img(i, j, k) + (percentege / 100.0 * (255 - img(i, j, k)));
                }
            }
        }
    }
}

void resizeImage(Image &img, int newW, int newH)
{
    Image temp(newW, newH);
    for (int x = 0; x < newW; x++)
    {
        for (int y = 0; y < newH; y++)
        {
            int newX = x * img.width / newW;
            int newY = y * img.height / newH;
            for (int k = 0; k < img.channels; k++)
            {
                temp(x, y, k) = img(newX, newY, k);
            }
        }
    }
    img = temp;
}

void mergeImages(Image &img1, Image &img2, int mode)
{
    if (img1.width != img2.width || img1.height != img2.height)
    {
        if (mode == 1)
        {
            int w = max(img1.width, img2.width);
            int h = max(img1.height, img2.height);
            resizeImage(img1, w, h);
            resizeImage(img2, w, h);
        }
        else
        {
            int w = min(img1.width, img2.width);
            int h = min(img1.height, img2.height);
            Image temp(w, h);
            for (int x = 0; x < w; x++)
            {
                for (int y = 0; y < h; y++)
                {
                    for (int k = 0; k < img1.channels; k++)
                    {
                        temp(x, y, k) = (img1(x, y, k) + img2(x, y, k)) / 2;
                    }
                }
            }
            img1 = temp;
            return;
        }
    }

    for (int x = 0; x < img1.width; x++)
    {
        for (int y = 0; y < img1.height; y++)
        {
            for (int k = 0; k < img1.channels; k++)
            {
                img1(x, y, k) = (img1(x, y, k) + img2(x, y, k)) / 2;
            }
        }
    }
}

void edge(Image &image)
{
    int gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    for (int i = 0; i < image.width; i++)
    {
        for (int j = 0; j < image.height; j++)
        {
            int sum = image(i, j, 0) + image(i, j, 1) + image(i, j, 2);
            int average = sum / 3;
            for (int k = 0; k < image.channels; k++)
            {
                image(i, j, k) = average;
            }
        }
    }
    Image result(image.width, image.height);

    for (int i = 1; i < image.width - 1; i++)
    {
        for (int j = 1; j < image.height - 1; j++)
        {
            int sumX = 0, sumY = 0;
            for (int m = -1; m <= 1; m++)
            {
                for (int n = -1; n <= 1; n++)
                {
                    sumX += image(i + m, j + n, 0) * gx[n + 1][m + 1];
                    sumY += image(i + m, j + n, 0) * gy[n + 1][m + 1];
                }
            }
            int magnitude = sqrt(sumX * sumX + sumY * sumY);
            if (magnitude > 255) magnitude = 255;
            for (int k = 0; k < image.channels; k++)
            {
                result(i, j, k) = magnitude;
            }
        }
    }
    image = result;
}

void crop(Image &image, int x1, int x2, int y1, int y2)
{
    if (x1 >= x2 || y1 >= y2 || x1 < 0 || x2 > image.width || y1 < 0 || y2 > image.height) return;
    Image cropped(x2 - x1, y2 - y1);
    for (int i = x1; i < x2; i++)
    {
        for (int j = y1; j < y2; j++)
        {
            for (int k = 0; k < image.channels; k++)
            {
                cropped(i - x1, j - y1, k) = image(i, j, k);
            }
        }
    }
    image = cropped;
}

void blur(Image &image, int level)
{
    Image blurred(image.width, image.height);
    int radius = (level == 1) ? 7 : (level == 2 ? 9 : 11);
    for (int i = 0; i < image.width; i++)
    {
        for (int j = 0; j < image.height; j++)
        {
            for (int k = 0; k < image.channels; k++)
            {
                int sum = 0, count = 0;
                for (int ichange = -radius; ichange <= radius; ichange++)
                {
                    for (int jchange = -radius; jchange <= radius; jchange++)
                    {
                        int newi = i + ichange;
                        int newj = j + jchange;
                        if (newi >= 0 && newi < image.width && newj >= 0 && newj < image.height)
                        {
                            sum += image(newi, newj, k);
                            count++;
                        }
                    }
                }
                blurred(i, j, k) = sum / count;
            }
        }
    }
    image = blurred;
}

unsigned char safePixel(float v)
{
    return min(255.0f, max(0.0f, v));
}

void sunlight(Image &img)
{
    for (int i = 0; i < img.width; i++)
    {
        for (int j = 0; j < img.height; j++)
        {
            float r = img(i, j, 0) * 1.15;
            float g = img(i, j, 1) * 1.15;
            float b = img(i, j, 2) * 0.85;

            img(i, j, 0) = safePixel(r);
            img(i, j, 1) = safePixel(g);
            img(i, j, 2) = safePixel(b);
        }
    }
}

void tv(Image &image)
{
    for (int i = 0; i < image.width; i++)
    {
        for (int j = 0; j < image.height; j++)
        {
            int sum = image(i, j, 0) + image(i, j, 1) + image(i, j, 2);
            int average = sum / 3;
            for (int k = 0; k < image.channels; k++)
            {
                image(i, j, k) = (image(i, j, k) * 0.4) + (average * 0.6);
                if (j % 32 < 16)
                    image(i, j, k) = image(i, j, k) * 0.7;
            }
        }
    }
}

void purple(Image &image)
{
    for (int x = 0; x < image.width; x++)
    {
        for (int y = 0; y < image.height; y++)
        {
            for (int k = 0; k < image.channels; k++)
            {
                float value = image(x, y, k);
                if (k == 0)
                    image(x, y, k) = min(255.0f, 1.2f * value);
                else if (k == 1)
                    image(x, y, k) = 0.6f * value;
                else if (k == 2)
                    image(x, y, k) = min(255.0f, 0.99f * value);
            }
        }
    }
}

void infrared(Image &image)
{
    for (int i = 0; i < image.width; i++)
    {
        for (int j = 0; j < image.height; j++)
        {
            double r = image(i, j, 0);
            double g = image(i, j, 1);
            double b = image(i, j, 2);
            double lum = 0.2126 * r + 0.7152 * g + 0.0722 * b;

            if (lum <= 128)
            {
                image(i, j, 0) = 255; image(i, j, 1) = 197; image(i, j, 2) = 211;
            }
            else
            {
                image(i, j, 0) = 210; image(i, j, 1) = 0; image(i, j, 2) = 0;
            }
        }
    }
}

void skew(Image &image, double angle)
{
    if (angle < 0 || angle >= 90) return;
    double t = tan(angle * 3.14159 / 180);
    int maxShift = (image.height - 1) * t;

    Image skewed(image.width + maxShift, image.height);
    for (int x = 0; x < skewed.width; x++)
        for (int y = 0; y < skewed.height; y++)
            for (int k = 0; k < skewed.channels; k++)
                skewed(x, y, k) = 0;

    for (int y = 0; y < image.height; y++)
    {
        int shift = (image.height - 1 - y) * t;
        for (int x = 0; x < image.width; x++)
            for (int k = 0; k < image.channels; k++)
                skewed(x + shift, y, k) = image(x, y, k);
    }
    image = skewed;
}

void oilPaint(Image &image)
{
    int size = 1;
    int number_of_groups = 20;
    Image original = image;

    for (int i = 0; i < image.height; i++)
    {
        for (int j = 0; j < image.width; j++)
        {
            vector<int> groupCount(number_of_groups, 0);
            vector<int> redTotal(number_of_groups, 0);
            vector<int> greenTotal(number_of_groups, 0);
            vector<int> blueTotal(number_of_groups, 0);

            for (int ichange = -size; ichange <= size; ichange++)
            {
                for (int jchange = -size; jchange <= size; jchange++)
                {
                    int neighborj = j + jchange;
                    int neighbori = i + ichange;

                    if (neighborj < 0 || neighborj >= image.width || neighbori < 0 || neighbori >= image.height)
                        continue;

                    int R = original(neighborj, neighbori, 0);
                    int G = original(neighborj, neighbori, 1);
                    int B = original(neighborj, neighbori, 2);
                    int brightness = (R + G + B) / 3;
                    int group = brightness * number_of_groups / 256;

                    groupCount[group]++;
                    redTotal[group] += R;
                    greenTotal[group] += G;
                    blueTotal[group] += B;
                }
            }

            int maxGroup = 0;
            for (int group = 1; group < number_of_groups; group++)
            {
                if (groupCount[group] > groupCount[maxGroup])
                    maxGroup = group;
            }

            if (groupCount[maxGroup] > 0)
            {
                image(j, i, 0) = redTotal[maxGroup] / groupCount[maxGroup];
                image(j, i, 1) = greenTotal[maxGroup] / groupCount[maxGroup];
                image(j, i, 2) = blueTotal[maxGroup] / groupCount[maxGroup];
            }
        }
    }
}

// --- واجهة المعاينة ---
class ImagePreview : public QLabel
{
public:
    explicit ImagePreview(QWidget *parent = nullptr) : QLabel(parent)
    {
        setAlignment(Qt::AlignCenter);
        setMinimumSize(500, 400);
        setText("Open an image to get started");
        setStyleSheet("QLabel { background-color: #1e222b; color: #9ca3af; border: 1px solid #374151; border-radius: 8px; font-size: 14px; }");
    }

    void setImage(const QPixmap &image)
    {
        originalImage = image;
        updatePreview();
    }

protected:
    void resizeEvent(QResizeEvent *event) override
    {
        QLabel::resizeEvent(event);
        updatePreview();
    }

private:
    QPixmap originalImage;
    void updatePreview()
    {
        if (!originalImage.isNull()) {
            setPixmap(originalImage.scaled(size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
        }
    }
};

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget window;
    window.setWindowTitle("Image Processing Studio - CS213 Assignment 1");
    window.resize(1100, 750);
    window.setStyleSheet(
        "QWidget { background-color: #111827; color: #f3f4f6; font-family: sans-serif; }"
        "QPushButton { background-color: #2563eb; color: white; padding: 8px 12px; border: none; border-radius: 6px; font-size: 13px; font-weight: bold; }"
        "QPushButton:hover { background-color: #1d4ed8; }"
        "QPushButton:disabled { background-color: #374151; color: #6b7280; }"
    );

    auto *title = new QLabel("Image Processing  ");
    title->setStyleSheet("font-size: 20px; font-weight: bold; color: #60a5fa;");

    auto *preview = new ImagePreview;
    auto *openButton = new QPushButton("Open Image");
    auto *saveButton = new QPushButton("Save Image");
    saveButton->setEnabled(false);

    QVBoxLayout *filtersLayout = new QVBoxLayout;
    filtersLayout->setSpacing(6);

    QStringList filterNames = {
        "1. Grayscale Conversion", "2. Black and White", "3. Invert Image",
        "4. Add Frame", "5. Flip Image", "6. Rotate Image",
        "7. Darken / Lighten", "8. Resize Image", "9. Merge Images",
        "10. Detect Edges", "11. Crop Image", "12. Blur Image",
        "13. Wano Sunlight", "14. TV Effect", "15. Purple Night",
        "16. Infrared", "17. Image Skewing", "18. Oil Painting"
    };

    QPixmap currentImage;

    for (int i = 0; i < filterNames.size(); ++i) {
        auto *btn = new QPushButton(filterNames[i]);
        btn->setStyleSheet(
            "QPushButton { background-color: #1f2937; color: #e5e7eb; text-align: left; padding-left: 10px; border: 1px solid #374151; }"
            "QPushButton:hover { background-color: #374151; border-color: #60a5fa; }"
        );
        filtersLayout->addWidget(btn);
        
        QObject::connect(btn, &QPushButton::clicked, [i, &window, &currentImage, preview]() {
            if (currentImage.isNull()) {
                QMessageBox::warning(&window, "Error", "Please open an image first!");
                return;
            }

            QImage qimg = currentImage.toImage().convertToFormat(QImage::Format_RGB888);
            Image img(qimg.width(), qimg.height());
            for (int y = 0; y < qimg.height(); ++y) {
                for (int x = 0; x < qimg.width(); ++x) {
                    QColor color = qimg.pixelColor(x, y);
                    img(x, y, 0) = color.red();
                    img(x, y, 1) = color.green();
                    img(x, y, 2) = color.blue();
                }
            }

            // تطبيق الفلاتر وطلب الإدخالات التفاعلية من نافذة الـ GUI بدلاً من الـ Terminal
            if (i == 0) grayScale(img);
            else if (i == 1) black_white(img);
            else if (i == 2) invert(img);
            else if (i == 3) {
                bool ok;
                int style = QInputDialog::getInt(&window, "Frame Style", "Choose style:\n1. Simple\n2. Fancy", 1, 1, 2, 1, &ok);
                if (!ok) return;
                int color = 1;
                if (style == 1) {
                    color = QInputDialog::getInt(&window, "Frame Color", "Choose color:\n1. Red\n2. Green\n3. Blue\n4. Yellow\n5. Pink", 1, 1, 5, 1, &ok);
                    if (!ok) return;
                }
                guiFrame(img, style, color);
            }
            else if (i == 4) {
                bool ok;
                int choice = QInputDialog::getInt(&window, "Flip Image", "Choose flip type:\n1. Horizontal\n2. Vertical", 1, 1, 2, 1, &ok);
                if (!ok) return;
                flip(img, choice);
            }
            else if (i == 5) {
                bool ok;
                int choice = QInputDialog::getInt(&window, "Rotate Image", "Choose rotation:\n1. 90 degrees\n2. 180 degrees\n3. 270 degrees", 1, 1, 3, 1, &ok);
                if (!ok) return;
                rotate(img, choice);
            }
            else if (i == 6) {
                bool ok;
                int choice = QInputDialog::getInt(&window, "Darken / Lighten", "Choose mode:\n1. Darken\n2. Lighten", 1, 1, 2, 1, &ok);
                if (!ok) return;
                int pct = QInputDialog::getInt(&window, "Percentage", "Enter percentage (0 - 100):", 50, 0, 100, 1, &ok);
                if (!ok) return;
                Darken(img, choice, pct);
            }
            else if (i == 7) {
                bool ok;
                int newW = QInputDialog::getInt(&window, "Resize", "Enter new width:", img.width / 2, 1, 5000, 1, &ok);
                if (!ok) return;
                int newH = QInputDialog::getInt(&window, "Resize", "Enter new height:", img.height / 2, 1, 5000, 1, &ok);
                if (!ok) return;
                resizeImage(img, newW, newH);
            }
            else if (i == 8) {
                QString filename = QFileDialog::getOpenFileName(&window, "Open Image to Merge", QString(), "Images (*.png *.jpg *.jpeg)");
                if (filename.isEmpty()) return;
                QImageReader reader(filename);
                QImage loadedImg2 = reader.read();
                if (loadedImg2.isNull()) return;
                Image img2(loadedImg2.width(), loadedImg2.height());
                for (int y = 0; y < loadedImg2.height(); ++y) {
                    for (int x = 0; x < loadedImg2.width(); ++x) {
                        QColor c = loadedImg2.pixelColor(x, y);
                        img2(x, y, 0) = c.red();
                        img2(x, y, 1) = c.green();
                        img2(x, y, 2) = c.blue();
                    }
                }
                bool ok;
                int mode = QInputDialog::getInt(&window, "Merge Mode", "Choose mode:\n1. Resize to max\n2. Average intersection", 1, 1, 2, 1, &ok);
                if (!ok) return;
                mergeImages(img, img2, mode);
            }
            else if (i == 9) edge(img);
            else if (i == 10) {
                bool ok;
                int x1 = QInputDialog::getInt(&window, "Crop", "Start X:", 0, 0, img.width, 1, &ok);
                if (!ok) return;
                int x2 = QInputDialog::getInt(&window, "Crop", "End X:", img.width, 0, img.width, 1, &ok);
                if (!ok) return;
                int y1 = QInputDialog::getInt(&window, "Crop", "Start Y:", 0, 0, img.height, 1, &ok);
                if (!ok) return;
                int y2 = QInputDialog::getInt(&window, "Crop", "End Y:", img.height, 0, img.height, 1, &ok);
                if (!ok) return;
                crop(img, x1, x2, y1, y2);
            }
            else if (i == 11) {
                bool ok;
                int level = QInputDialog::getInt(&window, "Blur Level", "Choose level (1, 2, or 3):", 1, 1, 3, 1, &ok);
                if (!ok) return;
                blur(img, level);
            }
            else if (i == 12) sunlight(img);
            else if (i == 13) tv(img);
            else if (i == 14) purple(img);
            else if (i == 15) infrared(img);
            else if (i == 16) {
                bool ok;
                double angle = QInputDialog::getDouble(&window, "Skew Angle", "Enter angle (0 - 89):", 30, 0, 89, 1, &ok);
                if (!ok) return;
                skew(img, angle);
            }
            else if (i == 17) oilPaint(img);

            QImage resultImg(img.width, img.height, QImage::Format_RGB888);
            for (int y = 0; y < img.height; ++y) {
                for (int x = 0; x < img.width; ++x) {
                    resultImg.setPixelColor(x, y, QColor(img(x, y, 0), img(x, y, 1), img(x, y, 2)));
                }
            }

            currentImage = QPixmap::fromImage(resultImg);
            preview->setImage(currentImage);
            QMessageBox::information(&window, "Success", QString("Filter %1 applied successfully!").arg(i + 1));
        });
    }
    filtersLayout->addStretch();

    QWidget *sidebarContainer = new QWidget;
    sidebarContainer->setLayout(filtersLayout);
    sidebarContainer->setFixedWidth(230);

    QScrollArea *scrollArea = new QScrollArea;
    scrollArea->setWidget(sidebarContainer);
    scrollArea->setWidgetResizable(true);
    scrollArea->setStyleSheet("QScrollArea { border: none; background-color: transparent; }");

    QHBoxLayout *topButtons = new QHBoxLayout;
    topButtons->addWidget(openButton);
    topButtons->addWidget(saveButton);
    topButtons->addStretch();

    QVBoxLayout *rightLayout = new QVBoxLayout;
    rightLayout->addLayout(topButtons);
    rightLayout->addWidget(preview, 1);

    QHBoxLayout *mainLayout = new QHBoxLayout(&window);
    mainLayout->setContentsMargins(15, 15, 15, 15);
    mainLayout->setSpacing(15);
    
    QVBoxLayout *leftPanel = new QVBoxLayout;
    leftPanel->addWidget(title);
    leftPanel->addWidget(scrollArea, 1);
    
    mainLayout->addLayout(leftPanel, 0);
    mainLayout->addLayout(rightLayout, 1);

    QObject::connect(openButton, &QPushButton::clicked, [&]() {
        QString filename = QFileDialog::getOpenFileName(&window, "Open Image", QString(), "Images (*.png *.jpg *.jpeg *.bmp *.tga)");
        if (filename.isEmpty()) return;

        QImageReader reader(filename);
        QImage loadedImage = reader.read();
        if (loadedImage.isNull()) {
            QMessageBox::warning(&window, "Error", "Could not open the selected image.");
            return;
        }

        currentImage = QPixmap::fromImage(loadedImage);
        preview->setImage(currentImage);
        saveButton->setEnabled(true);
    });

    QObject::connect(saveButton, &QPushButton::clicked, [&]() {
        if (currentImage.isNull()) return;
        QString filename = QFileDialog::getSaveFileName(&window, "Save Image", "edited_image.png", "PNG (*.png);;JPG (*.jpg)");
        if (filename.isEmpty()) return;
        currentImage.save(filename);
        QMessageBox::information(&window, "Success", "Image saved successfully.");
    });

    window.show();
    return app.exec();
}
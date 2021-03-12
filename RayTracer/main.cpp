#include "color.h"
#include "vec3.h"

#include <iostream>

using namespace std;

void outputImage(int image_height, int image_width);

int main() {
    const int image_width = 256;
    const int image_height = 256;

    cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    outputImage(image_height, image_width);
}

void outputImage(int image_height, int image_width)
{
    for (int h = image_height - 1; h >= 0; --h) {
        cerr << "\rScanlines remaining: " << h << ' ' << flush;
        for (int w = 0; w < image_width; ++w) {
            color pixel_color(double(w) / (image_width - 1), double(h) / (image_height - 1), 0.25);
            write_color(cout, pixel_color);
        }
    }

    cerr << "\nDone.\n";
}
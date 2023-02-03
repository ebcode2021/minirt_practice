#include "include/color.h"
#include "include/vec3.h"

#include <iostream>

int main()
{
	// Image
	const int image_width = 256;
	const int image_height = 256;

	// Render

	std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

	for (int row = image_height - 1; row >= 0; --row)
	{
		std::cerr << "\rScanlines remaining :" << row << ' ' << std::flush;
		for (int col = 0; col < image_width; ++col)
		{
			color pixel_color(double(col) / (image_width - 1), double(row)/(image_height - 1), 0.25);
			write_color(std::cout, pixel_color);
		}
	}
	std::cerr << "\nDone.\n";
}
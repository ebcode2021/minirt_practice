#include "include/rtweekend.h"
#include "include/color.h"
#include "include/hittable_list.h"
#include "include/sphere.h"

#include "include/camera.h"

#include <iostream>

// double hit_sphere(const point3& center, double radius, const ray& r)
// {
// 	vec3 oc = r.origin() - center;
// 	double a = r.direction().length_squared();
// 	double half_b = dot(oc, r.direction());
// 	double c = oc.length_squared() - radius * radius;
// 	double discriminant = half_b * half_b - a*c;

// 	if (discriminant < 0)
// 		return -1.0;
// 	else
// 		return (-half_b - sqrt(discriminant)) / a;
// }

color ray_color(const ray& r, const hittable& world)
{
	hit_record rec;
	if (world.hit(r, 0, infinity, rec))
		return 0.5 * (rec.normal + color(1, 1, 1));
	vec3 unit_direction = unit_vector(r.direction()); // 단위벡터
	double t = 0.5 * (unit_direction.y() + 1.0);
	return (1.0 - t) * color(1.0, 1.0, 1.0) + t * color(0.5, 0.7, 1.0);
}

int main()
{
	// Image
	const double aspect_ratio =  16.0 / 9.0; // 가로세로비
	const int image_width = 400;
	const int image_height = static_cast<int>(image_width / aspect_ratio);
	const int sample_per_pixel = 100;

	// World
	hittable_list world;
	world.add(make_shared<sphere>(point3(0, 0, -1), 0.5));
	world.add(make_shared<sphere>(point3(0, -100.5, -1), 100));

	// Camera
	camera cam;

	// Render
	std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

	for (int row = image_height - 1; row >= 0; --row)
	{
		std::cerr << "\rScanlines remaining :" << row << ' ' << std::flush;
		for (int col = 0; col < image_width ; ++col)
		{
			color pixel_color(0,0,0);
			for (int s = 0; s < sample_per_pixel; ++s)
			{
				double u = (col + random_double()) / (image_width - 1);
				double v = (row + random_double()) / (image_height - 1);
				ray r = cam.get_ray(u, v);
				pixel_color += ray_color(r, world);
			}
			write_color(std::cout, pixel_color, sample_per_pixel);
		}
	}
	std::cerr << "\nDone.\n";
}
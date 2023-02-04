#include "include/rtweekend.h"
#include "include/color.h"
#include "include/hittable_list.h"
#include "include/sphere.h"

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

	// World
	hittable_list world;
	world.add(make_shared<sphere>(point3(0, 0, -1), 0.5));
	world.add(make_shared<sphere>(point3(0, -100.5, -1), 100));

	// Camera
	double viewport_height = 2.0;
	double viewport_width = aspect_ratio * viewport_height;
	double focal_length = 1.0;

	point3 origin = point3(0, 0, 0);
	vec3 horizontal = vec3(viewport_width, 0, 0);
	vec3 vertical = vec3(0, viewport_height, 0);
	point3 lower_left_corner = origin - horizontal / 2 - vertical / 2 - vec3(0, 0, focal_length);

	// Render
	std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

	for (int row = image_height - 1; row >= 0; --row)
	{
		std::cerr << "\rScanlines remaining :" << row << ' ' << std::flush;
		for (int col = 0; col < image_width ; ++col)
		{
			double u = double(col) / (image_width - 1);
			double v = double(row) / (image_height - 1);
			ray r(origin, lower_left_corner + u * horizontal + v * vertical - origin);
			color pixel_color = ray_color(r, world);
			write_color(std::cout, pixel_color);
		}
	}
	std::cerr << "\nDone.\n";
}
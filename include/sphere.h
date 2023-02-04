/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 17:09:50 by eunson            #+#    #+#             */
/*   Updated: 2023/02/04 11:49:04 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPHERE_H
# define SPHERE_H

#include "hittable.h"
#include "vec3.h"

class sphere : public hittable
{
	public :
		sphere(){};
		sphere(point3 cen, double r) : center(cen), radius(r) {};
	
		virtual bool hit (const ray& r, double t_min, double t_max, hit_record& rec) const override;
	public :
		point3 center;
		double radius;
};

bool sphere::hit(const ray& r, double t_min, double t_max, hit_record& rec) const
{
	vec3 oc = r.origin() - center;
	double a = r.direction().length_squared();
	double half_b = dot(oc, r.direction());
	double c = oc.length_squared() - radius * radius;

	double discriminant = half_b * half_b - a * c;
	
	if (discriminant < 0)
		return false;
	double sqrtd = sqrt(discriminant);

	// find the nearest root that lies in the acceptable range
	double root = (-half_b - sqrtd) / a;
	if (root < t_min || t_max < root)
	{
		root = (-half_b + sqrtd) / a;
		if (root < t_min || t_max < root)
			return false;
	}
	
	rec.t = root; // 길이
	rec.p = r.at(rec.t); // 적중점
	vec3 outward_normal = (rec.p - center) / radius;
	rec.set_face_noraml(r, outward_normal);
	//rec.normal = (rec.p - center) / radius; // 법선의 단위벡터
	return true;
}

#endif
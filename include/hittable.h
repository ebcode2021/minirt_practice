/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hittable.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 17:07:02 by eunson            #+#    #+#             */
/*   Updated: 2023/02/03 17:09:06 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HITTABLE_H
# define HITTABLE_H

#include "ray.h"

struct hit_record
{
	point3	p; // 적중점
	vec3	normal; // 법선 벡터
	double	t; // 길이
};

class hittable
{
	public :
		virtual bool hit(const ray&r, double t_min, double t_max, hit_record& rec) const = 0;
};

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtweekend.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 12:13:26 by eunson            #+#    #+#             */
/*   Updated: 2023/02/04 12:14:57 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTWEEKEND_H
# define RTWEEKEND_H

#include <cmath>
#include <limits>
#include <memory>

// Usings

using std::shared_ptr;
using std::make_shared;
using std::sqrt;

// Constants

const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.141592;

// Utility Functions

inline double degrees_to_rasdians(double degrees)
{
	return degrees * pi / 180.0;
}

// Common Headers

#include "ray.h"
#include "vec3.h"

#endif
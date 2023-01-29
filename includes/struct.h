/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunbison <eunbison@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 19:12:42 by eunbison          #+#    #+#             */
/*   Updated: 2023/01/29 19:46:24 by eunbison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

typedef struct s_pixel
{

}				t_pixel;

typedef struct s_scene
{
	t_pixel	**map;
	void	*addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}				t_scene;

typedef struct s_ray
{

}				t_ray;

typedef struct s_camera
{

}				t_camera;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	t_scene	scene;
}				t_mlx;
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunbison <eunbison@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 19:25:22 by eunbison          #+#    #+#             */
/*   Updated: 2023/01/29 19:59:04 by eunbison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	validated_keycode(int key)
{
	
}

int	key_hook(int keycode, t_mlx *ptr)
{
	if (validated_keycode(keycode))
	{

	}
	return (0);
}

int	mouse_hook(t_mlx *ptr)
{
	mlx_destroy_image(ptr->mlx_ptr, ptr->win_ptr);
	free_scene();
	exit(EXIT_SUCCESS);
	return (0);
}
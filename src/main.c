/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunbison <eunbison@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 17:16:39 by eunbison          #+#    #+#             */
/*   Updated: 2023/01/29 19:59:17 by eunbison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int main(int argc, char *argv[])
{
	t_mlx	ptr;

	if (argc != 2)
		print_error_with_exit("check arguments");
	ptr.mlx_ptr = mlx_init();
	ptr.win_ptr = mlx_new_window(ptr.mlx_ptr, WIN_WIDTH, WIN_HIEHGT, TITLE);
	ptr.img_ptr = mlx_new_image(ptr.mlx_ptr, WIN_WIDTH, WIN_HIEHGT);
	init_scene(&ptr, argv[1]);
	draw_scene(&ptr);
	mlx_hook(ptr.win_ptr, HOOK_KEY_EVENT, key_hook, &ptr);
	//mlx_hook(ptr.win_ptr, HOOK_MOUSE_EVENT, mouse_hook, &ptr);

	// bonus 폴더 따로 만들지말지. 보통 안만들긴 했었음.
	// check arguments는 파싱하는 과정에서, 자동으로 하게되어있음.
	
	return (0);
}
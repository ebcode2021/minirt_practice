/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 17:16:39 by eunbison          #+#    #+#             */
/*   Updated: 2023/01/30 15:32:35 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int main(int argc, char *argv[])
{
	t_mlx	ptr;

	if (argc != 2)
		print_error_with_exit(CHECK_ARGC);
	ptr.mlx_ptr = mlx_init();
	ptr.win_ptr = mlx_new_window(ptr.mlx_ptr, WIN_WIDTH, WIN_HIEHGT, TITLE);
	ptr.img_ptr = mlx_new_image(ptr.mlx_ptr, WIN_WIDTH, WIN_HIEHGT);
 	// .rt file을 초기화 (문제 있으면 뭐 안에서 종료되겠고 == 파싱)
	init_scene(&ptr, argv[1]);
	draw_scene(&ptr); 
	// (일단 픽셀 찍고 -> 표면에 색 입히고 -> diffuse인지, specular인지)
	// just color -> diffuse light -> indirect light -> specular light
	
	mlx_hook(ptr.win_ptr, HOOK_KEY_EVENT, 0, key_hook, &ptr);
	mlx_hook(ptr.win_ptr, HOOK_MOUSE_EVENT, 0, mouse_hook, &ptr);
	mlx_loop(ptr.mlx_ptr);
	//mlx_hook(ptr.win_ptr, HOOK_MOUSE_EVENT, mouse_hook, &ptr);

	// bonus 폴더 따로 만들지말지. 보통 안만들긴 했었음.
	// check arguments는 파싱하는 과정에서, 자동으로 하게되어있음.
	
	return (0);
}
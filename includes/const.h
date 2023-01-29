/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   const.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunbison <eunbison@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 17:21:27 by eunbison          #+#    #+#             */
/*   Updated: 2023/01/29 19:23:36 by eunbison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONST_H
# define CONST_H

enum	e_key {
	KEY_A = 0,
	KEY_S = 1,
	KEY_D = 2,
	KEY_F = 3,
	KEY_H = 4,
	KEY_G = 5,
	KEY_PLUS = 24,
	KEY_MINUS = 27,
	KEY_ESC = 53,
	KEY_LEFT = 123,
	KEY_RIGHT = 124,
	KEY_DOWN = 125,
	KEY_UP = 126,
	KEY_1 = 18,
	KEY_2 = 19,
};

# define TITLE "tinyRT"

# define WIN_WIDTH 1280
# define WIN_HIEHGT 1024

# define CENTER_X 640
# define CENTER_Y 512

# define HOOK_KEY_EVENT 2
# define HOOK_MOUSE_EVENT 17

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunbison <eunbison@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 19:07:19 by eunbison          #+#    #+#             */
/*   Updated: 2023/01/29 19:16:39 by eunbison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	print_error_with_exit(char *msg)
{
	printf("Error");
	printf(":: %s", msg);
	exit (EXIT_FAILURE);
}

// error case 정리
// 1. 파일이 rt file 형식이 아닌경우
// 2. 권한에러 같은경우는 open에서 perror로 잡아줄듯.
// 3. 파싱 과정에서의 에러처리
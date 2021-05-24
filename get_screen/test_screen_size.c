/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_screen_size.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heom <heom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 22:38:35 by sumoon            #+#    #+#             */
/*   Updated: 2021/05/24 13:41:35 by heom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <mlx.h>
#include "mlx_custom.h"

/*
** int	mlx_get_screen_size(void *mlx_ptr, int *sizex, int *sizey);
*/

int	main(void)
{
	int		sizex;
	int		sizey;
	void	*mlx;

	mlx_init();
	mlx_get_screen_size(mlx, &sizex, &sizey);
	return (0);
}

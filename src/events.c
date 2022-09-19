/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acinca-f <acinca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 13:56:23 by acinca-f          #+#    #+#             */
/*   Updated: 2022/09/19 12:13:46 by acinca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	close_window(void)
{
	mlx_destroy_image(fdf()->mlx, fdf()->data.img);
	mlx_destroy_window(fdf()->mlx, fdf()->mlx_win);
	mlx_destroy_display(fdf()->mlx);
	free(fdf()->mlx);
	free(fdf()->data.addr);
	free(fdf()->points2);
	free(fdf()->points3);
	exit(0);
}

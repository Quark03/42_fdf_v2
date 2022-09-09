/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acinca-f <acinca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 12:00:09 by acinca-f          #+#    #+#             */
/*   Updated: 2022/09/09 14:51:40 by acinca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

/*
SCROLL_UP => 4
SCROLL_DOWN => 5
*/

void	zoom_in(t_fdf *fdf)
{
	ft_putstr_fd("Zoom In\n", 1);
	fdf->zoom += 2;
	render_window(fdf);
}

void	zoom_out(t_fdf *fdf)
{
	if (fdf->zoom > 0)
	{
		ft_putstr_fd("Zoom Out\n", 1);
		fdf->zoom -= 2;
		render_window(fdf);
	}
}

int	mouse_hook(int keycode, void *f)
{
	(void) f;
	if (keycode == 4)
		zoom_in(fdf());
	else if (keycode == 5)
		zoom_out(fdf());
	return (0);
}

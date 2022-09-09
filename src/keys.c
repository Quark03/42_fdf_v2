/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acinca-f <acinca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 11:52:35 by acinca-f          #+#    #+#             */
/*   Updated: 2022/09/09 14:31:16 by acinca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../fdf.h"
/*

W => 119
A => 97
S => 115
D => 100

ARROW_UP => 65362
ARROW_DOWN => 65364

ESC => 65307

*/

void	move_up(t_fdf *fdf)
{
	ft_putstr_fd("Moving Up\n", 1);
	fdf->offset.y -= 10;
	render_window(fdf);
}

void	move_down(t_fdf *fdf)
{
	ft_putstr_fd("Moving Down\n", 1);
	fdf->offset.y += 10;
	render_window(fdf);
}

void	move_left(t_fdf *fdf)
{
	ft_putstr_fd("Moving Left\n", 1);
	fdf->offset.x -= 10;
	render_window(fdf);
}

void	move_right(t_fdf *fdf)
{
	ft_putstr_fd("Moving Right\n", 1);
	fdf->offset.x += 10;
	render_window(fdf);
}

void	zoom_in_key(t_fdf *fdf)
{
	ft_putstr_fd("Zoom In\n", 1);
	fdf->zoom += 2;
	ft_putstr_fd("Zoom In 2\n", 1);
	render_window(fdf);
}

void	zoom_out_key(t_fdf *fdf)
{
	if (fdf->zoom > 0)
	{
		ft_putstr_fd("Zoom Out\n", 1);
		fdf->zoom -= 2;
		ft_putstr_fd("Zoom Out 2\n", 1);
		render_window(fdf);
	}
}

int	key_hook(int keycode, t_fdf *fdf)
{
	if (keycode == 119)
		move_up(fdf);
	else if (keycode == 97)
		move_left(fdf);
	else if (keycode == 115)
		move_down(fdf);
	else if (keycode == 100)
		move_right(fdf);
	else if (keycode == 65362)
		zoom_in_key(fdf);
	else if (keycode == 65364)
		zoom_out_key(fdf);
	else if (keycode == 65307)
		close_window();
	return(0);
}
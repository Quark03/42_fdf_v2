/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acinca-f <acinca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 11:12:52 by acinca-f          #+#    #+#             */
/*   Updated: 2022/09/09 11:13:21 by acinca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	plot(t_fdf *fdf, int x, int y)
{
	t_vect2	temp;

	temp.x = x;
	temp.y = y;
	temp.color = 0x0891b2;
	pixel_put(fdf, temp);
}

void	plot_line_height(t_fdf *fdf, int x0, int y0, int x1, int y1)
{
	int	dx;
	int	dy;
	int	xi;
	int	D;
	int	x;
	int	y;

	y = y0;
	dx = x1 - x0;
	dy = y1 - y0;
	xi = 1;
	if (dx < 0)
	{
		xi = -1;
		dx = -dx;
	}
	D = (2 * dx) - dy;
	x = x0;
	while (y < y1)
	{
		plot(fdf, x, y);
		if (D > 0)
		{
			x = x + xi;
			D = D + (2 * (dx - dy));
		}
		else
		{
			D = D + 2 * dx;
		}
		y++;
	}
}

void	plot_line_low(t_fdf *fdf, int x0, int y0, int x1, int y1)
{
	int	dx;
	int	dy;
	int	yi;
	int	D;
	int	y;
	int	x;

	dx = x1 - x0;
	dy = y1 - y0;
	yi = 1;
	if (dy < 0)
	{
		yi = -1;
		dy = -dy;
	}
	D = (2 * dy) - dx;
	y = y0;
	x = x0;
	while (x < x1)
	{
		plot(fdf, x, y);
		if (D > 0)
		{
			y = y + yi;
			D = D + (2 * (dy - dx));
		}
		else
		{
			D = D + 2 * dy;
		}
		x++;
	}
}

void	plot_line(t_fdf *fdf, t_vect2 initial, t_vect2 final)
{
	int	x0;
	int	y0;
	int	x1;
	int	y1;

	x0 = initial.x;
	y0 = initial.y;
	x1 = final.x;
	y1 = final.y;
	if (isValidPoint(fdf, initial) || isValidPoint(fdf, final)) {
		if ( abs(y1 - y0) < abs(x1 - x0) )
		{
			if (x0 > x1)
				plot_line_low(fdf, x1, y1, x0, y0);
			else
				plot_line_low(fdf, x0, y0, x1, y1);
		}
		else
		{
			if (y0 > y1)
				plot_line_height(fdf, x1, y1, x0, y0);
			else
				plot_line_height(fdf, x0, y0, x1, y1);
		}
	}
}
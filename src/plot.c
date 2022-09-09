/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acinca-f <acinca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 11:12:52 by acinca-f          #+#    #+#             */
/*   Updated: 2022/09/09 15:13:02 by acinca-f         ###   ########.fr       */
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

typedef struct s_plot_vars1 {
	int	dx;
	int	dy;
	int	xi;
	int	d;
	int	x;
	int	y;
}	t_plot_args1;

typedef struct s_plot_vars2 {
	int	dx;
	int	dy;
	int	yi;
	int	d;
	int	y;
	int	x;
}	t_plot_args2;

void	plot_line_height(int x0, int y0, int x1, int y1)
{
	t_plot_args1	args;

	args.y = y0;
	args.dx = x1 - x0;
	args.dy = y1 - y0;
	args.xi = 1;
	if (args.dx < 0)
	{
		args.xi = -1;
		args.dx = -args.dx;
	}
	args.d = (2 * args.dx) - args.dy;
	args.x = x0;
	while (args.y < y1)
	{
		plot(fdf(), args.x, args.y);
		if (args.d > 0)
		{
			args.x = args.x + args.xi;
			args.d = args.d + (2 * (args.dx - args.dy));
		}
		else
			args.d = args.d + 2 * args.dx;
		args.y++;
	}
}

void	plot_line_low(int x0, int y0, int x1, int y1)
{
	t_plot_args2	args;

	args.dx = x1 - x0;
	args.dy = y1 - y0;
	args.yi = 1;
	if (args.dy < 0)
	{
		args.yi = -1;
		args.dy = -args.dy;
	}
	args.d = (2 * args.dy) - args.dx;
	args.y = y0;
	args.x = x0;
	while (args.x < x1)
	{
		plot(fdf(), args.x, args.y);
		if (args.d > 0)
		{
			args.y = args.y + args.yi;
			args.d = args.d + (2 * (args.dy - args.dx));
		}
		else
			args.d = args.d + 2 * args.dy;
		args.x++;
	}
}

typedef struct s_plot_vars {
	int	x0;
	int	y0;
	int	x1;
	int	y1;
}	t_plot_vars;

void	plot_line(t_fdf *fdf, t_vect2 initial, t_vect2 final)
{
	t_plot_vars	vars;

	vars.x0 = initial.x;
	vars.y0 = initial.y;
	vars.x1 = final.x;
	vars.y1 = final.y;
	if (is_valid_point(fdf, initial) || is_valid_point(fdf, final))
	{
		if (abs(vars.y1 - vars.y0) < abs(vars.x1 - vars.x0))
		{
			if (vars.x0 > vars.x1)
				plot_line_low(vars.x1, vars.y1, vars.x0, vars.y0);
			else
				plot_line_low(vars.x0, vars.y0, vars.x1, vars.y1);
		}
		else
		{
			if (vars.y0 > vars.y1)
				plot_line_height(vars.x1, vars.y1, vars.x0, vars.y0);
			else
				plot_line_height(vars.x0, vars.y0, vars.x1, vars.y1);
		}
	}
}

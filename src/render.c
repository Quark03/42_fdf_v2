/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acinca-f <acinca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 14:31:26 by acinca-f          #+#    #+#             */
/*   Updated: 2022/09/09 15:10:28 by acinca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

/**
 * Render a point in a 3d isometric representation
 */
t_vect2	isometric_point(t_fdf *fdf, t_vect3 point)
{
	t_vect2	p;

	p.x = (point.x * 1 * fdf->zoom) + (point.y * -1 * fdf->zoom);
	p.y = (point.x * 0.5 * fdf->zoom) + (point.y * 0.5 * fdf->zoom)
		- (point.z * fdf->zoom);
	p.color = point.color;
	p.x += (fdf->map.width / 2) + fdf->offset.x;
	p.y += (fdf->map.height / 3) + fdf->offset.y;
	pixel_put(fdf, p);
	return (p);
}

/**
 * Render a point in the default 2D canvas
 * (0, 0) Top left corner
 */
void	pixel_put(t_fdf *fdf, t_vect2 point)
{
	char	*dst;

	if (isValidPoint(fdf, point))
	{
		dst = fdf->data.addr + (point.y * fdf->data.line_length + point.x
				* (fdf->data.bits_per_pixel / 8));
		*(unsigned int *)dst = point.color;
	}
}

/**
 * An array of points to render
 */
void	render_map(t_fdf *fdf)
{
	int		i;

	fdf->points2 = malloc(sizeof(t_vect2) * fdf->points_size);
	if (!fdf->points2)
		return ;
	i = 0;
	while (i < fdf->points_size)
	{
		fdf->points2[i] = isometric_point(fdf, fdf->points3[i]);
		i++;
	}
}

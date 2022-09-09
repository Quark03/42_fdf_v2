/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lines.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acinca-f <acinca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 12:09:07 by acinca-f          #+#    #+#             */
/*   Updated: 2022/09/09 14:47:39 by acinca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	walk_array(t_fdf *fdf, t_vect2 vect, int offset, int jump)
{
	int	i;

	i = 0;
	while (vect.y + i < fdf->points_size)
	{
		if (jump == -1)
			plot_line(fdf, fdf->points2[vect.x + i], fdf->points2[vect.y + i]);
		else
		{
			if ((i + offset) % jump != 0)
				plot_line(fdf, fdf->points2[vect.x + i],
					fdf->points2[vect.y + i]);
		}
		i++;
	}
}

void	render_lines(t_fdf *fdf)
{
	t_vect2	rel;

	rel.x = 0;
	rel.y = 1;
	walk_array(fdf, rel, 1, fdf->map.cols);
	rel.y = fdf->map.cols;
	walk_array(fdf, rel, 0, -1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acinca-f <acinca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 12:10:05 by acinca-f          #+#    #+#             */
/*   Updated: 2022/09/09 15:13:21 by acinca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

/**
 * Count the amount of points to process
 * Default (42.fdf) 209 points
 */
int	count_points(char *file)
{
	int		fd;
	char	*line;
	char	**points;
	int		counter;
	int		p;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (-1);
	counter = 0;
	line = get_next_line(fd);
	while (line != 0)
	{
		points = ft_split(line, ' ');
		p = 0;
		while (points[p] != 0)
		{
			counter++;
			p++;
		}
		line = get_next_line(fd);
	}
	close(fd);
	return (counter);
}

/**
 * Check if a point is inside the window
 * @param fdf
 * @param point
 *
*/
int	is_valid_point(t_fdf *fdf, t_vect2 point)
{
	if (point.x > 0 && point.x < fdf->map.width)
	{
		if (point.y > 0 && point.y < fdf->map.height)
		{
			return (1);
		}
		return (0);
	}
	return (0);
}

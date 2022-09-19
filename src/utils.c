/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acinca-f <acinca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 12:10:05 by acinca-f          #+#    #+#             */
/*   Updated: 2022/09/19 12:42:52 by acinca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	ft_counter(char **points)
{
	int	p;

	p = 0;
	while (points[p] != 0)
	{
		p++;
	}
	return (p);
}

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

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (-1);
	counter = 0;
	line = get_next_line(fd);
	points = NULL;
	while (line != 0)
	{
		points = ft_split(line, ' ');
		counter += ft_counter(points);
		if (line != NULL)
			free(line);
		free_split(points);
		line = get_next_line(fd);
	}
	close(fd);
	free(line);
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

/**
 * Plot the points
 */
void	plot_points(void)
{
	int	i;

	i = 0;
	while (i < fdf()->points_size)
		pixel_put(fdf(), fdf()->points2[i++]);
}

/**
 * Free the ft_split memory
 * @param ptr 
 */
void	free_split(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
		free(ptr[i++]);
	free(ptr);
}

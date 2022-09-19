/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acinca-f <acinca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 08:57:58 by acinca-f          #+#    #+#             */
/*   Updated: 2022/09/19 11:18:26 by acinca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	parse_point(t_fdf *fdf, char **points, t_vect3 *temp)
{
	char	**point;

	point = ft_split(points[fdf->map.cols++], ',');
	temp->x = fdf->map.cols;
	temp->y = fdf->map.rows;
	temp->z = ft_atoi(point[0]);
	if (point[1] != 0)
		temp->color = ft_atoi_base((point[1] + 2), 16);
	else
		temp->color = 0x4287f5;
	fdf->points3[fdf->points_size] = *temp;
	fdf->points_size += 1;
	free_split(point);
}

void	parse_file(t_fdf *fdf)
{
	char	*line;
	char	**points;
	t_vect3	temp;

	line = get_next_line(fdf->file);
	fdf->map.rows = 0;
	points = NULL;
	while (line != 0)
	{
		points = ft_split(line, ' ');
		fdf->map.cols = 0;
		while (points[fdf->map.cols] != 0)
			parse_point(fdf, points, &temp);
		if (line != NULL)
			free(line);
		free_split(points);
		line = get_next_line(fdf->file);
		fdf->map.rows++;
	}
	fdf->map.width = 900;
	fdf->map.height = 800;
	free(line);
}

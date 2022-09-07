/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acinca-f <acinca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 08:57:58 by acinca-f          #+#    #+#             */
/*   Updated: 2022/09/05 12:10:12 by acinca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	parse_file(t_fdf *fdf)
{
	char	*line;
	char	**numbers;
	t_vect3	temp;

	line = get_next_line(fdf->file);
	fdf->map.rows = 0;
	while (line != 0)
	{
		numbers = ft_split(line, ' ');
		fdf->map.cols = 0;
		while (numbers[fdf->map.cols] != 0)
		{
			temp.x = fdf->map.cols;
			temp.y = fdf->map.rows;
			temp.z = ft_atoi(numbers[fdf->map.cols++]);
			temp.color = 0xFFFFFF;
			fdf->points3[fdf->points_size] = temp;
			fdf->points_size += 1;
		}
		line = get_next_line(fdf->file);
		fdf->map.rows++;
	}
	fdf->map.width = 800;
	fdf->map.height = 600;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acinca-f <acinca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 10:59:57 by acinca-f          #+#    #+#             */
/*   Updated: 2022/09/05 12:08:29 by acinca-f         ###   ########.fr       */
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
				plot_line(fdf, fdf->points2[vect.x + i], fdf->points2[vect.y + i]);
		}
		i++;
	}
}

void	render_lines(t_fdf *fdf)
{
	t_vect2 rel;

	rel.x = 0;
	rel.y = 1;
	walk_array(fdf, rel, 1, fdf->map.cols);
	rel.y = fdf->map.cols;
	walk_array(fdf, rel, 0, -1);
}

/**
 * Render the window
 */
void	render(t_fdf *fdf)
{
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, fdf->map.width, fdf->map.height, "FDF");
	//mlx_win = mlx_new_window(mlx, 3000, 2000, "FDF");
	fdf->data.img = mlx_new_image(mlx, fdf->map.width, fdf->map.height);
	fdf->data.addr = mlx_get_data_addr(fdf->data.img, &fdf->data.bits_per_pixel, 
		&fdf->data.line_length, &fdf->data.endian);
	render_map(fdf);
	ft_putstr_fd("Drawing ......\n", 1);
	render_lines(fdf);
	mlx_put_image_to_window(mlx, mlx_win, fdf->data.img, 0, 0);
	mlx_loop(mlx);
}


int	main(int ac, char **av)
{
	t_fdf	fdf;

	fdf.points_size = 0;
	if (ac != 2)
		return (-1);
	fdf.file = open(av[1], O_RDONLY);
	if (fdf.file == -1)
	{
		ft_putstr_fd("Could not open file\n", 1);
		return (-1);
	}
	fdf.points3 = malloc(sizeof(t_vect3) * count_points(av[1]));
	if (!fdf.points3)
		return (-1);
	ft_putstr_fd("Parsing ......\n", 1);
	parse_file(&fdf);
	ft_putstr_fd("Rendering ......\n", 1);
	render(&fdf);
	free(fdf.points3);
	free(fdf.points2);
	return (0);
}

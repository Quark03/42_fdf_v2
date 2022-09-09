/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acinca-f <acinca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 10:59:57 by acinca-f          #+#    #+#             */
/*   Updated: 2022/09/09 12:48:06 by acinca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

/**
 * Renders the points & the lines
 */
void	render_window(t_fdf *fdf)
{
	printf("Loaded 0\n");
	if (fdf->data.img)
		mlx_destroy_image(fdf->mlx, fdf->data.img);
	printf("Loaded 1\n");
	fdf->data.img = mlx_new_image(fdf->mlx, fdf->map.width, fdf->map.height);
	printf("Loaded 2\n");
	fdf->data.addr = mlx_get_data_addr(fdf->data.img, &fdf->data.bits_per_pixel, 
		&fdf->data.line_length, &fdf->data.endian);
	printf("Loaded 3\n");
	render_map(fdf);
	printf("Loaded 4\n");
	render_lines(fdf);
	printf("Loaded 5\n");
	mlx_put_image_to_window(fdf->mlx, fdf->mlx_win, fdf->data.img, 0, 0);
	printf("Loaded 6\n");
	free(fdf->points2);
}

/**
 * Creates the window
 */
void	create_window(t_fdf *fdf)
{
	fdf->mlx = mlx_init();
	fdf->mlx_win = mlx_new_window(fdf->mlx, fdf->map.width, fdf->map.height, "FDF");
	fdf->offset.x = 0;
	fdf->offset.y =	0;
	fdf->zoom = 20;
	mlx_key_hook(fdf->mlx_win, key_hook, fdf);
	mlx_mouse_hook(fdf->mlx_win, mouse_hook, (void *)fdf);
	render_window(fdf);
	mlx_loop(fdf->mlx);
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
	ft_putstr_fd("Reading ......\n", 1);
	fdf.points3 = malloc(sizeof(t_vect3) * count_points(av[1]));
	if (!fdf.points3)
		return (-1);
	ft_putstr_fd("Parsing ......\n", 1);
	parse_file(&fdf);
	ft_putstr_fd("Creating Window ......\n", 1);
	create_window(&fdf);
	free(fdf.points3);
	return (0);
}

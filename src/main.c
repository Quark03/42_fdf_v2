/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acinca-f <acinca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 10:59:57 by acinca-f          #+#    #+#             */
/*   Updated: 2022/09/09 14:30:37 by acinca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

/**
 * Renders the points & the lines
 */
void	render_window(t_fdf *fdf)
{
	if (fdf->data.img)
		mlx_destroy_image(fdf->mlx, fdf->data.img);
	fdf->data.img = mlx_new_image(fdf->mlx, fdf->map.width, fdf->map.height);
	fdf->data.addr = mlx_get_data_addr(fdf->data.img, &fdf->data.bits_per_pixel, 
		&fdf->data.line_length, &fdf->data.endian);
	render_map(fdf);
	render_lines(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->mlx_win, fdf->data.img, 0, 0);
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

	mlx_hook(fdf->mlx_win, 17, 0, close_window, fdf);
	mlx_key_hook(fdf->mlx_win, key_hook, fdf);
	mlx_mouse_hook(fdf->mlx_win, mouse_hook, fdf);
	render_window(fdf);
	mlx_loop(fdf->mlx);
}

t_fdf *fdf()
{
	static t_fdf	fdf;

	return (&fdf);
}


int	main(int ac, char **av)
{
	if (ac != 2)
		return (-1);
	fdf()->file = open(av[1], O_RDONLY);
	if (fdf()->file == -1)
	{
		ft_putstr_fd("Could not open file\n", 1);
		return (-1);
	}
	ft_putstr_fd("Reading ......\n", 1);
	fdf()->points3 = malloc(sizeof(t_vect3) * count_points(av[1]));
	if (!fdf()->points3)
		return (-1);
	ft_putstr_fd("Parsing ......\n", 1);
	parse_file(fdf());
	ft_putstr_fd("Creating Window ......\n", 1);
	create_window(fdf());
	free(fdf()->points3);
	return (0);
}

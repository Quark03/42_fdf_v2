/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acinca-f <acinca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 11:13:33 by acinca-f          #+#    #+#             */
/*   Updated: 2022/09/19 12:43:48 by acinca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stdio.h>
# include <errno.h>
# include <libgen.h>
# include <stdlib.h>
# include <math.h>
# include "./libft/libft.h"
# include "./mlx/mlx.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 512
# endif

// Structs
typedef struct s_vect3 {
	int	x;
	int	y;
	int	z;
	int	color;
}	t_vect3;

typedef struct s_vect2 {
	int	x;
	int	y;
	int	color;
}	t_vect2;

typedef struct s_map {
	int	height;
	int	width;
	int	rows;
	int	cols;
}	t_map;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_fdf {
	void	*mlx;
	void	*mlx_win;
	int		file;
	t_vect3	*points3;
	t_vect2	*points2;
	int		points_size;
	t_map	map;
	t_data	data;
	t_vect2	offset;
	int		zoom;
}	t_fdf;

// events.c
int		close_window(void);

// gnl.c
char	*get_next_line(int fd);

// keys.c
int		key_hook(int keycode, t_fdf *fdf);

// keys2.c
void	zoom_in_key(t_fdf *fdf);
void	zoom_out_key(t_fdf *fdf);

// lines.c
void	render_lines(t_fdf *fdf);

// main.c
void	render_window(t_fdf *fdf);
void	create_window(t_fdf *fdf);
t_fdf	*fdf(void);

// mouse.c
int		mouse_hook(int keycode, void *f);

// parse.c
void	parse_file(t_fdf *fdf);

// plot.c
void	plot_line(t_fdf *fdf, t_vect2 initial, t_vect2 final);

// render.c
t_vect2	isometric_point(t_fdf *fdf, t_vect3 point);
void	pixel_put(t_fdf *fdf, t_vect2 point);
void	render_map(t_fdf *fdf);

// utils.c
int		count_points(char *file);
int		is_valid_point(t_fdf *fdf, t_vect2 point);
void	plot_points(void);
void	free_split(char **ptr);

#endif

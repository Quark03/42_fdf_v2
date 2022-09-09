/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acinca-f <acinca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 14:45:23 by acinca-f          #+#    #+#             */
/*   Updated: 2022/09/09 14:46:44 by acinca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	zoom_in_key(t_fdf *fdf)
{
	ft_putstr_fd("Zoom In\n", 1);
	fdf->zoom += 2;
	ft_putstr_fd("Zoom In 2\n", 1);
	render_window(fdf);
}

void	zoom_out_key(t_fdf *fdf)
{
	if (fdf->zoom > 0)
	{
		ft_putstr_fd("Zoom Out\n", 1);
		fdf->zoom -= 2;
		ft_putstr_fd("Zoom Out 2\n", 1);
		render_window(fdf);
	}
}

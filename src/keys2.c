/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acinca-f <acinca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 14:45:23 by acinca-f          #+#    #+#             */
/*   Updated: 2022/09/19 09:45:00 by acinca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	zoom_in_key(t_fdf *fdf)
{
	fdf->zoom += 2;
	render_window(fdf);
}

void	zoom_out_key(t_fdf *fdf)
{
	if (fdf->zoom > 0)
	{
		fdf->zoom -= 2;
		render_window(fdf);
	}
}

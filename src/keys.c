/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acinca-f <acinca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 11:52:35 by acinca-f          #+#    #+#             */
/*   Updated: 2022/09/09 11:22:57 by acinca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../fdf.h"
/*

W => 119
A => 97
S => 115
D => 100

*/

int	key_hook(int keycode, t_fdf *fdf)
{
	if (keycode == 119)
		move_up(fdf);
	else if (keycode = 97)
		move_left(fdf);
	else if (keycode = 115)
		move_down(fdf);
	else if (keycode == 100)
		move_right(fdf);
	return(0);
}

void	move_up(t_fdf *fdf)
{
	
}

void	move_down(t_fdf *fdf)
{

}

void	move_left(t_fdf *fdf)
{
	
}

void	move_right(t_fdf *fdf)
{
	
}
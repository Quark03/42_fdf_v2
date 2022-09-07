/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acinca-f <acinca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 12:00:09 by acinca-f          #+#    #+#             */
/*   Updated: 2022/09/07 12:04:06 by acinca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

/*
SCROLL_UP => 4
SCROLL_DOWN => 5
*/

int	mouse_hook(int keycode, t_fdf *fdf)
{
	printf("Mouse Code %d\n", keycode);
	(void) fdf;
	return(0);
}
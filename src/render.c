/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscolera <gscolera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 03:05:35 by gscolera          #+#    #+#             */
/*   Updated: 2019/01/22 05:51:12 by gscolera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		get_color(unsigned char r, unsigned char g, unsigned char b)
{
	return ((r << 16) | (g << 8) | b);
}

void 	calculate_pixel(ENGINE *engine, int x, int y)
{
	COMPLEX reserve;
	int 	i;

	get_cmplx(engine, x, y);
	i = 0;
	while (i < engine->img.iterations)
	{
		if (engine->type == 3)
		{
			engine->fr.z.re = fabs(engine->fr.z.re);
			engine->fr.z.im = fabs(engine->fr.z.im);
		}
		reserve.re = engine->fr.z.re;
		reserve.im = engine->fr.z.im;
		engine->fr.z.re = engine->fr.z.re * engine->fr.z.re - engine->fr.z.im * engine->fr.z.im + engine->fr.c.re;
		engine->fr.z.im = 2.0f * reserve.re * reserve.im + engine->fr.c.im;
		if ((engine->fr.z.re * engine->fr.z.re + engine->fr.z.im * engine->fr.z.im) > 4.0f)
			break;

		i++;
	}
	i = engine->img.iterations - i;
	i = get_color(i, i, i);
	*(int *)(engine->img.ptr + (x + y * WINDOW_W) * engine->img.bpp) = i;
}

int		render(ENGINE *engine)
{
	int	x;
	int	y;


	y = 0;
	while (y < WINDOW_H)
	{
		x = 0;
		while (x < WINDOW_W)
		{
			calculate_pixel(engine, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(engine->mlx, engine->window, engine->img.image, 0, 0);
}

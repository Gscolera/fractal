/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscolera <gscolera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 23:15:24 by gscolera          #+#    #+#             */
/*   Updated: 2019/01/22 04:36:41 by gscolera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static	char	get_fractal_name(char *argv)
{
	char type;

	if (ft_strequ(argv, "Mandelbrot"))
		type = 1;
	else if (ft_strequ(argv, "Julia"))
		type = 2;
	else if (ft_strequ(argv, "Burningship"))
		type = 3;
	else
	{
		write(1, "\033[1;31mfractol error:\033[0m Unknown fractal!\n\n", 44);
		write(1, "\n\033[1;34mAvailible options:\033[0m", 30);
		write(1, " Julia\n", 7);
		write(1, "\t\t   Burningship\n", 17);
		write(1, "\t\t   Mandelbrot\n", 16);
		exit(1);
	}
	return (type);
}

static _Bool	usage(void)
{
	write(1, "\033[1;31mfractol error:\033[0m fractol name missed!\n", 47);
	write(1, "\n\033[1;34mAvailible options:\033[0m", 30);
	write(1, " Julia\n", 7);
	write(1, "\t\t   Burningship\n", 17);
	write(1, "\t\t   Mandelbrot\n", 16);
	return (1);
}

int				main(int argc, char **argv)
{
	ENGINE engine;

	 if (argc != 2)
	 	return (usage());
	engine.type = get_fractal_name(argv[1]);
	run_engine(&engine, argv[1]);
	render(&engine);
	mlx_hook(engine.window, E_KEY_PRESS, 1L<<0, key_press, &engine);
	mlx_hook(engine.window, E_CLOSE_WINDOW, 0, stop_engine, &engine);
	mlx_hook(engine.window, E_MOUSE_PRESS, 1L << 2, mouse_press, &engine);
	mlx_hook(engine.window, E_MOUSE_MOVE, 1L << 6, mouse_move, &engine);
	mlx_loop(engine.mlx);
	return (0);
}

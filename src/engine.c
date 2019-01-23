#include "fractol.h"

void		run_engine(ENGINE *engine, char *title)
{
	engine->mlx = mlx_init();
	engine->window = mlx_new_window(engine->mlx, WINDOW_W, WINDOW_H, "fractol");
	engine->img.image = mlx_new_image(engine->mlx, WINDOW_W, WINDOW_H);
	engine->img.ptr = mlx_get_data_addr(engine->img.image, &engine->img.bpp,
									&engine->img.stride, &engine->img.endian);
	reset_camera(engine);
	engine->img.bpp /= 8;
	engine->cam.step = 1.05f;
	engine->deform = FALSE;
	engine->img.iterations = 100;
}

int			stop_engine(ENGINE *engine)
{
	mlx_destroy_image(engine->mlx, engine->img.image);
	mlx_destroy_window(engine->mlx, engine->window);
	free(engine->mlx);
	exit(0);
}

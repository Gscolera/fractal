#include "fractol.h"

int		mouse_move(int x, int y, ENGINE *engine)
{
	if (engine->type == 2 && engine->deform)
	{
		engine->fr.c.re = (double)x / (double)WINDOW_W
									* (engine->cam.x_max - engine->cam.x_min)
	 								* engine->cam.zoom + engine->cam.x_min;
	engine->fr.c.im = (double)y / (double)WINDOW_H
									* (engine->cam.x_max - engine->cam.x_min)
									* engine->cam.zoom + engine->cam.y_min;
	render(engine);
	}
	return (0);
}

int		mouse_press(int button, int x, int y, ENGINE *engine)
{
	if (button == 1)
		engine->deform = (engine->deform == 0) ? 1 : 0;
	else if (button == 4)
	{
		zoom(engine, 1 / engine->cam.step, x, y);
		render(engine);
	}
	else if (button == 5)
	{
		zoom(engine, engine->cam.step, x, y);
		render(engine);
	}
}

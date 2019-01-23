#include "fractol.h"

void 	get_cmplx(ENGINE *engine, double x, double y)
{

	engine->fr.z.re = ((x / WINDOW_W) * (engine->cam.x_max - engine->cam.x_min)
	* engine->cam.zoom + engine->cam.x_min + engine->cam.offset_x);
	engine->fr.z.im = ((y / WINDOW_H) *  (engine->cam.y_max - engine->cam.y_min)
	* engine->cam.zoom + engine->cam.y_min + engine->cam.offset_y);
	if (engine->type == 1 || engine->type == 3)
	{
		engine->fr.c.re = ((x / WINDOW_W) * (engine->cam.x_max - engine->cam.x_min)
		* engine->cam.zoom + engine->cam.x_min + engine->cam.offset_x);
		engine->fr.c.im = ((y / WINDOW_H) *  (engine->cam.y_max - engine->cam.y_min)
		*engine->cam.zoom + engine->cam.y_min + engine->cam.offset_y);
	}
}

void	reset_camera(ENGINE *engine)
{
	engine->cam.x_min = -2.0f;
	engine->cam.x_max = (engine->type == 2) ? 2.0f : 1.0f;
	engine->cam.y_min = (engine->type == 1) ? -1.0f : -2.0f;
	engine->cam.y_max = (engine->type == 2) ? 2.0f : 1.0f;
	engine->cam.zoom = 1.0f;
	engine->cam.offset_y = 0.0f;
	engine->cam.offset_x = 0.0f;
	if (engine->type == 2)
	{
		engine->fr.c.re = -0.7f;
		engine->fr.c.im = 0.27015f;
	}
}

void	zoom(ENGINE *engine, float step, int x, int y)
{
	double w;
	double h;
	double nw;
	double nh;

	w = (engine->cam.x_max - engine->cam.x_min) * engine->cam.zoom;
	h = (engine->cam.y_max - engine->cam.y_min) * engine->cam.zoom;
	nw = (engine->cam.x_max - engine->cam.x_min) * (engine->cam.zoom * step);
	nh = (engine->cam.y_max - engine->cam.y_min) * (engine->cam.zoom * step);
	engine->cam.zoom *= step;
	engine->cam.offset_x -= ((double)x / WINDOW_W) * (nw - w);
	engine->cam.offset_y -= ((double)y / WINDOW_H) * (nh - h);
}

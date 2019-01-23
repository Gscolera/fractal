/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscolera <gscolera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 02:20:30 by gscolera          #+#    #+#             */
/*   Updated: 2019/01/22 04:49:42 by gscolera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		key_press(int keycode, ENGINE *engine)
{
	if (keycode == KEY_ESC || keycode == KEY_NUM0)
		(keycode == KEY_ESC) ? stop_engine(engine) : reset_camera(engine);
	else if (keycode == KEY_MUL)
		engine->img.iterations += 100;
	else if (keycode == KEY_DIV)
		engine->img.iterations -= 100;
	else if (keycode == KEY_PLUS)
			engine->cam.zoom /= engine->cam.step;
	else if (keycode == KEY_MINUS)
		engine->cam.zoom *= engine->cam.step;
	else if (keycode == KEY_UP)
		engine->cam.offset_y -= (100.0f / (double)WINDOW_H) * engine->cam.zoom;
	else if (keycode == KEY_DOWN)
		engine->cam.offset_y += (100.0f / (double)WINDOW_H) * engine->cam.zoom;
	else if (keycode == KEY_RIGHT)
		engine->cam.offset_x += (100.0f / (double)WINDOW_W) * engine->cam.zoom;
	else if (keycode == KEY_LEFT)
		engine->cam.offset_x -= (100.0f / (double)WINDOW_W) * engine->cam.zoom;
	render(engine);
	return (0);
}

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include "keymap.h"
# include <stdio.h>
/*
*********************WINDOW_PARAMS**********************************************
*/
# define WINDOW_W 	800
# define WINDOW_H 	600
/*
********************************************************************************
*/
# define ENGINE		t_engine
# define IMAGE		t_image
# define COMPLEX	t_complex
# define CAMERA 	t_camera
# define FRACTOL	t_fractol
# define TRUE		1
# define FALSE		0

typedef struct	s_complex
{
	double		re;
	double		im;
}				t_complex;

typedef struct	s_camera
{
	double		x_min;
	double		x_max;
	double		y_min;
	double		y_max;
	double		zoom;
	double		step;
	double		offset_x;
	double		offset_y;
}				t_camera;

typedef struct	s_image
{
	void 		*image;
	char 		*ptr;
	int			bpp;
	int			stride;
	int			endian;
	short		iterations;
}				t_image;

typedef struct	s_fractol
{
	COMPLEX		z;
	COMPLEX		c;
}				t_fractol;
typedef	struct	s_engine
{
	void		*mlx;
	void		*window;
	IMAGE		img;
	CAMERA		cam;
	FRACTOL		fr;
	_Bool		deform;
	char		type;
}				t_engine;


int				render(ENGINE *engine);
/*
*********************ENGINE*****************************************************
*/
void			run_engine(ENGINE *engine, char *title);
int				stop_engine(ENGINE *engine);
/*
*********************CAMERA*****************************************************
*/
void 			get_cmplx(ENGINE *engine, double x, double y);
void 			reset_camera(ENGINE *engine);
void			zoom(ENGINE *engine, float step, int x, int y);


/*
*********************CONTROLS***************************************************
*/
int				key_press(int keycode, ENGINE *engine);
int				mouse_move(int x, int y, ENGINE *engine);
int				mouse_press(int button, int x, int y, ENGINE *engine);

/*
*********************LIBFT******************************************************
*/
_Bool			ft_strequ(char *str1, char *str2);

#endif

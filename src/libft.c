#include "fractol.h"

_Bool	ft_strequ(char *str1, char *str2)
{
	while (*str1 && *str1 == *str2)
	{
		str1++;
		str2++;
	}
	return ((*str1 == *str2) ? 1 : 0);
}

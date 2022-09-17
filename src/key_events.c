#include "../include/cub3D.h"

int		ft_exit(char *str)
{
	ft_putstr_fd(str, 1);
	write(1, "\n", 1);
	exit(0);
}

int		ft_mlx_pressed(int keycode)
{
	if (keycode == 53)
		exit(0);
	if ((keycode == 13 || keycode == 1 || keycode == 0 || keycode == 2))
	{
		if (keycode == 13)
			keys.w = 1;
		if (keycode == 1)
			keys.s = 1;
		if (keycode == 0)
			keys.a = 1;
		if (keycode == 2)
			keys.d = 1;
	}
	return (0);
}

int		ft_mlx_released(int keycode)
{
	if (keycode == 13 || keycode == 1 || keycode == 0 || keycode == 2)
	{
		if (keycode == 13)
			keys.w = 0;
		if (keycode == 1)
			keys.s = 0;
		if (keycode == 0)
			keys.a = 0;
		if (keycode == 2)
			keys.d = 0;
	}
	return (0);
}

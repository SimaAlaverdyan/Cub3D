/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salaverd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 17:48:26 by salaverd          #+#    #+#             */
/*   Updated: 2022/08/03 18:07:46 by salaverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	ft_exit(char *str)
{
	ft_putstr_fd(str, 1);
	write(1, "\n", 1);
	exit(0);
}

int main(int argc, char **argv)
{
	void	*mlx;
	void	*mlx_win;
	int		fd;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (!(ft_check_extension(argv[1], ".cub")))
			ft_exit("Invalid file");
		mlx = mlx_init();
		mlx_win = mlx_new_window(mlx, 920, 1000, "Cub3D");
		mlx_loop(mlx);
	}
	return (0);
}

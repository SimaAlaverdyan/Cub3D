/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhatsago <zhatsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 17:48:26 by salaverd          #+#    #+#             */
/*   Updated: 2022/09/23 19:12:05 by zhatsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	mlx_start(void)
{
	game.mlx = mlx_init();
	set_mlx_images();
	set_mlx_addresses();
	game.mlx_win = mlx_new_window(game.mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3D");
	mlx_put_image_to_window(game.mlx, game.mlx_win, t_map.data.img, 0, 0);
	mlx_hook(game.mlx_win, 2, 1L << 0, ft_mlx_pressed, &game.mlx);
	mlx_hook(game.mlx_win, 3, 1L << 1, ft_mlx_released, &game.mlx);
	mlx_hook(game.mlx_win, 17, 1L << 17, ft_exit, NULL);
	mlx_loop_hook(game.mlx, start, &game);
	mlx_loop(game.mlx);
}

int	main(int argc, char **argv)
{
	int		fd;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
			ft_exit("Failed opening file");
		if (!(ft_check_extension(argv[1], ".cub")))
			ft_exit("Invalid file");
		init(fd);
		close(fd);
		fd = open(argv[1], O_RDONLY);
		parsing(fd);
		mlx_start();
		ft_free();
	}
	return (0);
}

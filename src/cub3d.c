/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhatsago <zhatsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 17:48:26 by salaverd          #+#    #+#             */
/*   Updated: 2022/08/13 20:45:51 by zhatsago         ###   ########.fr       */
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
	int		fd;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
			ft_exit("Failed opening file");
		if (!(ft_check_extension(argv[1], ".cub")))
			ft_exit("Invalid file");
		// init_map(fd, argv);
		init(fd, argv); 					///////FOR STACK INIT
	    get_cols(fd);
		close(fd);
		fd = open(argv[1], O_RDONLY);

		parsing(fd);
		// printf("%d\n", t_map.rows);
		// printf("%d\n", t_map.cols);
		close(fd);
		// while (1)
		// {
		// 	/* code */
		// }
		
		// mlx = mlx_init();
		// mlx_win = mlx_new_window(mlx, 920, 1000, "Cub3D");
		// mlx_loop(mlx);
		
		// for (int i = 0; i < t_map.rows; i++)
		// {
		// 	for (int j = 0; j < t_map.cols; j++)
		// 	{
		// 		printf("%c", t_map.matrix[i][j]);
		// 	}
		// 	printf("\n");
		// }
		// printf("\n");
		// printf("\n");

	}	
	return (0);
}
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

// void	ft_exit(char *str)
// {
// 	ft_putstr_fd(str, 1);
// 	write(1, "\n", 1);
// 	exit(0);
// }

// int main(int argc, char **argv)
// {
// 	void	*mlx;
// 	void	*mlx_win;
// 	int		fd;

// 	if (argc == 2)
// 	{
// 		fd = open(argv[1], O_RDONLY);
// 		if (!(ft_check_extension(argv[1], ".cub")))
// 			ft_exit("Invalid file");
// 		mlx = mlx_init();
// 		mlx_win = mlx_new_window(mlx, 920, 1000, "Cub3D");
// 		mlx_loop(mlx);
// 	}
// 	return (0);
// }
t_RowsCols matrix_row_col(int fd)
{
    t_RowsCols  s;
    char        *line;
    int         row;
    int         col;
    int         ret;
    int         max_col;
    
    max_col = 0;
    line = NULL;
    row = 0;
    ret = 1;
    
    while (ret)
    {
        ret = get_next_line(fd, &line);
        row++;
        free(line);
        col = ft_gnl_strlen(line);
        
        if (col > max_col)
            max_col = col;
        
        if (!ret)
            break ;
    }
    s.rows = row;
    s.cols = max_col;
    return s;
}

void create_initial_matrix(int rows, int cols)
{
	int matrix[rows][cols];
	int i = 0;
	int j = 0;
	
	while (i < rows)
	{
		j = 0;
		while (j < cols)
		{
			matrix[i][j] = 1;
			j++;
		}
		i++;
	}

	i = 0;
	
	while (i < rows)
	{
		j = 0;
		while (j < cols)
		{
			printf("%d ", matrix[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

int main()
{
	t_RowsCols result;
    int fd = open("./maps/2.cub", O_RDONLY);
    
    result = matrix_row_col(fd);

	printf("%d\n", result.rows);
    printf("%d", result.cols);
	printf("\n");
	create_initial_matrix(result.rows, result.cols);
    return (0);
}
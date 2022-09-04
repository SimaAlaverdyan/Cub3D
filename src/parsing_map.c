/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhatsago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 19:53:55 by zhatsago          #+#    #+#             */
/*   Updated: 2022/09/04 19:55:46 by zhatsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

char	*remove_empty_lines(int fd)				/////removing empty lines before F color
{
	int		res;
	char	*line;
//	create_matrix(t_map.rows - t_map.rows_tmp, t_map.cols);
	res = get_next_line(fd, &line);
	while (res > 0)
	{
		if (ft_strlen(line) == 0)
		{
			res = get_next_line(fd, &line);
			continue ;
		}
		else
			break ;
	}
	return (line);
	// ft_isspace(line);
}

void	tmp_map(int fd)
{
	int		r;
	char	*result;
	char	*tmp;
	char	*line;

	line = remove_empty_lines(fd);
	result = NULL;
	line = ft_strjoin(line, "\n");
	result = line;
	r = get_next_line(fd, &line);
	while (r > 0)
	{
		line = ft_strjoin(line, "\n");
		tmp = ft_strjoin(result, line);
		free(result);
		result = tmp;
		free(line);
		r = get_next_line(fd, &line);
	}
	t_map.tmp_map = ft_split(result, '\n');
	free(result);
}

void	parsing_map(int fd)
{
	tmp_map(fd);
	close(fd);
	r_and_c();
	create_matrix(t_map.rows, t_map.cols);
}

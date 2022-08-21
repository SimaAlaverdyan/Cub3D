/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salaverd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 19:39:03 by salaverd          #+#    #+#             */
/*   Updated: 2022/08/17 19:39:15 by salaverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int     ft_check_extension(char *path, char *ext)
{
	int	pathlen;
	int	extlen;

	pathlen = ft_strlen(path);
	extlen = ft_strlen(ext);
	if (!(extlen == 4) || !(pathlen > 4))
		return (0);
	return (*(path + pathlen - 1) == *(ext + extlen - 1)
		&& *(path + pathlen - 2) == *(ext + extlen - 2)
		&& *(path + pathlen - 3) == *(ext + extlen - 3)
		&& *(path + pathlen - 4) == *(ext + extlen - 4));
}

int     check_map_name(char *string, char *ext)
{
    int i = 0;
    int len = ft_strlen(ext);
    while (string[i])
        i++;
    while (len--)
        i--;
    if (string[i] == '.')
    {
        if (ft_strncmp((string + i), ext, ft_strlen(ext)))
			return (1);
    }
	return(0);
}

int		check_ext(char *path, char *ext)
{
	int i;

	i = 0;
	while (path[i] != '.')
		i++;
	if(ft_strncmp(path, ext, ft_strlen(ext)))
		return (1);
	return (0);
}
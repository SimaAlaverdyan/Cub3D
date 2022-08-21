#include "../include/cub3D.h"

int		ft_isspace(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\t' || str[i] == '\n' || str[i] == '\r' ||
			str[i] == '\v' || str[i] == '\f' || str[i] == ' ')
			return (1);
		i++;
	}
	return (0);
}
char    *parse_texture_path(char *line)
{
    char    *path;
    int     fd;

    while (*line == ' ')
        line++;
    // if (ft_isspace(line))
    //     ft_exit("Error: Texture path format error");
    path = ft_strdup(line);
    printf("%s\n", path);
    // check_map_name(path, ".xpm");
    if (!(check_ext(path, ".xpm")))
        ft_exit("Error: File extension error");
    // printf("%s\n", path);
    fd = open(path, O_RDONLY);
    if (fd == -1)
        ft_exit("File doesn't exist");
    else
        close(fd);
    return (path);
}

void    parsing_texture(char *line)
{
    if(line[0] == 'N' && line[1] == 'O')
        t_map.no.path = parse_texture_path(line + 2);       //////SHOULD IT PARSE line + 3 OR JUST line?
    else if(line[0] == 'S' && line[1] == 'O')
        t_map.so.path = parse_texture_path(line + 2);
    else if(line[0] == 'W' && line[1] == 'E')
        t_map.we.path = parse_texture_path(line + 2);
    else if(line[0] == 'E' && line[1] == 'A')
        t_map.ea.path = parse_texture_path(line + 2);
    else if (line[0] == 'F')
        // parse_color(line);
        printf("f\n");
    else if (line[0] == 'C')
        // parse_color(line);
        printf("c\n");
    // printf("%s\n", line + 3);
    printf("%s\n", t_map.no.path);
    printf("%s\n", t_map.so.path);
    printf("%s\n", t_map.we.path);
    printf("%s\n", t_map.ea.path);
}

void    parsing(int fd)
{
    int     i;
    // int     ret;
    char    *line;

    i = 0;
    while (i < 8 && get_next_line(fd, &line))
    {
        if (ft_strlen(line) == 0)
            continue;
        else
        {
            parsing_texture(line);
            i++;
        }
    } 
}

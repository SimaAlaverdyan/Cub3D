#include "../include/cub3D.h"

void parse_color(char *line, char mode)
{
    int i;
    char **colors;
    i = 0;

    while (*line == ' ')
        line++;
    colors = ft_split(line, ',');
    while (i < 3)
    {
        if (mode == 'F')
            t_map.f_color[i] = ft_atoi(colors[i]);
        else if (mode == 'C')
            t_map.c_color[i] = ft_atoi(colors[i]);
        i++;
    }  
    if (!check_colors())
        ft_exit("Error: wrong color numbers");
}

int check_colors()
{
    int i;

    i = 0;
    while (i < 3)
    {
        if (t_map.f_color[i] < 0 || t_map.f_color[i] > 255)
            return (0);
        if(t_map.c_color[i] < 0 || t_map.c_color[i] > 255)
            return (0);
        i++;
    }
    return (1);
}

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
    path = ft_strdup(line);
    if (!(check_map_name(path, ".xpm")))
        ft_exit("Error: File extension error");
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
        t_map.no.path = parse_texture_path(line + 2);
    else if(line[0] == 'S' && line[1] == 'O')
        t_map.so.path = parse_texture_path(line + 2);
    else if(line[0] == 'W' && line[1] == 'E')
        t_map.we.path = parse_texture_path(line + 2);
    else if(line[0] == 'E' && line[1] == 'A')
        t_map.ea.path = parse_texture_path(line + 2);
    else if (line[0] == 'F')
        parse_color(line + 1, 'F');
    else if (line[0] == 'C')
        parse_color(line + 1, 'C');
    // printf("%s\n",t_map.ea.path );
    // printf("%s\n",t_map.we.path );
    // printf("%s\n",t_map.no.path );
    // printf("%s\n",t_map.so.path );
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
    if (t_map.ea.path == NULL || t_map.we.path == NULL || t_map.no.path == NULL || t_map.so.path == NULL)
        ft_exit("Error: missing texture");
    // printf("\n%s\n", t_map.no.path);
    // printf("%s\n", t_map.so.path);
    // printf("%s\n", t_map.we.path);
    // printf("%s\n", t_map.ea.path);
}

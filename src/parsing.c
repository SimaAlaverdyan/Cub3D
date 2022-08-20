#include "../include/cub3D.h"

void    parsing_texture(char **line)
{
    //
}

void    parsing(int fd, char *argv)
{
    int     fd;
    int     line_count;
    int     ret;
    char    *line;

    line_count = 0;
    while (line_count < 8 && get_next_line(fd, &line))
    {
        if (ft_strlen(line) == 0)
            continue;
        else
        {
            parsing_texture(line);
            line_count++;
        }
    }
    
}

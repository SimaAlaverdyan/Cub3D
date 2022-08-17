#include "../include/cub3D.h"

void    init_map(int fd, char **argv)
{
    get_rows_cols(fd);
    allocate_matrix(t_map.rows, t_map.cols);
    close(fd);
    fd = open(argv[1], O_RDONLY);
    create_matrix(fd, t_map.cols);
}
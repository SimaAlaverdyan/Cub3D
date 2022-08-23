#include "../include/cub3D.h"

void    init(int fd, char **argv)
{
    get_cols(fd);
    // create_matrix(t_map.rows, t_map.cols);
    // create_initial_matrix(t_map.rows, t_map.cols, t_map.matrix);
    // allocate_matrix(t_map.rows, t_map.cols);
    // close(fd);
    fd = open(argv[1], O_RDONLY);
    // create_matrix(fd, t_map.cols);
}
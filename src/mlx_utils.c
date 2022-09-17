#include "../include/cub3D.h"

void    set_mlx_images()
{
    t_map.data.img = mlx_new_image(game.mlx, 920, 1000);
    t_map.no.img = mlx_xpm_file_to_image(game.mlx, t_map.no.path,
                            &t_map.no.width, &t_map.no.height);
    // printf("%s\n", t_map.no.path);
    t_map.so.img = mlx_xpm_file_to_image(game.mlx, t_map.so.path,
                            &t_map.so.width, &t_map.so.height);
    // printf("%s\n", t_map.so.path);
    t_map.we.img = mlx_xpm_file_to_image(game.mlx, t_map.we.path,
                            &t_map.we.width, &t_map.we.height);
    // printf("%s\n", t_map.we.img);
    t_map.ea.img = mlx_xpm_file_to_image(game.mlx, t_map.ea.path,
                            &t_map.ea.width, &t_map.ea.height);
    // printf("%s\n", t_map.ea.img);
}

void set_mlx_addresses()
{
    t_map.data.addr = mlx_get_data_addr(t_map.data.img, &t_map.data.bits_per_pixel,
                            &t_map.data.line_length, &t_map.data.endian);
    t_map.so.addr = mlx_get_data_addr(t_map.so.img, &t_map.so.bits_per_pixel,
                            &t_map.so.line_length, &t_map.so.endian);
    t_map.no.addr = mlx_get_data_addr(t_map.no.img, &t_map.no.bits_per_pixel,
                            &t_map.no.line_length, &t_map.no.endian);
    t_map.we.addr = mlx_get_data_addr(t_map.we.img, &t_map.we.bits_per_pixel,
                            &t_map.we.line_length, &t_map.we.endian);
    t_map.ea.addr = mlx_get_data_addr(t_map.ea.img, &t_map.ea.bits_per_pixel,
                            &t_map.ea.line_length, &t_map.ea.endian);
}
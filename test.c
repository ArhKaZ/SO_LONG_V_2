#include "inc/so_long.h"
int main()
{
    void *mlx;
    void *mlx_win;
    void *sprite;
    int x;
    int y;
    x = 0;
    y = 0;
    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, 500 , 500, "SO_LONG");
    sprite = mlx_xpm_file_to_image(mlx, "texture_converted/Spaceship_bottom.xpm", &x, &y);
    mlx_loop(mlx);
}
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
    sprite = mlx_xpm_file_to_image(mlx, "./texture_converted/Boss/Boss_left.xpm", &x, &y);
    mlx_put_image_to_window(mlx, mlx_win, sprite, 0, 0);
}
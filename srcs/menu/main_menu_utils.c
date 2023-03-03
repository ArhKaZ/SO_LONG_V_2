/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_menu_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 02:10:20 by syluiset          #+#    #+#             */
/*   Updated: 2023/03/03 20:36:11 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	free_menu(t_menu *menu)
{
	t_texture	*sprite;

	sprite = menu->menu[0];
	free_texture(sprite, menu->mlx->mlx);
	sprite = menu->menu[1];
	free_texture(sprite, menu->mlx->mlx);
	sprite = menu->menu[2];
	free_texture(sprite, menu->mlx->mlx);
	sprite = menu->menu[3];
	free_texture(sprite, menu->mlx->mlx);
	menu = NULL;
}

int	close_menu_exit(t_param *param, void *mlx_menu, void *mlx_win, void *mlx)
{
	free_menu(param->menu);
	free_all(param);
	mlx_destroy_window(mlx_menu, mlx_win);
	mlx_destroy_display(mlx_menu);
	free(mlx_menu);
	mlx_destroy_display(mlx);
	free(mlx);
	exit(EXIT_SUCCESS);
}

int	close_menu_start(t_param *p, void *mlx_menu, void *mlx_win, void *mlx)
{
	t_mlx	*mlx_game;

	mlx_game = create_empty_mlx();
	free_menu(p->menu);
	mlx_destroy_window(mlx_menu, mlx_win);
	mlx_destroy_display(mlx_menu);
	free(mlx_menu);
	mlx_game->mlx = mlx;
	mlx_game->menu = false;
	mlx_game->mlx_win = mlx_new_window(mlx_game->mlx, p->map->width * 64,
			p->map->height * 64, "SO_LONG");
	free(p->mlx);
	p->mlx = mlx_game;
	create_visu(p->map, p->mlx, p->player->coor, p->textures);
	p->time = clock() * 1000 / CLOCKS_PER_SEC;
	so_long(p);
	return (1);
}

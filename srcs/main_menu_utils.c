/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_menu_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 02:10:20 by syluiset          #+#    #+#             */
/*   Updated: 2023/02/26 19:12:44 by syluiset         ###   ########.fr       */
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

int	close_menu_start(t_param *p)
{
	t_mlx	*mlx;

	mlx = create_empty_mlx();
	mlx_destroy_window(p->menu->mlx->mlx, p->menu->mlx->mlx_win);
	mlx_destroy_display(p->menu->mlx->mlx);
	free_menu(p->menu);
	mlx->mlx = p->mlx->mlx;
	mlx->menu = false;
	mlx->mlx_win = mlx_new_window(mlx->mlx, p->map->width * 64,
				p->map->height * 64, "SO_LONG");
	free(p->mlx);
	p->mlx = mlx;
	create_visu(p->map, p->mlx, p->player->coor, p->textures);
	so_long(p);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_and_destroy.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:49:55 by syluiset          #+#    #+#             */
/*   Updated: 2023/02/22 16:58:46 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	close_win(t_param *param, void *mlx, void *mlx_win)
{
	free_all(param);
	mlx_destroy_window(mlx, mlx_win);
	mlx_destroy_display(mlx);
	free(mlx);
	exit(EXIT_SUCCESS);
}

t_gps	*create_empty_gps(void) //create_gps(x y)
{
	t_gps	*gps;

	gps = NULL;
	gps = malloc(sizeof(t_gps));
	if (!gps)
		return (NULL);
	gps->x = 0;
	gps->y = 0;
	return (gps);
}

t_mlx	*create_empty_mlx(void)
{
	t_mlx	*mlx;

	mlx = NULL;
	mlx = malloc(sizeof(t_mlx));
	if (!mlx)
		return (NULL);
	mlx->mlx = NULL;
	mlx->mlx_win = NULL;
	return (mlx);
}

t_param	*create_param(t_map *map, t_mlx *mlx, t_player *player, t_all_texture *all_texture)
{
	t_param	*param;

	param = malloc(sizeof(t_param));
	if (!param)
		return (NULL);
	param->map = map;
	param->mlx = mlx;
	param->player = player;
	param->textures = all_texture;
	param->shots = NULL;
	param->boss = NULL;
	param->finish = 0;
	return (param);
}

t_player	*create_empty_player(void)
{
	t_player *player;

	player = malloc(sizeof(t_player));
	player->collect = 0;
	player->coor = create_empty_gps();
	player->moves = 0;
	player->hp = 3;
	player->direction = 2;
	player->score = 0;
	return (player);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_and_destroy.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:49:55 by syluiset          #+#    #+#             */
/*   Updated: 2023/03/06 13:58:10 by syluiset         ###   ########.fr       */
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

t_gps	*create_gps(int x, int y)
{
	t_gps	*gps;

	gps = NULL;
	gps = malloc(sizeof(t_gps));
	if (!gps)
		return (NULL);
	gps->x = x;
	gps->y = y;
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

t_param	*create_param(void)
{
	t_param		*param;

	param = malloc(sizeof(t_param));
	if (!param)
		return (NULL);
	param->map = create_empty_map();
	if (!param->map)
		return (NULL);
	param->mlx = create_empty_mlx();
	if (!param->mlx)
		return (NULL);
	param->player = create_empty_player();
	if (!param->player)
		return (NULL);
	param->textures = NULL;
	param->shots = NULL;
	param->boss = NULL;
	param->finish = 0;
	param->menu = NULL;
	return (param);
}

t_player	*create_empty_player(void)
{
	t_player	*player;

	player = malloc(sizeof(t_player));
	if (!player)
		return (NULL);
	player->collect = 0;
	player->coor = create_gps(0, 0);
	if (!player->coor)
		return (NULL);
	player->moves = 0;
	player->hp = 3;
	player->direction = 1;
	player->score = 0;
	return (player);
}

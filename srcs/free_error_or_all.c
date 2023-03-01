/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_error_or_all.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 13:42:37 by syluiset          #+#    #+#             */
/*   Updated: 2023/03/01 13:43:00 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	free_error(t_map *map, t_player *player, t_mlx *mlx)
{
	free_map(map);
	free_player(player);
	free(mlx);
}

void	free_all(t_param *param)
{
	free_map(param->map);
	free_player(param->player);
	free_ennemy(param->boss);
	free_textures(param->textures, param->mlx->mlx);
	free(param->menu->mlx);
	param->menu->mlx = NULL;
	free(param->menu);
	param->menu = NULL;
	free(param->mlx);
	param->mlx = NULL;
	free(param);
	param = NULL;
}

void	free_error_non_finish(t_param *param)
{
	free_map(param->map);
	free_player(param->player);
	free_ennemy(param->boss);
	free_textures(param->textures, param->mlx->mlx);
	mlx_destroy_display(param->mlx->mlx);
	free(param->mlx->mlx);
	free(param->mlx);
	param->mlx = NULL;
	free(param);
	param = NULL;
	exit(EXIT_FAILURE);
}

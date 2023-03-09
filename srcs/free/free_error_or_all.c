/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_error_or_all.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 13:42:37 by syluiset          #+#    #+#             */
/*   Updated: 2023/03/09 10:52:12 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	free_error(t_param *param)
{
	if (param != NULL)
	{
		if (param->map != NULL)
			free_map(param->map);
		if (param->player != NULL)
			free_player(param->player);
		if (param->mlx != NULL)
			free(param->mlx);
		free(param);
	}
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

void	free_textures(t_all_text *texts, void *mlx)
{
	free_back(texts->back, mlx);
	free_coin(texts->coin, mlx);
	free_planets(texts->planets, mlx);
	free_texture(texts->wall, mlx);
	free_ships_sprite(texts->ships, mlx);
	free_black_hole(texts->black_hole, mlx);
	free_black_hole(texts->black_hole_close, mlx);
	free_end_and_go(texts->end, mlx);
	free_shoot(texts->shoot, mlx);
	free_nb(texts->nb, mlx);
	free_explosion(texts->explosion, mlx);
	free(texts);
	texts = NULL;
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

void	free_error_main_menu(t_param *param, t_mlx *mlx)
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
	mlx_destroy_window(mlx->mlx, mlx->mlx_win);
	mlx_destroy_display(mlx->mlx);
	free(mlx);
}

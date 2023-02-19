/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 17:14:04 by syluiset          #+#    #+#             */
/*   Updated: 2023/02/19 22:23:19 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	put_score(t_map *map, t_mlx *mlx, t_player *player, t_all_texture *text)
{
	char	*nb_collect;

	nb_collect = ft_itoa(player->score);
	//mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, text->background->p, 0, (map->height - 1) * 64);
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, text->wall->p, 0 , (map->height - 1) * 64);
	//mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, text->background->p, 64, (map->height - 1) * 64);
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, text->wall->p, 64, (map->height - 1) * 64);
	mlx_string_put(mlx->mlx, mlx->mlx_win, 10, map->height * 64 - 3, 0xFFFFFF, "Score:");
	mlx_string_put(mlx->mlx, mlx->mlx_win, 62, map->height * 64 - 3, 0xFFFFFF, nb_collect);
	free(nb_collect);
}

void	put_move(t_map *map, t_mlx *mlx, t_player *player, t_all_texture *text)
{
	char	*nb_moves;

	nb_moves = ft_itoa(player->moves);
	//mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, text->background->p, 2 * 64 , (map->height - 1) * 64);
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, text->wall->p, 2 * 64, (map->height - 1) * 64);
	//mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, text->background->p, 3 * 64, (map->height - 1) * 64);
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, text->wall->p, 3 * 64, (map->height - 1) * 64);
	mlx_string_put(mlx->mlx, mlx->mlx_win, 2 * 64, map->height * 64 - 3, 0xFFFFFF, "Moves:");
	mlx_string_put(mlx->mlx, mlx->mlx_win, 2 * 64 + 48, map->height * 64 - 3, 0xFFFFFF, nb_moves);
	free(nb_moves);
}

void	put_hp(t_map *map, t_mlx *mlx, t_player *player, t_all_texture *text)
{
	//mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, text->background->p, 4 * 64 , (map->height - 1) * 64);
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, text->wall->p, 4 * 64, (map->height - 1) * 64);
	//mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, text->background->p, 5 * 64, (map->height - 1) * 64);
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, text->wall->p, 5 * 64, (map->height - 1) * 64);
	mlx_string_put(mlx->mlx, mlx->mlx_win, 4 * 64, map->height * 64 - 3, 0xFFFFFF, "HP :");
	if (player->hp == 3)
	{
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, text->hp->full->p, 4 * 64 + 35, map->height * 64 - 16);
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, text->hp->full->p, 4 * 64 + 55, map->height * 64 - 16);
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, text->hp->full->p, 5 * 64 + 11, map->height * 64 - 16);
	}
	if (player->hp == 2)
	{
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, text->hp->full->p, 4 * 64 + 35, map->height * 64 - 16);
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, text->hp->full->p, 4 * 64 + 55, map->height * 64 - 16);
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, text->hp->empty->p, 5 * 64 + 11, map->height * 64 - 16);
	}
	if (player->hp == 1)
	{
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, text->hp->full->p, 4 * 64 + 35, map->height * 64 - 16);
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, text->hp->empty->p, 4 * 64 + 55, map->height * 64 - 16);
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, text->hp->empty->p, 5 * 64 + 11, map->height * 64 - 16);
	}
	if (player->hp == 0)
	{
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, text->hp->empty->p, 4 * 64 + 35, map->height * 64 - 16);
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, text->hp->empty->p, 4 * 64 + 55, map->height * 64 - 16);
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, text->hp->empty->p, 5 * 64 + 11, map->height * 64 - 16);
	}

}

void	put_strings(t_param *param)
{
	put_score(param->map, param->mlx, param->player, param->textures);
	put_move(param->map, param->mlx, param->player, param->textures);
	put_hp(param->map, param->mlx, param->player, param->textures);
}
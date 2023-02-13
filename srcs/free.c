/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:29:58 by syluiset          #+#    #+#             */
/*   Updated: 2023/01/30 13:59:41 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	free_map(t_map *map)
{
	int i;

	i = 0;
	while (map->map[i])
	{
		free(map->map[i]);
		i++;
	}
	free(map->map[i]);
	free(map->map);
	free(map);
}

void	free_char_map(char **map)
{
	int i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map[i]);
	free(map);
}

void	free_player(t_player *player)
{
	free(player->coor);
	free(player);
}

void	free_texture(t_texture *text, void *mlx)
{
	free(text->path);
	mlx_destroy_image(mlx, text->p);
	free(text->size);
	free(text);
}
void	free_textures(t_all_texture *texts, void *mlx)
{
	free_texture(texts->background, mlx);
	//free_texture(texts->coin, mlx);
	//free_texture(texts->earth, mlx);
	free_texture(texts->exit, mlx);
	free_texture(texts->player->player_bottom, mlx);
	free_texture(texts->player->player_left, mlx);
	free_texture(texts->player->player_right, mlx);
	free_texture(texts->player->player_top, mlx);
	free_texture(texts->wall, mlx);
	free(texts);
}

void	free_all(t_param *param)
{
	free_map(param->map);
	free_player(param->player);
	free_textures(param->textures, param->mlx->mlx);
	free(param);
}
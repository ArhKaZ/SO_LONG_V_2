/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:29:58 by syluiset          #+#    #+#             */
/*   Updated: 2023/03/07 10:12:55 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	free_char_map(char **map)
{
	int	i;

	i = 0;
	if (map != NULL)
	{
		while (map[i] != NULL)
		{
			free(map[i]);
			i++;
		}
		free(map);
		map = NULL;
	}
}

void	free_map(t_map *map)
{
	free_char_map(map->map);
	free(map->coor_exit);
	map->coor_exit = NULL;
	free(map);
	map = NULL;
}

void	free_ennemy(t_ennemy *boss)
{
	t_ennemy	*temp;
	t_ennemy	*tempnxt;

	if (!boss)
		return ;
	tempnxt = boss;
	while (tempnxt != NULL)
	{
		temp = tempnxt;
		tempnxt = temp->next;
		free(temp->coor);
		free(temp);
	}
	boss = NULL;
}

void	free_player(t_player *player)
{
	free(player->coor);
	player->coor = NULL;
	free(player);
	player = NULL;
}

void	free_texture(t_texture *text, void *mlx)
{
	mlx_destroy_image(mlx, text->p);
	text->p = NULL;
	free(text->size);
	text->size = NULL;
	free(text);
	text = NULL;
}

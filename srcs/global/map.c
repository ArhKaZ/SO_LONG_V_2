/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:48:41 by syluiset          #+#    #+#             */
/*   Updated: 2023/03/08 11:38:55 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

t_map	*create_empty_map(void)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->begin = 0;
	map->exit = 0;
	map->nb_empty = 0;
	map->nb_item = 0;
	map->nb_wall = 0;
	map->nb_ennemy = 0;
	map->nb_shot = 0;
	map->map = NULL;
	map->height = 0;
	map->width = 0;
	map->coor_exit = create_gps(0, 0);
	if (map->coor_exit == NULL)
		return (free(map), NULL);
	return (map);
}

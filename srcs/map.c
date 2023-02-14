/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:48:41 by syluiset          #+#    #+#             */
/*   Updated: 2023/02/14 16:52:57 by syluiset         ###   ########.fr       */
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
	map->coor_exit = create_empty_gps();
	return (map);
}

bool	get_map(char *path, t_map *map)
{
	char	*map_temp;
	int i;

	i = 0;
	map_temp = get_map_to_string(path, map);
	if (map_temp == NULL)
		return (false);
	map->map = ft_split(map_temp, '\n');
	free(map_temp);
	while(map->map[0][i])
		i++;
	map->width = i;
	i = 0;
	while (map->map[i] != NULL)
		i++;
	map->height = i;
	return (true);
}
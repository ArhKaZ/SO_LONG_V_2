/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 00:47:17 by syluiset          #+#    #+#             */
/*   Updated: 2023/03/08 11:00:36 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

char	**cp_map(t_map *map)
{
	char	**map_cp;
	int		h;

	map_cp = NULL;
	h = 0;
	map_cp = malloc(sizeof(char *) * (map->height + 1));
	if (!map_cp)
		return (NULL);
	while (h < map->height)
	{
		map_cp[h] = ft_strdup(map->map[h]);
		h++;
	}
	map_cp[h] = NULL;
	return (map_cp);
}

bool	check_map_is_finishable(char **map)
{
	int		i;
	int		j;

	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E' || map[i][j] == 'C')
			{
				free_char_map(map);
				ft_putstr_fd("Error\nMap is not finishable\n", 2);
				return (false);
			}
			j++;
		}
		i++;
	}
	return (true);
}

bool	map_is_finishable(t_map *map)
{
	char	**map_cp;

	map_cp = NULL;
	map_cp = cp_map(map);
	if (map_cp == NULL)
		return (false);
	checker_map(map, map_cp);
	if (check_map_is_finishable(map_cp) == false)
		return (false);
	free_char_map(map_cp);
	return (true);
}

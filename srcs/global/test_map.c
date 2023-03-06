/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 00:47:17 by syluiset          #+#    #+#             */
/*   Updated: 2023/03/06 14:08:14 by syluiset         ###   ########.fr       */
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

bool	map_is_finishable(t_map *map)
{
	char	**map_cp;
	int		i;
	int		j;

	i = 0;
	map_cp = NULL;
	map_cp = checker_map(map, cp_map(map));
	while (map_cp[i] != NULL)
	{
		j = 0;
		while (map_cp[i][j])
		{
			if (map_cp[i][j] == 'E' || map_cp[i][j] == 'C')
			{
				free_char_map(map_cp);
				ft_putstr_fd("Error\nMap is not finishable\n", 2);
				return (false);
			}
			j++;
		}
		i++;
	}
	free_char_map(map_cp);
	return (true);
}

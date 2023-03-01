/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 00:47:17 by syluiset          #+#    #+#             */
/*   Updated: 2023/03/01 14:03:30 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

bool	change_to_x(t_map *map, char **map_cp, int x, int y)
{
	if (x < 1 || x > map->width - 1)
		return (false);
	if (map_cp[y][x] == 'C' || map_cp[y][x] == 'E' || map_cp[y][x] == 'P'
			|| map_cp[y][x] == '0')
		map_cp[y][x] = 'X';
	if (map_cp[y][x] == '1')
		return (false);
	return (true);
}

char	**cp_map(t_map *map)
{
	char	**map_cp;
	int		h;

	map_cp = NULL;
	h = 0;
	map_cp = malloc(sizeof(char *) * (map->height + 1));
	while (h < map->height)
	{
		map_cp[h] = ft_strdup(map->map[h]);
		h++;
	}
	map_cp[h] = NULL;
	return (map_cp);
}

void	change_p(char **map_cp, t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map_cp[i] != NULL)
	{
		j = 0;
		while (map_cp[i][j])
		{
			if (map_cp[i][j] == 'P')
				change_to_x(map, map_cp, j, i);
			j++;
		}
		i++;
	}
}

char	**checker_map(t_map *map, char **map_cp)
{
	int	count_x;
	int	new_count_x;
	int	y;
	int	x;

	count_x = 0;
	change_p(map_cp, map);
	new_count_x = 1;
	while (count_x != new_count_x)
	{
		count_x = new_count_x;
		new_count_x = 0;
		y = 0;
		while (map_cp[y] != NULL)
		{
			x = 0;
			while (map_cp[y][x])
			{
				if (map_cp[y][x] == 'X')
				{
					change_to_x(map, map_cp, x - 1, y);
					change_to_x(map, map_cp, x + 1, y);
					change_to_x(map, map_cp, x, y - 1);
					change_to_x(map, map_cp, x, y + 1);
					new_count_x++;
				}
				x++;
			}
			y++;
		}
	}
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

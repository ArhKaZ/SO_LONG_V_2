/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 18:40:46 by syluiset          #+#    #+#             */
/*   Updated: 2023/03/01 14:21:46 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	change_to_x(t_map *map, char **map_cp, int x, int y)
{
	if (x < 1 || x > map->width - 1)
		return ;
	if (map_cp[y][x] == 'C' || map_cp[y][x] == 'E' || map_cp[y][x] == 'P'
			|| map_cp[y][x] == '0')
		map_cp[y][x] = 'X';
	if (map_cp[y][x] == '1')
		return ;
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

int	loop_check_map(t_map *map, char **map_cp, int count_x)
{
	int	x;
	int	y;

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
				count_x++;
			}
			x++;
		}
		y++;
	}
	return (count_x);
}

char	**checker_map(t_map *map, char **map_cp)
{
	int	count_x;
	int	new_count_x;

	count_x = 0;
	change_p(map_cp, map);
	new_count_x = 1;
	while (count_x != new_count_x)
	{
		count_x = new_count_x;
		new_count_x = 0;
		new_count_x = loop_check_map(map, map_cp, 0);
	}
	return (map_cp);
}

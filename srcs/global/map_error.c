/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:51:15 by syluiset          #+#    #+#             */
/*   Updated: 2023/03/01 14:00:58 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

bool	is_rectangle(t_map *map)
{
	int	height;
	int	width;

	width = 0;
	height = 0;
	while (map->map[height] != NULL && height < map->height)
	{
		while (map->map[height][width])
			width++;
		if (width != map->width)
			return (false);
		height++;
	}
	if (height != map->height)
		return (false);
	else
		return (true);
}

bool	surround_by_wall(t_map *map)
{
	int	i;

	i = 0;
	while (map->map[0][i])
	{
		if (map->map[0][i] != '1')
			return (false);
		if (map->map[map->height - 1][i] != '1')
			return (false);
		i++;
	}
	i = 0;
	while (i < map->height)
	{
		if (map->map[i][0] != '1')
			return (false);
		if (map->map[i][map->width - 1] != '1')
			return (false);
		i++;
	}
	return (true);
}

bool	is_exploitable(t_map *map)
{
	if (map->begin != 1)
	{
		ft_putstr_fd("Error\nMap does not have begin\n", 2);
		return (false);
	}
	if (map->exit != 1)
	{
		ft_putstr_fd("Error\nMap does not have exit\n", 2);
		return (false);
	}
	if (map->nb_item < 1)
	{
		ft_putstr_fd("Error\nMap does not have item\n", 2);
		return (false);
	}
	if (surround_by_wall(map) == false)
	{
		ft_putstr_fd("Error\nMap is not surround by walls\n", 2);
		return (false);
	}
	return (true);
}

bool	checking_map(t_map *map)
{
	if (is_rectangle(map) == false)
	{
		ft_putstr_fd("Error\nMap is not rectangular\n", 2);
		return (false);
	}
	if (is_exploitable(map) == false)
		return (false);
	return (true);
}

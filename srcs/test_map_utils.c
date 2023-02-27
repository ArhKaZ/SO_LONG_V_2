/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 18:40:46 by syluiset          #+#    #+#             */
/*   Updated: 2023/02/23 14:56:09 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

// void	try_by_top_plus(char **map_cp, int x, int y, t_map *map)
// {
// 	int	cp_y;
// 	int	count_less_y;
// 	int	i;

// 	i = 0;
// 	count_less_y = 0;
// 	cp_y = y;
// 	while (x <= map->width - 2 || cp_y != y)
// 	{
// 		if (map_cp[cp_y][x + 1] != '1')
// 		{
// 			x += 1;
// 			change_to_x(map, map_cp, x, cp_y);
// 			while (i < count_less_y)
// 			{
// 				if (map_cp[cp_y + i][x] != '1')
// 					cp_y += 1;
// 				else
// 					break ;
// 				i++;
// 			}
// 		}
// 		else
// 		{
// 			if (cp_y == 0)
// 				break ;
// 			cp_y -= 1;
// 			count_less_y += 1;
// 		}
// 	}
// }

// void	try_by_bottom_plus(char **map_cp, int x, int y, t_map *map)
// {
// 	int	cp_y;
// 	int	count_less_y;
// 	int	i;

// 	i = 0;
// 	count_less_y = 0;
// 	cp_y = y;
// 	while (x <= map->width - 2 || cp_y != y)
// 	{
// 		if (map_cp[cp_y][x + 1] != '1')
// 		{
// 			x += 1;
// 			change_to_x(map, map_cp, x, cp_y);
// 			while (i < count_less_y)
// 			{
// 				if (map_cp[cp_y + i][x] != '1')
// 					cp_y -= 1;
// 				else
// 					break ;
// 				i++;
// 			}
// 		}
// 		else
// 		{
// 			if (cp_y == map->height - 1)
// 				break ;
// 			cp_y += 1;
// 		}
// 	}
// }

// void	try_by_top_less(char **map_cp, int x, int y, t_map *map)
// {
// 	int	cp_y;
// 	int	count_less_y;
// 	int	i;

// 	i = 0;
// 	count_less_y = 0;
// 	cp_y = y;
// 	while (x >= 1 || cp_y != y)
// 	{
// 		if (map_cp[cp_y][x -1] != '1')
// 		{
// 			x -= 1;
// 			change_to_x(map, map_cp, x, cp_y);
// 			while (i < count_less_y)
// 			{
// 				if (map_cp[cp_y + i][x] != '1')
// 					cp_y += 1;
// 				else
// 					break ;
// 				i++;
// 			}
// 		}
// 		else
// 		{
// 			if (cp_y == 0)
// 				break ;
// 			cp_y -= 1;
// 		}
// 	}
// }

// void	try_by_bottom_less(char **map_cp, int x, int y, t_map *map)
// {
// 	int	cp_y;
// 	int	count_less_y;
// 	int	i;

// 	i = 0;
// 	count_less_y = 0;
// 	cp_y = y;
// 	while (x >= 1 || cp_y != y)
// 	{
// 		if (map_cp[cp_y][x - 1] != '1')
// 		{
// 			x -= 1;
// 			change_to_x(map, map_cp, x, cp_y);
// 			while (i < count_less_y)
// 			{
// 				if (map_cp[cp_y + i][x] != '1')
// 					cp_y -= 1;
// 				else
// 					break ;
// 				i++;
// 			}
// 		}
// 		else
// 		{
// 			if (cp_y == map->height - 1)
// 				break ;
// 			cp_y += 1;
// 		}
// 	}
// }

// void	try_go_wall(char **map_cp, t_gps *coor, t_map *map, int direction)
// {
// 	if (direction == 1)
// 	{
// 		try_by_top_plus(map_cp, coor->x, coor->y, map);
// 		try_by_bottom_plus(map_cp, coor->x, coor->y, map);
// 	}
// 	else
// 	{
// 		try_by_top_less(map_cp, coor->x, coor->y, map);
// 		try_by_bottom_less(map_cp, coor->x, coor->y, map);
// 	}
// }

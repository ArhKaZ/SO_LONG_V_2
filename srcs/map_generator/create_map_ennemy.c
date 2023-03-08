/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map_ennemy.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 15:50:27 by syluiset          #+#    #+#             */
/*   Updated: 2023/03/08 13:52:17 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/map.h"

t_gen_map	*create_gen_map(int collect, int ennemy)
{
	t_gen_map	*map;

	map = malloc(sizeof(t_gen_map));
	if (!map)
		return (NULL);
	map->begin = 0;
	map->exit = 0;
	map->item = 0;
	map->item_on_line = 0;
	map->d_on_line = 0;
	map->item_param = collect;
	map->ennemy_param = ennemy;
	map->ennemy = 0;
	return (map);
}

void	line_of_wall(t_gps *coor)
{
	int	x;

	x = 0;
	while (x < coor->x + 2)
	{
		ft_printf("1");
		x++;
	}
	ft_printf("\n");
}

bool	should_put_ennemy(t_gen_map *map, int height)
{
	if (map->ennemy < map->ennemy_param)
	{
		if (map->ennemy_param > height)
		{
			if (map->d_on_line < (map->ennemy_param / height))
				return (true);
		}
		else
		{
			if (map->d_on_line < (height / map->ennemy_param))
				return (true);
		}
	}
	return (false);
}

void	put_component_with_d(t_gen_map *map, t_gps *coor, int rand)
{
	if (map->begin == 0 && rand == 0)
	{
		ft_printf("P");
		map->begin += 1;
	}
	else if (map->exit == 0 && rand == 1)
	{
		ft_printf("E");
		map->exit += 1;
	}
	else if (should_put_ennemy(map, coor->y) && rand == 4)
	{
		ft_printf("D");
		map->ennemy += 1;
		map->d_on_line += 1;
	}
	else if (should_put_item(map, coor->y) == true && (rand == 2 || rand == 7))
	{
		ft_printf("C");
		map->item += 1;
		map->item_on_line += 1;
	}
	else
		ft_printf("0");
}

void	create_map_with_d(t_gps *coor, int density, int collect, int ennemy)
{
	int			y;
	int			x;
	t_gen_map	*map;

	y = 0;
	map = create_gen_map(collect, ennemy);
	if (!map)
		return ;
	while (y < coor->y + 1)
	{
		x = 0;
		if (on_y_action(y, coor) == true)
			break ;
		while (x <= coor->x + 1)
		{
			on_x_action_e(x, coor, density, map);
			x++;
		}
		ft_printf("\n");
		map->item_on_line = 0;
		map->d_on_line = 0;
		y++;
	}
	free(map);
}

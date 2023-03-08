/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 15:12:39 by syluiset          #+#    #+#             */
/*   Updated: 2023/03/08 13:52:11 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/map.h"

t_gps	*create_gps(int height, int width)
{
	t_gps	*new;

	new = malloc(sizeof(t_gps));
	if (!new)
		return (NULL);
	new->y = height;
	new->x = width;
	return (new);
}

bool	should_put_item(t_gen_map *map, int height)
{
	if (map->item < map->item_param)
	{
		if (map->item_param > height)
		{
			if (map->item_on_line < (map->item_param / height))
				return (true);
		}
		else
		{
			if (map->item_on_line < (height / map->item_param))
				return (true);
		}
	}
	return (false);
}

void	put_component(t_gen_map *map, t_gps *coor, int rand)
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
	else if (should_put_item(map, coor->y) == true && (rand == 2 || rand == 7))
	{
		ft_printf("C");
		map->item += 1;
		map->item_on_line += 1;
	}
	else
		ft_printf("0");
}

void	create_map(t_gps *coor, int density, int collect)
{
	int			y;
	int			x;
	t_gen_map	*map;

	map = create_gen_map(collect, 0);
	if (!map)
		return ;
	y = 0;
	while (y < coor->y + 1)
	{
		x = 0;
		if (on_y_action(y, coor) == true)
			break ;
		while (x <= coor->x + 1)
		{
			on_x_action(x, coor, density, map);
			x++;
		}
		ft_printf("\n");
		map->item_on_line = 0;
		y++;
	}
	free(map);
}

int	main(int argc, char **argv)
{
	t_gps	*gps;

	gps = malloc(sizeof(t_gps));
	if (!gps)
		return (0);
	if (argc == 5)
	{
		gps->x = ft_atoi(argv[1]);
		gps->y = ft_atoi(argv[2]);
		create_map(gps, ft_atoi(argv[3]), ft_atoi(argv[4]));
	}
	if (argc == 6)
	{
		gps->x = ft_atoi(argv[1]);
		gps->y = ft_atoi(argv[2]);
		create_map_with_d(gps, ft_atoi(argv[3]), ft_atoi(argv[4]),
			ft_atoi(argv[5]));
	}
	free(gps);
	return (0);
}

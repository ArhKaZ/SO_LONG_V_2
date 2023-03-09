/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_visu_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:37:20 by syluiset          #+#    #+#             */
/*   Updated: 2023/03/09 10:54:54 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

bool	put_obstacle(t_map *map, t_mlx *mlx, t_sprite_planet *plnts)
{
	int			height;
	int			width;
	t_texture	*sprite;
	t_gps		*place;

	height = 1;
	while (height < map->height - 1)
	{
		width = 1;
		while (width < map->width - 1)
		{
			if (map->map[height][width] == '1')
			{
				place = create_gps(width, height);
				if (place == NULL)
					return (false);
				sprite = plnts->planets[get_random(4)];
				put_image(mlx, sprite->p, place);
				free(place);
			}
			width++;
		}
		height++;
	}
	return (true);
}

bool	put_wall_line(t_map *map, t_mlx *mlx, t_texture *wall)
{
	int		width;
	t_gps	*place;

	width = -1;
	while (++width < map->width)
	{
		place = create_gps(width, 0);
		if (place == NULL)
			return (false);
		put_image(mlx, wall->p, place);
		place->y = map->height - 1;
		put_image(mlx, wall->p, place);
		free(place);
	}
	return (true);
}

bool	put_wall_col(t_map *map, t_mlx *mlx, t_texture *wall)
{
	int		height;
	t_gps	*place;

	height = 0;
	while (++height < map->height)
	{
		place = create_gps(0, height);
		if (place == NULL)
			return (false);
		put_image(mlx, wall->p, place);
		place->x = map->width - 1;
		put_image(mlx, wall->p, place);
		free(place);
	}
	return (true);
}

bool	put_background(t_map *map, t_mlx *mlx, t_texture *back[2])
{
	int		height;
	int		width;
	t_gps	*place;

	height = 0;
	while (height < map->height * back[0]->size->y)
	{
		width = 0;
		while (width < map->width * back[0]->size->x)
		{
			if (map->map[height / 64][width / 64] == '0')
			{
				place = create_gps(width / 64, height / 64);
				if (place == NULL)
					return (false);
				put_image(mlx, back[get_random(2)]->p, place);
				free(place);
			}
			width += back[0]->size->x;
		}
		height += back[0]->size->y;
	}
	return (true);
}

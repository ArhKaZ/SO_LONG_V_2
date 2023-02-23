/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_visu_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:37:20 by syluiset          #+#    #+#             */
/*   Updated: 2023/02/23 14:24:22 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	*get_sprite_obstacle(t_sprite_planet *texts)
{
	void	*sprite;
	int		random;

	sprite = NULL;
	random = get_random(4);
	if (random == 0)
		sprite = texts->planet_1->p;
	if (random == 1)
		sprite = texts->planet_2->p;
	if (random == 2)
		sprite = texts->planet_3->p;
	if (random == 3)
		sprite = texts->planet_4->p;
	return (sprite);
}

void	put_obstacle_in_map(t_map *map, t_mlx *mlx, t_sprite_planet *plnts)
{
	int		height;
	int		width;
	void	*sprite;
	t_gps	*place;

	height = 1;
	while (height < map->height - 1)
	{
		width = 1;
		while (width < map->width - 1)
		{
			if (map->map[height][width] == '1')
			{
				place = create_gps(width, height);
				sprite = get_sprite_obstacle(plnts);
				put_image(mlx, sprite, place);
				free(place);
			}
			width++;
		}
		height++;
	}
}

void	put_wall(t_map *map, t_mlx *mlx, t_texture *wall)
{
	int		width;
	int		height;
	t_gps	*place;

	width = -1;
	while (++width < map->width)
	{
		place = create_gps(width, 0);
		put_image(mlx, wall->p, place);
		place->y = map->height - 1;
		put_image(mlx, wall->p, place);
		free(place);
	}
	height = 0;
	while (++height < map->height)
	{
		place = create_gps(0, height);
		put_image(mlx, wall->p, place);
		place->x = map->width - 1;
		put_image(mlx, wall->p, place);
		free(place);
	}
}

void	put_background(t_map *map, t_mlx *mlx, t_texture *back)
{
	int		height;
	int		width;
	t_gps	*place;

	height = 0;
	while (height < map->height * back->size->y)
	{
		width = 0;
		while (width < map->width * back->size->x)
		{
			if (map->map[height / 64][width / 64] == '0')
			{
				place = create_gps(width / 64, height / 64);
				put_image(mlx, back->p, place);
				free(place);
			}
			width += back->size->x;
		}
		height += back->size->y;
	}
}

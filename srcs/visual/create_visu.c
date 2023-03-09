/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_visu.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:50:44 by syluiset          #+#    #+#             */
/*   Updated: 2023/03/09 10:55:06 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	put_player(t_map *map, t_mlx *mlx, t_gps *p, t_texture *player)
{
	int	height;
	int	width;

	height = 1;
	while (height < map->height)
	{
		width = 1;
		while (width < map->width)
		{
			if (map->map[height][width] == 'P')
			{
				p->y = height;
				p->x = width;
				put_image(mlx, player->p, p);
				return ;
			}
			width++;
		}
		height++;
	}
}

void	put_exit(t_map *map, t_mlx *mlx, t_texture *bh)
{
	int	height;
	int	width;

	height = 1;
	while (height < map->height)
	{
		width = 1;
		while (width < map->width)
		{
			if (map->map[height][width] == 'E')
			{
				map->coor_exit->x = width;
				map->coor_exit->y = height;
				put_image(mlx, bh->p, map->coor_exit);
				return ;
			}
			width++;
		}
		height++;
	}
}

bool	put_coins(t_map *map, t_mlx *mlx, t_texture *coin)
{
	int		height;
	int		width;
	t_gps	*place;

	height = 1;
	while (height < map->height)
	{
		width = 1;
		while (width < map->width)
		{
			if (map->map[height][width] == 'C')
			{
				place = create_gps(width, height);
				if (place == NULL)
					return (false);
				put_image(mlx, coin->p, place);
				free(place);
			}
			width++;
		}
		height++;
	}
	return (true);
}

bool	put_ennemy(t_map *map, t_mlx *mlx, t_texture *ennemy)
{
	int		height;
	int		width;
	t_gps	*place;

	height = 1;
	while (height < map->height - 1)
	{
		width = 1;
		while (width < map->width - 1)
		{
			if (map->map[height][width] == 'D')
			{
				place = create_gps(width, height);
				if (place == NULL)
					return (false);
				put_image(mlx, ennemy->p, place);
				free(place);
			}
			width++;
		}
		height++;
	}
	return (true);
}

bool	create_visu(t_map *map, t_mlx *mlx, t_gps *p, t_all_text *all_text)
{
	if (put_background(map, mlx, all_text->back->back) == false)
		return (false);
	if (put_wall_line(map, mlx, all_text->wall) == false)
		return (false);
	if (put_wall_col(map, mlx, all_text->wall) == false)
		return (false);
	if (put_obstacle(map, mlx, all_text->planets) == false)
		return (false);
	if (put_coins(map, mlx, all_text->coin->coins[0]) == false)
		return (false);
	all_text->coin->frame_act = 0;
	put_player(map, mlx, p, all_text->ships->player[1]);
	put_exit(map, mlx, all_text->black_hole_close->bh[0]);
	all_text->black_hole_close->frame_act = 0;
	if (put_ennemy(map, mlx, all_text->ships->ennemy[1]) == false)
		return (false);
	return (true);
}

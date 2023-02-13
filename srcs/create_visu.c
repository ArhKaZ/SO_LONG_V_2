/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_visu.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:50:44 by syluiset          #+#    #+#             */
/*   Updated: 2023/01/31 01:05:27 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	*get_sprite_obstacle(t_all_texture *texts, t_map *map, int height, int width)
{
	void	*sprite;
	int		random;

	sprite = NULL;
	random = get_random(4);
	if (random == 0)
	{
		sprite = texts->planets->planet_1->p;
		lst_planet_add_back(&map->planets, create_planet(height, width, 1));
	}
	if (random == 1)
	{
		sprite = texts->planets->planet_2->p;
		lst_planet_add_back(&map->planets, create_planet(height, width, 2));
	}
	if (random == 2)
	{
		sprite = texts->planets->planet_3->p;
		lst_planet_add_back(&map->planets, create_planet(height, width, 3));
	}
	if (random == 3)
	{
		sprite = texts->planets->planet_4->p;
		lst_planet_add_back(&map->planets, create_planet(height, width, 4));
	}
	return (sprite);
}

void	put_obstacle_in_map(t_map *map, void *mlx, void *mlx_win, t_all_texture *texts)
{
	int		height;
	int		width;
	void	*sprite;

	height = 1;
	while (height < map->height - 1)
	{
		width = 1;
		while (width < map->width - 1)
		{
			if (map->map[height][width] == '1')
			{
				sprite = get_sprite_obstacle(texts, map, height, width);
				mlx_put_image_to_window(mlx, mlx_win, sprite, width * 64 + 8, height * 64 + 8);
			}
			width++;
		}
		height++;
	}
}

void	put_wall(t_map *map, void *mlx, void *mlx_win, t_texture *wall)
{
	int		width;
	int 	height;

	width = 0;
	while (width < map->width)
	{
		mlx_put_image_to_window(mlx, mlx_win, wall->p, width * 64 + 12,  12);
		mlx_put_image_to_window(mlx, mlx_win, wall->p, width * 64 + 12, (map->height - 1) * 64 + 12);
		width++;
	}
	height = 1;
	while (height < map->height)
	{
		mlx_put_image_to_window(mlx, mlx_win, wall->p, 12, height * 64 + 12);
		mlx_put_image_to_window(mlx, mlx_win, wall->p, (map->width - 1) * 64 + 12, height * 64 + 12);
		height++;
	}
}

void	put_background(t_map *map, void *mlx, void *mlx_win, t_texture *back)
{
	int	height;
	int	width;

	height = 0;
	while (height < map->height * back->size->y)
	{
		width = 0;
		while (width < map->width * back->size->x)
		{
			mlx_put_image_to_window(mlx, mlx_win, back->p, width, height);
			width += back->size->x;
		}
		height += back->size->y;
	}
}

void	put_player(t_map *map, t_mlx *mlx, t_gps *p, t_texture *player)
{
	int	height;
	int	width;

	height = 1;
	while (height < map->height )
	{
		width = 1;
		while (width < map->width)
		{
			if (map->map[height][width] == 'P')
			{
				p->y = height;
				p->x = width;
				mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, player->p, width * 64 + 9, height * 64 + 9);
				return ;
			}
			width++;
		}
		height++;
	}
}

void	put_exit(t_map *map, void *mlx, void *mlx_win, t_black_hole *exit)
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
				mlx_put_image_to_window(mlx, mlx_win, exit->frame1->p, width * 64 , height * 64);
				exit->frame_act = 1;
				return ;
			}
			width++;
		}
		height++;
	}
}

void	put_coins(t_map *map, void *mlx, void *mlx_win, t_texture *coin)
{
	int		height;
	int		width;

	height = 1;
	while (height < map->height)
	{
		width = 1;
		while (width < map->width)
		{
			if (map->map[height][width] == 'C')
				mlx_put_image_to_window(mlx, mlx_win, coin->p, width * 64 + 12 , height * 64 + 12);//TODO:changes
			width++;
		}
		height++;
	}
}

//!bonus
void	put_ennemy(t_map *map, void *mlx, void *mlx_win, t_sprite_boss *ennemy)
{
	int		height;
	int		width;

	height = 1;
	while (height < map->height - 1)
	{
		width = 1;
		while (width < map->width - 1)
		{
			if (map->map[height][width] == 'D')
				mlx_put_image_to_window(mlx, mlx_win, ennemy->boss_top->p, width * 64 + 8, height * 64 + 8);
			width++;
		}
		height++;
	}
}
//!bonus

void	create_visu(t_map *map, t_mlx *mlx, t_gps *player, t_all_texture *all_texture)
{
	put_background(map, mlx->mlx, mlx->mlx_win, all_texture->background);
	put_wall(map, mlx->mlx, mlx->mlx_win, all_texture->wall);
	put_obstacle_in_map(map, mlx->mlx, mlx->mlx_win, all_texture);
	put_coins(map, mlx->mlx,mlx->mlx_win, all_texture->coin->frame1);
	all_texture->coin->frame_act = 1;
	put_player(map, mlx, player, all_texture->player->player_top);
	put_exit(map, mlx->mlx, mlx->mlx_win, all_texture->black_hole);
	put_ennemy(map, mlx->mlx, mlx->mlx_win, all_texture->ennemy);
	//?put_exit_animate(map, mlx->mlx, mlx->mlx_win, all_texture->black_hole);
}

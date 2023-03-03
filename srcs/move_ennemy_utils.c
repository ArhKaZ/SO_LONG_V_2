/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ennemy_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:30:42 by syluiset          #+#    #+#             */
/*   Updated: 2023/03/03 16:16:41 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	move_ennemy_in_tab(t_map *map, t_gps *ennemy, t_gps *new, char c)
{
	map->map[new->y][new->x] = 'D';
	map->map[ennemy->y][ennemy->x] = c;
}

void	move_ennemy_sprite(t_param *param, t_gps *new, int direction)
{
	void	*sprite;

	sprite = NULL;
	sprite = param->textures->ships->ennemy[direction]->p;
	move_ennemy_in_tab(param->map, param->boss->coor, new, '0');
	put_image(param->mlx, sprite, new);
	sprite = param->textures->back->back[get_random(2)]->p;
	put_image(param->mlx, sprite, param->boss->coor);
	param->boss->coor->x = new->x;
	param->boss->coor->y = new->y;
	sprite = NULL;
}

void	not_move_ennemy_sprite(t_param *param, int direction)
{
	void	*sprite;

	sprite = NULL;
	sprite = param->textures->ships->ennemy[direction]->p;
	put_image(param->mlx, sprite, param->boss->coor);
	sprite = NULL;
}

void	move_ennemy_to_coin(t_param *param, t_gps *new, int direction)
{
	void	*sprite;
	t_coins	*coin;

	sprite = NULL;
	coin = param->textures->coin;
	sprite = param->textures->ships->ennemy[direction]->p;
	move_ennemy_in_tab(param->map, param->boss->coor, new, 'C');
	put_image(param->mlx, sprite, new);
	if (coin->frame_act == 15)
		coin->frame_act = 0;
	sprite = coin->coins[coin->frame_act]->p;
	put_image(param->mlx, sprite, param->boss->coor);
	param->boss->coor->x = new->x;
	param->boss->coor->y = new->y;
	sprite = NULL;
}

void	move_ennemy(t_param *param, int random)
{
	if (random == 0)
	{
		move_ennemy_left(param, param->boss->coor);
		param->boss->direction = random;
	}
	if (random == 1)
	{
		move_ennemy_right(param, param->boss->coor);
		param->boss->direction = random;
	}
	if (random == 2)
	{
		move_ennemy_top(param, param->boss->coor);
		param->boss->direction = random;
	}
	if (random == 3)
	{
		move_ennemy_bottom(param, param->boss->coor);
		param->boss->direction = random;
	}
}

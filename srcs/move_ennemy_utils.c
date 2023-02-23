/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ennemy_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:30:42 by syluiset          #+#    #+#             */
/*   Updated: 2023/02/23 12:33:18 by syluiset         ###   ########.fr       */
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
	if (direction == 1)
		sprite = param->textures->ships->ennemy[0]->p;
	if (direction == 2)
		sprite = param->textures->ships->ennemy[1]->p;
	if (direction == 3)
		sprite = param->textures->ships->ennemy[2]->p;
	if (direction == 4)
		sprite = param->textures->ships->ennemy[3]->p;
	move_ennemy_in_tab(param->map, param->boss->coor, new, '0');
	put_image(param->mlx, sprite, new);
	sprite = param->textures->background->p;
	put_image(param->mlx, sprite, param->boss->coor);
	param->boss->coor->x = new->x;
	param->boss->coor->y = new->y;
	sprite = NULL;
}

void	not_move_ennemy_sprite(t_param *param, int direction)
{
	void	*sprite;

	sprite = NULL;
	if (direction == 1)
		sprite = param->textures->ships->ennemy[0]->p;
	if (direction == 2)
		sprite = param->textures->ships->ennemy[1]->p;
	if (direction == 3)
		sprite = param->textures->ships->ennemy[2]->p;
	if (direction == 4)
		sprite = param->textures->ships->ennemy[3]->p;
	put_image(param->mlx, sprite, param->boss->coor);
	sprite = NULL;
}

void	move_ennemy_to_coin(t_param *param, t_gps *new, int direction)
{
	void	*sprite;
	t_coins	*coin;

	coin = param->textures->coin;
	sprite = param->textures->background->p;
	mlx_put_image_to_window(param->mlx->mlx, param->mlx->mlx_win, sprite, new->x * 64, new->y * 64);
	if (direction == 1)
		sprite = param->textures->ships->ennemy[0]->p;
	if (direction == 2)
		sprite = param->textures->ships->ennemy[1]->p;
	if (direction == 3)
		sprite = param->textures->ships->ennemy[2]->p;
	if (direction == 4)
		sprite = param->textures->ships->ennemy[3]->p;
	move_ennemy_in_tab(param->map, param->boss->coor, new, 'C');
	put_image(param->mlx, sprite, new);
	// sprite = param->textures->background->p;
	// put_image(param->mlx, sprite, param->boss->coor);
	sprite = coin->coins[coin->frame_act];
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

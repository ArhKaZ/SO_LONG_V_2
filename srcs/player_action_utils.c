/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_action_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 14:25:45 by syluiset          #+#    #+#             */
/*   Updated: 2023/03/01 14:52:11 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	move_player(t_map *map, t_player *player, t_gps *new)
{
	char	c;

	c = map->map[new->y][new->x];
	map->map[new->y][new->x] = 'P';
	map->map[player->coor->y][player->coor->x] = c;
	player->moves += 1;
}

void	not_move_player_sprite(t_param *param, int direction)
{
	void	*sprite;

	sprite = NULL;
	if (direction == 0)
		sprite = param->textures->ships->player[0]->p;
	if (direction == 1)
		sprite = param->textures->ships->player[1]->p;
	if (direction == 2)
		sprite = param->textures->ships->player[2]->p;
	if (direction == 3)
		sprite = param->textures->ships->player[3]->p;
	put_image(param->mlx, sprite, param->player->coor);
	sprite = NULL;
	param->player->direction = direction;
}

void	move_player_sprite(t_param *param, t_gps *new, int direction)
{
	void	*sprite;

	sprite = NULL;
	param->player->direction = direction;
	if (direction == 0)
		sprite = param->textures->ships->player[0]->p;
	if (direction == 1)
		sprite = param->textures->ships->player[1]->p;
	if (direction == 2)
		sprite = param->textures->ships->player[2]->p;
	if (direction == 3)
		sprite = param->textures->ships->player[3]->p;
	move_player(param->map, param->player, new);
	put_image(param->mlx, sprite, new);
	sprite = param->textures->background->back[get_random(8)]->p;
	put_image(param->mlx, sprite, param->player->coor);
	param->player->coor->x = new->x;
	param->player->coor->y = new->y;
	sprite = NULL;
}

int	move_exit(t_param *param, t_gps *new, int move)
{
	if (param->player->collect == param->map->nb_item)
	{
		move_player_sprite(param, new, move);
		param->finish = 1;
	}
	else
		not_move_player_sprite(param, move);
	return (0);
}

void	move_coins(t_param *p, t_gps *new, int direction)
{
	p->player->collect += 1;
	p->player->score += 140;
	if (p->player->collect == p->map->nb_item)
		change_exit(p);
	put_image(p->mlx, p->textures->background->back[get_random(8)]->p, new);
	p->map->map[new->y][new->x] = '0';
	move_player_sprite(p, new, direction);
}

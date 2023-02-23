/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_action_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 14:25:45 by syluiset          #+#    #+#             */
/*   Updated: 2023/02/23 12:23:25 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	move_player(t_map *map, t_player *player, t_gps *new)
{
	char c;

	c = map->map[new->y][new->x];
	map->map[new->y][new->x] = 'P';
	map->map[player->coor->y][player->coor->x] = c;
	player->moves += 1;
}

void	not_move_player_sprite(t_param *param, int direction)
{
	void	*sprite;

	sprite = NULL;
	if (direction == 1)
		sprite = param->textures->ships->player[0]->p;
	if (direction == 2)
		sprite = param->textures->ships->player[1]->p;
	if (direction == 3)
		sprite = param->textures->ships->player[2]->p;
	if (direction == 4)
		sprite = param->textures->ships->player[3]->p;
	mlx_put_image_to_window(param->mlx->mlx, param->mlx->mlx_win, sprite, param->player->coor->x * 64, param->player->coor->y * 64);
	sprite = NULL;
	param->player->direction = direction;
}

void	less_hp(t_param *param, int direction)
{
	param->player->hp -= 1;
	if (param->player->hp == 0)
		param->finish = 1;
	not_move_ennemy_sprite(param, direction);
	//?put_hp(param->map, param->mlx, param->player, param->textures);
}

void	move_player_sprite(t_param *param, t_gps *new, int direction)
{
	void	*sprite;

	sprite = NULL;
	param->player->direction = direction;
	if (direction == 1)
		sprite = param->textures->ships->player[0]->p;
	if (direction == 2)
		sprite = param->textures->ships->player[1]->p;
	if (direction == 3)
		sprite = param->textures->ships->player[2]->p;
	if (direction == 4)
		sprite = param->textures->ships->player[3]->p;
	move_player(param->map, param->player, new);
	mlx_put_image_to_window(param->mlx->mlx, param->mlx->mlx_win, sprite, new->x * 64, new->y * 64);
	sprite = param->textures->background->p;
	mlx_put_image_to_window(param->mlx->mlx, param->mlx->mlx_win, sprite, param->player->coor->x * 64, param->player->coor->y * 64);
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
		game_win(param);
	}
	else
		not_move_player_sprite(param, move);
	return (0);
}

void	move_coins(t_param *param, t_gps *new, int direction)
{
	param->player->collect += 1;
	param->player->score += 140;
	if (param->player->collect == param->map->nb_item)
		change_exit(param);
	mlx_put_image_to_window(param->mlx->mlx, param->mlx->mlx_win, param->textures->background->p, new->x * 64, new->y * 64);
	param->map->map[new->y][new->x] = '0';
	move_player_sprite(param, new, direction);
}

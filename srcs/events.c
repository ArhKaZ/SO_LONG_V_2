/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 12:43:10 by syluiset          #+#    #+#             */
/*   Updated: 2023/02/13 17:48:50 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	close_win(t_param *param)
{

	mlx_destroy_window(param->mlx->mlx, param->mlx->mlx_win);
	free_all(param);
	exit(EXIT_SUCCESS);
}

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

	sprite = param->textures->background->p;
	mlx_put_image_to_window(param->mlx->mlx, param->mlx->mlx_win, sprite, param->player->coor->x * 64, param->player->coor->y * 64);
	if (direction == 1)
	{
		sprite = param->textures->player->player_left->p;
		param->player->direction = 1;
	}
	if (direction == 2)
	{
		sprite = param->textures->player->player_top->p;
		param->player->direction = 2;
	}
	if (direction == 3)
	{
		sprite = param->textures->player->player_right->p;
		param->player->direction = 3;
	}
	if (direction == 4)
	{
		sprite = param->textures->player->player_bottom->p;
		param->player->direction = 4;
	}
	mlx_put_image_to_window(param->mlx->mlx, param->mlx->mlx_win, sprite, param->player->coor->x * 64 + 9, param->player->coor->y * 64 + 9);
	sprite = NULL;
}

void	less_hp(t_param *param, int direction)
{
	param->player->hp -= 1;
	not_move_ennemy_sprite(param, direction);
	put_hp(param->map, param->mlx, param->player, param->textures);
}

void	move_player_sprite(t_param *param, t_gps *new, int direction)
{
	void	*sprite;

	sprite = NULL;
	if (direction == 1)
	{
		sprite = param->textures->player->player_left->p;
		param->player->direction = 1;
	}
	if (direction == 2)
	{
		sprite = param->textures->player->player_top->p;
		param->player->direction = 2;
	}
	if (direction == 3)
	{
		sprite = param->textures->player->player_right->p;
		param->player->direction = 3;
	}
	if (direction == 4)
	{
		sprite = param->textures->player->player_bottom->p;
		param->player->direction = 4;
	}

	move_player(param->map, param->player, new);
	mlx_put_image_to_window(param->mlx->mlx, param->mlx->mlx_win, sprite, new->x * 64 + 9, new->y * 64 + 9);
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
		close_win(param);
	}
	else
		not_move_player_sprite(param, move);
	return (0);
}

void	change_exit(t_param *param)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (param->map->map[y] != NULL)
	{
		x = 0;
		while (param->map->map[y][x])
		{
			if (param->map->map[y][x] == 'E')
			{
				mlx_put_image_to_window(param->mlx->mlx, param->mlx->mlx_win, param->textures->background->p, x * 64, y * 64);
				mlx_put_image_to_window(param->mlx->mlx, param->mlx->mlx_win, param->textures->black_hole->frame1->p, x * 64, y * 64);
			}
			x++;
		}
		y++;
	}
}

void	move_coins(t_param *param, t_gps *new, int direction)
{
	param->player->collect += 1;
	if (param->player->collect == param->map->nb_item)
		change_exit(param);
	mlx_put_image_to_window(param->mlx->mlx, param->mlx->mlx_win, param->textures->background->p, new->x * 64, new->y * 64);
	param->map->map[new->y][new->x] = '0';
	move_player_sprite(param, new, direction);
	put_score(param->map, param->mlx, param->player, param->textures);
}

int render_next_frame(int keycode, t_param *param)
{
	ft_printf("%d", keycode);
	if (keycode == 65307)
		close_win(param);
	if (keycode == 97)
		move_left(param);
	if (keycode == 115)
		move_bottom(param);
	if (keycode == 100)
		move_right(param);
	if (keycode == 119)
		move_top(param);
	//!bonus
	if (keycode == 32 && param->map->nb_shot == 0)
		create_new_shot(param);
	//!bonus
	put_move(param->map, param->mlx, param->player, param->textures);
	return (0);
}

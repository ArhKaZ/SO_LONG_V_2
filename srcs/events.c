/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 12:43:10 by syluiset          #+#    #+#             */
/*   Updated: 2023/02/19 21:12:08 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	close_win(t_param *param, void *mlx, void *mlx_win)
{
	free_all(param);
	mlx_destroy_window(mlx, mlx_win);
	mlx_destroy_display(mlx);
	free(mlx);
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

	sprite = NULL;
	//sprite = param->textures->background->p;
	//mlx_put_image_to_window(param->mlx->mlx, param->mlx->mlx_win, sprite, param->player->coor->x * 64, param->player->coor->y * 64);
	if (direction == 1)
		sprite = param->textures->player->player_left->p;
	if (direction == 2)
		sprite = param->textures->player->player_top->p;
	if (direction == 3)
		sprite = param->textures->player->player_right->p;
	if (direction == 4)
		sprite = param->textures->player->player_bottom->p;
	mlx_put_image_to_window(param->mlx->mlx, param->mlx->mlx_win, sprite, param->player->coor->x * 64, param->player->coor->y * 64);
	sprite = NULL;
	param->player->direction = direction;
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
	param->player->direction = direction;
	if (direction == 1)
		sprite = param->textures->player->player_left->p;
	if (direction == 2)
		sprite = param->textures->player->player_top->p;
	if (direction == 3)
		sprite = param->textures->player->player_right->p;
	if (direction == 4)
		sprite = param->textures->player->player_bottom->p;
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

void	change_exit(t_param *param)
{
	put_image(param->mlx, param->textures->background->p, param->map->coor_exit, 0);
	put_image(param->mlx, param->textures->black_hole->frame1->p, param->map->coor_exit, 0);
	param->textures->black_hole->frame_act = 1;
	return ;
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
	//?put_score(param->map, param->mlx, param->player, param->textures);
}

int render_next_frame(int keycode, t_param *param)
{
	if (param->finish == false)
	{
		if (keycode == 97)
			move_left(param);
		if (keycode == 115)
			move_bottom(param);
		if (keycode == 100)
			move_right(param);
		if (keycode == 119)
			move_top(param);
		if (keycode == 32 && param->map->nb_shot == 0)
			create_new_shot(param);
		//?put_move(param->map, param->mlx, param->player, param->textures);
	}
	if (keycode == 65307)
			close_win(param, param->mlx->mlx, param->mlx->mlx_win);
	return (0);
}

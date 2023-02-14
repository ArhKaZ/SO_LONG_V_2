/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ennemy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:32:53 by syluiset          #+#    #+#             */
/*   Updated: 2023/02/14 16:00:31 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	move_ennemy(t_map *map, t_gps *ennemy, t_gps *new, char c)
{
	map->map[new->y][new->x] = 'D';
	map->map[ennemy->y][ennemy->x] = c;
}

void	move_ennemy_sprite(t_param *param, t_gps *new, int direction, t_gps *ennemy)
{
	void	*sprite;

	sprite = NULL;
	if (direction == 1)
		sprite = param->textures->ennemy->boss_left->p;
	if (direction == 2)
		sprite = param->textures->ennemy->boss_top->p;
	if (direction == 3)
		sprite = param->textures->ennemy->boss_right->p;
	if (direction == 4)
		sprite = param->textures->ennemy->boss_bottom->p;
	// else
	// 	sprite = NULL;
	move_ennemy(param->map, ennemy, new, '0');
	mlx_put_image_to_window(param->mlx->mlx, param->mlx->mlx_win, sprite, new->x * 64 + 9, new->y * 64 + 9);
	sprite = param->textures->background->p;
	mlx_put_image_to_window(param->mlx->mlx, param->mlx->mlx_win, sprite, ennemy->x * 64, ennemy->y * 64);
	ennemy->x = new->x;
	ennemy->y = new->y;
	sprite = NULL;
}

void	not_move_ennemy_sprite(t_param *param, int direction)
{
	void	*sprite;

	sprite = param->textures->background->p;
	mlx_put_image_to_window(param->mlx->mlx, param->mlx->mlx_win, sprite, param->boss->coor->x * 64, param->boss->coor->y * 64);
	if (direction == 1)
		sprite = param->textures->ennemy->boss_left->p;
	if (direction == 2)
		sprite = param->textures->ennemy->boss_top->p;
	if (direction == 3)
		sprite = param->textures->ennemy->boss_right->p;
	if (direction == 4)
		sprite = param->textures->ennemy->boss_bottom->p;
	mlx_put_image_to_window(param->mlx->mlx, param->mlx->mlx_win, sprite, param->boss->coor->x * 64 + 9, param->boss->coor->y * 64 + 9);
	sprite = NULL;
}

void	*choose_texture_coin(t_param *param)
{
	if (param->textures->coin->frame_act == 1)
		return (param->textures->coin->frame1->p);
	if (param->textures->coin->frame_act == 2)
		return (param->textures->coin->frame2->p);
	if (param->textures->coin->frame_act == 3)
		return (param->textures->coin->frame3->p);
	if (param->textures->coin->frame_act == 4)
		return (param->textures->coin->frame4->p);
	if (param->textures->coin->frame_act == 5)
		return (param->textures->coin->frame5->p);
	if (param->textures->coin->frame_act == 6)
		return (param->textures->coin->frame6->p);
	if (param->textures->coin->frame_act == 7)
		return (param->textures->coin->frame7->p);
	if (param->textures->coin->frame_act == 8)
		return (param->textures->coin->frame8->p);
	if (param->textures->coin->frame_act == 9)
		return (param->textures->coin->frame9->p);
	if (param->textures->coin->frame_act == 10)
		return (param->textures->coin->frame10->p);
	if (param->textures->coin->frame_act == 11)
		return (param->textures->coin->frame11->p);
	if (param->textures->coin->frame_act == 12)
		return (param->textures->coin->frame12->p);
	if (param->textures->coin->frame_act == 13)
		return (param->textures->coin->frame13->p);
	if (param->textures->coin->frame_act == 14)
		return (param->textures->coin->frame14->p);
	if (param->textures->coin->frame_act == 15)
		return (param->textures->coin->frame15->p);
	return (NULL);
}

void	move_ennemy_to_coin(t_param *param, t_gps *new, int direction, t_gps *ennemy)
{
	void	*sprite;

	sprite = param->textures->background->p;
	mlx_put_image_to_window(param->mlx->mlx, param->mlx->mlx_win, sprite, new->x * 64, new->y * 64);
	if (direction == 1)
		sprite = param->textures->ennemy->boss_left->p;
	if (direction == 2)
		sprite = param->textures->ennemy->boss_top->p;
	if (direction == 3)
		sprite = param->textures->ennemy->boss_right->p;
	if (direction == 4)
		sprite = param->textures->ennemy->boss_bottom->p;
	move_ennemy(param->map, ennemy, new, 'C');
	mlx_put_image_to_window(param->mlx->mlx, param->mlx->mlx_win, sprite, new->x * 64 + 9, new->y * 64 + 9);
	sprite = param->textures->background->p;
	mlx_put_image_to_window(param->mlx->mlx, param->mlx->mlx_win, sprite, ennemy->x * 64, ennemy->y * 64);
	sprite = choose_texture_coin(param);
	mlx_put_image_to_window(param->mlx->mlx, param->mlx->mlx_win, sprite, ennemy->x * 64 + 12, ennemy->y * 64 + 12);
	ennemy->x = new->x;
	ennemy->y = new->y;
	sprite = NULL;
}

int	move_ennemy_left(t_param *param, t_gps *ennemy)
{
	char	value_case;
	t_gps	*new;

	if (ennemy != NULL)
	{
		new = create_empty_gps();
		new->x = ennemy->x - 1;
		new->y = ennemy->y;
		value_case = param->map->map[new->y][new->x];
		if (value_case == '1' || value_case == 'E' || value_case == 'D' )
		{
			not_move_ennemy_sprite(param, 1);
			free(new);
			return (0);
		}
		if (value_case == 'C')
		{
			move_ennemy_to_coin(param, new, 1, ennemy);
			free(new);
			return (1);
		}
		if (value_case == 'P')
			less_hp(param, 1);
		if (value_case == '0')
			move_ennemy_sprite(param, new, 1, ennemy);
		free(new);
	}
	return (0);
}

int	move_ennemy_right(t_param *param, t_gps *ennemy)
{
	char	value_case;
	t_gps	*new;

	if (ennemy != NULL)
	{
		new = create_empty_gps();
		new->x = ennemy->x + 1;
		new->y = ennemy->y;
		value_case = param->map->map[new->y][new->x];
		if (value_case == '1' || value_case == 'E' || value_case == 'D')
		{
			not_move_ennemy_sprite(param, 3);
			free(new);
			return (0);
		}
		if (value_case == 'C')
		{
			move_ennemy_to_coin(param, new, 3, ennemy);
			free(new);
			return (1);
		}
		if (value_case == 'P')
			less_hp(param, 3);
		if (value_case == '0')
			move_ennemy_sprite(param, new, 3, ennemy);
		free(new);
	}
	return (0);
}

int	move_ennemy_top(t_param *param, t_gps *ennemy)
{
	char	value_case;
	t_gps	*new;

	if (ennemy != NULL)
	{
		new = create_empty_gps();
		new->x = ennemy->x;
		new->y = ennemy->y - 1;
		value_case = param->map->map[new->y][new->x];
		if (value_case == '1' || value_case == 'E' || value_case == 'D')
		{
			not_move_ennemy_sprite(param, 2);
			free(new);
			return (0);
		}
		if (value_case == 'C')
		{
			move_ennemy_to_coin(param, new, 2, ennemy);
			free(new);
			return (1);
		}
		if (value_case == 'P')
			less_hp(param, 2);
		if (value_case == '0')
			move_ennemy_sprite(param, new, 2, ennemy);
		free(new);
	}
	return (0);
}

int	move_ennemy_bottom(t_param *param, t_gps *ennemy)
{
	char	value_case;
	t_gps	*new;

	if (ennemy != NULL)
	{
		new = create_empty_gps();
		new->x = ennemy->x;
		new->y = ennemy->y + 1;
		value_case = param->map->map[new->y][new->x];
		if (value_case == '1' || value_case == 'E' || value_case == 'D')
		{
			not_move_ennemy_sprite(param, 4);
			free(new);
			return (0);
		}
		if (value_case == 'C')
		{
			move_ennemy_to_coin(param, new, 4, ennemy);
			free(new);
			return (1);
		}
		if (value_case == 'P')
			less_hp(param, 4);
		if (value_case == '0')
			move_ennemy_sprite(param, new, 4, ennemy);
		free(new);
	}
	return (0);
}

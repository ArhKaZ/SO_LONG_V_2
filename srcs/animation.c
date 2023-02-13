/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:58:46 by syluiset          #+#    #+#             */
/*   Updated: 2023/02/13 16:20:44 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
t_gps	*find_exit(t_param *param)
{
	t_gps	*exit;
	int i;
	int j;

	i = 0;
	exit = create_empty_gps();
	while (param->map->map[i] != NULL)
	{
		j = 0;
		while (param->map->map[i][j])
		{
			if (param->map->map[i][j] == 'E')
			{
				exit->x = j;
				exit->y = i;
			}
			j++;
		}
		i++;
	}
	return (exit);
}

int	animate_black_hole(t_param *param)
{
	t_black_hole *bh;
	t_map	*map;

	map = param->map;
	bh = param->textures->black_hole;
	if (bh->frame_act < 9)
	{
		if (bh->frame_act == 1)
			mlx_put_image_to_window(param->mlx->mlx, param->mlx->mlx_win, bh->frame2->p, map->coor_exit->x * 64, map->coor_exit->y * 64);
		if (bh->frame_act == 2)
			mlx_put_image_to_window(param->mlx->mlx, param->mlx->mlx_win, bh->frame3->p, map->coor_exit->x * 64, map->coor_exit->y * 64);
		if (bh->frame_act == 3)
			mlx_put_image_to_window(param->mlx->mlx, param->mlx->mlx_win, bh->frame4->p, map->coor_exit->x * 64, map->coor_exit->y * 64);
		if (bh->frame_act == 4)
			mlx_put_image_to_window(param->mlx->mlx, param->mlx->mlx_win, bh->frame5->p, map->coor_exit->x * 64, map->coor_exit->y * 64);
		if (bh->frame_act == 5)
			mlx_put_image_to_window(param->mlx->mlx, param->mlx->mlx_win, bh->frame6->p, map->coor_exit->x * 64, map->coor_exit->y * 64);
		if (bh->frame_act == 6)
			mlx_put_image_to_window(param->mlx->mlx, param->mlx->mlx_win, bh->frame7->p, map->coor_exit->x * 64, map->coor_exit->y * 64);
		if (bh->frame_act == 7)
			mlx_put_image_to_window(param->mlx->mlx, param->mlx->mlx_win, bh->frame8->p, map->coor_exit->x * 64, map->coor_exit->y * 64);
		if (bh->frame_act == 8)
			mlx_put_image_to_window(param->mlx->mlx, param->mlx->mlx_win, bh->frame9->p, map->coor_exit->x * 64, map->coor_exit->y * 64);
		bh->frame_act += 1;
	}
	else if (bh->frame_act == 9)
	{
		mlx_put_image_to_window(param->mlx->mlx, param->mlx->mlx_win, bh->frame1->p, map->coor_exit->x * 64, map->coor_exit->y * 64);
		bh->frame_act = 1;
	}
	return (0);
}

int		put_frame_for_coin(t_param *param)
{
	t_coins *coins;

	coins = param->textures->coin;
	if (coins->frame_act < 15)
	{
		if (coins->frame_act == 1)
			put_coins(param->map, param->mlx->mlx, param->mlx->mlx_win, coins->frame2);
		if (coins->frame_act == 2)
			put_coins(param->map, param->mlx->mlx, param->mlx->mlx_win, coins->frame3);
		if (coins->frame_act == 3)
			put_coins(param->map, param->mlx->mlx, param->mlx->mlx_win, coins->frame4);
		if (coins->frame_act == 4)
			put_coins(param->map, param->mlx->mlx, param->mlx->mlx_win, coins->frame5);
		if (coins->frame_act == 5)
			put_coins(param->map, param->mlx->mlx, param->mlx->mlx_win, coins->frame6);
		if (coins->frame_act == 6)
			put_coins(param->map, param->mlx->mlx, param->mlx->mlx_win, coins->frame7);
		if (coins->frame_act == 7)
			put_coins(param->map, param->mlx->mlx, param->mlx->mlx_win, coins->frame8);
		if (coins->frame_act == 8)
			put_coins(param->map, param->mlx->mlx, param->mlx->mlx_win, coins->frame9);
		if (coins->frame_act == 9)
			put_coins(param->map, param->mlx->mlx, param->mlx->mlx_win, coins->frame10);
		if (coins->frame_act == 10)
			put_coins(param->map, param->mlx->mlx, param->mlx->mlx_win, coins->frame11);
		if (coins->frame_act == 11)
			put_coins(param->map, param->mlx->mlx, param->mlx->mlx_win, coins->frame12);
		if (coins->frame_act == 12)
			put_coins(param->map, param->mlx->mlx, param->mlx->mlx_win, coins->frame13);
		if (coins->frame_act == 13)
			put_coins(param->map, param->mlx->mlx, param->mlx->mlx_win, coins->frame14);
		if (coins->frame_act == 14)
			put_coins(param->map, param->mlx->mlx, param->mlx->mlx_win, coins->frame15);
		coins->frame_act += 1;
	}
	else if (coins->frame_act == 15)
	{
		put_coins(param->map, param->mlx->mlx, param->mlx->mlx_win, coins->frame1);
		coins->frame_act = 1;
	}
	return (0);
}

int	choose_direction(t_param *param)
{
	t_ennemy	*first;
	int			random;

	if (param->map->nb_ennemy > 0)
	{
		first = param->boss;
		while (param->boss != NULL)
		{
			if (param->boss->next != NULL)
			{
				if (param->map->map[param->boss->next->coor->y][param->boss->next->coor->x] == 'V')
				{
					param->boss = clear_ennemy(param->boss);
				}
			}
			random = get_random(50);
			if (random == 0)
				move_ennemy_left(param, param->boss->coor);
			if (random == 1)
				move_ennemy_right(param, param->boss->coor);
			if (random == 2)
				move_ennemy_top(param, param->boss->coor);
			if (random == 3)
				move_ennemy_bottom(param, param->boss->coor);
			param->boss = param->boss->next;
		}
		param->boss = first;
	}
	return (0);
}

int	animation(t_param *param)
{
	if (shoot_exist(param) == 1)
		animate_shoot(param, param->shots->coor);
	choose_direction(param);
	put_frame_for_coin(param);
	animate_black_hole(param);
	//game_over(param);
	usleep(50000);
	return (0);
}


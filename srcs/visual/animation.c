/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:58:46 by syluiset          #+#    #+#             */
/*   Updated: 2023/02/27 13:40:05 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	change_exit(t_param *param)
{
	void	*sprite;

	sprite = param->textures->background->p;
	put_image(param->mlx, sprite, param->map->coor_exit);
	sprite = param->textures->black_hole->bh[0]->p;
	put_image(param->mlx, sprite, param->map->coor_exit);
	param->textures->black_hole->frame_act = 1;
	return ;
}

int	animate_black_hole_close(t_param *param)
{
	t_black_hole	*bh;
	t_map			*map;
	t_texture		*sprite;

	sprite = NULL;
	map = param->map;
	bh = param->textures->black_hole_close;
	if (bh->frame_act <= 8)
	{
		sprite = bh->bh[bh->frame_act];
		bh->frame_act += 1;
	}
	else if (bh->frame_act == 9)
	{
		bh->frame_act = 0;
		sprite = bh->bh[bh->frame_act];
	}
	put_image(param->mlx, sprite->p, map->coor_exit);
	return (0);
}

int	animate_black_hole(t_param *param)
{
	t_black_hole	*bh;
	t_map			*map;
	t_texture		*sprite;

	sprite = NULL;
	map = param->map;
	bh = param->textures->black_hole;
	if (bh->frame_act <= 8)
	{
		sprite = bh->bh[bh->frame_act];
		bh->frame_act += 1;
	}
	else if (bh->frame_act == 9)
	{
		bh->frame_act = 0;
		sprite = bh->bh[bh->frame_act];
	}
	put_image(param->mlx, sprite->p, map->coor_exit);
	return (0);
}

int	put_frame_for_coin(t_param *param)
{
	t_coins		*coins;
	t_texture	*sprite;

	sprite = NULL;
	coins = param->textures->coin;
	if (coins->frame_act <= 14)
	{
		sprite = coins->coins[coins->frame_act];
		coins->frame_act += 1;
	}
	else if (coins->frame_act == 15)
	{
		coins->frame_act = 0;
		sprite = coins->coins[coins->frame_act];
	}
	put_coins(param->map, param->mlx, sprite);
	return (0);
}

int	animation(t_param *param)
{
	if (param->mlx->menu == false)
	{
		if (param->finish != 1)
		{
			if (shoot_exist(param) == 1)
				animate_shoot(param, param->shots->coor);
			choose_direction(param);
			put_frame_for_coin(param);
			if (param->player->collect != param->map->nb_item)
				animate_black_hole_close(param);
			else
				animate_black_hole(param);
			put_strings(param);
			usleep(50000);
		}
		is_end(param);

	}
	return (0);
}

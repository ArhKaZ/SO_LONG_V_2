/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_shot.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 11:07:26 by syluiset          #+#    #+#             */
/*   Updated: 2023/02/27 13:45:01 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	animate_shoot_left(t_param *param, t_gps *coor)
{
	t_shoot_texture	*shoot;
	t_texture		*sprite;

	sprite = NULL;
	shoot = param->textures->shoot;
	if (param->map->nb_shot == 1)
	{
		if (shoot->frame_act <= 3)
		{
			sprite = shoot->s_left[shoot->frame_act];
			shoot->frame_act += 1;
		}
		else if (shoot->frame_act == 4)
		{
			shoot->frame_act = 0;
			sprite = shoot->s_left[shoot->frame_act];
		}
		put_image(param->mlx, sprite->p, coor);
	}
	return (0);
}

int	animate_shoot_top(t_param *param, t_gps *coor)
{
	t_shoot_texture	*shoot;
	t_texture		*sprite;

	sprite = NULL;
	shoot = param->textures->shoot;
	if (param->map->nb_shot == 1)
	{
		if (shoot->frame_act <= 3)
		{
			sprite = shoot->s_top[shoot->frame_act];
			shoot->frame_act += 1;
		}
		else if (shoot->frame_act == 4)
		{
			shoot->frame_act = 0;
			sprite = shoot->s_top[shoot->frame_act];
		}
		put_image(param->mlx, sprite->p, coor);
	}
	return (0);
}

int	animate_shoot_right(t_param *param, t_gps *coor)
{
	t_shoot_texture	*shoot;
	t_texture		*sprite;

	sprite = NULL;
	shoot = param->textures->shoot;
	if (param->map->nb_shot == 1)
	{
		if (shoot->frame_act <= 3)
		{
			sprite = shoot->s_right[shoot->frame_act];
			shoot->frame_act += 1;
		}
		else if (shoot->frame_act == 4)
		{
			shoot->frame_act = 0;
			sprite = shoot->s_right[shoot->frame_act];
		}
		put_image(param->mlx, sprite->p, coor);
	}
	return (0);
	return (0);
}

int	animate_shoot_bot(t_param *param, t_gps *coor)
{
	t_shoot_texture	*shoot;
	t_texture		*sprite;

	sprite = NULL;
	shoot = param->textures->shoot;
	if (param->map->nb_shot == 1)
	{
		if (shoot->frame_act <= 3)
		{
			sprite = shoot->s_bot[shoot->frame_act];
			shoot->frame_act += 1;
		}
		else if (shoot->frame_act == 4)
		{
			shoot->frame_act = 0;
			sprite = shoot->s_bot[shoot->frame_act];
		}
		put_image(param->mlx, sprite->p, coor);
	}
	return (0);
}

int	animate_shoot(t_param *param, t_gps *coor)
{
	if (param->shots->direction == 0)
		animate_shoot_left(param, coor);
	if (param->shots->direction == 1)
		animate_shoot_top(param, coor);
	if (param->shots->direction == 2)
		animate_shoot_right(param, coor);
	if (param->shots->direction == 3)
		animate_shoot_bot(param, coor);
	return (0);
}

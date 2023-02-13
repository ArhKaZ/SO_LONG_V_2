/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_shot.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 11:07:26 by syluiset          #+#    #+#             */
/*   Updated: 2023/02/13 13:06:00 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	animate_shoot_left(t_param *param, t_gps *coor)
{
	t_shoot_texture	*shoot;

	shoot = param->textures->shoot;
	if (param->map->nb_shot == 1)
	{
		put_image(param->mlx, param->textures->background->p, coor, 0);
		if (shoot->frame_act < 4)
		{
			if (shoot->frame_act == 1)
				put_image(param->mlx, shoot->frame2_left->p, coor, 12);
			if (shoot->frame_act == 2)
				put_image(param->mlx, shoot->frame3_left->p, coor, 12);
			if (shoot->frame_act == 3)
				put_image(param->mlx, shoot->frame4_left->p, coor, 12);
			shoot->frame_act += 1;
		}
		else if (shoot->frame_act == 4)
		{
			put_image(param->mlx, shoot->frame1_left->p, coor, 12);
			shoot->frame_act = 1;
		}
	}
	return (0);
}
int	animate_shoot_top(t_param *param, t_gps *coor)
{
	t_shoot_texture	*shoot;

	shoot = param->textures->shoot;
	if (param->map->nb_shot == 1)
	{
		put_image(param->mlx, param->textures->background->p, coor, 0);
		if (shoot->frame_act < 4)
		{
			if (shoot->frame_act == 1)
				put_image(param->mlx, shoot->frame2_top->p, coor, 12);
			if (shoot->frame_act == 2)
				put_image(param->mlx, shoot->frame3_top->p, coor, 12);
			if (shoot->frame_act == 3)
				put_image(param->mlx, shoot->frame4_top->p, coor, 12);
			shoot->frame_act += 1;
		}
		else if (shoot->frame_act == 4)
		{
			put_image(param->mlx, shoot->frame1_top->p, coor, 12);
			shoot->frame_act = 1;
		}
	}
	return (0);
}
int	animate_shoot_right(t_param *param, t_gps *coor)
{
	t_shoot_texture	*shoot;

	shoot = param->textures->shoot;
	if (param->map->nb_shot == 1)
	{
		put_image(param->mlx, param->textures->background->p, coor, 0);
		if (shoot->frame_act < 4)
		{
			if (shoot->frame_act == 1)
				put_image(param->mlx, shoot->frame2_right->p, coor, 12);
			if (shoot->frame_act == 2)
				put_image(param->mlx, shoot->frame3_right->p, coor, 12);
			if (shoot->frame_act == 3)
				put_image(param->mlx, shoot->frame4_right->p, coor, 12);
			shoot->frame_act += 1;
		}
		else if (shoot->frame_act == 4)
		{
			put_image(param->mlx, shoot->frame1_right->p, coor, 12);
			shoot->frame_act = 1;
		}
	}
	return (0);
}
int	animate_shoot_bot(t_param *param, t_gps *coor)
{
	t_shoot_texture	*shoot;

	shoot = param->textures->shoot;
	if (param->map->nb_shot == 1)
	{
		put_image(param->mlx, param->textures->background->p, coor, 0);
		if (shoot->frame_act < 4)
		{
			if (shoot->frame_act == 1)
				put_image(param->mlx, shoot->frame2_bot->p, coor, 12);
			if (shoot->frame_act == 2)
				put_image(param->mlx, shoot->frame3_bot->p, coor, 12);
			if (shoot->frame_act == 3)
				put_image(param->mlx, shoot->frame4_bot->p, coor, 12);
			shoot->frame_act += 1;
		}
		else if (shoot->frame_act == 4)
		{
			put_image(param->mlx, shoot->frame1_bot->p, coor, 12);
			shoot->frame_act = 1;
		}
	}
	return (0);
}

int animate_shoot(t_param *param, t_gps *coor)
{
    if (param->shots->direction == 1)
    
        animate_shoot_left(param, coor);
    if (param->shots->direction == 2)
        animate_shoot_top(param, coor);
    if (param->shots->direction == 3)
        animate_shoot_right(param, coor);
    if (param->shots->direction == 4)
        animate_shoot_bot(param, coor);
    return (0);
}
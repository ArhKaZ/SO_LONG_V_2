/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shoot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 17:10:42 by syluiset          #+#    #+#             */
/*   Updated: 2023/02/26 20:40:12 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	kill_ennemy(t_param *p, t_gps *new)
{
	clock_t		begin;
	clock_t		current;
	t_explosion	*ex;

	begin = clock();
	current = clock();
	ex_for_dir(p->textures->explosion, p->mlx, p->boss->direction);
	ex = p->textures->explosion;
	p->player->score += 50;
	while ((current - begin) * 1000 / CLOCKS_PER_SEC < 100)
	{
		if (ex->frame_act_e < 2)
		{
			put_image(p->mlx, ex->ennemy_ex[ex->frame_act_e]->p, new);
			ex->frame_act_e += 1;
		}
		else
		{
			ex->frame_act_e = 0;
			put_image(p->mlx, ex->ennemy_ex[ex->frame_act_e]->p, new);
		}
		current = clock();
	}
	del_ennemy(p, new);
	put_image(p->mlx, p->textures->background->p, new);
}

void	make_explosion(t_param *param, t_gps *new)
{
	//put_image(param->mlx, param->textures->background->p, param->shots->coor);
	if (new->x == 0 || new->y == 0 || new->y == param->map->height - 1
		|| new->x == param->map->width - 1)
		return ;
	else
	{
		put_image(param->mlx, param->textures->planets->planet_exp->p, new);
		if (param->player->score - 20 > 0)
		{
			param->player->score -= 20;
		}
		else
			param->player->score = 0;
		param->map->map[new->y][new->x] = '2';
		param->map->map[param->shots->coor->y][param->shots->coor->x] = '0';
	}
	return ;
}

bool	move_shot(t_param *param)
{
	t_gps	*new;
	clock_t	current;
	bool	ret;

	ret = true;
	current = clock();
	if ((current - param->shots->shoot_time) * 1000 / CLOCKS_PER_SEC > 1)
	{
		new = get_next_coor_s(param->shots->direction, param->shots->coor);
		if (put_shot_in_coor(param, new) == false)
			ret = false;
		else
			param->shots->shoot_time = current;
		free(new);
	}
	return (ret);
}

int	shoot_exist(t_param *param)
{
	if (param->map->nb_shot == 1)
	{
		if (move_shot(param) == true)
			return (1);
		else
			return (0);
	}
	return (0);
}

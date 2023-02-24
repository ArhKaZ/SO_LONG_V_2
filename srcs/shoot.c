/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shoot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 17:10:42 by syluiset          #+#    #+#             */
/*   Updated: 2023/02/24 02:51:14 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	kill_ennemy(t_param *param, t_gps *new)
{
	clock_t		begin;
	clock_t		current;
	t_explosion	*ex;

	begin = clock();
	current = clock();
	ex = create_explosion(param->mlx, param->boss->direction);
	put_image(param->mlx, ex->ennemy_ex[0]->p, new);
	param->player->score += 50;
	while ((current - begin) * 1000 / CLOCKS_PER_SEC < 100)
	{
		if (ex->frame_act < 2)
		{
			put_image(param->mlx, ex->ennemy_ex[ex->frame_act]->p, new);
			ex->frame_act += 1;
		}
		else
		{
			ex->frame_act = 0;
			put_image(param->mlx, ex->ennemy_ex[ex->frame_act]->p, new);
		}
		current = clock();
	}
	del_ennemy(param, new);
	put_image(param->mlx, param->textures->background->p, new);
	free_explosion(ex, param->mlx->mlx);
}

void	make_explosion(t_param *param, t_gps *new)
{
	put_image(param->mlx, param->textures->background->p, param->shots->coor);
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

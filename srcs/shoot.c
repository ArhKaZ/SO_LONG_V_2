/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shoot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 17:10:42 by syluiset          #+#    #+#             */
/*   Updated: 2023/02/23 15:44:06 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

t_shoot	*create_shot(clock_t time, int direction)
{
	t_shoot	*shot;

	shot = malloc(sizeof(t_shoot));
	shot->direction = direction;
	shot->shoot_time = time;
	return (shot);
}

t_gps	*get_next_coor_s(int direction, t_gps *coor)
{
	t_gps	*new;

	new = NULL;
	if (direction == 1)
		new = create_gps(coor->x - 1, coor->y);
	if (direction == 2)
		new = create_gps(coor->x, coor->y - 1);
	if (direction == 3)
		new = create_gps(coor->x + 1, coor->y);
	if (direction == 4)
		new = create_gps(coor->x, coor->y + 1);
	return (new);
}

void	kill_boss(t_param *param, t_gps *new)
{
	clock_t		begin;
	clock_t		current;
	t_explosion	*ex;

	begin = clock();
	current = clock();
	ex = create_explosion(param->mlx, param->boss->direction);
	put_image(param->mlx, ex->boss_explosion1->p, new);
	param->player->score += 50;
	while ((current - begin) * 1000 / CLOCKS_PER_SEC < 100)
	{
		if (ex->frame_act < 2)
		{
			if (ex->frame_act == 0)
				put_image(param->mlx, ex->boss_explosion2->p, new);
			if (ex->frame_act == 1)
				put_image(param->mlx, ex->boss_explosion3->p, new);
			ex->frame_act += 1;
		}
		else
		{
			put_image(param->mlx, ex->boss_explosion1->p, new);
			ex->frame_act = 0;
		}
		current = clock();
	}
	del_ennemy(param, new);
	put_image(param->mlx, param->textures->background->p, new);
	free_explosion(ex, param->mlx->mlx);
}

void	make_explosion(t_param *param, t_gps *new)
{
	if (new->x == 0 || new->y == 0 || new->y == param->map->height - 1
			|| new->x == param->map->width - 1)
		return ;
	else
	{
		put_image(param->mlx, param->textures->planets->planet_exp->p, new);
		if (param->player->score - 20 > 0)
			param->player->score -= 20;
		else
			param->player->score = 0;
	}
	return ;
}

void	put_shoot_in_direction(t_param *param, t_gps *new)
{
	if (param->shots->direction == 1)
		put_image(param->mlx, param->textures->shoot->s_left[0]->p, new);
	if (param->shots->direction == 2)
		put_image(param->mlx, param->textures->shoot->s_top[0]->p, new);
	if (param->shots->direction == 3)
		put_image(param->mlx, param->textures->shoot->s_right[0]->p, new);
	if (param->shots->direction == 4)
		put_image(param->mlx, param->textures->shoot->s_bot[0]->p, new);
	param->textures->shoot->frame_act = 0;
}

bool	put_shot_in_coor(t_param *param, t_gps *new)
{
	char	value_case;

	value_case = param->map->map[new->y][new->x];
	if (value_case == '1')
	{
		put_image(param->mlx, param->textures->background->p, param->shots->coor);
		make_explosion(param, new);
		param->map->map[new->y][new->x] = '2';
		param->map->map[param->shots->coor->y][param->shots->coor->x] = '0';
		del_shot(param);
		return (false);
	}
	if (value_case == 'D')
	{
		kill_boss(param, new);
		param->map->map[param->shots->coor->y][param->shots->coor->x] = '0';
		put_image(param->mlx, param->textures->background->p, param->shots->coor);
		del_shot(param);
		return (false);
	}
	if (value_case == '0')
	{
		param->map->map[param->shots->coor->y][param->shots->coor->x] = '0';
		put_image(param->mlx, param->textures->background->p, param->shots->coor);
		param->map->map[new->y][new->x] = 'S';
		put_shoot_in_direction(param, new);
		param->shots->coor->x = new->x;
		param->shots->coor->y = new->y;
	}
	if (value_case == 'E' || value_case == 'C' || value_case == '2')
	{
		put_image(param->mlx, param->textures->background->p, param->shots->coor);
		param->map->map[param->shots->coor->y][param->shots->coor->x] = '0';
		del_shot(param);
		return (false);
	}
	return (true);
}

void	create_new_shot(t_param *param)
{
	t_shoot	*shot;

	shot = create_shot(clock(), param->player->direction);
	shot->coor = get_next_coor_s(param->player->direction, param->player->coor);
	if (param->map->map[shot->coor->y][shot->coor->x] == '1')
	{
		if (!(shot->coor->x == 0 || shot->coor->y == 0 || shot->coor->x == param->map->width - 1 || shot->coor->y == param->map->height - 1))
			make_explosion(param, shot->coor);
		free(shot->coor);
		free(shot);
		return ;
	}
	if (param->map->map[shot->coor->y][shot->coor->x] == 'D')
	{
		kill_boss(param, shot->coor);
		put_image(param->mlx, param->textures->background->p, shot->coor);
		free(shot->coor);
		free(shot);
		return ;
	}
	if (param->map->map[shot->coor->y][shot->coor->x] == 'E')
	{
		free(shot->coor);
		free(shot);
		return ;
	}
	if (param->map->map[shot->coor->y][shot->coor->x] == 'C')
	{
		free(shot->coor);
		free(shot);
		return ;
	}
	if (param->map->map[shot->coor->y][shot->coor->x] == '0')
	{
		param->map->nb_shot += 1;
		param->map->map[shot->coor->y][shot->coor->x] = 'S';
		param->shots = shot;
		put_shoot_in_direction(param, param->shots->coor);
		param->textures->shoot->frame_act = 1;
		return ;
	}
}

void	del_shot(t_param *param)
{
	param->map->nb_shot -= 1;
	free(param->shots->coor);
	free(param->shots);
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

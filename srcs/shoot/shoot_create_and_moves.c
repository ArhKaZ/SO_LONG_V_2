/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shoot_create_and_moves.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 02:41:36 by syluiset          #+#    #+#             */
/*   Updated: 2023/03/06 14:34:01 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	put_shot_in_new(t_param *p, t_gps *new)
{
	void	*sprite;

	sprite = p->textures->back->back[get_random(2)]->p;
	p->map->map[p->shots->coor->y][p->shots->coor->x] = '0';
	put_image(p->mlx, sprite, p->shots->coor);
	p->map->map[new->y][new->x] = 'S';
	put_shoot_in_direction(p, new);
	p->shots->coor->x = new->x;
	p->shots->coor->y = new->y;
}

bool	kill_ennemy_and_del_shot(t_param *p, t_gps *new)
{
	void	*sprite;

	sprite = p->textures->back->back[get_random(2)]->p;
	kill_ennemy(p, new);
	p->map->map[p->shots->coor->y][p->shots->coor->x] = '0';
	put_image(p->mlx, sprite, p->shots->coor);
	del_shot(p, p->shots);
	return (false);
}

bool	put_shot_in_coor(t_param *p, t_gps *new)
{
	char	value_case;
	void	*sprite;

	sprite = NULL;
	value_case = p->map->map[new->y][new->x];
	if (value_case == '1')
	{
		make_explosion(p, new, p->shots, 0);
		del_shot(p, p->shots);
		return (false);
	}
	if (value_case == 'D')
		return (kill_ennemy_and_del_shot(p, new));
	if (value_case == '0')
		put_shot_in_new(p, new);
	if (value_case == 'E' || value_case == 'C' || value_case == '2')
	{
		sprite = p->textures->back->back[get_random(2)]->p;
		put_image(p->mlx, sprite, p->shots->coor);
		p->map->map[p->shots->coor->y][p->shots->coor->x] = '0';
		del_shot(p, p->shots);
		return (false);
	}
	return (true);
}

void	create_shot_spe_case(t_param *param, int c, t_shoot *shot)
{
	if (c == 'D')
	{
		kill_ennemy(param, shot->coor);
		free(shot->coor);
		free(shot);
	}
	else if (c == 'E' || c == 'C' || c == '2')
	{
		free(shot->coor);
		free(shot);
	}
}

void	create_new_shot(t_param *param)
{
	t_shoot	*shot;
	char	c;

	shot = create_shot(clock(), param->player->direction, param->player->coor);
	if (shot == NULL)
		return ;
	c = param->map->map[shot->coor->y][shot->coor->x];
	if (c == '1')
	{
		if (!(shot->coor->x == 0 || shot->coor->y == 0
				|| shot->coor->x == param->map->width - 1
				|| shot->coor->y == param->map->height - 1))
			make_explosion(param, shot->coor, shot, 1);
		else
			del_shot(param, shot);
	}
	else if (c == '0')
	{
		param->map->nb_shot = 1;
		param->map->map[shot->coor->y][shot->coor->x] = 'S';
		param->shots = shot;
		put_shoot_in_direction(param, param->shots->coor);
	}
	else
		create_shot_spe_case(param, c, shot);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shoot_create_and_moves.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 02:41:36 by syluiset          #+#    #+#             */
/*   Updated: 2023/02/26 21:31:27 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	put_shot_in_new(t_param *param, t_gps *new)
{
	param->map->map[param->shots->coor->y][param->shots->coor->x] = '0';
	put_image(param->mlx, param->textures->background->p, param->shots->coor);
	param->map->map[new->y][new->x] = 'S';
	put_shoot_in_direction(param, new);
	param->shots->coor->x = new->x;
	param->shots->coor->y = new->y;
}

bool	kill_ennemy_and_del_shot(t_param *param, t_gps *new)
{
	kill_ennemy(param, new);
	param->map->map[param->shots->coor->y][param->shots->coor->x] = '0';
	put_image(param->mlx, param->textures->background->p, param->shots->coor);
	del_shot(param);
	return (false);
}

bool	put_shot_in_coor(t_param *p, t_gps *new)
{
	char	value_case;

	value_case = p->map->map[new->y][new->x];
	if (value_case == '1')
	{
		make_explosion(p, new, 0);
		del_shot(p);
		return (false);
	}
	if (value_case == 'D')
		return (kill_ennemy_and_del_shot(p, new));
	if (value_case == '0')
		put_shot_in_new(p, new);
	if (value_case == 'E' || value_case == 'C' || value_case == '2')
	{
		put_image(p->mlx, p->textures->background->p, p->shots->coor);
		p->map->map[p->shots->coor->y][p->shots->coor->x] = '0';
		del_shot(p);
		return (false);
	}
	return (true);
}

void	create_new_shot(t_param *param)
{
	t_shoot	*shot;
	char	c;

	shot = create_shot(clock(), param->player->direction, param->player->coor);
	c = param->map->map[shot->coor->y][shot->coor->x];
	if (c == '1')
	{
		if (!(shot->coor->x == 0 || shot->coor->y == 0
				|| shot->coor->x == param->map->width - 1
				|| shot->coor->y == param->map->height - 1))
			make_explosion(param, shot->coor, 1);
	}
	else if (c == 'D')
	{
		kill_ennemy(param, shot->coor);
		free(shot->coor);
		free(shot);
	}
	else if (c == '0')
	{
		param->map->nb_shot = 1;
		param->map->map[shot->coor->y][shot->coor->x] = 'S';
		param->shots = shot;
		put_shoot_in_direction(param, param->shots->coor);
	}
	// free(shot->coor);
	// free(shot);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ennemy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:32:53 by syluiset          #+#    #+#             */
/*   Updated: 2023/02/22 15:07:04 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

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

int	choose_direction(t_param *param)
{
	t_ennemy	*first;
	if (param->map->nb_ennemy > 0)
	{
		free_ennemy(param->boss);
		param->boss = get_ennemy(param->map);
		first = param->boss;
		while (param->boss != NULL)
		{
			move_ennemy(param, get_random(50));
			param->boss = param->boss->next;
		}
		param->boss = first;
	}
	return (0);
}


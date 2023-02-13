/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_in_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 14:25:45 by syluiset          #+#    #+#             */
/*   Updated: 2023/02/13 12:51:36 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int		nb_ennemy(t_ennemy *lst)
{
	int i;
	t_ennemy *fir;

	fir = lst;
	i = 0;
	while (lst != NULL)
	{
		i++;
		lst = lst->next;
	}
	lst = fir;
	return (i);
}

void	move_left(t_param *param)
{
	char	value_case;
	t_gps	*new;

	new = create_empty_gps();
	new->x = param->player->coor->x - 1;
	new->y = param->player->coor->y;
	value_case = param->map->map[new->y][new->x];
	if (value_case == '1' || value_case == 'D')
	{
		not_move_player_sprite(param, 1);
		free(new);
		return ;
	}
	if (value_case == 'E')
	{
		if (move_exit(param, new, 1) == 0)
		{
			free(new);
			return ;
		}
	}
	if (value_case == 'C')
		move_coins(param, new, 1);
	if (value_case == '0')
		move_player_sprite(param, new, 1);
	free(new);
}

void	move_right(t_param *param)
{
	char	value_case;
	t_gps	*new;

	new = create_empty_gps();
	new->x = param->player->coor->x + 1;
	new->y = param->player->coor->y;
	value_case = param->map->map[new->y][new->x];
	if (value_case == '1' || value_case == 'D')
	{
		not_move_player_sprite(param, 3);
		free(new);
		return ;
	}
	if (value_case == 'E')
	{
		if (move_exit(param, new, 3) == 0)
		{
			free(new);
			return ;
		}
	}
	if (value_case == 'C')
		move_coins(param, new, 3);
	if (value_case == '0')
		move_player_sprite(param, new, 3);
	free(new);
}

void	move_top(t_param *param)
{
	char	value_case;
	t_gps	*new;

	new = create_empty_gps();
	new->x = param->player->coor->x;
	new->y = param->player->coor->y - 1;
	value_case = param->map->map[new->y][new->x];
	if (value_case == '1' || value_case == 'D')
	{
		not_move_player_sprite(param, 2);
		free(new);
		return ;
	}
	if (value_case == 'E')
	{
		if (move_exit(param, new, 2) == 0)
		{
			free(new);
			return ;
		}
	}
	if (value_case == 'C')
		move_coins(param, new, 2);
	if (value_case == '0')
		move_player_sprite(param, new, 2);
	free(new);
}

void	move_bottom(t_param *param)
{
	char	value_case;
	t_gps	*new;

	new = create_empty_gps();
	new->x = param->player->coor->x;
	new->y = param->player->coor->y + 1;
	value_case = param->map->map[new->y][new->x];
	if (value_case == '1' || value_case == 'D')
	{
		not_move_player_sprite(param, 4);
		free(new);
		return ;
	}
	if (value_case == 'E')
	{
		if (move_exit(param, new, 4) == 0)
		{
			free(new);
			return ;
		}
	}
	if (value_case == 'C')
		move_coins(param, new, 4);
	if (value_case == '0')
		move_player_sprite(param, new, 4);
	free(new);
}

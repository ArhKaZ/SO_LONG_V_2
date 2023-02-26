/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_action.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 12:43:10 by syluiset          #+#    #+#             */
/*   Updated: 2023/02/26 14:37:22 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	move_left(t_param *param)
{
	char	value_case;
	t_gps	*new;

	new = create_gps(param->player->coor->x - 1, param->player->coor->y);
	value_case = param->map->map[new->y][new->x];
	if (value_case == '1' || value_case == 'D')
	{
		not_move_player_sprite(param, 1);
		return (free(new));
	}
	if (value_case == 'E')
	{
		if (move_exit(param, new, 1) == 0)
			return (free(new));
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

	new = create_gps(param->player->coor->x + 1, param->player->coor->y);
	value_case = param->map->map[new->y][new->x];
	if (value_case == '1' || value_case == 'D')
	{
		not_move_player_sprite(param, 3);
		return (free(new));
	}
	if (value_case == 'E')
	{
		if (move_exit(param, new, 3) == 0)
			return (free(new));
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

	new = create_gps(param->player->coor->x, param->player->coor->y - 1);
	value_case = param->map->map[new->y][new->x];
	if (value_case == '1' || value_case == 'D')
	{
		not_move_player_sprite(param, 2);
		return (free(new));
	}
	if (value_case == 'E')
	{
		if (move_exit(param, new, 2) == 0)
			return (free(new));
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

	new = create_gps(param->player->coor->x, param->player->coor->y + 1);
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

int	render_next_frame(int keycode, t_param *param)
{
	if (keycode == 65307)
			close_win(param, param->mlx->mlx, param->mlx->mlx_win);
	if (param->mlx->menu == false)
	{
		if (param->finish != 1)
		{
			if (keycode == 97)
				move_left(param);
			if (keycode == 115)
				move_bottom(param);
			if (keycode == 100)
				move_right(param);
			if (keycode == 119)
				move_top(param);
			if (keycode == 32 && param->map->nb_shot == 0)
				create_new_shot(param);
		}
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_damage.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:04:18 by syluiset          #+#    #+#             */
/*   Updated: 2023/03/01 13:51:58 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

t_texture	*get_sprite_frame(t_param *param, int direction)
{
	t_texture *sprite;
	if (param->textures->explosion->frame_act_p == 0)
	{
		sprite = param->textures->background->p;
		param->textures->explosion->frame_act_p = 1;
	}
	else
	{
		sprite = param->textures->ships->player[direction]->p;
		param->textures->explosion->frame_act_p = 0;
	}
	return (sprite);
}

void	damage_on_player(t_param *param)
{
	clock_t		begin;
	clock_t		current;
	int			direction;
	t_player	*player;
	void		*sprite;

	player = param->player;
	direction = param->player->direction;
	begin = clock();
	current = clock();
	while ((current - begin) * 1000 / CLOCKS_PER_SEC < 200)
	{
		sprite = get_sprite_frame(param, direction);
		put_image(param->mlx, sprite, player->coor);
		current = clock();
	}
	sprite = param->textures->ships->player[direction]->p;
	put_image(param->mlx, sprite, player->coor);
}

void	less_hp(t_param *param, int direction)
{
	if (param->player->hp - 1 == 0)
	{
		param->finish = 1;
		param->player->hp -= 1;
		//is_end(param);
	}
	else
	{
		param->player->hp -= 1;
		not_move_ennemy_sprite(param, direction);
		damage_on_player(param);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_end.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 13:15:25 by syluiset          #+#    #+#             */
/*   Updated: 2023/02/23 15:36:40 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	game_win(t_param *param)
{
	t_gps		*place;
	t_texture	*sprite;

	sprite = NULL;
	place = NULL;
	param->finish = true;
	if (param->map->height < 8 || param->map->width < 8)
	{
		sprite = param->textures->end->w_little;
		place = create_gps((param->map->width * 64 - sprite->size->x) / 2,
				(param->map->height * 64 - sprite->size->y) / 2);
		put_last_image(param, place, sprite->p, 1);
	}
	else if (param->map->height < 14 || param->map->width < 14)
	{
		sprite = param->textures->end->w_med;
		place = create_gps((param->map->width * 64 - sprite->size->x) / 2,
				(param->map->height * 64 - sprite->size->y) / 2);
		put_last_image(param, place, sprite->p, 2);
	}
	else if (param->map->height >= 14 || param->map->width >= 14)
	{
		sprite = param->textures->end->w_big;
		place = create_gps((param->map->width * 64 - sprite->size->x) / 2,
				(param->map->height * 64 - sprite->size->y) / 2);
		put_last_image(param, place, sprite->p, 3);
	}
	free(place);
	return (0);
}

int	game_over(t_param *param)
{
	t_gps		*place;
	t_texture	*sprite;

	sprite = NULL;
	place = NULL;
	param->finish = true;
	if (param->map->height < 8 || param->map->width < 8)
	{
		sprite = param->textures->end->l_little;
		place = create_gps((param->map->width * 64 - sprite->size->x) / 2,
				(param->map->height * 64 - sprite->size->y) / 2);
		put_last_image(param, place, sprite->p, 1);
	}
	else if (param->map->height < 14 || param->map->width < 14)
	{
		sprite = param->textures->end->l_med;
		place = create_gps((param->map->width * 64 - sprite->size->x) / 2,
				(param->map->height * 64 - sprite->size->y) / 2);
		put_last_image(param, place, sprite->p, 2);
	}
	else if (param->map->height >= 14 || param->map->width >= 14)
	{
		sprite = param->textures->end->l_big;
		place = create_gps((param->map->width * 64 - sprite->size->x) / 2,
				(param->map->height * 64 - sprite->size->y) / 2);
		put_last_image(param, place, sprite->p, 3);
	}
	free(place);
	return (0);
}

int	is_end(t_param *param)
{
	if (param->finish == 1)
		game_win(param);
	if (param->player->hp == 0)
		game_over(param);
	return (1);
}

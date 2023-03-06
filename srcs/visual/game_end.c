/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_end.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 13:15:25 by syluiset          #+#    #+#             */
/*   Updated: 2023/03/06 15:07:30 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	put_last_image_little(t_param *param, bool win)
{
	t_gps		*place;
	t_texture	*sprite;

	if (win == true)
		sprite = param->textures->end->w_little;
	else
		sprite = param->textures->end->l_little;
	place = create_gps((param->map->width * 64 - sprite->size->x) / 2,
			(param->map->height * 64 - sprite->size->y) / 2);
	put_last_image(param, place, sprite, 1);
	free(place);
}

void	put_last_image_med(t_param *param, bool win)
{
	t_gps		*place;
	t_texture	*sprite;

	if (win == true)
		sprite = param->textures->end->w_med;
	else
		sprite = param->textures->end->l_med;
	place = create_gps((param->map->width * 64 - sprite->size->x) / 2,
			(param->map->height * 64 - sprite->size->y) / 2);
	put_last_image(param, place, sprite, 2);
	free(place);
}

void	put_last_image_big(t_param *param, bool win)
{
	t_gps		*place;
	t_texture	*sprite;

	if (win == true)
		sprite = param->textures->end->w_big;
	else
		sprite = param->textures->end->l_big;
	place = create_gps((param->map->width * 64 - sprite->size->x) / 2,
			(param->map->height * 64 - sprite->size->y) / 2);
	put_last_image(param, place, sprite, 3);
	free(place);
}

int	is_end(t_param *param)
{
	bool	win;

	win = true;
	if (param->finish == 1)
	{
		param->finish = 2;
		if (param->player->hp == 0)
			win = false;
		if (param->map->height < 8 || param->map->width < 8)
			put_last_image_little(param, win);
		else if (param->map->height < 14 || param->map->width < 14)
			put_last_image_med(param, win);
		else if (param->map->height >= 14 || param->map->width >= 14)
			put_last_image_big(param, win);
	}
	return (1);
}

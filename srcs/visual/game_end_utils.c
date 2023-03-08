/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_end_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:33:49 by syluiset          #+#    #+#             */
/*   Updated: 2023/03/08 13:37:10 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	put_sprite_nb(t_param *param, int nb, t_gps *place)
{
	t_texture	*sprite;

	if (nb == 0)
	{
		sprite = param->textures->nb->nb[0];
		put_image_xy(param->mlx, sprite->p, place);
	}
	while (nb > 0)
	{
		sprite = param->textures->nb->nb[nb % 10];
		place->x -= (sprite->size->x + 4);
		put_image_xy(param->mlx, sprite->p, place);
		nb /= 10;
	}
	free(place);
}

void	put_score_end(t_param *p, t_gps *place_img, t_gps *img_size, int size)
{
	t_gps		*place;
	int			x;
	int			y;

	x = 0;
	y = 0;
	if (size == 1)
	{
		x = place_img->x + ((img_size->x / 100) * 100);
		y = place_img->y + ((img_size->y / 100) * 42.5);
	}
	if (size == 2)
	{
		x = place_img->x + ((img_size->x / 100) * 95);
		y = place_img->y + ((img_size->y / 100) * 34.5);
	}
	if (size == 3)
	{
		x = place_img->x + ((img_size->x / 100) * 95);
		y = place_img->y + ((img_size->y / 100) * 41);
	}
	place = create_gps(x, y);
	put_sprite_nb(p, p->player->score, place);
}

void	put_moves_end(t_param *p, t_gps *place_img, t_gps *img_size, int size)
{
	t_gps		*place;
	int			y;
	int			x;

	y = 0;
	x = 0;
	if (size == 1)
	{
		x = place_img->x + ((img_size->x / 100) * 100);
		y = place_img->y + ((img_size->y / 100) * 80.5);
	}
	if (size == 2)
	{
		x = place_img->x + ((img_size->x / 100) * 90);
		y = place_img->y + ((img_size->y / 100) * 65);
	}
	if (size == 3)
	{
		x = place_img->x + ((img_size->x / 100) * 90);
		y = place_img->y + ((img_size->y / 100) * 73.5);
	}
	place = create_gps(x, y);
	put_sprite_nb(p, p->player->moves, place);
}

void	put_last_image(t_param *param, t_gps *place, t_texture *s, int size)
{
	mlx_clear_window(param->mlx->mlx, param->mlx->mlx_win);
	put_image_xy(param->mlx, s->p, place);
	put_moves_end(param, place, s->size, size);
	put_score_end(param, place, s->size, size);
}

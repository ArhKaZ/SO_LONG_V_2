/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_end_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:33:49 by syluiset          #+#    #+#             */
/*   Updated: 2023/03/03 20:29:26 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	put_sprite_nb(t_param *param, int nb, t_gps *place)
{
	void	*sprite
	if (nb == 0)
	{
		sprite = param->textures->nb->nb[0]->;
		put_image_xy(param->mlx, sprite, place);
	}
	while (nb > 0)
	{
		sprite = param->textures->nb->nb[nb % 10]->p;
		place->x -= (sprite->size->x + 4);
		put_image_xy(param->mlx, sprite, place);
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
		y = place_img->y + ((img_size->y / 100) * 43);
	}
	if (size == 2)
	{
		x = place_img->x + ((img_size->x / 100) * 95);
		y = place_img->y + ((img_size->y / 100) * 37.5);
	}
	if (size == 3)
	{
		x = place_img->x + ((img_size->x / 100) * 95);
		y = place_img->y + ((img_size->y / 100) * 41);
	}
	place = create_gps(x, y);
	put_sprite_nb(p, p->player->score, place);
}

void	put_time_end(t_param *p, t_gps *place_img, t_gps *img_size, int size)
{
	t_gps		*place;
	int			y;
	int			x;
	clock_t		now;

	y = 0;
	x = 0;
	if (size == 1)
	{
		x = place_img->x + ((img_size->x / 100) * 90);
		y = place_img->y + ((img_size->y / 100) * 86);
	}
	if (size == 2)
	{
		x = place_img->x + ((img_size->x / 100) * 90);
		y = place_img->y + ((img_size->y / 100) * 68.5);
	}
	if (size == 3)
	{
		x = place_img->x + ((img_size->x / 100) * 90);
		y = place_img->y + ((img_size->y / 100) * 75);
	}
	place = create_gps(x, y);
	now = clock();
	put_sprite_nb(p, now - (p->time), place);
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
		x = place_img->x + ((img_size->x / 100) * 90);
		y = place_img->y + ((img_size->y / 100) * 60);
	}
	if (size == 2)
	{
		x = place_img->x + ((img_size->x / 100) * 90);
		y = place_img->y + ((img_size->y / 100) * 50);
	}
	if (size == 3)
	{
		x = place_img->x + ((img_size->x / 100) * 90);
		y = place_img->y + ((img_size->y / 100) * 60);
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

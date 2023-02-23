/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_end_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:33:49 by syluiset          #+#    #+#             */
/*   Updated: 2023/02/23 15:42:08 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

t_texture	*choose_sprite_nb(t_all_texture *text, int nb)
{
	if (nb == 0)
		return (text->nb->zero);
	if (nb == 1)
		return (text->nb->one);
	if (nb == 2)
		return (text->nb->two);
	if (nb == 3)
		return (text->nb->three);
	if (nb == 4)
		return (text->nb->four);
	if (nb == 5)
		return (text->nb->five);
	if (nb == 6)
		return (text->nb->six);
	if (nb == 7)
		return (text->nb->seven);
	if (nb == 8)
		return (text->nb->eight);
	if (nb == 9)
		return (text->nb->nine);
	return (NULL);
}

void	put_sprite_nb(t_param *param, int nb, t_texture *sprite, t_gps *place)
{
	if (nb == 0)
	{
		sprite = param->textures->nb->zero;
		put_image(param->mlx, sprite->p, place);
	}
	while (nb > 0)
	{
		sprite = choose_sprite_nb(param->textures, nb % 10);
		place->x -= (sprite->size->x + 4);
		put_image(param->mlx, sprite->p, place);
		nb /= 10;
	}
}

void	put_score_end(t_param *p, t_gps *place_img, t_gps *img_size, int size)
{
	t_gps		*place;
	t_texture	*sprite;

	sprite = NULL;
	place = NULL;
	if (size == 1)
	{
		place = create_gps(place_img->x + (img_size->x / 100) * 100,
				place_img->y + (img_size->y / 100) * 46);
	}
	if (size == 2)
	{
		place = create_gps(place_img->x + (img_size->x / 100) * 95,
				place_img->y + (img_size->y / 100) * 37.5);
	}
	if (size == 3)
	{
		place = create_gps(place_img->x + (img_size->x / 100) * 95,
				place_img->y + (img_size->y / 100) * 41);
	}
	put_sprite_nb(p, p->player->score, sprite, place);
	free(place);
}

void	put_moves_end(t_param *p, t_gps *place_img, t_gps *img_size, int size)
{
	t_gps		*place;
	t_texture	*sprite;

	sprite = NULL;
	place = NULL;
	if (size == 1)
	{
		place = create_gps(place_img->x + (img_size->x / 100) * 90,
				place_img->y + (img_size->y / 100) * 86);
	}
	if (size == 2)
	{
		place = create_gps(place_img->x + (img_size->x / 100) * 90,
				place_img->y + (img_size->y / 100) * 68.5);
	}
	if (size == 3)
	{
		place = create_gps(place_img->x + (img_size->x / 100) * 90,
				place_img->y + (img_size->y / 100) * 75);
	}
	put_sprite_nb(p, p->player->moves, sprite, place);
	free(place);
}

void	put_last_image(t_param *param, t_gps *place, t_texture *s, int size)
{
	mlx_clear_window(param->mlx->mlx, param->mlx->mlx_win);
	put_image(param->mlx, s->p, place);
	put_moves_end(param, place, s->size, size);
	put_score_end(param, place, s->size, size);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_over.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 13:15:25 by syluiset          #+#    #+#             */
/*   Updated: 2023/02/23 13:20:47 by syluiset         ###   ########.fr       */
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
void	put_sprite_nb(t_param *param, int nb_temp, t_texture *sprite, t_gps *place)
{
	if (nb_temp == 0)
	{
		sprite = param->textures->nb->zero;
		mlx_put_image_to_window(param->mlx->mlx, param->mlx->mlx_win, sprite->p, place->x, place->y);
	}
	while (nb_temp > 0)
	{
		sprite = choose_sprite_nb(param->textures, nb_temp % 10);
		place->x -= (sprite->size->x + 4);
		mlx_put_image_to_window(param->mlx->mlx, param->mlx->mlx_win, sprite->p, place->x, place->y);
		nb_temp /= 10;
	}
}

void	put_score_end(t_param *param, t_gps *place_back, t_gps *back_size, int choice)
{
	t_gps	*place;
	int		size_x_10;
	int		size_y_10;
	t_texture	*sprite;

	sprite = NULL;
	place = NULL;
	if (choice == 1)
	{
		place = create_gps(place_back->x + (back_size->x / 100) * 100,
			place_back->y + (back_size->y / 100) * 46);
	}
	if (choice == 2)
	{
		place = create_gps(place_back->x + (back_size->x / 100) * 95,
			place_back->y + (back_size->y / 100) * 37.5);
	}
	if (choice == 3)
	{
		place = create_gps(place_back->x + (back_size->x / 100) * 95,
			place_back->y + (back_size->y / 100) * 41);
	}
	put_sprite_nb(param, param->player->score, sprite, place);
	free(place);
}

void	put_moves_end(t_param *param, t_gps *place_back, t_gps *back_size, int choice)
{
	t_gps	*place;
	float		size_x_10;
	float		size_y_10;
	t_texture	*sprite;

	sprite = NULL;
	place = NULL;
	if (choice == 1)
	{
		place = create_gps(place_back->x + (back_size->x / 100) * 90,
			place_back->y + (back_size->y / 100) * 86);
	}
	if (choice == 2)
	{
		place = create_gps(place_back->x + (back_size->x / 100) * 90,
			place_back->y + (back_size->y / 100) * 68.5);
	}
	if (choice == 3)
	{
		place = create_gps(place_back->x + (back_size->x / 100) * 90,
			place_back->y + (back_size->y / 100) * 75);
	}
	put_sprite_nb(param, param->player->moves, sprite, place);
	free(place);
}

void	put_last_image(t_param *param, t_gps *place, t_texture *sprite, int choice)
{
	mlx_clear_window(param->mlx->mlx, param->mlx->mlx_win);
	mlx_put_image_to_window(param->mlx->mlx, param->mlx->mlx_win, sprite->p, place->x, place->y);
	put_moves_end(param, place, sprite->size, choice);
	put_score_end(param, place, sprite->size, choice);
}

int	game_win(t_param *param)
{
	t_gps	*place;
	t_texture	*sprite;

	sprite = NULL;
	place = NULL;
	param->finish = true;
	if (param->map->height < 8 || param->map->width < 8)
	{
		sprite = param->textures->end->w_little;
		place = create_gps((param->map->width * 64 - sprite->size->x) / 2,
			(param->map->height * 64 - sprite->size->y) / 2);
		put_last_image(param, place, sprite, 1);
	}
	else if (param->map->height < 14 || param->map->width < 14)
	{
		sprite = param->textures->end->w_med;
		place = create_gps((param->map->width * 64 - sprite->size->x) / 2,
			(param->map->height * 64 - sprite->size->y) / 2);
		put_last_image(param, place, sprite, 2);
	}
	else if (param->map->height >= 14 || param->map->width >= 14)
	{
		sprite = param->textures->end->w_big;
		place = create_gps((param->map->width * 64 - sprite->size->x) / 2,
			(param->map->height * 64 - sprite->size->y) / 2);
		put_last_image(param, place, sprite, 3);
	}
	free(place);
	return (0);
}

int	game_over(t_param *param)
{
	t_gps	*place;
	t_texture	*sprite;

	sprite = NULL;
	place = NULL;
	param->finish = true;
	if (param->map->height < 8 || param->map->width < 8)
	{
		sprite = param->textures->end->l_little;
		place = create_gps((param->map->width * 64 - sprite->size->x) / 2,
			(param->map->height * 64 - sprite->size->y) / 2);
		put_last_image(param, place, sprite, 1);
	}
	else if (param->map->height < 14 || param->map->width < 14)
	{
		sprite = param->textures->end->l_med;
		place = create_gps((param->map->width * 64 - sprite->size->x) / 2,
			(param->map->height * 64 - sprite->size->y) / 2);
		put_last_image(param, place, sprite, 2);
	}
	else if (param->map->height >= 14 || param->map->width >= 14)
	{
		sprite = param->textures->end->l_big;
		place = create_gps((param->map->width * 64 - sprite->size->x) / 2,
			(param->map->height * 64 - sprite->size->y) / 2);
		put_last_image(param, place, sprite, 3);
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

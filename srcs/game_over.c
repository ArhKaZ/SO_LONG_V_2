/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_over.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 13:15:25 by syluiset          #+#    #+#             */
/*   Updated: 2023/02/17 15:44:51 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

// int	check_key(int keycode, t_param *param) //? besoin
// {
// 	if (keycode == 53)
// 	{
// 		free_textures(param->textures, param->mlx->mlx);
// 		free(param->mlx);
// 		free(param);
// 		close_win(param);
// 	}
// 	return (0);
// }

void	free_finish(t_param *param)
{
	free_map(param->map);
	free_player(param->player);
	free_ennemy(param->boss);
}

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

// int	get_distance_from_digit(int	nb)
// {
// 	int	digit;
// 	digit = 0;
// 	while ()
// }

void	put_score_end(t_param *param)
{
	t_gps	*place;
	int		height_div_10;
	int		width_div_10;
	int		nb_temp;
	t_texture	*sprite;
	
	sprite = NULL;
	height_div_10 = (param->map->height * 64) / 100;
	width_div_10 = (param->map->width * 64) / 100;
	place = create_empty_gps();
	place->x = width_div_10 * 65;
	place->y = height_div_10 * 41.8;
	nb_temp = param->player->score;
	while (nb_temp > 0)
	{
		sprite = choose_sprite_nb(param->textures, nb_temp % 10);
		mlx_put_image_to_window(param->mlx->mlx, param->mlx->mlx_win, sprite->p, place->x, place->y);
		nb_temp /= 10;
		place->x -= (sprite->size->x + 4);
	}
	free(place);
}

void	put_moves_end(t_param *param, t_gps *place_back, t_gps *back_size)
{
	t_gps	*place;
	int		size_x_10;
	int		size_y_10;
	int		nb_temp;
	t_texture	*sprite;

	sprite = NULL;
	place = create_empty_gps();
	size_x_10 = back_size->x / 100;
	size_y_10 = back_size->y / 100;
	place->x = place_back->x * 64 + size_x_10 * 50;
	place->y = place_back->y * 64 + size_y_10 * 40;
	// place->x = width_div_10 * 63;
	// place->y = height_div_10 * 58.5;
	nb_temp = param->player->moves;
	while (nb_temp > 0)
	{
		sprite = choose_sprite_nb(param->textures, nb_temp % 10);
		mlx_put_image_to_window(param->mlx->mlx, param->mlx->mlx_win, sprite->p, place->x, place->y);
		nb_temp /= 10;
		place->x -= (sprite->size->x + 4);
	}
	free(place);
}

int	game_win(t_param *param)
{
	t_gps	*place;
	t_texture	*sprite;

	sprite = NULL;
	param->finish = true;
	place = create_empty_gps(); 
	if (param->map->height < 8 && param->map->width < 8)
		sprite = param->textures->end->little;
	else if (param->map->height < 14 && param->map->width < 14)
		sprite = param->textures->end->medium;
	else if (param->map->height >= 14 && param->map->width >= 14)
		sprite = param->textures->end->big;
	place->x = (param->map->width - (sprite->size->x / 64)) / 2;
	place->y = (param->map->height - (sprite->size->y / 64)) / 2;
	mlx_clear_window(param->mlx->mlx, param->mlx->mlx_win);
	put_image(param->mlx, sprite->p, place, 0);
	put_moves_end(param, place, sprite->size);
	put_score_end(param);
	free(place);
	return (0);
}

int	game_over(t_param *param)
{
	t_gps		*place;
	t_texture	*sprite;

	sprite = NULL;
	param->finish = true;
	place = create_empty_gps(); 
	if (param->map->height < 8 && param->map->width < 8)
		sprite = param->textures->game_over->little;
	else if (param->map->height < 14 && param->map->width < 14)
		sprite = param->textures->game_over->medium;
	else if (param->map->height >= 14 && param->map->width >= 14)
		sprite = param->textures->game_over->big;
	place->x = (param->map->width - (sprite->size->x / 64)) / 2;
	place->y = (param->map->height - (sprite->size->y / 64)) / 2;
	mlx_clear_window(param->mlx->mlx, param->mlx->mlx_win);
	put_image(param->mlx, sprite->p, place, 0);
	put_moves_end(param, place, sprite->size);
	put_score_end(param);
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
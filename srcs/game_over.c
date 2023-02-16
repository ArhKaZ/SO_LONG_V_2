/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_over.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 13:15:25 by syluiset          #+#    #+#             */
/*   Updated: 2023/02/16 17:59:01 by syluiset         ###   ########.fr       */
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

int	game_over(t_param *param)
{
	// char	*score;
	// char	*moves;
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
	//score = ft_itoa(param->player->collect);
	//moves = ft_itoa(param->player->moves);
	place->x = (param->map->width - (sprite->size->x / 64)) / 2;
	place->y = (param->map->height - (sprite->size->y / 64)) / 2;
	mlx_clear_window(param->mlx->mlx, param->mlx->mlx_win);
	put_image(param->mlx, sprite->p, place, 0);
	//free_textures_go(param->textures, param->mlx->mlx);
	free(place);
	//free_finish(param);
	//mlx_key_hook(param->mlx->mlx_win, check_key, param);
	return (0);
}

void	put_score_end(t_param *param, t_texture *sprite)
{
	t_gps	*place;
	int		height_div_10;
	int		width_div_10;
	int		nb_temp;
	
	height_div_10 = param->map->height / 10;
	width_div_10 = param->map->width / 10;
	place = create_empty_gps();
	place->x = width_div_10 * 6;
	place->y = height_div_10 * 6;
	nb_temp = param->player->score;
	//TODO use tab? 
}

void	put_moves_end(t_param *param, t_texture *sprite)
{
	t_gps	*place;
	int		height_div_10;
	int		width_div_10;
	int		nb_temp;
	
	height_div_10 = param->map->height / 10;
	width_div_10 = param->map->width / 10;
	place = create_empty_gps();
	place->x = width_div_10 * 6;
	place->y = height_div_10 * 6; //? atteindre moves :
	nb_temp = param->player->score;
	//TODO use tab? 
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
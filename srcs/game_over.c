/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_over.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 13:15:25 by syluiset          #+#    #+#             */
/*   Updated: 2023/02/14 17:05:07 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	check_key(int keycode, t_param *param) //? besoin
{
	if (keycode == 53)
	{
		free_textures(param->textures, param->mlx->mlx);
		free(param->mlx);
		free(param);
		close_win(param);
	}
	return (0);
}

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
	t_gps	*zero;

	if (param->player->hp == 0)
	{
		param->finish = true;
		zero = create_empty_gps();
		zero->x = param->map->width / 6;
		zero->y = param->map->height / 4;
		//score = ft_itoa(param->player->collect);
		//moves = ft_itoa(param->player->moves);
		mlx_clear_window(param->mlx->mlx, param->mlx->mlx_win);
		//free_textures_go(param->textures, param->mlx->mlx);
		if (param->map->height < 10 && param->map->width < 10)
			put_image(param->mlx, param->textures->game_over->little->p, zero, 0);
		//if (param->map->height < 20 && param->map->width < 20)
			//put_image(param->mlx, param->textures->game_over->medium->p, zero, 0);
		if (param->map->height > 20 && param->map->width > 20)
			put_image(param->mlx, param->textures->game_over->big->p, zero, 0);
		free(zero);
		//free_finish(param);
		//mlx_key_hook(param->mlx->mlx_win, check_key, param);
	}
	return (0);
}

int	game_finish(t_param *param)
{
	// char	*score;
	// char	*moves;
	t_gps	*zero;

	param->finish = true;
	zero = create_empty_gps();
	zero->x = param->map->width / 6;
	zero->y = param->map->height / 4;
	//score = ft_itoa(param->player->collect);
	//moves = ft_itoa(param->player->moves);
	mlx_clear_window(param->mlx->mlx, param->mlx->mlx_win);
	ft_printf("cc");
	//free_textures_go(param->textures, param->mlx->mlx);
	if (param->map->height < 10 && param->map->width < 10)
		put_image(param->mlx, param->textures->game_over->little->p, zero, 0);
	//if (param->map->height < 20 && param->map->width < 20)
		//put_image(param->mlx, param->textures->game_over->medium->p, zero, 0);
	if (param->map->height > 20 && param->map->width > 20)
		put_image(param->mlx, param->textures->game_over->big->p, zero, 0);
	free(zero);
	//free_finish(param);
	//mlx_key_hook(param->mlx->mlx_win, check_key, param);
	return (0);
}


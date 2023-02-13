/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_over.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 13:15:25 by syluiset          #+#    #+#             */
/*   Updated: 2023/02/12 19:50:17 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	check_key(int keycode, t_param *param)
{
	if (keycode == 53)
		close_win(param);
	return (0);
}

void	free_textures_go(t_all_texture *texts, void *mlx)
{
	free_texture(texts->background, mlx);
	//free_texture(texts->coin, mlx);
	//free_texture(texts->earth, mlx);
	free_texture(texts->exit, mlx);
	free_texture(texts->player->player_bottom, mlx);
	free_texture(texts->player->player_top, mlx);
	free_texture(texts->player->player_right, mlx);
	free_texture(texts->player->player_left, mlx);
	free_texture(texts->wall, mlx);
}

int	game_over(t_param *param)
{
	// char	*score;
	// char	*moves;
	t_gps	*zero;

	if (param->player->hp == 0)
	{
		zero = create_empty_gps();
		zero->x = param->map->width / 6;
		zero->y = param->map->height / 4;
		//score = ft_itoa(param->player->collect);
		//moves = ft_itoa(param->player->moves);
		mlx_clear_window(param->mlx->mlx, param->mlx->mlx_win);
		//free_textures_go(param->textures, param->mlx->mlx);
		if (param->map->height < 10 && param->map->width < 10)
			put_image(param->mlx, param->textures->game_over->little->p, zero, 0);
		//mlx_string_put(param->mlx->mlx, param->mlx->mlx_win, (param->map->width * 64) / 10 * 3, (param->map->height * 64) / 10 * 4, 0x453F7C, score);
		//mlx_string_put(param->mlx, param->mlx->mlx_win, (param->map->width * 64) / 10 * 6, (param->map->height * 64) / 10 * 4, 0x453F7C, moves);
		mlx_key_hook(param->mlx->mlx_win, check_key, param);
	}
	return (0);
}
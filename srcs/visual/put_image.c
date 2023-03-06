/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:06:27 by syluiset          #+#    #+#             */
/*   Updated: 2023/03/06 15:07:39 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	put_image(t_mlx *mlx, void *sprite, t_gps *coor)
{
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, sprite,
		coor->x * 64, coor->y * 64);
	return ;
}

void	put_image_xy(t_mlx *mlx, void *sprite, t_gps *coor)
{
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, sprite,
		coor->x, coor->y);
	return ;
}

void	put_image_player(t_mlx *mlx, t_texture *sprite, t_gps *coor)
{
	coor->x *= 64;
	coor->y *= 64;
	coor->x += 64 - sprite->size->x;
	coor->y += 64 - sprite->size->y;
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, sprite->p,
		coor->x, coor->y);
	return ;
}

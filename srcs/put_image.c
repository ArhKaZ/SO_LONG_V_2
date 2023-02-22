/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:06:27 by syluiset          #+#    #+#             */
/*   Updated: 2023/02/22 13:28:22 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	put_image(t_mlx *mlx, void *sprite, t_gps *coor)
{
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, sprite, coor->x * 64, coor->y * 64);
	return ;
}

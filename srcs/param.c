/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:02:20 by syluiset          #+#    #+#             */
/*   Updated: 2023/02/14 15:22:00 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

t_param	*create_param(t_map *map, t_mlx *mlx, t_player *player, t_all_texture *all_texture)
{
	t_param	*param;

	param = malloc(sizeof(t_param));
	if (!param)
		return (NULL);
	param->map = map;
	param->mlx = mlx;
	param->player = player;
	param->textures = all_texture;
	param->shots = NULL;
	param->finish = 0;
	return (param);
}
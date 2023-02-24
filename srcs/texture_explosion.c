/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_explosion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:52:38 by syluiset          #+#    #+#             */
/*   Updated: 2023/02/24 02:33:27 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

t_explosion	*create_ex_sprite(t_mlx *mlx, char *path1, char *path2, char *path3)
{
	t_explosion	*ex;

	ex = NULL;
	ex = malloc(sizeof(t_explosion));
	ex->ennemy_ex[0] = create_texture(path1, mlx);
	ex->ennemy_ex[1] = create_texture(path2, mlx);
	ex->ennemy_ex[2] = create_texture(path3, mlx);
	return (ex);
}

t_explosion	*create_explosion(t_mlx *mlx, int direction)
{
	t_explosion	*ex;

	ex = NULL;
	if (direction == 0)
	{
		ex = create_ex_sprite(mlx, "xpm/expl/e_left_ex_1.xpm",
				"xpm/expl/e_left_ex_2.xpm", "xpm/expl/e_left_ex_3.xpm");
	}
	if (direction == 1)
	{
		ex = create_ex_sprite(mlx, "xpm/expl/e_right_ex_1.xpm",
				"xpm/expl/e_right_ex_2.xpm", "xpm/expl/e_right_ex_3.xpm");
	}
	if (direction == 2)
	{
		ex = create_ex_sprite(mlx, "xpm/expl/e_top_ex_1.xpm",
				"xpm/expl/e_top_ex_2.xpm", "xpm/expl/e_top_ex_3.xpm");
	}
	if (direction == 3)
	{
		ex = create_ex_sprite(mlx, "xpm/expl/e_bot_ex_1.xpm",
				"xpm/expl/e_bot_ex_2.xpm", "xpm/expl/e_bot_ex_3.xpm");
	}
	ex->frame_act = 0;
	return (ex);
}

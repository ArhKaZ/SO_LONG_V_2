/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_explosion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:52:38 by syluiset          #+#    #+#             */
/*   Updated: 2023/03/03 18:39:27 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

t_explosion	*create_ex_sprite(t_mlx *mlx)
{
	t_explosion	*ex;

	ex = NULL;
	ex = malloc(sizeof(t_explosion));
	if (!ex)
		return (NULL);
	ex->ennemy_ex[0] = create_texture("xpm/expl/e_top_ex_1.xpm", mlx);
	ex->ennemy_ex[1] = create_texture("xpm/expl/e_top_ex_2.xpm", mlx);
	ex->ennemy_ex[2] = create_texture("xpm/expl/e_top_ex_3.xpm", mlx);
	ex->frame_act_e = 0;
	ex->frame_act_p = 0;
	verif_explosion(ex);
	return (ex);
}

void	create_explosion(t_explosion *ex, t_mlx *mlx, int direction)
{
	if (direction == 0)
	{
		ex->ennemy_ex[0] = create_texture("xpm/expl/e_left_ex_1.xpm", mlx);
		ex->ennemy_ex[1] = create_texture("xpm/expl/e_left_ex_2.xpm", mlx);
		ex->ennemy_ex[2] = create_texture("xpm/expl/e_left_ex_3.xpm", mlx);
	}
	if (direction == 1)
	{
		ex->ennemy_ex[0] = create_texture("xpm/expl/e_right_ex_1.xpm", mlx);
		ex->ennemy_ex[1] = create_texture("xpm/expl/e_right_ex_2.xpm", mlx);
		ex->ennemy_ex[2] = create_texture("xpm/expl/e_right_ex_3.xpm", mlx);
	}
	if (direction == 2)
	{
		ex->ennemy_ex[0] = create_texture("xpm/expl/e_top_ex_1.xpm", mlx);
		ex->ennemy_ex[1] = create_texture("xpm/expl/e_top_ex_2.xpm", mlx);
		ex->ennemy_ex[2] = create_texture("xpm/expl/e_top_ex_3.xpm", mlx);
	}
	if (direction == 3)
	{
		ex->ennemy_ex[0] = create_texture("xpm/expl/e_bot_ex_1.xpm", mlx);
		ex->ennemy_ex[1] = create_texture("xpm/expl/e_bot_ex_2.xpm", mlx);
		ex->ennemy_ex[2] = create_texture("xpm/expl/e_bot_ex_3.xpm", mlx);
	}
	ex->frame_act_e = 0;
}

void	ex_for_dir(t_param *p, t_explosion *ex, t_mlx *mlx, int direction)
{
	free_texture(ex->ennemy_ex[0], mlx->mlx);
	free_texture(ex->ennemy_ex[1], mlx->mlx);
	free_texture(ex->ennemy_ex[2], mlx->mlx);
	create_explosion(ex, mlx, direction);
	verif_explosion(ex);
	if (!ex)
	{
		ft_putstr_fd("Error\nSprite for explosion", 2);
		close_win(p, mlx->mlx, mlx->mlx_win);
	}
}

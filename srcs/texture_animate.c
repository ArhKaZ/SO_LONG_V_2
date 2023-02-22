/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_animate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 17:37:20 by syluiset          #+#    #+#             */
/*   Updated: 2023/02/22 17:42:07 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

t_coins	*create_collectible(t_mlx *mlx)
{
	t_coins	*coins;

	coins = NULL;
	coins = malloc(sizeof(t_coins));
	coins->coins[0] = create_texture("texture_converted/coins/coins1.xpm", mlx);
	coins->coins[1]= create_texture("texture_converted/coins/coins2.xpm", mlx);
	coins->coins[2]= create_texture("texture_converted/coins/coins3.xpm", mlx);
	coins->coins[3]= create_texture("texture_converted/coins/coins4.xpm", mlx);
	coins->coins[4]= create_texture("texture_converted/coins/coins5.xpm", mlx);
	coins->coins[5]= create_texture("texture_converted/coins/coins6.xpm", mlx);
	coins->coins[6]= create_texture("texture_converted/coins/coins7.xpm", mlx);
	coins->coins[7]= create_texture("texture_converted/coins/coins8.xpm", mlx);
	coins->coins[8]= create_texture("texture_converted/coins/coins9.xpm", mlx);
	coins->coins[9] = create_texture("texture_converted/coins/coins10.xpm", mlx);
	coins->coins[10] = create_texture("texture_converted/coins/coins11.xpm", mlx);
	coins->coins[11] = create_texture("texture_converted/coins/coins12.xpm", mlx);
	coins->coins[12] = create_texture("texture_converted/coins/coins13.xpm", mlx);
	coins->coins[13] = create_texture("texture_converted/coins/coins14.xpm", mlx);
	coins->coins[14] = create_texture("texture_converted/coins/coins15.xpm", mlx);
	coins->frame_act = 0;
	return (coins);
}

t_black_hole	*create_black_hole(t_mlx *mlx)
{
	t_black_hole *bh;

	bh = NULL;
	bh = malloc(sizeof(t_black_hole));
	bh->bh[0] = create_texture("texture_converted/black_hole/black_hole_close1.xpm", mlx);
	bh->bh[1] = create_texture("texture_converted/black_hole/black_hole_close2.xpm", mlx);
	bh->bh[2] = create_texture("texture_converted/black_hole/black_hole_close3.xpm", mlx);
	bh->bh[3] = create_texture("texture_converted/black_hole/black_hole_close4.xpm", mlx);
	bh->bh[4] = create_texture("texture_converted/black_hole/black_hole_close5.xpm", mlx);
	bh->bh[5] = create_texture("texture_converted/black_hole/black_hole_close6.xpm", mlx);
	bh->bh[6] = create_texture("texture_converted/black_hole/black_hole_close7.xpm", mlx);
	bh->bh[7] = create_texture("texture_converted/black_hole/black_hole_close8.xpm", mlx);
	bh->bh[8] = create_texture("texture_converted/black_hole/black_hole_close9.xpm", mlx);
	bh->frame_act = 0;
	return (bh);
}

t_black_hole	*create_black_hole_for_end(t_mlx *mlx)
{
	t_black_hole *bh;

	bh = NULL;
	bh = malloc(sizeof(t_black_hole));
	bh->bh[0] = create_texture("texture_converted/black_hole/black_hole1.xpm", mlx);
	bh->bh[1] = create_texture("texture_converted/black_hole/black_hole2.xpm", mlx);
	bh->bh[2] = create_texture("texture_converted/black_hole/black_hole3.xpm", mlx);
	bh->bh[3] = create_texture("texture_converted/black_hole/black_hole4.xpm", mlx);
	bh->bh[4] = create_texture("texture_converted/black_hole/black_hole5.xpm", mlx);
	bh->bh[5] = create_texture("texture_converted/black_hole/black_hole6.xpm", mlx);
	bh->bh[6] = create_texture("texture_converted/black_hole/black_hole7.xpm", mlx);
	bh->bh[7] = create_texture("texture_converted/black_hole/black_hole8.xpm", mlx);
	bh->bh[8] = create_texture("texture_converted/black_hole/black_hole9.xpm", mlx);
	bh->frame_act = 0;
	return (bh);
}

t_explode	*create_explode(t_mlx *mlx, int direction)
{
	t_explode	*ex;

	ex = NULL;
	ex = malloc(sizeof(t_explode));
	if (direction == 0)
	{
		ex->boss_explosion1 = create_texture("texture_converted/explosion/boss_left_ex_1.xpm", mlx);
		ex->boss_explosion2 = create_texture("texture_converted/explosion/boss_left_ex_2.xpm", mlx);
		ex->boss_explosion3 = create_texture("texture_converted/explosion/boss_left_ex_3.xpm", mlx);
	}
	if (direction == 1)
	{
		ex->boss_explosion1 = create_texture("texture_converted/explosion/boss_right_ex_1.xpm", mlx);
		ex->boss_explosion2 = create_texture("texture_converted/explosion/boss_right_ex_2.xpm", mlx);
		ex->boss_explosion3 = create_texture("texture_converted/explosion/boss_right_ex_3.xpm", mlx);
	}
	if (direction == 2)
	{
		ex->boss_explosion1 = create_texture("texture_converted/explosion/boss_top_ex_1.xpm", mlx);
		ex->boss_explosion2 = create_texture("texture_converted/explosion/boss_top_ex_2.xpm", mlx);
		ex->boss_explosion3 = create_texture("texture_converted/explosion/boss_top_ex_3.xpm", mlx);
	}
	if (direction == 3)
	{
		ex->boss_explosion1 = create_texture("texture_converted/explosion/boss_bottom_ex_1.xpm", mlx);
		ex->boss_explosion2 = create_texture("texture_converted/explosion/boss_bottom_ex_2.xpm", mlx);
		ex->boss_explosion3 = create_texture("texture_converted/explosion/boss_bottom_ex_3.xpm", mlx);
	}
	ex->frame_act = 0;
	return (ex);
}

t_shoot_texture	*create_shoot_sprite(t_mlx *mlx)
{
	t_shoot_texture	*s;

	s = NULL;
	s = malloc(sizeof(t_shoot_texture));
	s->s_left[0] = create_texture("texture_converted/shoot/pulse1_left.xpm", mlx);
	s->s_top[0] = create_texture("texture_converted/shoot/pulse1_top.xpm", mlx);
	s->s_right[0] = create_texture("texture_converted/shoot/pulse1_right.xpm", mlx);
	s->s_bot[0] = create_texture("texture_converted/shoot/pulse1_bot.xpm", mlx);
	s->s_left[1] = create_texture("texture_converted/shoot/pulse2_left.xpm", mlx);
	s->s_top[1] = create_texture("texture_converted/shoot/pulse2_top.xpm", mlx);
	s->s_right[1] = create_texture("texture_converted/shoot/pulse2_right.xpm", mlx);
	s->s_bot[1] = create_texture("texture_converted/shoot/pulse2_bot.xpm", mlx);
	s->s_left[2] = create_texture("texture_converted/shoot/pulse3_left.xpm", mlx);
	s->s_top[2] = create_texture("texture_converted/shoot/pulse3_top.xpm", mlx);
	s->s_right[2] = create_texture("texture_converted/shoot/pulse3_right.xpm", mlx);
	s->s_bot[2] = create_texture("texture_converted/shoot/pulse3_bot.xpm", mlx);
	s->s_left[3] = create_texture("texture_converted/shoot/pulse4_left.xpm", mlx);
	s->s_top[3] = create_texture("texture_converted/shoot/pulse4_top.xpm", mlx);
	s->s_right[3] = create_texture("texture_converted/shoot/pulse4_right.xpm", mlx);
	s->s_bot[3] = create_texture("texture_converted/shoot/pulse4_bot.xpm", mlx);
	return (s);
}

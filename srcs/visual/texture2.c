/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 17:37:20 by syluiset          #+#    #+#             */
/*   Updated: 2023/03/03 18:01:33 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

t_sprite_back	*create_back(t_mlx *mlx)
{
	t_sprite_back	*back;

	back = malloc(sizeof(t_sprite_back));
	if (!back)
		return (NULL);
	back->back[0] = create_texture("xpm/back/Starfield_01.xpm", mlx);
	back->back[1] = create_texture("xpm/back/Starfield_02.xpm", mlx);
	if (!back->back[0] || !back->back[1])
	{
		if (back->back[0])
			free(back->back[0]);
		if (back->back[1])
			free(back->back[1]);
		free(back);
		back = NULL;
	}
	return (back);
}

t_coins	*create_collectible(t_mlx *mlx)
{
	t_coins	*coins;

	coins = malloc(sizeof(t_coins));
	if (!coins)
		return (NULL);
	coins->coins[0] = create_texture("xpm/coins/coins1.xpm", mlx);
	coins->coins[1] = create_texture("xpm/coins/coins2.xpm", mlx);
	coins->coins[2] = create_texture("xpm/coins/coins3.xpm", mlx);
	coins->coins[3] = create_texture("xpm/coins/coins4.xpm", mlx);
	coins->coins[4] = create_texture("xpm/coins/coins5.xpm", mlx);
	coins->coins[5] = create_texture("xpm/coins/coins6.xpm", mlx);
	coins->coins[6] = create_texture("xpm/coins/coins7.xpm", mlx);
	coins->coins[7] = create_texture("xpm/coins/coins8.xpm", mlx);
	coins->coins[8] = create_texture("xpm/coins/coins9.xpm", mlx);
	coins->coins[9] = create_texture("xpm/coins/coins10.xpm", mlx);
	coins->coins[10] = create_texture("xpm/coins/coins11.xpm", mlx);
	coins->coins[11] = create_texture("xpm/coins/coins12.xpm", mlx);
	coins->coins[12] = create_texture("xpm/coins/coins13.xpm", mlx);
	coins->coins[13] = create_texture("xpm/coins/coins14.xpm", mlx);
	coins->coins[14] = create_texture("xpm/coins/coins15.xpm", mlx);
	verif_collectible(coins);
	return (coins);
}

t_black_hole	*create_black_hole(t_mlx *mlx)
{
	t_black_hole	*bh;

	bh = malloc(sizeof(t_black_hole));
	if (!bh)
		return (NULL);
	bh->bh[0] = create_texture("xpm/black_hole/black_hole_close1.xpm", mlx);
	bh->bh[1] = create_texture("xpm/black_hole/black_hole_close2.xpm", mlx);
	bh->bh[2] = create_texture("xpm/black_hole/black_hole_close3.xpm", mlx);
	bh->bh[3] = create_texture("xpm/black_hole/black_hole_close4.xpm", mlx);
	bh->bh[4] = create_texture("xpm/black_hole/black_hole_close5.xpm", mlx);
	bh->bh[5] = create_texture("xpm/black_hole/black_hole_close6.xpm", mlx);
	bh->bh[6] = create_texture("xpm/black_hole/black_hole_close7.xpm", mlx);
	bh->bh[7] = create_texture("xpm/black_hole/black_hole_close8.xpm", mlx);
	bh->bh[8] = create_texture("xpm/black_hole/black_hole_close9.xpm", mlx);
	bh->frame_act = 0;
	verif_black_hole(bh);
	return (bh);
}

t_black_hole	*create_black_hole_for_end(t_mlx *mlx)
{
	t_black_hole	*bh;

	bh = NULL;
	bh = malloc(sizeof(t_black_hole));
	if (!bh)
		return (NULL);
	bh->bh[0] = create_texture("xpm/black_hole/black_hole1.xpm", mlx);
	bh->bh[1] = create_texture("xpm/black_hole/black_hole2.xpm", mlx);
	bh->bh[2] = create_texture("xpm/black_hole/black_hole3.xpm", mlx);
	bh->bh[3] = create_texture("xpm/black_hole/black_hole4.xpm", mlx);
	bh->bh[4] = create_texture("xpm/black_hole/black_hole5.xpm", mlx);
	bh->bh[5] = create_texture("xpm/black_hole/black_hole6.xpm", mlx);
	bh->bh[6] = create_texture("xpm/black_hole/black_hole7.xpm", mlx);
	bh->bh[7] = create_texture("xpm/black_hole/black_hole8.xpm", mlx);
	bh->bh[8] = create_texture("xpm/black_hole/black_hole9.xpm", mlx);
	bh->frame_act = 0;
	verif_black_hole(bh);
	return (bh);
}

t_shoot_texture	*create_shoot_sprite(t_mlx *mlx)
{
	t_shoot_texture	*s;

	s = malloc(sizeof(t_shoot_texture));
	if (!s)
		return (NULL);
	s->s_left[0] = create_texture("xpm/shoot/pulse1_left.xpm", mlx);
	s->s_top[0] = create_texture("xpm/shoot/pulse1_top.xpm", mlx);
	s->s_right[0] = create_texture("xpm/shoot/pulse1_right.xpm", mlx);
	s->s_bot[0] = create_texture("xpm/shoot/pulse1_bot.xpm", mlx);
	s->s_left[1] = create_texture("xpm/shoot/pulse2_left.xpm", mlx);
	s->s_top[1] = create_texture("xpm/shoot/pulse2_top.xpm", mlx);
	s->s_right[1] = create_texture("xpm/shoot/pulse2_right.xpm", mlx);
	s->s_bot[1] = create_texture("xpm/shoot/pulse2_bot.xpm", mlx);
	s->s_left[2] = create_texture("xpm/shoot/pulse3_left.xpm", mlx);
	s->s_top[2] = create_texture("xpm/shoot/pulse3_top.xpm", mlx);
	s->s_right[2] = create_texture("xpm/shoot/pulse3_right.xpm", mlx);
	s->s_bot[2] = create_texture("xpm/shoot/pulse3_bot.xpm", mlx);
	s->s_left[3] = create_texture("xpm/shoot/pulse4_left.xpm", mlx);
	s->s_top[3] = create_texture("xpm/shoot/pulse4_top.xpm", mlx);
	s->s_right[3] = create_texture("xpm/shoot/pulse4_right.xpm", mlx);
	s->s_bot[3] = create_texture("xpm/shoot/pulse4_bot.xpm", mlx);
	verif_shot(s);
	return (s);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:01:59 by syluiset          #+#    #+#             */
/*   Updated: 2023/02/21 15:47:53 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

t_texture	*create_texture(char *path, t_mlx *mlx)
{
	t_texture	*texture;

	texture = NULL;
	texture = malloc(sizeof(t_texture));
	texture->size = create_empty_gps();
	texture->p = mlx_xpm_file_to_image(mlx->mlx, path, &texture->size->x, &texture->size->y);
	return (texture);
}

t_coins	*create_collectible(t_mlx *mlx) //TODO:NORM
{
	t_coins	*coins;

	coins = NULL;
	coins = malloc(sizeof(t_coins));
	coins->frame1 = create_texture("texture_converted/coins/coins1.xpm", mlx);
	coins->frame2 = create_texture("texture_converted/coins/coins2.xpm", mlx);
	coins->frame3 = create_texture("texture_converted/coins/coins3.xpm", mlx);
	coins->frame4 = create_texture("texture_converted/coins/coins4.xpm", mlx);
	coins->frame5 = create_texture("texture_converted/coins/coins5.xpm", mlx);
	coins->frame6 = create_texture("texture_converted/coins/coins6.xpm", mlx);
	coins->frame7 = create_texture("texture_converted/coins/coins7.xpm", mlx);
	coins->frame8 = create_texture("texture_converted/coins/coins8.xpm", mlx);
	coins->frame9 = create_texture("texture_converted/coins/coins9.xpm", mlx);
	coins->frame10 = create_texture("texture_converted/coins/coins10.xpm", mlx);
	coins->frame11 = create_texture("texture_converted/coins/coins11.xpm", mlx);
	coins->frame12 = create_texture("texture_converted/coins/coins12.xpm", mlx);
	coins->frame13 = create_texture("texture_converted/coins/coins13.xpm", mlx);
	coins->frame14 = create_texture("texture_converted/coins/coins14.xpm", mlx);
	coins->frame15 = create_texture("texture_converted/coins/coins15.xpm", mlx);
	coins->frame_act = 0;
	return (coins);
}

t_sprite_player	*create_player_sprites(t_mlx *mlx)
{
	t_sprite_player *player;

	player = NULL;
	player = malloc(sizeof(t_sprite_player));
	player->player_bottom = create_texture("texture_converted/ship/ship_bot.xpm", mlx);
	player->player_left = create_texture("texture_converted/ship/ship_left.xpm", mlx);
	player->player_right = create_texture("texture_converted/ship/ship_right.xpm", mlx);
	player->player_top = create_texture("texture_converted/ship/ship_top.xpm", mlx);
	return (player);
}

t_black_hole	*create_black_hole(t_mlx *mlx)
{
	t_black_hole *bh;

	bh = NULL;
	bh = malloc(sizeof(t_black_hole));
	bh->frame1 = create_texture("texture_converted/black_hole/black_hole_close1.xpm", mlx);
	bh->frame2 = create_texture("texture_converted/black_hole/black_hole_close2.xpm", mlx);
	bh->frame3 = create_texture("texture_converted/black_hole/black_hole_close3.xpm", mlx);
	bh->frame4 = create_texture("texture_converted/black_hole/black_hole_close4.xpm", mlx);
	bh->frame5 = create_texture("texture_converted/black_hole/black_hole_close5.xpm", mlx);
	bh->frame6 = create_texture("texture_converted/black_hole/black_hole_close6.xpm", mlx);
	bh->frame7 = create_texture("texture_converted/black_hole/black_hole_close7.xpm", mlx);
	bh->frame8 = create_texture("texture_converted/black_hole/black_hole_close8.xpm", mlx);
	bh->frame9 = create_texture("texture_converted/black_hole/black_hole_close9.xpm", mlx);
	bh->frame_act = 0;
	return (bh);
}

t_black_hole	*create_black_hole_for_end(t_mlx *mlx)
{
	t_black_hole *bh;

	bh = NULL;
	bh = malloc(sizeof(t_black_hole));
	bh->frame1 = create_texture("texture_converted/black_hole/black_hole1.xpm", mlx);
	bh->frame2 = create_texture("texture_converted/black_hole/black_hole2.xpm", mlx);
	bh->frame3 = create_texture("texture_converted/black_hole/black_hole3.xpm", mlx);
	bh->frame4 = create_texture("texture_converted/black_hole/black_hole4.xpm", mlx);
	bh->frame5 = create_texture("texture_converted/black_hole/black_hole5.xpm", mlx);
	bh->frame6 = create_texture("texture_converted/black_hole/black_hole6.xpm", mlx);
	bh->frame7 = create_texture("texture_converted/black_hole/black_hole7.xpm", mlx);
	bh->frame8 = create_texture("texture_converted/black_hole/black_hole8.xpm", mlx);
	bh->frame9 = create_texture("texture_converted/black_hole/black_hole9.xpm", mlx);
	bh->frame_act = 0;
	return (bh);
}

t_sprite_boss	*create_sprite_boss(t_mlx *mlx)
{
	t_sprite_boss *boss;

	boss = NULL;
	boss = malloc(sizeof(t_sprite_boss));
	boss->boss_bottom = create_texture("texture_converted/boss/boss_bottom.xpm", mlx);
	boss->boss_left = create_texture("texture_converted/boss/boss_left.xpm", mlx);
	boss->boss_right = create_texture("texture_converted/boss/boss_right.xpm", mlx);
	boss->boss_top = create_texture("texture_converted/boss/boss_top.xpm", mlx);
	return (boss);
}

t_hp	*create_sprite_hp(t_mlx *mlx)
{
	t_hp *hp;

	hp = NULL;
	hp = malloc(sizeof(t_hp));
	hp->empty = create_texture("texture_converted/hp_empty.xpm", mlx);
	hp->full = create_texture("texture_converted/hp_full.xpm", mlx);
	return (hp);
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

t_sprite_planet	*create_planet_sprite(t_mlx *mlx)
{
	t_sprite_planet	*planets;

	planets = NULL;
	planets = malloc(sizeof(t_sprite_planet));
	planets->planet_1 = create_texture("texture_converted/planet/Planet1.xpm", mlx);
	planets->planet_2 = create_texture("texture_converted/planet/Planet2.xpm", mlx);
	planets->planet_3 = create_texture("texture_converted/planet/Planet3.xpm", mlx);
	planets->planet_4 = create_texture("texture_converted/planet/Planet4.xpm", mlx);
	planets->planet_exp = create_texture("texture_converted/planet/Planet_explode.xpm", mlx);
	return (planets);
}

t_shoot_texture	*create_shoot_sprite(t_mlx *mlx)
{
	t_shoot_texture	*s;

	s = NULL;
	s = malloc(sizeof(t_shoot_texture));
	s->frame1_left = create_texture("texture_converted/shoot/pulse1_left.xpm", mlx);
	s->frame1_top = create_texture("texture_converted/shoot/pulse1_top.xpm", mlx);
	s->frame1_right = create_texture("texture_converted/shoot/pulse1_right.xpm", mlx);
	s->frame1_bot = create_texture("texture_converted/shoot/pulse1_bot.xpm", mlx);
	s->frame2_left = create_texture("texture_converted/shoot/pulse2_left.xpm", mlx);
	s->frame2_top = create_texture("texture_converted/shoot/pulse2_top.xpm", mlx);
	s->frame2_right = create_texture("texture_converted/shoot/pulse2_right.xpm", mlx);
	s->frame2_bot = create_texture("texture_converted/shoot/pulse2_bot.xpm", mlx);
	s->frame3_left = create_texture("texture_converted/shoot/pulse3_left.xpm", mlx);
	s->frame3_top = create_texture("texture_converted/shoot/pulse3_top.xpm", mlx);
	s->frame3_right = create_texture("texture_converted/shoot/pulse3_right.xpm", mlx);
	s->frame3_bot = create_texture("texture_converted/shoot/pulse3_bot.xpm", mlx);
	s->frame4_left = create_texture("texture_converted/shoot/pulse4_left.xpm", mlx);
	s->frame4_top = create_texture("texture_converted/shoot/pulse4_top.xpm", mlx);
	s->frame4_right = create_texture("texture_converted/shoot/pulse4_right.xpm", mlx);
	s->frame4_bot = create_texture("texture_converted/shoot/pulse4_bot.xpm", mlx);
	return (s);
}

t_go	*create_game_over(t_mlx *mlx)
{
	t_go	*go;

	go = NULL;
	go = malloc(sizeof(t_go));
	go->little = create_texture("texture_converted/game_over/little_lose.xpm", mlx);
	go->medium = create_texture("texture_converted/game_over/med_lose.xpm", mlx);
	go->big = create_texture("texture_converted/game_over/big_lose.xpm", mlx);
	return (go);
}

t_end	*create_end(t_mlx *mlx)
{
	t_end	*end;

	end = NULL;
	end = malloc(sizeof(t_end));
	end->little = create_texture("texture_converted/finish/little_win.xpm", mlx);
	end->medium = create_texture("texture_converted/finish/med_win.xpm", mlx);
	end->big = create_texture("texture_converted/finish/big_win.xpm", mlx);
	return (end);
}

t_nb	*create_nb_little(t_mlx *mlx)
{
	t_nb	*nb;

	nb = NULL;
	nb = malloc(sizeof(t_nb));
	nb->zero = create_texture("texture_converted/nb/little_0.xpm", mlx);
	nb->one = create_texture("texture_converted/nb/little_1.xpm", mlx);
	nb->two = create_texture("texture_converted/nb/little_2.xpm", mlx);
	nb->three = create_texture("texture_converted/nb/little_3.xpm", mlx);
	nb->four = create_texture("texture_converted/nb/little_4.xpm", mlx);
	nb->five = create_texture("texture_converted/nb/little_5.xpm", mlx);
	nb->six = create_texture("texture_converted/nb/little_6.xpm", mlx);
	nb->seven = create_texture("texture_converted/nb/little_7.xpm", mlx);
	nb->eight = create_texture("texture_converted/nb/little_8.xpm", mlx);
	nb->nine = create_texture("texture_converted/nb/little_9.xpm", mlx);
	return (nb);
}

t_nb	*create_nb_medium(t_mlx *mlx)
{
	t_nb	*nb;

	nb = NULL;
	nb = malloc(sizeof(t_nb));
	nb->zero = create_texture("texture_converted/nb/med_0.xpm", mlx);
	nb->one = create_texture("texture_converted/nb/med_1.xpm", mlx);
	nb->two = create_texture("texture_converted/nb/med_2.xpm", mlx);
	nb->three = create_texture("texture_converted/nb/med_3.xpm", mlx);
	nb->four = create_texture("texture_converted/nb/med_4.xpm", mlx);
	nb->five = create_texture("texture_converted/nb/med_5.xpm", mlx);
	nb->six = create_texture("texture_converted/nb/med_6.xpm", mlx);
	nb->seven = create_texture("texture_converted/nb/med_7.xpm", mlx);
	nb->eight = create_texture("texture_converted/nb/med_8.xpm", mlx);
	nb->nine = create_texture("texture_converted/nb/med_9.xpm", mlx);
	return (nb);
}
t_nb	*create_nb_big(t_mlx *mlx)
{
	t_nb	*nb;

	nb = NULL;
	nb = malloc(sizeof(t_nb));
	nb->zero = create_texture("texture_converted/nb/big_0.xpm", mlx);
	nb->one = create_texture("texture_converted/nb/big_1.xpm", mlx);
	nb->two = create_texture("texture_converted/nb/big_2.xpm", mlx);
	nb->three = create_texture("texture_converted/nb/big_3.xpm", mlx);
	nb->four = create_texture("texture_converted/nb/big_4.xpm", mlx);
	nb->five = create_texture("texture_converted/nb/big_5.xpm", mlx);
	nb->six = create_texture("texture_converted/nb/big_6.xpm", mlx);
	nb->seven = create_texture("texture_converted/nb/big_7.xpm", mlx);
	nb->eight = create_texture("texture_converted/nb/big_8.xpm", mlx);
	nb->nine = create_texture("texture_converted/nb/big_9.xpm", mlx);
	return (nb);
}

t_nb	*create_nb(t_mlx *mlx, int width, int height)
{
	t_nb	*nb;

	nb = NULL;
	if (width < 8 || height < 8)
		nb= create_nb_little(mlx);
	else if (width < 14 || height < 14)
		nb = create_nb_medium(mlx);
	else if (width >= 14 || height >= 14)
		nb = create_nb_big(mlx);
	return (nb);
}

t_all_texture	*create_all_texture(t_mlx *mlx, int width, int height)
{
	t_all_texture	*all_texture;

	all_texture = NULL;
	all_texture = malloc(sizeof(t_all_texture));
	if (!all_texture)
		return (NULL);
	all_texture->background = create_texture("texture_converted/space_Stars6.xpm", mlx);
	all_texture->coin = create_collectible(mlx);
	all_texture->planets = create_planet_sprite(mlx);
	all_texture->player = create_player_sprites(mlx);
	all_texture->wall = create_texture("texture_converted/asteroid.xpm", mlx);
	all_texture->black_hole_close = create_black_hole(mlx);
	all_texture->black_hole = create_black_hole_for_end(mlx);
	all_texture->ennemy = create_sprite_boss(mlx);
	all_texture->hp = create_sprite_hp(mlx);
	all_texture->game_over = create_game_over(mlx);
	all_texture->shoot = create_shoot_sprite(mlx);
	all_texture->end = create_end(mlx);
	all_texture->nb = create_nb(mlx, width, height);
	return (all_texture);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:01:59 by syluiset          #+#    #+#             */
/*   Updated: 2023/02/14 15:02:32 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

// void	*put_line_in_pixel(void *img, char *line)
// {
// 	int i;

// 	i = 0;
// 	while (line[i])
// 	{
// 		if (line[i] != '_')
// 	}
// }

// void	*get_image(char *path, t_mlx *mlx, t_gps *size)
// {
// 	int fd;
// 	void	*img;
// 	bool	loop;
// 	char	*line;

// 	loop = false;
// 	fd = open(path, O_RDONLY);
// 	img = mlx_new_image(mlx->mlx, size->x, size->y);
// 	while (loop == false)
// 	{
// 		line = get_next_line(fd);
// 		if (line == NULL)
// 		{
// 			loop = true;
// 			break;
// 		}
// 		else
// 		{

// 		}
// 	}
// }

t_texture	*create_texture(char *path, t_mlx *mlx)
{
	void	*p;
	t_gps	*size;
	t_texture	*texture;

	size = create_empty_gps();
	p = mlx_xpm_file_to_image(mlx->mlx, path, &size->x, &size->y);
	texture = malloc(sizeof(t_texture));
	texture->p = p;
	texture->path = ft_strdup(path);
	texture->size = size;
	return (texture);
}

t_coins	*create_collectible(t_mlx *mlx) //TODO:NORM
{
	t_coins	*coins;

	coins = malloc(sizeof(t_coins));
	coins->frame1 = create_texture("texture_converted/collectable/Collectible1.xpm", mlx);
	coins->frame2 = create_texture("texture_converted/collectable/Collectible2.xpm", mlx);
	coins->frame3 = create_texture("texture_converted/collectable/Collectible3.xpm", mlx);
	coins->frame4 = create_texture("texture_converted/collectable/Collectible4.xpm", mlx);
	coins->frame5 = create_texture("texture_converted/collectable/Collectible5.xpm", mlx);
	coins->frame6 = create_texture("texture_converted/collectable/Collectible6.xpm", mlx);
	coins->frame7 = create_texture("texture_converted/collectable/Collectible7.xpm", mlx);
	coins->frame8 = create_texture("texture_converted/collectable/Collectible8.xpm", mlx);
	coins->frame9 = create_texture("texture_converted/collectable/Collectible9.xpm", mlx);
	coins->frame10 = create_texture("texture_converted/collectable/Collectible10.xpm", mlx);
	coins->frame11 = create_texture("texture_converted/collectable/Collectible11.xpm", mlx);
	coins->frame12 = create_texture("texture_converted/collectable/Collectible12.xpm", mlx);
	coins->frame13 = create_texture("texture_converted/collectable/Collectible13.xpm", mlx);
	coins->frame14 = create_texture("texture_converted/collectable/Collectible14.xpm", mlx);
	coins->frame15 = create_texture("texture_converted/collectable/Collectible15.xpm", mlx);
	coins->frame_act = 0;
	return (coins);
}

t_sprite_player	*create_player_sprites(t_mlx *mlx)
{
	t_sprite_player *player;

	player = malloc(sizeof(t_sprite_player));
	player->player_bottom = create_texture("texture_converted/Spaceship_bottom.xpm", mlx);
	player->player_left = create_texture("texture_converted/Spaceship_left.xpm", mlx);
	player->player_right = create_texture("texture_converted/Spaceship_right.xpm", mlx);
	player->player_top = create_texture("texture_converted/Spaceship_top.xpm", mlx);
	return (player);
}
//!bonus
t_black_hole	*create_black_hole(t_mlx *mlx)
{
	t_black_hole *bh;

	bh = malloc(sizeof(t_black_hole));
	bh->frame1 = create_texture("texture_converted/Black_hole/Black_hole1.xpm", mlx);
	bh->frame2 = create_texture("texture_converted/Black_hole/Black_hole2.xpm", mlx);
	bh->frame3 = create_texture("texture_converted/Black_hole/Black_hole3.xpm", mlx);
	bh->frame4 = create_texture("texture_converted/Black_hole/Black_hole4.xpm", mlx);
	bh->frame5 = create_texture("texture_converted/Black_hole/Black_hole5.xpm", mlx);
	bh->frame6 = create_texture("texture_converted/Black_hole/Black_hole6.xpm", mlx);
	bh->frame7 = create_texture("texture_converted/Black_hole/Black_hole7.xpm", mlx);
	bh->frame8 = create_texture("texture_converted/Black_hole/Black_hole8.xpm", mlx);
	bh->frame9 = create_texture("texture_converted/Black_hole/Black_hole9.xpm", mlx);
	bh->frame_act = 0;
	return (bh);
}

t_sprite_boss	*create_sprite_boss(t_mlx *mlx)
{
	t_sprite_boss *boss;

	boss = malloc(sizeof(t_sprite_boss));
	boss->boss_bottom = create_texture("texture_converted/Boss/Boss_bottom.xpm", mlx);
	boss->boss_left = create_texture("texture_converted/Boss/Boss_left.xpm", mlx);
	boss->boss_right = create_texture("texture_converted/Boss/Boss_right.xpm", mlx);
	boss->boss_top = create_texture("texture_converted/Boss/Boss_top.xpm", mlx);
	return (boss);
}

t_hp	*create_sprite_hp(t_mlx *mlx)
{
	t_hp *hp;

	hp = malloc(sizeof(t_hp));
	hp->empty = create_texture("texture_converted/hp_empty.xpm", mlx);
	hp->full = create_texture("texture_converted/hp_full.xpm", mlx);
	return (hp);
}

t_explode	*create_explode(t_mlx *mlx)
{
	t_explode	*ex;

	ex = malloc(sizeof(t_explode));
	ex->frame1 = create_texture("texture_converted/explosion/Explode0.xpm", mlx);
	ex->frame2 = create_texture("texture_converted/explosion/Explode1.xpm", mlx);
	ex->planet_explosion = create_texture("texture_converted/explosion/Explosion_planet.xpm", mlx);
	ex->boss_explosion1 = create_texture("texture_converted/explosion/Boss_explode1.xpm", mlx);
	ex->boss_explosion2 = create_texture("texture_converted/explosion/Boss_explode2.xpm", mlx);
	ex->boss_explosion3 = create_texture("texture_converted/explosion/Boss_explode3.xpm", mlx);
	return (ex);
}

t_sprite_planet	*create_planet_sprite(t_mlx *mlx)
{
	t_sprite_planet	*planets;

	planets = malloc(sizeof(t_sprite_planet));
	planets->planet_1 = create_texture("texture_converted/planet/Planet1.xpm", mlx);
	planets->planet_2 = create_texture("texture_converted/planet/Planet.xpm", mlx);
	planets->planet_3 = create_texture("texture_converted/planet/Planet3.xpm", mlx);
	planets->planet_4 = create_texture("texture_converted/planet/Planet4.xpm", mlx);
	planets->planet_exp = create_texture("texture_converted/planet/Planet_explode.xpm", mlx);
	return (planets);
}

//!bonus

t_shoot_texture	*create_shoot_sprite(t_mlx *mlx)
{
	t_shoot_texture	*s;

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

	go = malloc(sizeof(t_go));
	go->little = create_texture("texture_converted/game_over/little3.xpm", mlx);
	go->medium = NULL;
	go->big = create_texture("texture_converted/game_over/Big_game_over.xpm", mlx);
	return (go);
}

t_end	*create_end(t_mlx *mlx)
{
	t_end	*end;
	end = malloc(sizeof(t_end));
	end->little = create_texture("texture_converted/finish/Real_little.xpm", mlx);
	end->medium = NULL;
	end->big = NULL;
	return (end);
}

t_all_texture	*create_all_texture(t_mlx *mlx)
{
	t_all_texture	*all_texture;

	all_texture = malloc(sizeof(t_all_texture));
	if (!all_texture)
		return (NULL);
	all_texture->background = create_texture("texture_converted/Space_Stars6.xpm", mlx);
	all_texture->coin = create_collectible(mlx);
	all_texture->planets = create_planet_sprite(mlx);
	all_texture->player = create_player_sprites(mlx);
	all_texture->wall = create_texture("texture_converted/Asteroid.xpm", mlx);
	all_texture->black_hole = create_black_hole(mlx);
	all_texture->ennemy = create_sprite_boss(mlx);
	all_texture->hp = create_sprite_hp(mlx);
	all_texture->game_over = create_game_over(mlx);
	all_texture->explode = create_explode(mlx);
	all_texture->shoot = create_shoot_sprite(mlx);
	all_texture->end = create_end(mlx);
	return (all_texture);
}

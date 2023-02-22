/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:01:59 by syluiset          #+#    #+#             */
/*   Updated: 2023/02/22 17:52:34 by syluiset         ###   ########.fr       */
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

t_end	*create_end(t_mlx *mlx)
{
	t_end	*end;

	end = NULL;
	end = malloc(sizeof(t_end));
	end->w_little = create_texture("texture_converted/finish/little_win.xpm", mlx);
	end->w_med = create_texture("texture_converted/finish/med_win.xpm", mlx);
	end->w_big = create_texture("texture_converted/finish/big_win.xpm", mlx);
	end->l_little = create_texture("texture_converted/finish/little_lose.xpm", mlx);
	end->l_med = create_texture("texture_converted/finish/med_lose.xpm", mlx);
	end->l_big = create_texture("texture_converted/finish/big_lose.xpm", mlx);
	return (end);
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
	all_texture->shoot = create_shoot_sprite(mlx);
	all_texture->end = create_end(mlx);
	all_texture->nb = create_nb(mlx, width, height);
	return (all_texture);
}

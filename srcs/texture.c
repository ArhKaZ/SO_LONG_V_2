/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:01:59 by syluiset          #+#    #+#             */
/*   Updated: 2023/02/26 23:33:08 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

t_texture	*create_texture(char *path, t_mlx *mlx)
{
	t_texture	*texture;

	texture = NULL;
	texture = malloc(sizeof(t_texture));
	texture->size = create_gps(0, 0);
	texture->p = mlx_xpm_file_to_image(mlx->mlx, path,
			&texture->size->x, &texture->size->y);
	return (texture);
}

t_ship	*create_ships_sprite(t_mlx *mlx)
{
	t_ship	*ships;

	ships = NULL;
	ships = malloc(sizeof(t_ship));
	ships->player[0] = create_texture("xpm/ship/ship_left.xpm", mlx);
	ships->player[1] = create_texture("xpm/ship/ship_top.xpm", mlx);
	ships->player[2] = create_texture("xpm/ship/ship_right.xpm", mlx);
	ships->player[3] = create_texture("xpm/ship/ship_bot.xpm", mlx);
	ships->ennemy[0] = create_texture("xpm/boss/boss_left.xpm", mlx);
	ships->ennemy[1] = create_texture("xpm/boss/boss_top.xpm", mlx);
	ships->ennemy[2] = create_texture("xpm/boss/boss_right.xpm", mlx);
	ships->ennemy[3] = create_texture("xpm/boss/boss_bottom.xpm", mlx);
	return (ships);
}

t_sprite_planet	*create_planet_sprite(t_mlx *mlx)
{
	t_sprite_planet	*planets;

	planets = NULL;
	planets = malloc(sizeof(t_sprite_planet));
	planets->planet_1 = create_texture("xpm/planet/Planet1.xpm", mlx);
	planets->planet_2 = create_texture("xpm/planet/Planet2.xpm", mlx);
	planets->planet_3 = create_texture("xpm/planet/Planet3.xpm", mlx);
	planets->planet_4 = create_texture("xpm/planet/Planet4.xpm", mlx);
	planets->planet_exp = create_texture("xpm/planet/Planet_explode.xpm", mlx);
	return (planets);
}

t_end	*create_end(t_mlx *mlx)
{
	t_end	*end;

	end = NULL;
	end = malloc(sizeof(t_end));
	end->w_little = create_texture("xpm/finish/little_win.xpm", mlx);
	end->w_med = create_texture("xpm/finish/med_win.xpm", mlx);
	end->w_big = create_texture("xpm/finish/big_win.xpm", mlx);
	end->l_little = create_texture("xpm/finish/little_lose.xpm", mlx);
	end->l_med = create_texture("xpm/finish/med_lose.xpm", mlx);
	end->l_big = create_texture("xpm/finish/big_lose.xpm", mlx);
	return (end);
}

t_all_texture	*create_all_texture(t_mlx *mlx, int width, int height)
{
	t_all_texture	*all_texture;

	all_texture = NULL;
	all_texture = malloc(sizeof(t_all_texture));
	if (!all_texture)
		return (NULL);
	all_texture->background = create_texture("xpm/background.xpm", mlx);
	all_texture->coin = create_collectible(mlx);
	all_texture->planets = create_planet_sprite(mlx);
	all_texture->wall = create_texture("xpm/asteroid.xpm", mlx);
	all_texture->black_hole_close = create_black_hole(mlx);
	all_texture->black_hole = create_black_hole_for_end(mlx);
	all_texture->ships = create_ships_sprite(mlx);
	all_texture->shoot = create_shoot_sprite(mlx);
	all_texture->end = create_end(mlx);
	all_texture->nb = create_nb(mlx, width, height);
	all_texture->explosion = create_ex_sprite(mlx);
	return (all_texture);
}

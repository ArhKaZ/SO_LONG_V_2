/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:01:59 by syluiset          #+#    #+#             */
/*   Updated: 2023/03/02 16:27:17 by syluiset         ###   ########.fr       */
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
	if (!ships)
		//EXIT
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
	if (!planets)
		//EXIT
	planets->planets[0] = create_texture("xpm/planet/planet2.xpm", mlx);
	planets->planets[1] = create_texture("xpm/planet/planet2.xpm", mlx);
	planets->planets[2] = create_texture("xpm/planet/planet3.xpm", mlx);
	planets->planets[3] = create_texture("xpm/planet/planet4.xpm", mlx);
	planets->planet_exp = create_texture("xpm/planet/Planet_explode.xpm", mlx);
	return (planets);
}

t_end	*create_end(t_mlx *mlx)
{
	t_end	*end;

	end = NULL;
	end = malloc(sizeof(t_end));
	if (!end)
		//EXIT
	end->w_little = create_texture("xpm/finish/l_win.xpm", mlx);
	end->w_med = create_texture("xpm/finish/m_win.xpm", mlx);
	end->w_big = create_texture("xpm/finish/b_win.xpm", mlx);
	end->l_little = create_texture("xpm/finish/l_lose.xpm", mlx);
	end->l_med = create_texture("xpm/finish/m_lose.xpm", mlx);
	end->l_big = create_texture("xpm/finish/b_lose.xpm", mlx);
	//if (!(end->w_little || end->))
	return (end);
}

t_all_texture	*create_all_texture(t_mlx *mlx, int width, int height)
{
	t_all_texture	*all_texture;

	all_texture = NULL;
	all_texture = malloc(sizeof(t_all_texture));
	//if (!all_texture)
		//EXIT
	all_texture->back = create_back(mlx);
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

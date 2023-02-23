/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_textures_two.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 13:48:53 by syluiset          #+#    #+#             */
/*   Updated: 2023/02/23 13:49:37 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	free_planets(t_sprite_planet *p, void *mlx)
{
	free_texture(p->planet_1, mlx);
	free_texture(p->planet_2, mlx);
	free_texture(p->planet_3, mlx);
	free_texture(p->planet_4, mlx);
	free_texture(p->planet_exp, mlx);
	free(p);
	p = NULL;
}

void	free_end_and_go(t_end *end, void *mlx)
{
	free_texture(end->l_big, mlx);
	free_texture(end->l_little, mlx);
	free_texture(end->l_med, mlx);
	free_texture(end->w_big, mlx);
	free_texture(end->w_little, mlx);
	free_texture(end->w_med, mlx);
	free(end);
	end = NULL;
}

void	free_nb(t_nb *nb, void *mlx)
{
	free_texture(nb->zero, mlx);
	free_texture(nb->one, mlx);
	free_texture(nb->two, mlx);
	free_texture(nb->three, mlx);
	free_texture(nb->four, mlx);
	free_texture(nb->five, mlx);
	free_texture(nb->six, mlx);
	free_texture(nb->seven, mlx);
	free_texture(nb->eight, mlx);
	free_texture(nb->nine, mlx);
	free(nb);
	nb = NULL;
}

void	free_explode(t_explode *ex, void *mlx)
{
	free_texture(ex->boss_explosion1, mlx);
	free_texture(ex->boss_explosion2, mlx);
	free_texture(ex->boss_explosion3, mlx);
	free(ex);
	ex = NULL;
}

void	free_shoot(t_shoot_texture *s, void *mlx)
{
	free_texture(s->s_left[0], mlx);
	free_texture(s->s_top[0], mlx);
	free_texture(s->s_right[0], mlx);
	free_texture(s->s_bot[0], mlx);
	free_texture(s->s_left[1], mlx);
	free_texture(s->s_top[1], mlx);
	free_texture(s->s_right[1], mlx);
	free_texture(s->s_bot[1], mlx);
	free_texture(s->s_left[2], mlx);
	free_texture(s->s_top[2], mlx);
	free_texture(s->s_right[2], mlx);
	free_texture(s->s_bot[2], mlx);
	free_texture(s->s_left[3], mlx);
	free_texture(s->s_top[3], mlx);
	free_texture(s->s_right[3], mlx);
	free_texture(s->s_bot[3], mlx);
	free(s);
	s = NULL;
}
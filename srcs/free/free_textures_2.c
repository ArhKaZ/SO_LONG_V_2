/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_textures_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 13:48:53 by syluiset          #+#    #+#             */
/*   Updated: 2023/03/03 19:04:20 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	free_planets(t_sprite_planet *p, void *mlx)
{
	free_texture(p->planets[0], mlx);
	free_texture(p->planets[1], mlx);
	free_texture(p->planets[2], mlx);
	free_texture(p->planets[3], mlx);
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
	free_texture(nb->nb[0], mlx);
	free_texture(nb->nb[1], mlx);
	free_texture(nb->nb[2], mlx);
	free_texture(nb->nb[3], mlx);
	free_texture(nb->nb[4], mlx);
	free_texture(nb->nb[5], mlx);
	free_texture(nb->nb[6], mlx);
	free_texture(nb->nb[7], mlx);
	free_texture(nb->nb[8], mlx);
	free_texture(nb->nb[9], mlx);
	free(nb);
	nb = NULL;
}

void	free_explosion(t_explosion *ex, void *mlx)
{
	free_texture(ex->ennemy_ex[0], mlx);
	free_texture(ex->ennemy_ex[1], mlx);
	free_texture(ex->ennemy_ex[2], mlx);
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 18:02:53 by syluiset          #+#    #+#             */
/*   Updated: 2023/03/09 10:52:32 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	verif_planets(t_sprite_planet *pl)
{
	if (!pl->planet_exp || !pl->planets[0] || !pl->planets[1]
		|| !pl->planets[2] || !pl->planets[3])
	{
		if (pl->planet_exp)
			free(pl->planet_exp);
		if (pl->planet_exp)
			free(pl->planets[0]);
		if (pl->planet_exp)
			free(pl->planets[1]);
		if (pl->planet_exp)
			free(pl->planets[2]);
		if (pl->planet_exp)
			free(pl->planets[3]);
		free(pl);
		pl = NULL;
	}
}

void	verif_end(t_end *end)
{
	if (!end->w_big || !end->l_big || !end->l_little || !end->l_med
		|| !end->w_little || !end->w_med)
	{
		if (end->w_big)
			free(end->w_big);
		if (end->w_little)
			free(end->w_little);
		if (end->w_med)
			free(end->w_med);
		if (end->l_big)
			free(end->l_big);
		if (end->l_little)
			free(end->l_little);
		if (end->l_med)
			free(end->l_med);
		free(end);
		end = NULL;
	}
}

void	verif_ship(t_ship *ship)
{
	if (!ship->ennemy[0] || !ship->ennemy[1] || !ship->ennemy[2]
		|| !ship->ennemy[3] || !ship->player[0] || !ship->player[1]
		|| !ship->player[2] || !ship->player[3])
	{
		if (ship->ennemy[0])
			free(ship->ennemy[0]);
		if (ship->ennemy[1])
			free(ship->ennemy[1]);
		if (ship->ennemy[2])
			free(ship->ennemy[2]);
		if (ship->ennemy[3])
			free(ship->ennemy[3]);
		if (ship->player[0])
			free(ship->player[0]);
		if (ship->player[1])
			free(ship->player[1]);
		if (ship->player[2])
			free(ship->player[2]);
		if (ship->player[3])
			free(ship->player[3]);
		free(ship);
		ship = NULL;
	}
}

void	free_textures_error(t_all_text *texts)
{
	free(texts->back);
	if (texts->coin != NULL)
		free(texts->coin);
	if (texts->planets != NULL)
		free(texts->planets);
	if (texts->wall != NULL)
		free(texts->wall);
	if (texts->black_hole_close != NULL)
		free(texts->black_hole_close);
	if (texts->black_hole != NULL)
		free(texts->black_hole);
	if (texts->ships != NULL)
		free(texts->ships);
	if (texts->shoot != NULL)
		free(texts->shoot);
	if (texts->end != NULL)
		free(texts->end);
	if (texts->nb != NULL)
		free(texts->nb);
	if (texts->explosion != NULL)
		free(texts->explosion);
}

bool	verif_texture(t_all_text *texts)
{
	if (texts->back == NULL)
		return (false);
	if (texts->coin == NULL || texts->planets == NULL || texts->wall == NULL
		|| texts->black_hole_close == NULL || texts->black_hole == NULL
		|| texts->ships == NULL || texts->shoot == NULL || texts->end == NULL
		|| texts->nb == NULL || texts->explosion == NULL)
	{
		free_textures_error(texts);
		return (false);
	}
	return (true);
}

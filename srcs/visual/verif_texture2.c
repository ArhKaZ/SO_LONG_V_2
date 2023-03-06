/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_texture2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:06:55 by syluiset          #+#    #+#             */
/*   Updated: 2023/03/06 15:08:02 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	verif_collectible(t_coins *c)
{
	int	i;

	i = 0;
	while (i <= 14)
	{
		if (!c->coins[i])
			break ;
		i++;
	}
	if (i != 15)
	{
		i = 0;
		while (i <= 14)
		{
			if (c->coins[i])
				free(c->coins[i]);
			i++;
		}
		free(c);
		c = NULL;
	}
}

void	verif_black_hole(t_black_hole *bh)
{
	int	i;

	i = 0;
	while (i <= 8)
	{
		if (!bh->bh[i])
			break ;
		i++;
	}
	if (i != 9)
	{
		i = 0;
		while (i <= 8)
		{
			if (bh->bh[i])
				free(bh->bh[i]);
			i++;
		}
		free(bh);
		bh = NULL;
	}
}

void	verif_nb(t_nb *nb)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		if (!nb->nb[i])
			break ;
		i++;
	}
	if (i != 10)
	{
		i = 0;
		while (i < 10)
		{
			if (nb->nb[i])
				free(nb->nb[i]);
			i++;
		}
		free(nb);
		nb = NULL;
	}
}

void	verif_explosion(t_explosion *ex)
{
	if (!ex->ennemy_ex[0] || !ex->ennemy_ex[1] || !ex->ennemy_ex[2])
	{
		if (ex->ennemy_ex[0])
			free(ex->ennemy_ex[0]);
		if (ex->ennemy_ex[1])
			free(ex->ennemy_ex[1]);
		if (ex->ennemy_ex[2])
			free(ex->ennemy_ex[2]);
		free(ex);
		ex = NULL;
	}
}

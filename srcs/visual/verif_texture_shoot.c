/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_texture_shoot.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:50:54 by syluiset          #+#    #+#             */
/*   Updated: 2023/03/03 19:47:44 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

bool	verif_s_left(t_texture *s[4])
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (!s[i])
			break;
		i++;
	}
	if (i != 4)
	{
		i = 0;
		while (i < 4)
		{
			if (s[i])
				free(s[i]);
			i++;
		}
		return (false);
	}
	return (true);
}

bool	verif_s_top(t_texture *s[4])
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (!s[i])
			break;
		i++;
	}
	if (i != 4)
	{
		i = 0;
		while (i < 4)
		{
			if (s[i])
				free(s[i]);
			i++;
		}
		return (false);
	}
	return (true);
}

bool	verif_s_right(t_texture *s[4])
{
	int i;

	i = 0;
	while (i <= 4)
	{
		if (!s[i])
			break;
		i++;
	}
	if (i != 4)
	{
		i = 0;
		while (i < 4)
		{
			if (s[i])
				free(s[i]);
			i++;
		}
		return (false);
	}
	return (true);
}

bool	verif_s_bot(t_texture *s[4])
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (!s[i])
			break;
		i++;
	}
	if (i != 4)
	{
		i = 0;
		while (i < 4)
		{
			if (s[i])
				free(s[i]);
			i++;
		}
		return (false);
	}
	return (true);
}

void	verif_shot(t_shoot_texture *s)
{
	if (verif_s_left(s->s_left) == false || verif_s_top(s->s_top) == false
		|| verif_s_right(s->s_right) || verif_s_right(s->s_bot) == false)
	{
		verif_s_left(s->s_left);
		verif_s_top(s->s_top);
		verif_s_right(s->s_right);
		verif_s_bot(s->s_bot);
		free(s);
		s = NULL;
	}
}
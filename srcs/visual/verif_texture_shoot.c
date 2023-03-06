/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_texture_shoot.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:50:54 by syluiset          #+#    #+#             */
/*   Updated: 2023/03/06 15:08:13 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

bool	verif_s(t_texture *s[4])
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (!s[i])
			break ;
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

void	free_shot_texture_spe_case(t_texture *s[4])
{
	int	i;

	i = 0;
	while (i < 4)
	{
		free(s[i]);
		i++;
	}
}

void	verif_shot(t_shoot_texture *s)
{
	if (!verif_s(s->s_left) || !verif_s(s->s_top) || !verif_s(s->s_right)
		|| !verif_s(s->s_bot))
	{
		free_shot_texture_spe_case(s->s_left);
		free_shot_texture_spe_case(s->s_top);
		free_shot_texture_spe_case(s->s_right);
		free_shot_texture_spe_case(s->s_bot);
		free(s);
		s = NULL;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sprite_rand.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 14:35:28 by syluiset          #+#    #+#             */
/*   Updated: 2023/03/01 18:11:28 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	*get_sprite_back(t_sprite_back *texts)
{
	void	*sprite;

	random = get_random(8);
	return (texts->back[random]);
}

void	*get_sprite_obstacle(t_sprite_planet *texts)
{
	void	*sprite;
	int		random;

	sprite = NULL;
	random = get_random(4);
	if (random == 0)
		sprite = texts->planet_1->p;
	if (random == 1)
		sprite = texts->planet_2->p;
	if (random == 2)
		sprite = texts->planet_3->p;
	if (random == 3)
		sprite = texts->planet_4->p;
	return (sprite);
}

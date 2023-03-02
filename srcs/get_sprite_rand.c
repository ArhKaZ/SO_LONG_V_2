/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sprite_rand.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 14:35:28 by syluiset          #+#    #+#             */
/*   Updated: 2023/03/02 13:42:25 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

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

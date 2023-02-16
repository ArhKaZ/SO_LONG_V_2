/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:07:49 by syluiset          #+#    #+#             */
/*   Updated: 2023/02/16 17:57:04 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

t_player	*create_empty_player(void)
{
	t_player *player;

	player = malloc(sizeof(t_player));
	player->collect = 0;
	player->coor = create_empty_gps();
	player->moves = 0;
	player->hp = 1;
	player->direction = 2;
	player->score = 0;
	return (player);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:07:49 by syluiset          #+#    #+#             */
/*   Updated: 2023/02/21 17:13:17 by syluiset         ###   ########.fr       */
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
	player->hp = 3;
	player->direction = 2;
	player->score = 0;
	return (player);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_damage.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:04:18 by syluiset          #+#    #+#             */
/*   Updated: 2023/02/23 15:05:22 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	less_hp(t_param *param, int direction)
{
	param->player->hp -= 1;
	if (param->player->hp == 0)
		param->finish = 1;
	not_move_ennemy_sprite(param, direction);
}

//texture dmg on player
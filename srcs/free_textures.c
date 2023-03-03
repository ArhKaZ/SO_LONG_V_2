/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 13:39:18 by syluiset          #+#    #+#             */
/*   Updated: 2023/03/03 15:35:54 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	free_coin(t_coins *text, void *mlx)
{
	free_texture(text->coins[0], mlx);
	free_texture(text->coins[1], mlx);
	free_texture(text->coins[2], mlx);
	free_texture(text->coins[3], mlx);
	free_texture(text->coins[4], mlx);
	free_texture(text->coins[5], mlx);
	free_texture(text->coins[6], mlx);
	free_texture(text->coins[7], mlx);
	free_texture(text->coins[8], mlx);
	free_texture(text->coins[9], mlx);
	free_texture(text->coins[10], mlx);
	free_texture(text->coins[11], mlx);
	free_texture(text->coins[12], mlx);
	free_texture(text->coins[13], mlx);
	free_texture(text->coins[14], mlx);
	free(text);
	text = NULL;
}

void	free_ships_sprite(t_ship *ships, void *mlx)
{
	free_texture(ships->ennemy[0], mlx);
	free_texture(ships->ennemy[1], mlx);
	free_texture(ships->ennemy[2], mlx);
	free_texture(ships->ennemy[3], mlx);
	free_texture(ships->player[0], mlx);
	free_texture(ships->player[1], mlx);
	free_texture(ships->player[2], mlx);
	free_texture(ships->player[3], mlx);
	free(ships);
	ships = NULL;
}

void	free_black_hole(t_black_hole *bh, void *mlx)
{
	free_texture(bh->bh[0], mlx);
	free_texture(bh->bh[1], mlx);
	free_texture(bh->bh[2], mlx);
	free_texture(bh->bh[3], mlx);
	free_texture(bh->bh[4], mlx);
	free_texture(bh->bh[5], mlx);
	free_texture(bh->bh[6], mlx);
	free_texture(bh->bh[7], mlx);
	free_texture(bh->bh[8], mlx);
	free(bh);
	bh = NULL;
}

void	free_hp(t_hp *hp, void *mlx)
{
	free_texture(hp->empty, mlx);
	free_texture(hp->full, mlx);
	free(hp);
	hp = NULL;
}

void	free_back(t_sprite_back *back, void *mlx)
{
	free_texture(back->back[0], mlx);
	free_texture(back->back[1], mlx);
	free(back);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 13:39:18 by syluiset          #+#    #+#             */
/*   Updated: 2023/02/24 03:52:38 by syluiset         ###   ########.fr       */
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

void	free_textures(t_all_texture *texts, void *mlx)
{
	ft_printf("%p", texts->background);
	free_texture(texts->background, mlx);
	ft_printf("%p", texts->coin);
	free_coin(texts->coin, mlx);
	ft_printf("%p", texts->planets);
	free_planets(texts->planets, mlx);
	ft_printf("%p", texts->wall);
	free_texture(texts->wall, mlx);
	ft_printf("%p", texts->ships);
	free_ships_sprite(texts->ships, mlx);
	ft_printf("%p", texts->black_hole);
	free_black_hole(texts->black_hole, mlx);
	free_black_hole(texts->black_hole_close, mlx);
	free_end_and_go(texts->end, mlx);
	free_shoot(texts->shoot, mlx);
	free_nb(texts->nb, mlx);
	free(texts);
	texts = NULL;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 17:14:04 by syluiset          #+#    #+#             */
/*   Updated: 2023/02/22 18:00:16 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	put_score(t_param *p)
{
	char	*nb_collect;
	t_gps	*place;

	place = create_empty_gps();
	place->x = 0;
	place->y = p->map->height - 1;
	nb_collect = ft_itoa(p->player->score);
	put_image(p->mlx, p->textures->wall->p, place);
	place->x = 1;
	put_image(p->mlx, p->textures->wall->p, place);
	mlx_string_put(p->mlx->mlx, p->mlx->mlx_win, 10, p->map->height * 64 - 3,
	0xFFFFFF, "Score:");
	mlx_string_put(p->mlx->mlx, p->mlx->mlx_win, 62, p->map->height * 64 - 3,
	0xFFFFFF, nb_collect);
	free(nb_collect);
	free(place);
}

void	put_move(t_param *p)
{
	char	*nb_moves;
	t_gps	*place;

	place = create_empty_gps();
	place->x = 2;
	place->y = p->map->height - 1;
	nb_moves = ft_itoa(p->player->moves);
	put_image(p->mlx, p->textures->wall->p, place);
	place->x = 3;
	put_image(p->mlx, p->textures->wall->p, place);
	mlx_string_put(p->mlx->mlx, p->mlx->mlx_win, 2 * 64,
	p->map->height * 64 - 3, 0xFFFFFF, "Moves:");
	mlx_string_put(p->mlx->mlx, p->mlx->mlx_win, 2 * 64 + 48,
	p->map->height * 64 - 3, 0xFFFFFF, nb_moves);
	free(nb_moves);
	free(place);
}

void	put_sprite_hp(t_param *p, t_texture *s1, t_texture *s2, t_texture *s3)
{
	t_gps		*place;

	place = create_empty_gps();
	place->x = (4 * 64 + 35) / 64;
	place->y = (p->map->height * 64 - 16) / 64;
	put_image(p->mlx, s1->p, place);
	place->x = (4 * 64 + 55) / 64;
	put_image(p->mlx, s2->p, place);
	place->x = (5 * 64 + 11) / 64;
	put_image(p->mlx, s3->p, place);
	free(place);
}

void	put_hp(t_param *p, t_hp *hp)
{
	t_gps	*place;

	place = create_empty_gps();
	place->y = p->map->height - 1;
	place->x = 4;
	put_image(p->mlx, p->textures->wall->p, place);
	place->x = 5;
	put_image(p->mlx, p->textures->wall->p, place);
	mlx_string_put(p->mlx->mlx, p->mlx->mlx_win, 4 * 64,
		p->map->height * 64 - 3, 0xFFFFFF, "HP :"); //! maybe change
	if (p->player->hp == 3)
		put_sprite_hp(p, hp->full, hp->full, hp->full);
	if (p->player->hp == 2)
		put_sprite_hp(p, hp->full, hp->full, hp->empty);
	if (p->player->hp == 1)
		put_sprite_hp(p, hp->full, hp->empty, hp->empty);
	if (p->player->hp == 0)
		put_sprite_hp(p, hp->empty, hp->empty, hp->empty);

}

void	put_strings(t_param *param)
{
	t_hp *hp;

	hp = NULL;
	hp = malloc(sizeof(t_hp));
	hp->empty = create_texture("texture_converted/hp_empty.xpm", param->mlx);
	hp->full = create_texture("texture_converted/hp_full.xpm", param->mlx);
	put_score(param);
	put_move(param);
	put_hp(param, hp);
	free(hp);
}

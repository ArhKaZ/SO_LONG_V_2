/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:29:58 by syluiset          #+#    #+#             */
/*   Updated: 2023/02/22 17:46:57 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	free_char_map(char **map)
{
	int i;

	i = 0;
	if (map != NULL)
	{
		while (map[i] != NULL)
		{
			free(map[i]);
			i++;
		}
		free(map[i]);
		free(map);
		map = NULL;
	}
}

void	free_map(t_map *map)
{
	free_char_map(map->map);
	free(map->coor_exit);
	map->coor_exit = NULL;
	free(map);
	map = NULL;
}

void	free_ennemy(t_ennemy *boss)
{
	t_ennemy	*temp;
	t_ennemy	*tempnxt;

	if (!boss)
		return ;
	tempnxt = boss;
	while (tempnxt != NULL)
	{
		temp = tempnxt;
		tempnxt = temp->next;
		free(temp->coor);
		free(temp);
	}
	boss = NULL;
}


void	free_player(t_player *player)
{
	free(player->coor);
	player->coor = NULL;
	free(player);
	player = NULL;
}

void	free_texture(t_texture *text, void *mlx)
{
	mlx_destroy_image(mlx, text->p);
	text->p = NULL;
	free(text->size);
	text->size = NULL;
	free(text);
	text = NULL;
}

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

void	free_player_s(t_sprite_player *p, void *mlx)
{
	free_texture(p->player_bottom, mlx);
	free_texture(p->player_top, mlx);
	free_texture(p->player_right, mlx);
	free_texture(p->player_left, mlx);
	free(p);
	p = NULL;
}

void	free_ennemy_s(t_sprite_boss *b, void *mlx)
{
	free_texture(b->boss_bottom, mlx);
	free_texture(b->boss_top, mlx);
	free_texture(b->boss_right, mlx);
	free_texture(b->boss_left, mlx);
	free(b);
	b = NULL;
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

void	free_planets(t_sprite_planet *p, void *mlx)
{
	free_texture(p->planet_1, mlx);
	free_texture(p->planet_2, mlx);
	free_texture(p->planet_3, mlx);
	free_texture(p->planet_4, mlx);
	free_texture(p->planet_exp, mlx);
	free(p);
	p = NULL;
}

void	free_end_and_go(t_end *end, void *mlx)
{
	free_texture(end->l_big, mlx);
	free_texture(end->l_little, mlx);
	free_texture(end->l_med, mlx);
	free_texture(end->w_big, mlx);
	free_texture(end->w_little, mlx);
	free_texture(end->w_med, mlx);
	free(end);
	end = NULL;
}

void	free_nb(t_nb *nb, void *mlx)
{
	free_texture(nb->zero, mlx);
	free_texture(nb->one, mlx);
	free_texture(nb->two, mlx);
	free_texture(nb->three, mlx);
	free_texture(nb->four, mlx);
	free_texture(nb->five, mlx);
	free_texture(nb->six, mlx);
	free_texture(nb->seven, mlx);
	free_texture(nb->eight, mlx);
	free_texture(nb->nine, mlx);
	free(nb);
	nb = NULL;
}

void	free_explode(t_explode *ex, void *mlx)
{
	free_texture(ex->boss_explosion1, mlx);
	free_texture(ex->boss_explosion2, mlx);
	free_texture(ex->boss_explosion3, mlx);
	free(ex);
	ex = NULL;
}

void	free_shoot(t_shoot_texture *s, void *mlx)
{
	free_texture(s->s_left[0], mlx);
	free_texture(s->s_top[0], mlx);
	free_texture(s->s_right[0], mlx);
	free_texture(s->s_bot[0], mlx);
	free_texture(s->s_left[1], mlx);
	free_texture(s->s_top[1], mlx);
	free_texture(s->s_right[1], mlx);
	free_texture(s->s_bot[1], mlx);
	free_texture(s->s_left[2], mlx);
	free_texture(s->s_top[2], mlx);
	free_texture(s->s_right[2], mlx);
	free_texture(s->s_bot[2], mlx);
	free_texture(s->s_left[3], mlx);
	free_texture(s->s_top[3], mlx);
	free_texture(s->s_right[3], mlx);
	free_texture(s->s_bot[3], mlx);
	free(s);
	s = NULL;
}

void	free_textures(t_all_texture *texts, void *mlx)
{
	free_texture(texts->background, mlx);
	free_coin(texts->coin, mlx);
	free_planets(texts->planets, mlx);
	free_player_s(texts->player, mlx);
	free_texture(texts->wall, mlx);
	free_ennemy_s(texts->ennemy, mlx);
	free_black_hole(texts->black_hole, mlx);
	free_black_hole(texts->black_hole_close, mlx);
	free_hp(texts->hp, mlx);
	free_end_and_go(texts->end, mlx);
	free_shoot(texts->shoot, mlx);
	free_nb(texts->nb, mlx);
	free(texts);
	texts = NULL;
}

void	free_all(t_param *param)
{
	free_map(param->map);
	free_player(param->player);
	free_textures(param->textures, param->mlx->mlx);
	free_ennemy(param->boss);
	free(param->mlx);
	param->mlx = NULL;
	free(param);
	param = NULL;
}

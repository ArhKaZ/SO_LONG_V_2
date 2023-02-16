/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:29:58 by syluiset          #+#    #+#             */
/*   Updated: 2023/02/16 17:40:21 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	free_map(t_map *map)
{
	int i;

	i = 0;
	if (map->map != NULL)
	{
		while (map->map[i] != NULL)
		{
			free(map->map[i]);
			i++;
		}
	}
	free(map->map);
	free(map->coor_exit);
	free(map);
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

void	free_char_map(char **map)
{
	int i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map[i]);
	free(map);
}

void	free_player(t_player *player)
{
	free(player->coor);
	free(player);
}

void	free_texture(t_texture *text, void *mlx)
{
	if (text != NULL)
	{
		free(text->path);
		mlx_destroy_image(mlx, text->p);
		//?free(text->size); JE NE COMPRENDS PAS
		free(text);
	}
}

void	free_coin(t_coins *text, void *mlx)
{
	free_texture(text->frame1, mlx);	
	free_texture(text->frame2, mlx);	
	free_texture(text->frame3, mlx);	
	free_texture(text->frame4, mlx);	
	free_texture(text->frame5, mlx);	
	free_texture(text->frame6, mlx);	
	free_texture(text->frame7, mlx);	
	free_texture(text->frame8, mlx);	
	free_texture(text->frame9, mlx);	
	free_texture(text->frame10, mlx);	
	free_texture(text->frame11, mlx);	
	free_texture(text->frame12, mlx);	
	free_texture(text->frame13, mlx);	
	free_texture(text->frame14, mlx);	
	free_texture(text->frame15, mlx);	
	free(text);
}

void	free_player_s(t_sprite_player *p, void *mlx)
{
	free_texture(p->player_bottom, mlx);
	free_texture(p->player_top, mlx);
	free_texture(p->player_right, mlx);
	free_texture(p->player_left, mlx);
	free(p);
}

void	free_ennemy_s(t_sprite_boss *b, void *mlx)
{
	free_texture(b->boss_bottom, mlx);
	free_texture(b->boss_top, mlx);
	free_texture(b->boss_right, mlx);
	free_texture(b->boss_left, mlx);
	free(b);
}

void	free_black_hole(t_black_hole *bh, void *mlx)
{
	free_texture(bh->frame1, mlx);
	free_texture(bh->frame2, mlx);
	free_texture(bh->frame3, mlx);
	free_texture(bh->frame4, mlx);
	free_texture(bh->frame5, mlx);
	free_texture(bh->frame6, mlx);
	free_texture(bh->frame7, mlx);
	free_texture(bh->frame8, mlx);
	free_texture(bh->frame9, mlx);
	free(bh);
}


void	free_hp(t_hp *hp, void *mlx)
{
	free_texture(hp->empty, mlx);
	free_texture(hp->full, mlx);
	free(hp);	
}

void	free_planets(t_sprite_planet *p, void *mlx)
{
	free_texture(p->planet_1, mlx);	
	free_texture(p->planet_2, mlx);	
	free_texture(p->planet_3, mlx);	
	free_texture(p->planet_4, mlx);	
	free_texture(p->planet_exp, mlx);	
	free(p);
}

void	free_end_and_go(t_end *end, t_go *go, void *mlx)
{
	free_texture(go->little, mlx);	
	free_texture(go->medium, mlx);	
	free_texture(go->big, mlx);	
	free_texture(end->big, mlx);
	free_texture(end->medium, mlx);
	free_texture(end->little, mlx);
	free(go);
	free(end);
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
}

void	free_all_nb(t_all_nb *nb, void *mlx)
{
	if (nb->big != NULL)
		free_nb(nb->big, mlx);
	else if (nb->medium != NULL)
		free_nb(nb->medium, mlx);
	else if (nb->little != NULL)
		free_nb(nb->little, mlx);
	free(nb);
}

void	free_explode(t_explode *ex, void *mlx)
{
	free_texture(ex->frame1, mlx);
	free_texture(ex->frame2, mlx);
	free_texture(ex->planet_explosion, mlx);
	free_texture(ex->boss_explosion1, mlx);
	free_texture(ex->boss_explosion2, mlx);
	free_texture(ex->boss_explosion3, mlx);
	free(ex);
}

void	free_shoot(t_shoot_texture *s, void *mlx)
{
	free_texture(s->frame1_left, mlx);
	free_texture(s->frame1_top, mlx);
	free_texture(s->frame1_right, mlx);
	free_texture(s->frame1_bot, mlx);
	free_texture(s->frame2_left, mlx);
	free_texture(s->frame2_top, mlx);
	free_texture(s->frame2_right, mlx);
	free_texture(s->frame2_bot, mlx);
	free_texture(s->frame3_left, mlx);
	free_texture(s->frame3_top, mlx);
	free_texture(s->frame3_right, mlx);
	free_texture(s->frame3_bot, mlx);
	free_texture(s->frame4_left, mlx);
	free_texture(s->frame4_top, mlx);
	free_texture(s->frame4_right, mlx);
	free_texture(s->frame4_bot, mlx);
	free(s);
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
	free_hp(texts->hp, mlx);
	free_end_and_go(texts->end, texts->game_over, mlx);
	free_explode(texts->explode, mlx);
	free_shoot(texts->shoot, mlx);
	free_all_nb(texts->nb, mlx);
	free(texts);
}

void	free_all(t_param *param)
{
	free_map(param->map);
	free_player(param->player);
	free_textures(param->textures, param->mlx->mlx);
	free_ennemy(param->boss);
	free(param->mlx);
	free(param);
}
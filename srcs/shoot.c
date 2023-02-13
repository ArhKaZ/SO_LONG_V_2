/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shoot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 17:10:42 by syluiset          #+#    #+#             */
/*   Updated: 2023/02/13 16:20:11 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

// t_shoot	*lst_s_last(t_shoot *lst)
// {
// 	if (!lst)
// 		return (NULL);
// 	while (lst->next != NULL)
// 		lst = lst->next;
// 	return (lst);
// }

// void	shoot_add_back(t_shoot **shoot, t_shoot *new)
// {
// 	t_shoot	*temp;

// 	if (!shoot || !new)
// 		return ;
// 	if (*shoot != NULL)
// 	{
// 		temp = lst_s_last(*shoot);
// 		temp->next = new;
// 	}
// 	else
// 		*shoot = new;
// }

// void	del_shot(t_shoot *shoot)
// {
// 	t_shoot	*next;

// 	next = shoot->next;
// 	free(shoot->coor);
// 	free(shoot);
// 	if (next != NULL)
// 		shoot = next;
// 	return ;
// }

t_shoot	*create_shot(clock_t time, int direction)
{
	t_shoot	*shot;

	shot = malloc(sizeof(t_shoot));
	shot->coor = create_empty_gps();
	shot->direction = direction;
	shot->shoot_time = time;
	return (shot);
}

t_gps	*get_next_coor_s(int direction, t_gps *coor)
{
	t_gps	*new;

	new = create_empty_gps();
	if (direction == 1)
	{
		new->x = coor->x - 1;
		new->y = coor->y;
	}
	if (direction == 2)
	{
		new->x = coor->x;
		new->y = coor->y - 1;
	}
	if (direction == 3)
	{
		new->x = coor->x + 1;
		new->y = coor->y;
	}
	if (direction == 4)
	{
		new->x = coor->x;
		new->y = coor->y + 1;
	}
	return (new);
}

void	kill_boss(t_param *param, t_gps *new)
{
	put_image(param->mlx, param->textures->background->p, param->shots->coor, 0);
	put_image(param->mlx, param->textures->explode->frame1->p, new, 0);
	put_image(param->mlx, param->textures->explode->boss_explosion1->p, new, 22);
	usleep(5000);
	put_image(param->mlx, param->textures->explode->frame2->p, new, 0);
	put_image(param->mlx, param->textures->explode->boss_explosion2->p, new, 17);
	usleep(5000);
	put_image(param->mlx, param->textures->explode->boss_explosion3->p, new, 13);
	usleep(5000);
	put_image(param->mlx, param->textures->background->p, new, 0);
	del_ennemy(param, new);
}

void	make_explosion(t_param *param, t_gps *new)
{
	put_image(param->mlx, param->textures->background->p, param->shots->coor, 0);
	if (new->x == 0 || new->y == 0 || new->y == param->map->height - 1 || new->x == param->map->width - 1)
		return ;
	else
	{
		put_image(param->mlx, param->textures->explode->frame1->p, new, 0);
		usleep(5000);
		put_image(param->mlx, param->textures->explode->planet_explosion->p, new, 19);
		put_image(param->mlx, param->textures->explode->frame2->p, new, 0);
		usleep(5000);
		put_image(param->mlx, param->textures->background->p, new, 0);
		put_image(param->mlx, param->textures->planets->planet_exp->p, new, 8);
	}
	return ;
}

void	pass_collectible(t_param *param, t_gps *new)
{
	if (param->shots->direction == 1)
	{
		new->x = new->x - 1;
	}
	if (param->shots->direction == 2)
	{
		new->y = new->y - 1;
	}
	if (param->shots->direction == 3)
	{
		new->x = new->x + 1;
	}
	if (param->shots->direction == 4)
		new->y = new->y + 1;
	put_shot_in_coor(param, new);
}

void	put_shoot_in_direction(t_param *param, t_gps *new)
{
	if (param->shots->direction == 1)
		put_image(param->mlx, param->textures->shoot->frame1_left->p, new, 12);
	if (param->shots->direction == 2)
		put_image(param->mlx, param->textures->shoot->frame1_top->p, new, 12);
	if (param->shots->direction == 3)
		put_image(param->mlx, param->textures->shoot->frame1_right->p, new, 12);
	if (param->shots->direction == 4)
		put_image(param->mlx, param->textures->shoot->frame1_bot->p, new, 12);
	param->textures->shoot->frame_act = 1;
}

bool	put_shot_in_coor(t_param *param, t_gps *new)
{
	char	value_case;

	value_case = param->map->map[new->y][new->x];
	if (value_case == '1')
	{
		make_explosion(param, new);
		param->map->map[param->shots->coor->y][param->shots->coor->x] = '0';
		return (false);
	}
	if (value_case == 'D')
	{
		kill_boss(param, new);
		param->map->map[param->shots->coor->y][param->shots->coor->x] = '0';
		return (false);
	}
	if (value_case == '0')
	{
		param->map->map[param->shots->coor->y][param->shots->coor->x] = '0';
		put_image(param->mlx, param->textures->background->p, param->shots->coor, 0);
		param->map->map[new->y][new->x] = 'S';
		put_shoot_in_direction(param, new);
		param->shots->coor->x = new->x;
		param->shots->coor->y = new->y;
	}
	if (value_case == 'E') //animation ?
	{
		put_image(param->mlx, param->textures->background->p, param->shots->coor, 0);
		param->map->map[param->shots->coor->y][param->shots->coor->x] = '0';
		return (false);
	}
	if (value_case == 'C')
	{
		put_image(param->mlx, param->textures->background->p, param->shots->coor, 0);
		param->map->map[param->shots->coor->y][param->shots->coor->x] = '0';
		return (false);
	}
	return (true);
}

void	create_new_shot(t_param *param)
{
	t_shoot	*shot;

	shot = create_shot(clock(), param->player->direction);
	shot->coor = get_next_coor_s(param->player->direction, param->player->coor);
	if (param->map->map[shot->coor->y][shot->coor->x] == '1')
	{
		if (shot->coor->x == 0 || shot->coor->y == 0 || shot->coor->x == param->map->width - 1 || shot->coor->y == param->map->height - 1)
			return ;
		make_explosion(param, shot->coor);
		return ;
	}
	if (param->map->map[shot->coor->y][shot->coor->x] == 'D')
	{
		param->boss = del_ennemy(param, shot->coor);
		put_image(param->mlx, param->textures->background->p, shot->coor, 0);
		return ;
	}
	if (param->map->map[shot->coor->y][shot->coor->x] == 'E')
		return ;
	if (param->map->map[shot->coor->y][shot->coor->x] == 'C')
		return ;
	if (param->map->map[shot->coor->y][shot->coor->x] == '0')
	{
		param->map->nb_shot += 1;
		param->map->map[shot->coor->y][shot->coor->x] = 'S';
		param->shots = shot;
		put_shoot_in_direction(param, param->shots->coor);
		param->textures->shoot->frame_act = 1;
		return ;
	}
}

void	del_shot(t_param *param)
{
	param->map->nb_shot -= 1;
	free(param->shots->coor);
	free(param->shots);
}

bool	move_shot(t_param *param)
{
	t_gps	*new;
	clock_t	actual;
	bool	ret;

	ret = true;
	actual = clock();
	if ((actual - param->shots->shoot_time) * 1000 / CLOCKS_PER_SEC > 3)
	{
		new = get_next_coor_s(param->shots->direction, param->shots->coor);
		if (put_shot_in_coor(param, new) == false)
			ret = false;
		param->shots->shoot_time = actual;
		free(new);
	}
	return (ret);
}

int	shoot_exist(t_param *param)
{
	if (param->map->nb_shot == 1)
	{
		if (move_shot(param) == false)
			del_shot(param);
		return (1);
	}
	return (0);
}
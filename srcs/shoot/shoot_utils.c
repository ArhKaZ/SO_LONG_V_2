/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shoot_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 02:24:46 by syluiset          #+#    #+#             */
/*   Updated: 2023/03/06 14:33:29 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

t_gps	*get_next_coor_s(int direction, t_gps *coor)
{
	t_gps	*new;

	new = NULL;
	if (direction == 0)
		new = create_gps(coor->x - 1, coor->y);
	if (direction == 1)
		new = create_gps(coor->x, coor->y - 1);
	if (direction == 2)
		new = create_gps(coor->x + 1, coor->y);
	if (direction == 3)
		new = create_gps(coor->x, coor->y + 1);
	if (!new)
		return (NULL);
	return (new);
}

t_shoot	*create_shot(clock_t time, int direction, t_gps *player)
{
	t_shoot	*shot;

	shot = malloc(sizeof(t_shoot));
	if (!shot)
		return (NULL);
	shot->direction = direction;
	shot->shoot_time = time;
	shot->coor = get_next_coor_s(direction, player);
	if (shot->coor == NULL)
		return (NULL);
	return (shot);
}

void	del_shot(t_param *param, t_shoot *shot)
{
	param->map->nb_shot = 0;
	free(shot->coor);
	free(shot);
}

void	put_shoot_in_direction(t_param *param, t_gps *new)
{
	if (param->shots->direction == 0)
		put_image(param->mlx, param->textures->shoot->s_left[0]->p, new);
	if (param->shots->direction == 1)
		put_image(param->mlx, param->textures->shoot->s_top[0]->p, new);
	if (param->shots->direction == 2)
		put_image(param->mlx, param->textures->shoot->s_right[0]->p, new);
	if (param->shots->direction == 3)
		put_image(param->mlx, param->textures->shoot->s_bot[0]->p, new);
	param->textures->shoot->frame_act = 0;
}

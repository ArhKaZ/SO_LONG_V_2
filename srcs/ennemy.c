/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ennemy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:01:15 by syluiset          #+#    #+#             */
/*   Updated: 2023/02/13 16:23:04 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

t_ennemy	*create_new_ennemy(int height, int width)
{
	t_ennemy	*new;

	new = malloc(sizeof(t_ennemy));
	new->coor = malloc(sizeof(t_gps));
	new->coor->x = width;
	new->coor->y = height;
	new->next = NULL;
	return (new);
}

t_ennemy	*last_ennemy(t_ennemy *list)
{
	while (list->next != NULL)
		list = list->next;
	return (list);
}

void	add_ennemy_back(t_ennemy **lst, int height, int width)
{
	t_ennemy	*temp;
	t_ennemy	*new;

	new = create_new_ennemy(height, width);
	if (!lst)
		return ;
	if (*lst != NULL)
	{
		temp = last_ennemy(*lst);
		temp->next = new;
	}
	else
		*lst = new;
}

t_ennemy	*clear_ennemy(t_ennemy *ennemy)
{	
	t_ennemy	*temp;
	t_ennemy	*next;
	t_ennemy	*before;

	temp = ennemy;
	before = temp;
	temp = temp->next;
	next = temp->next;
	before->next = next;
	free(temp->coor);
	free(temp);
	return (before);
}

t_ennemy	*del_ennemy(t_param *param, t_gps *coor)
{
	t_ennemy	*first;
	t_ennemy	*temp;
	t_ennemy	*next;
	
	first = param->boss;
	temp = param->boss;
	if (temp->coor->x == coor->x && temp->coor->y == coor->y)
	{
		next = temp->next;
		free(temp->coor);
		free(temp);
		temp = next;
		return (temp);
	}
	else
	{
		while (temp != NULL)
		{
			if (temp->next->coor->x == coor->x && temp->next->coor->y == coor->y)
			{
				param->map->map[coor->y][coor->x] = 'V';
			}
			temp = temp->next;
		}
	}
	temp = first;
	param->map->map[coor->y][coor->x] = '0';
	return (temp);
}

t_ennemy	*get_ennemy(t_map *map)
{
	t_ennemy	*lst;
	int height;
	int width;

	height = 1;
	lst = NULL;
	while (map->map[height] != NULL)
	{
		width = 1;
		while (map->map[height][width])
		{
			if (map->map[height][width] == 'D')
				add_ennemy_back(&lst, height, width);
			width++;
		}
		height++;
	}
	return (lst);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:48:41 by syluiset          #+#    #+#             */
/*   Updated: 2023/01/30 13:55:22 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

t_lst_planet	*create_planet(int height, int width, int texture)
{
	t_lst_planet	*new;
	t_gps			*coor;

	coor = malloc(sizeof(t_gps));
	new = malloc(sizeof(t_lst_planet));
	coor->x = width;
	coor->y = height;
	new->coor = coor;
	new->texture = texture;
	new->next = NULL;
	return (new);
}

t_lst_planet	*lst_p_last(t_lst_planet *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	lst_planet_add_back(t_lst_planet **lst, t_lst_planet *new)
{
	t_lst_planet	*temp;

	if (!lst || !new)
		return ;
	if (*lst != NULL)
	{
		temp = lst_p_last(*lst);
		temp->next = new;
	}
	else
		*lst = new;
}

t_map	*create_empty_map(void)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->begin = 0;
	map->exit = 0;
	map->nb_empty = 0;
	map->nb_item = 0;
	map->nb_wall = 0;
	//!bonus
	map->nb_ennemy = 0;
	map->nb_shot = 0;
	//!bonus
	map->map = NULL;
	map->height = 0;
	map->width = 0;
	map->coor_exit = create_empty_gps();
	map->planets = NULL;
	return (map);
}

bool	get_map(char *path, t_map *map)
{
	char	*map_temp;
	int i;

	i = 0;
	map_temp = get_map_to_string(path, map);
	if (map_temp == NULL)
		return (false);
	map->map = ft_split(map_temp, '\n');
	free(map_temp);
	while(map->map[0][i])
		i++;
	map->width = i;
	i = 0;
	while (map->map[i] != NULL)
		i++;
	map->height = i;
	return (true);
}
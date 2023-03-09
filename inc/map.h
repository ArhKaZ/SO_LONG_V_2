/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 15:51:13 by syluiset          #+#    #+#             */
/*   Updated: 2023/03/09 10:48:06 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H
# include "./so_long.h"

typedef struct s_gen_map
{
	int	rand;
	int	exit;
	int	begin;
	int	item;
	int	item_on_line;
	int	d_on_line;
	int	item_param;
	int	ennemy_param;
	int	ennemy;
}				t_gen_map;

int			map_random(int nb_max);

bool		should_put_item(t_gen_map *map, int height);

t_gen_map	*create_gen_map(int collect, int ennemy);

void		line_of_wall(t_gps *coor);

void		create_map_with_d(t_gps *coor, int density, int collect, int enne);

void		on_x_action(int x, t_gps *coor, int density, t_gen_map *map);

bool		on_y_action(int y, t_gps *coor);

void		on_x_action_e(int x, t_gps *coor, int density, t_gen_map *map);

void		put_component(t_gen_map *map, t_gps *coor, int rand);

void		put_component_with_d(t_gen_map *map, t_gps *coor, int rand);

#endif

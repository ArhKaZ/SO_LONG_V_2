/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 15:16:13 by syluiset          #+#    #+#             */
/*   Updated: 2023/03/06 15:35:26 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/map.h"

void	on_x_action_e(int x, t_gps *coor, int density, t_gen_map *map)
{
	if (x == 0 || x == coor->x + 1
		|| map_random(coor->x) * 2 < density)
		ft_printf("1");
	else
		put_component_with_d(map, coor, map_random(9));
}

void	on_x_action(int x, t_gps *coor, int density, t_gen_map *map)
{
	if (x == 0 || x == coor->x + 1
		|| map_random(coor->x) * 2 < density)
		ft_printf("1");
	else
		put_component(map, coor, map_random(9));
}

bool	on_y_action(int y, t_gps *coor)
{
	if (y == 0)
		line_of_wall(coor);
	if (y == coor->y)
	{
		line_of_wall(coor);
		return (true);
	}
	return (false);
}

int	map_random(int nb_max)
{
	int	random_number;
	int	fd;
	int	ret;

	fd = open("/dev/random", O_RDONLY);
	if (fd < 0 || read(fd, 0, 0) < 0)
		exit(EXIT_FAILURE);
	ret = read(fd, &random_number, sizeof(int));
	if (ret < 0)
		return (-1);
	close(fd);
	random_number %= nb_max;
	if (random_number < 0)
		random_number = random_number * -1;
	return (random_number);
}

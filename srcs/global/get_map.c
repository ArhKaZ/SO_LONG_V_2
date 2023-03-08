/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:38:49 by syluiset          #+#    #+#             */
/*   Updated: 2023/03/08 11:42:15 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	add_to_map(t_map *map, char c)
{
	if (c == '0')
		map->nb_empty += 1;
	if (c == '1')
		map->nb_wall += 1;
	if (c == 'C')
		map->nb_item += 1;
	if (c == 'E')
		map->exit += 1;
	if (c == 'P')
		map->begin += 1;
	if (c == 'D')
		map->nb_ennemy += 1;
}

char	*map_in_one_string(char *line, char *string)
{
	char	*temp;

	if (string == NULL)
		string = ft_strdup(line);
	else
	{
		temp = ft_strdup(string);
		free(string);
		string = ft_strjoin(temp, line);
		free(temp);
	}
	free(line);
	return (string);
}

char	*get_map_to_string(char *path)
{
	int		fd;
	char	*line;
	char	*map_string;

	map_string = NULL;
	fd = open(path, O_RDONLY);
	while (get_next_line_loop(fd, &line))
		map_string = map_in_one_string(line, map_string);
	close(fd);
	return (map_string);
}

bool	all_check_map(char *map_temp, t_map **map)
{
	if (map_temp == NULL)
	{
		(*map)->map = NULL;
		return (false);
	}
	if (check_line_empty(map_temp) == true)
	{
		free(map_temp);
		return (false);
	}
	(*map)->map = ft_split(map_temp, '\n');
	if ((*map)->map == NULL)
		return (false);
	if (check_line((*map)->map, *map) == false)
	{
		free_char_map((*map)->map);
		(*map)->map = NULL;
		return (false);
	}
	return (true);
}

bool	get_map(char *path, t_map *map)
{
	char	*map_temp;
	int		i;

	i = 0;
	map_temp = get_map_to_string(path);
	if (map_temp == NULL)
	{
		ft_putstr_fd("Error\nMap is empty or got error", 2);
		return (false);
	}
	if (all_check_map(map_temp, &map) == false)
		return (false);
	free(map_temp);
	while (map->map[0][i])
		i++;
	map->width = i;
	i = 0;
	while (map->map[i] != NULL)
		i++;
	map->height = i;
	return (true);
}

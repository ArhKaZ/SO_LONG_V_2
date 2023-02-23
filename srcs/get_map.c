/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:38:49 by syluiset          #+#    #+#             */
/*   Updated: 2023/02/23 15:55:03 by syluiset         ###   ########.fr       */
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

char	*get_map_to_string(char *path, t_map *map)
{
	int		fd;
	char	*line;
	char	*map_string;
	size_t	length;
	bool	ret;

	ret = true;
	length = 0;
	map_string = NULL;
	fd = open(path, O_RDONLY);
	while (get_next_line_loop(fd, &line))
	{
		if (ret == false)
			free(line);
		else
		{
			if (check_line(line, map, &length) == false)
			{
				if (map_string != NULL)
					free(map_string);
				free(line);
				ret = false;
			}
			else
				map_string = map_in_one_string(line, map_string);
		}
	}
	close(fd);
	if (ret == true)
		return (map_string);
	return (NULL);
}


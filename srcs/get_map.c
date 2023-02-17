/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:38:49 by syluiset          #+#    #+#             */
/*   Updated: 2023/02/17 16:44:34 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

bool	check_char(char c)
{
	if (c == '0' || c == '1' || c == 'C' || c == 'E' || c == 'P' || c == '\n' || c == 'D')
		return (true);
	else
		return (false);
}

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
	//!bonus
	if (c == 'D')
		map->nb_ennemy += 1;
	//!bonus
}

bool	check_line(char *line, t_map *map, size_t *length)
{
	size_t i;
	
	i = 0;
	if (line[0] == 0)
		return (false);
	while (line[i] && line[i] != '\n')
		i++;
	if (*length != 0)
	{
		if (i != *length)
		{
			ft_putstr_fd("Error map is not regular\n", 2);
			return (false);
		}
	}
	*length = i;
	i = 0;
	while (line[i])
	{
		if (check_char(line[i]) == false)
			return (false);
		add_to_map(map, line[i]);
		i++;
	}
	return (true);
}

char	*map_in_one_string(char *line, char *string)
{
	char *temp;

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

//t_bool get_next_line (int fd, char **line_pt)

char	*get_map_to_string(char *path, t_map *map)
{
	int		fd;
	char	*line;
	char	*map_string;
	size_t	length;

	length = 0;
	map_string = NULL;
	fd = open(path, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (check_line(line, map, &length) == false)
		{
			if (map_string != NULL)
				free(map_string);
			return (NULL);
		}
		map_string = map_in_one_string(line, map_string);
	}
	close(fd);
	return (map_string);
}

bool	check_extension(char *path)
{
	int i;

	i = 0;
	while (path[i] != '.' && path[i])
		i++;
	if (i != 0 && ft_strncmp(path + i, ".ber", 4) == 0)
		return (true);
	else
	{
		ft_putstr_fd("Error\n Le nom du fichier n'est pas conforme", 2);
		return (false);
	}
}

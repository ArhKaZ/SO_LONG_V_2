/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 12:04:35 by syluiset          #+#    #+#             */
/*   Updated: 2023/02/23 15:55:06 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

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
		ft_putstr_fd("Error\nLe nom du fichier n'est pas conforme\n", 2);
		return (false);
	}
}

bool get_next_line_loop (int fd, char **line_pt)
{
	*line_pt = get_next_line(fd);
	if (*line_pt == NULL)
		return (false);
	else
		return (true);
}

bool	check_line(char *line, t_map *map, size_t *length)
{
	size_t	i;

	i = 0;
	if (line[0] == 0)
		return (false);
	while (line[i] && line[i] != '\n')
		i++;
	if (*length != 0)
	{
		if (i != *length)
		{
			ft_putstr_fd("Error\nmap is not regular\n", 2);
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

bool	check_char(char c)
{
	if (c == '0' || c == '1' || c == 'C' || c == 'E'
		|| c == 'P' || c == '\n' || c == 'D')
		return (true);
	else
		return (false);
}
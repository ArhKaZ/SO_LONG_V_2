/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 12:04:35 by syluiset          #+#    #+#             */
/*   Updated: 2023/03/09 14:32:58 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

bool	check_extension(char *path)
{
	if (ft_strrchr(path, '.') == 0)
	{
		ft_putstr_fd("Error\nThe file name is not correct\n", 2);
		return (false);
	}
	path = ft_strrchr(path, '.');
	if (ft_strncmp(path, ".ber", 4) != 0)
	{
		ft_putstr_fd("Error\nThe file name is not correct\n", 2);
		return (false);
	}
	return (true);
}

bool	get_next_line_loop(int fd, char **line_pt)
{
	*line_pt = get_next_line(fd);
	if (*line_pt == NULL)
		return (false);
	else
		return (true);
}

bool	check_line(char **map, t_map *map_s)
{
	int		i;
	size_t	length;
	int		j;

	i = 0;
	length = ft_strlen(map[i]);
	while (map[i] != NULL)
	{
		j = 0;
		if (ft_strlen(map[i]) != length)
		{
			ft_putstr_fd("Error\nMap is not regular\n", 2);
			return (false);
		}
		while (map[i][j])
		{
			if (check_char(map[i][j]) == false)
				return (false);
			add_to_map(map_s, map[i][j]);
			j++;
		}
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

bool	check_line_empty(char *s)
{
	int	i;

	i = 0;
	while (s[i + 1])
	{
		if (s[i] == '\n' && s[i + 1] == '\n')
		{
			ft_putstr_fd("Error\nMap as a empty line", 2);
			return (true);
		}
		i++;
	}
	return (false);
}

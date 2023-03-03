/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rand.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 12:11:21 by syluiset          #+#    #+#             */
/*   Updated: 2023/02/23 14:54:00 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	get_random(int nb_max)
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
	{
		random_number = random_number * -1;
	}
	return (random_number);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gps.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 15:32:33 by syluiset          #+#    #+#             */
/*   Updated: 2023/02/16 14:58:52 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

t_gps	*create_empty_gps(void)
{
	t_gps *gps;

	gps = NULL;
	gps = malloc(sizeof(t_gps));
	if (!gps)
		return (NULL);
	gps->x = 0;
	gps->y = 0;
	return (gps);
}
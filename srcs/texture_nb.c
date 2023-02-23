/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_nb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 17:27:47 by syluiset          #+#    #+#             */
/*   Updated: 2023/02/23 12:11:10 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

t_nb	*create_nb_little(t_mlx *mlx)
{
	t_nb	*nb;

	nb = NULL;
	nb = malloc(sizeof(t_nb));
	nb->zero = create_texture("xpm/nb/little_0.xpm", mlx);
	nb->one = create_texture("xpm/nb/little_1.xpm", mlx);
	nb->two = create_texture("xpm/nb/little_2.xpm", mlx);
	nb->three = create_texture("xpm/nb/little_3.xpm", mlx);
	nb->four = create_texture("xpm/nb/little_4.xpm", mlx);
	nb->five = create_texture("xpm/nb/little_5.xpm", mlx);
	nb->six = create_texture("xpm/nb/little_6.xpm", mlx);
	nb->seven = create_texture("xpm/nb/little_7.xpm", mlx);
	nb->eight = create_texture("xpm/nb/little_8.xpm", mlx);
	nb->nine = create_texture("xpm/nb/little_9.xpm", mlx);
	return (nb);
}

t_nb	*create_nb_medium(t_mlx *mlx)
{
	t_nb	*nb;

	nb = NULL;
	nb = malloc(sizeof(t_nb));
	nb->zero = create_texture("xpm/nb/med_0.xpm", mlx);
	nb->one = create_texture("xpm/nb/med_1.xpm", mlx);
	nb->two = create_texture("xpm/nb/med_2.xpm", mlx);
	nb->three = create_texture("xpm/nb/med_3.xpm", mlx);
	nb->four = create_texture("xpm/nb/med_4.xpm", mlx);
	nb->five = create_texture("xpm/nb/med_5.xpm", mlx);
	nb->six = create_texture("xpm/nb/med_6.xpm", mlx);
	nb->seven = create_texture("xpm/nb/med_7.xpm", mlx);
	nb->eight = create_texture("xpm/nb/med_8.xpm", mlx);
	nb->nine = create_texture("xpm/nb/med_9.xpm", mlx);
	return (nb);
}

t_nb	*create_nb_big(t_mlx *mlx)
{
	t_nb	*nb;

	nb = NULL;
	nb = malloc(sizeof(t_nb));
	nb->zero = create_texture("xpm/nb/big_0.xpm", mlx);
	nb->one = create_texture("xpm/nb/big_1.xpm", mlx);
	nb->two = create_texture("xpm/nb/big_2.xpm", mlx);
	nb->three = create_texture("xpm/nb/big_3.xpm", mlx);
	nb->four = create_texture("xpm/nb/big_4.xpm", mlx);
	nb->five = create_texture("xpm/nb/big_5.xpm", mlx);
	nb->six = create_texture("xpm/nb/big_6.xpm", mlx);
	nb->seven = create_texture("xpm/nb/big_7.xpm", mlx);
	nb->eight = create_texture("xpm/nb/big_8.xpm", mlx);
	nb->nine = create_texture("xpm/nb/big_9.xpm", mlx);
	return (nb);
}

t_nb	*create_nb(t_mlx *mlx, int width, int height)
{
	t_nb	*nb;

	nb = NULL;
	if (width < 8 || height < 8)
		nb = create_nb_little(mlx);
	else if (width < 14 || height < 14)
		nb = create_nb_medium(mlx);
	else if (width >= 14 || height >= 14)
		nb = create_nb_big(mlx);
	return (nb);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_nb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 17:27:47 by syluiset          #+#    #+#             */
/*   Updated: 2023/02/22 20:30:37 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

t_nb	*create_nb_little(t_mlx *mlx)
{
	t_nb	*nb;

	nb = NULL;
	nb = malloc(sizeof(t_nb));
	nb->zero = create_texture("texture_converted/nb/little_0.xpm", mlx);
	nb->one = create_texture("texture_converted/nb/little_1.xpm", mlx);
	nb->two = create_texture("texture_converted/nb/little_2.xpm", mlx);
	nb->three = create_texture("texture_converted/nb/little_3.xpm", mlx);
	nb->four = create_texture("texture_converted/nb/little_4.xpm", mlx);
	nb->five = create_texture("texture_converted/nb/little_5.xpm", mlx);
	nb->six = create_texture("texture_converted/nb/little_6.xpm", mlx);
	nb->seven = create_texture("texture_converted/nb/little_7.xpm", mlx);
	nb->eight = create_texture("texture_converted/nb/little_8.xpm", mlx);
	nb->nine = create_texture("texture_converted/nb/little_9.xpm", mlx);
	return (nb);
}

t_nb	*create_nb_medium(t_mlx *mlx)
{
	t_nb	*nb;

	nb = NULL;
	nb = malloc(sizeof(t_nb));
	nb->zero = create_texture("texture_converted/nb/med_0.xpm", mlx);
	nb->one = create_texture("texture_converted/nb/med_1.xpm", mlx);
	nb->two = create_texture("texture_converted/nb/med_2.xpm", mlx);
	nb->three = create_texture("texture_converted/nb/med_3.xpm", mlx);
	nb->four = create_texture("texture_converted/nb/med_4.xpm", mlx);
	nb->five = create_texture("texture_converted/nb/med_5.xpm", mlx);
	nb->six = create_texture("texture_converted/nb/med_6.xpm", mlx);
	nb->seven = create_texture("texture_converted/nb/med_7.xpm", mlx);
	nb->eight = create_texture("texture_converted/nb/med_8.xpm", mlx);
	nb->nine = create_texture("texture_converted/nb/med_9.xpm", mlx);
	return (nb);
}

t_nb	*create_nb_big(t_mlx *mlx)
{
	t_nb	*nb;

	nb = NULL;
	nb = malloc(sizeof(t_nb));
	nb->zero = create_texture("texture_converted/nb/big_0.xpm", mlx);
	nb->one = create_texture("texture_converted/nb/big_1.xpm", mlx);
	nb->two = create_texture("texture_converted/nb/big_2.xpm", mlx);
	nb->three = create_texture("texture_converted/nb/big_3.xpm", mlx);
	nb->four = create_texture("texture_converted/nb/big_4.xpm", mlx);
	nb->five = create_texture("texture_converted/nb/big_5.xpm", mlx);
	nb->six = create_texture("texture_converted/nb/big_6.xpm", mlx);
	nb->seven = create_texture("texture_converted/nb/big_7.xpm", mlx);
	nb->eight = create_texture("texture_converted/nb/big_8.xpm", mlx);
	nb->nine = create_texture("texture_converted/nb/big_9.xpm", mlx);
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

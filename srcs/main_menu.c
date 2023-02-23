/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_menu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 15:45:56 by syluiset          #+#    #+#             */
/*   Updated: 2023/02/23 17:35:58 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	main_menu()
{
	t_mlx	*mlx;
	t_texture	*back;
	t_texture	*exit;
	t_texture	*start;
	t_gps		*place;

	place = create_gps(0, 0);
	mlx = create_empty_mlx();
	mlx->mlx = mlx_init();
	mlx->mlx_win = mlx_new_window(mlx->mlx, 800, 800, "SO_LONG");
	back = create_texture("xpm/menu/menu.xpm", mlx);
	exit = create_texture("xpm/menu/select_exit.xpm", mlx);
	start = create_texture("xpm/menu/select_start.xpm", mlx);
	put_image(mlx, back->p, place);
	mlx_hook(mlx->mlx_win, 17, 1L >> 0, &close_menu, param);
	mlx_loop(mlx->mlx);
}

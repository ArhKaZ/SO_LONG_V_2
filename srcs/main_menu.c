/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_menu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 15:45:56 by syluiset          #+#    #+#             */
/*   Updated: 2023/03/01 13:20:50 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"


t_menu	*create_t_menu(t_mlx *mlx)
{
	t_menu		*menu;

	menu = malloc(sizeof(t_menu));
	menu->menu[0] = create_texture("xpm/menu/menu_start.xpm", mlx);
	menu->menu[1] = create_texture("xpm/menu/menu_command.xpm", mlx);
	menu->menu[2] = create_texture("xpm/menu/menu_exit.xpm", mlx);
	menu->menu[3] = create_texture("xpm/menu/command.xpm", mlx);
	menu->select = 0;
	menu->mlx = mlx;
	return (menu);
}

int	main_menu(t_param *param)
{
	t_gps	*place;
	t_mlx	*mlx;

	mlx = create_empty_mlx();
	mlx->mlx = mlx_init();
	mlx->mlx_win = mlx_new_window(mlx->mlx, 800, 800, "SO_LONG");
	param->menu = create_t_menu(mlx);
	place = create_gps(0, 0);
	put_image(mlx, param->menu->menu[0]->p, place);
	free(place);
	mlx_hook(mlx->mlx_win, 17, 1L >> 0, &close_win, param);
	mlx_hook(mlx->mlx_win, 2, 1L >> 0, &move_in_menu, param);
	mlx_loop(mlx->mlx);
	return (1);
}

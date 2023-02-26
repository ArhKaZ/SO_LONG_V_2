/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_menu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 15:45:56 by syluiset          #+#    #+#             */
/*   Updated: 2023/02/26 19:11:10 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	move_in_menu(int keycode, t_param *param)
{
	t_gps	*zero;
	t_menu	*menu;

	menu = param->menu;
	zero = create_gps(0, 0);
	if (keycode == 115 && menu->keycode != 115)
	{
		put_image(menu->mlx, menu->menu[1]->p, zero);
		menu->keycode = keycode;
		free(zero);
	}
	else if (keycode == 119 && menu->keycode != 119)
	{
		put_image(menu->mlx, menu->menu[0]->p, zero);
		menu->keycode = keycode;
		free(zero);
	}
	else if (keycode == 32)
	{
		if (menu->keycode == 119)
			close_menu_start(param);
		if (menu->keycode == 115)
			close_menu_exit(param, menu->mlx->mlx, menu->mlx->mlx_win, param->mlx->mlx);
	}
	if (keycode == 65307)
		close_menu_exit(param, menu->mlx->mlx, menu->mlx->mlx_win, param->mlx->mlx);
}

int	choose_in_menu(int keycode, t_param *param)
{
	if (param->mlx->menu == true)
		move_in_menu(keycode, param);
	return (0);
}

t_menu	*create_t_menu(t_mlx *mlx)
{
	t_menu		*menu;

	menu = malloc(sizeof(t_menu));
	menu->menu[0] = create_texture("xpm/menu/menu_start.xpm", mlx);
	menu->menu[1] = create_texture("xpm/menu/menu_exit.xpm", mlx);
	menu->keycode = 119;
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
	mlx_hook(mlx->mlx_win, 2, 1L >> 0, &choose_in_menu, param);
	mlx_loop(mlx->mlx);
	return (1);
}

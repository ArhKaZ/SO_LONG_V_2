/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_menu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 15:45:56 by syluiset          #+#    #+#             */
/*   Updated: 2023/02/26 12:50:22 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	choose_in_menu(int keycode, t_param *param)
{
	t_gps	*zero;
	t_menu	*menu;

	menu = param->menu;
	zero = create_gps(0, 0);
	if (keycode == 115 && menu->keycode != 115)
	{
		put_image(param->mlx, menu->menu[1]->p, zero);
		menu->keycode = keycode;
	}
	else if (keycode == 119 && menu->keycode != 119)
	{
		put_image(param->mlx, menu->menu[0]->p, zero);
		menu->keycode = keycode;
	}
	else if (keycode == 32)
	{
		if (menu->keycode == 119)
			close_menu_start(param);
		if (menu->keycode == 115)
			close_menu_exit(param);
	}
	// if (keycode == 65307)
	// 	close_win(param, param->mlx->mlx, param->mlx->mlx_win);
	return (0);
}

t_menu	*create_t_menu(t_param *p)
{
	t_menu		*menu;

	menu = malloc(sizeof(t_menu));
	menu->menu[0] = create_texture("xpm/menu/menu_start.xpm", p->mlx);
	menu->menu[1] = create_texture("xpm/menu/menu_exit.xpm", p->mlx);
	menu->keycode = 119;
	return (menu);
}

int	main_menu(t_param *param)
{
	t_gps	*place;

	param->menu = create_t_menu(param);
	param->mlx->mlx_win = mlx_new_window(param->mlx->mlx, 800, 800, "SO_LONG");
	place = create_gps(0, 0);
	put_image(param->mlx, param->menu->menu[0]->p, place);
	return (1);
}

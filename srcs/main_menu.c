/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_menu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 15:45:56 by syluiset          #+#    #+#             */
/*   Updated: 2023/02/24 00:20:59 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
void	free_menu(t_menu *menu)
{
	free(menu->menu[0]);
	free(menu->menu[1]);
	free(menu->menu);
	free(menu->mlx);
	free(menu);
}

int	close_menu_exit(t_param *param)
{
	mlx_destroy_window(param->menu->mlx->mlx, param->menu->mlx->mlx_win);
	mlx_destroy_display(param->menu->mlx->mlx);
	free(param->menu->mlx->mlx);
	close_win(param, param->mlx->mlx, param->mlx->mlx_win);
	return (1);
}

int	close_menu_start(t_param *param)
{
	mlx_destroy_window(param->menu->mlx->mlx, param->menu->mlx->mlx_win);
	mlx_destroy_display(param->menu->mlx->mlx);
	free(param->menu->mlx->mlx);
	so_long(param);
	return (1);
}

int	close_menu(t_param *param)
{
	mlx_destroy_window(param->menu->mlx->mlx, param->menu->mlx->mlx_win);
	mlx_destroy_display(param->menu->mlx->mlx);
	free(param->menu->mlx->mlx);
	return (1);
}
int	choose_in_menu(int keycode, t_param *param)
{
	t_gps	*zero;
	t_menu	*menu;

	menu = param->menu;
	zero = create_gps(0, 0);
	if (keycode == 115 && menu->keycode != 115)
	{
		put_image(menu->mlx, menu->menu[1], zero);
		menu->keycode = keycode;
	}
	if (keycode == 119 && menu->keycode != 119)
	{
		put_image(menu->mlx, menu->menu[0], zero);
		menu->keycode = keycode;
	}
	if (keycode == 32)
	{
		if (menu->keycode == 119)
			close_menu_start(param);
		if (menu->keycode == 115)
			close_menu_exit(param);
	}
	if (keycode == 65307)
		close_win(param, param->mlx->mlx, param->mlx->mlx_win);
	return (0);
}

t_menu	*create_t_menu(void)
{
	t_mlx		*mlx;
	t_menu		*menu;

	menu = malloc(sizeof(t_menu));
	mlx = create_empty_mlx();
	mlx->mlx = mlx_init();
	mlx->mlx_win = mlx_new_window(mlx->mlx, 800, 800, "SO_LONG");
	menu->menu[0] = create_texture("xpm/menu/menu_start.xpm", mlx);
	menu->menu[1] = create_texture("xpm/menu/menu_exit.xpm", mlx);
	menu->mlx = mlx;
	return (menu);
}

int	main_menu(t_param *param)
{
	t_gps	*place;

	param->menu = create_t_menu();
	place = create_gps(0, 0);
	put_image(param->menu->mlx, param->menu->menu[0]->p, place);
	mlx_hook(param->menu->mlx->mlx_win, 17, 1L >> 0, &close_menu, param);
	mlx_hook(param->menu->mlx->mlx_win, 2, 1L >> 0, &choose_in_menu, param);
	mlx_loop(param->menu->mlx->mlx);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_menu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 15:45:56 by syluiset          #+#    #+#             */
/*   Updated: 2023/02/27 23:39:20 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	select_choice(t_param *param, t_menu *menu, t_gps *zero)
{
	int	select;

	select = menu->select;
	if (select == 0)
		close_menu_start(param, menu->mlx->mlx, menu->mlx->mlx_win,
			param->mlx->mlx);
	if (select == 1)
	{
		mlx_clear_window(menu->mlx->mlx, menu->mlx->mlx_win);
		put_image(menu->mlx, menu->menu[3]->p, zero);
		select = 3;
	}
	if (select == 2)
		close_menu_exit(param, menu->mlx->mlx, menu->mlx->mlx_win,
			param->mlx->mlx);
	if (select == 3)
	{
		mlx_clear_window(menu->mlx->mlx, menu->mlx->mlx_win);
		put_image(menu->mlx, menu->menu[1]->p, zero);
		select = 1;
	}
}

void	move_in_menu(int keycode, t_param *param)
{
	t_gps	*zero;
	int		select;
	t_menu	*menu;

	menu = param->menu;
	select = param->menu->select;
	zero = create_gps(0, 0);
	if (select < 2 && keycode == 115)
	{
		mlx_clear_window(param->mlx->mlx, param->mlx->mlx_win);
		if (select == 0)
			put_image(menu->mlx, menu->menu[1]->p, zero);
		if (select == 1)
			put_image(menu->mlx, menu->menu[2]->p, zero);
		param->menu->select += 1;
	}
	if (select > 0 && select < 3 && keycode == 119)
	{
		mlx_clear_window(menu->mlx->mlx, menu->mlx->mlx_win);
		if (select == 1)
			put_image(menu->mlx, menu->menu[0]->p, zero);
		if (select == 2)
			put_image(menu->mlx, menu->menu[1]->p, zero);
		param->menu->select -= 1;
	}
	if (keycode == 32)
		select_choice(param, menu, zero);
}

// void	move_in_menu(int keycode, t_param *param)
// {
// 	t_gps	*zero;
// 	t_menu	*menu;

// 	menu = param->menu;
// 	zero = create_gps(0, 0);
// 	if (keycode == 115 && menu->keycode != 115)
// 		put_image(menu->mlx, menu->menu[1]->p, zero);
// 	else if (keycode == 119 && menu->keycode != 119)
// 		put_image(menu->mlx, menu->menu[0]->p, zero);
// 	free(zero);
// 	if (keycode == 32)
// 	{
// 		if (menu->keycode == 119)
// 			close_menu_start(param, menu->mlx->mlx, menu->mlx->mlx_win,
// 				param->mlx->mlx);
// 		if (menu->keycode == 115)
// 			close_menu_exit(param, menu->mlx->mlx, menu->mlx->mlx_win,
// 				param->mlx->mlx);
// 	}
// 	if (keycode == 65307)
// 		close_menu_exit(param, menu->mlx->mlx, menu->mlx->mlx_win,
// 			param->mlx->mlx);
// 	menu->keycode = keycode;
// }

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
	mlx_hook(mlx->mlx_win, 2, 1L >> 0, &choose_in_menu, param);
	mlx_loop(mlx->mlx);
	return (1);
}

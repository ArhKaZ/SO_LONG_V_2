/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress_menu.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 13:13:17 by syluiset          #+#    #+#             */
/*   Updated: 2023/03/08 13:30:35 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	select_command(t_param *param, t_menu *menu, t_gps *zero)
{
	int	select;

	select = menu->select;
	if (select == 1)
	{
		mlx_clear_window(menu->mlx->mlx, menu->mlx->mlx_win);
		put_image(menu->mlx, menu->menu[3]->p, zero);
		param->menu->select = 3;
	}
	else
	{
		mlx_clear_window(menu->mlx->mlx, menu->mlx->mlx_win);
		put_image(menu->mlx, menu->menu[1]->p, zero);
		param->menu->select = 1;
	}
}

void	select_choice(t_param *param, t_menu *menu, t_gps *zero)
{
	int	select;

	select = menu->select;
	if (select == 1 || select == 3)
		select_command(param, menu, zero);
	else
	{
		if (select == 0)
		{
			free(zero);
			close_menu_start(param, menu->mlx->mlx, menu->mlx->mlx_win,
				param->mlx->mlx);
		}
		else
		{
			free(zero);
			close_menu_exit(param, menu->mlx->mlx, menu->mlx->mlx_win,
				param->mlx->mlx);
		}
	}
}

void	press_down(t_param *p, t_menu *menu, t_gps *zero)
{
	int		select;

	select = p->menu->select;
	if (select < 2)
	{
		mlx_clear_window(menu->mlx->mlx, p->menu->mlx->mlx_win);
		if (select == 0)
			put_image(menu->mlx, menu->menu[1]->p, zero);
		if (select == 1)
			put_image(menu->mlx, menu->menu[2]->p, zero);
		p->menu->select += 1;
	}
}

void	press_up(t_param *p, t_menu *menu, t_gps *zero)
{
	int		select;

	select = p->menu->select;
	if (select > 0 && select < 3)
	{
		mlx_clear_window(menu->mlx->mlx, menu->mlx->mlx_win);
		if (select == 1)
			put_image(menu->mlx, menu->menu[0]->p, zero);
		if (select == 2)
			put_image(menu->mlx, menu->menu[1]->p, zero);
		p->menu->select -= 1;
	}
}

int	move_in_menu(int keycode, t_param *p)
{
	t_gps	*zero;
	t_menu	*menu;

	menu = p->menu;
	zero = create_gps(0, 0);
	if (!zero)
		close_menu_exit(p, p->menu->mlx->mlx, p->menu->mlx->mlx_win,
			p->mlx->mlx);
	if (keycode == CROSS_DOWN)
		press_down(p, menu, zero);
	if (keycode == CROSS_UP)
		press_up(p, menu, zero);
	if (keycode == ENTER)
		select_choice(p, menu, zero);
	if (keycode == ESC)
	{
		free(zero);
		close_menu_exit(p, p->menu->mlx->mlx, p->menu->mlx->mlx_win,
			p->mlx->mlx);
	}
	free(zero);
	return (1);
}

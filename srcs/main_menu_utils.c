/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_menu_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 02:10:20 by syluiset          #+#    #+#             */
/*   Updated: 2023/02/24 16:50:02 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	free_menu(t_menu *menu)
{
	free(menu->menu[0]->p);
	free(menu->menu[0]->size);
	free(menu->menu[1]->p);
	free(menu->menu[1]->size);
	free(menu->mlx->mlx);
	free(menu->mlx);
	free(menu);
}

int	close_menu_exit(t_param *param)
{
	void	*mlx;
	void	*mlx_win;

	mlx = param->menu->mlx->mlx;
	mlx_win = param->menu->mlx->mlx_win;
	close_win(param, mlx, mlx_win);
	exit(EXIT_SUCCESS);
	return (1);
}

int	close_menu_start(t_param *param)
{
	mlx_destroy_window(param->menu->mlx->mlx, param->menu->mlx->mlx_win);
	mlx_destroy_display(param->menu->mlx->mlx);
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

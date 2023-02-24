/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_menu_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 02:10:20 by syluiset          #+#    #+#             */
/*   Updated: 2023/02/24 16:42:36 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	free_menu(t_menu *menu)
{
	free_texture(menu->menu[0], menu->mlx->mlx);
	free_texture(menu->menu[1], menu->mlx->mlx);
	mlx_destroy_display(menu->mlx->mlx);
	free(menu->mlx->mlx);
	free(menu->mlx);
	free(menu);
}

int	close_menu_exit(t_param *param)
{
	// mlx_destroy_window(param->menu->mlx->mlx, param->menu->mlx->mlx_win);
	// mlx_destroy_display(param->menu->mlx->mlx);
	// free(param->menu->mlx->mlx);
	close_win(param, param->menu->mlx->mlx, param->menu->mlx->mlx_win);
	exit(EXIT_SUCCESS);
	return (1);
}

int	close_menu_start(t_param *param)
{
	mlx_destroy_window(param->menu->mlx->mlx, param->menu->mlx->mlx_win);
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

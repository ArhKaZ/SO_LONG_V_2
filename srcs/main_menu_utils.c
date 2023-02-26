/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_menu_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 02:10:20 by syluiset          #+#    #+#             */
/*   Updated: 2023/02/26 12:55:45 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	free_menu(t_menu *menu)
{
	free(menu->menu[0]->p);
	free(menu->menu[0]->size);
	free(menu->menu[1]->p);
	free(menu->menu[1]->size);
	free(menu);
}

int	close_menu_exit(t_param *param)
{
	close_win(param, param->mlx->mlx, param->mlx->mlx_win);
	return (1);
}

int	close_menu_start(t_param *param)
{
	mlx_destroy_window(param->mlx->mlx, param->mlx->mlx_win);
	//mlx_destroy_display(param->mlx->mlx);
	//so_long(param);
	param->mlx->menu = false;
	return (1);
}

// int	close_menu(t_param *param)
// {
// 	mlx_destroy_window(param->mlx->mlx, param->mlx->mlx_win);
// 	mlx_destroy_display(param->mlx->mlx);
// 	free(param->mlx->mlx);
// 	return (1);
// }

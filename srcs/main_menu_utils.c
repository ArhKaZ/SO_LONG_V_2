/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_menu_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 02:10:20 by syluiset          #+#    #+#             */
/*   Updated: 2023/02/26 14:28:15 by syluiset         ###   ########.fr       */
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

int	close_menu_start(t_param *p)
{
	t_mlx	*mlx;

	mlx = create_empty_mlx();
	mlx_destroy_window(p->mlx->mlx, p->mlx->mlx_win);
	ft_printf("%p\n", p->mlx->mlx_win);
	// mlx_destroy_display(p->mlx->mlx);
	//p->mlx->mlx = mlx_init();
	mlx->mlx = p->mlx->mlx;
	mlx->menu = false;
	mlx->mlx_win = mlx_new_window(p->mlx->mlx, p->map->width * 64,
				p->map->height * 64, "SO_LONG");
	ft_printf("%p\n", mlx->mlx_win);
	free(p->mlx);
	p->mlx = mlx;
	create_visu(p->map, p->mlx, p->player->coor, p->textures);
	return (1);
}

// int	close_menu(t_param *param)
// {
// 	mlx_destroy_window(param->mlx->mlx, param->mlx->mlx_win);
// 	mlx_destroy_display(param->mlx->mlx);
// 	free(param->mlx->mlx);
// 	return (1);
// }

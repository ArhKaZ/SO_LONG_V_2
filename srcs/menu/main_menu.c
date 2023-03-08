/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_menu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 15:45:56 by syluiset          #+#    #+#             */
/*   Updated: 2023/03/08 13:15:13 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

t_mlx	*create_mlx_menu(void)
{
	t_mlx	*mlx;

	mlx = create_empty_mlx();
	if (mlx == NULL)
		return (NULL);
	mlx->mlx = mlx_init();
	if (mlx->mlx == NULL)
	{
		free(mlx);
		return (NULL);
	}
	mlx->mlx_win = mlx_new_window(mlx->mlx, 800, 800, "SO_LONG");
	if (mlx->mlx_win == NULL)
	{
		mlx_destroy_display(mlx->mlx);
		free(mlx->mlx);
		free(mlx);
		return (NULL);
	}
	return (mlx);
}

void	free_param(t_param *param)
{
	free_map(param->map);
	free_player(param->player);
	free_ennemy(param->boss);
	free_textures(param->textures, param->mlx->mlx);
}

t_menu	*create_t_menu(void)
{
	t_menu		*menu;

	menu = malloc(sizeof(t_menu));
	if (!menu)
		return (NULL);
	menu->mlx = create_mlx_menu();
	if (menu->mlx == NULL)
	{
		free(menu);
		return (NULL);
	}
	menu->menu[0] = create_texture("xpm/menu/menu_start.xpm", menu->mlx);
	menu->menu[1] = create_texture("xpm/menu/menu_command.xpm", menu->mlx);
	menu->menu[2] = create_texture("xpm/menu/menu_exit.xpm", menu->mlx);
	menu->menu[3] = create_texture("xpm/menu/command.xpm", menu->mlx);
	menu->select = 0;
	return (menu);
}

int	main_menu(t_param *param)
{
	t_gps	*place;

	param->menu = create_t_menu();
	if (param->menu == NULL)
	{
		free_param(param);
		exit(EXIT_FAILURE);
	}
	place = create_gps(0, 0);
	if (!place)
		free_error_main_menu(param, param->menu->mlx);
	put_image(param->menu->mlx, param->menu->menu[0]->p, place);
	free(place);
	mlx_hook(param->menu->mlx->mlx_win, 17, 1L >> 0, &close_win, param);
	mlx_hook(param->menu->mlx->mlx_win, 2, 1L >> 0, &move_in_menu, param);
	mlx_loop(param->menu->mlx->mlx);
	return (1);
}

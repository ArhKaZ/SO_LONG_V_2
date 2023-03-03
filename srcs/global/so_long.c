/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:18:21 by syluiset          #+#    #+#             */
/*   Updated: 2023/03/03 17:10:32 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	close_with_cross_run(t_param *param)
{
	close_win(param, param->mlx->mlx, param->mlx->mlx_win);
	return (1);
}

t_param	*get_param(char **argv)
{
	t_map			*map;
	t_player		*player;
	t_all_texture	*all_texture;
	t_param			*param;
	t_mlx			*mlx;

	mlx = create_empty_mlx();
	map = create_empty_map();
	player = create_empty_player();
	if (get_map(argv[1], map) == false || checking_map(map) == false)
		return (free_error(map, player, mlx), NULL);
	mlx->mlx = mlx_init();
	mlx->menu = true;
	all_texture = create_all_texture(mlx, map->width, map->height);
	if (all_texture == NULL)
	{
		free_error(map, player, mlx);
		return (ft_putstr_fd("Error\ncan't load texture\n", 2),
			exit(EXIT_FAILURE), NULL);
	}
	param = create_param(map, mlx, player, all_texture);
	if (map->nb_ennemy > 0)
		param->boss = get_ennemy(map);
	return (param);
}

int	so_long(t_param *p)
{
	mlx_loop_hook(p->mlx->mlx, &animation, p);
	mlx_hook(p->mlx->mlx_win, 2, 1L >> 0, &render_next_frame, p);
	mlx_hook(p->mlx->mlx_win, 17, 1L >> 0, &close_with_cross_run, p);
	mlx_loop(p->mlx->mlx);
	return (0);
}

int	main(int argc, char **argv)
{
	t_param		*param;

	if (argc == 2)
	{
		if (check_extension(argv[1]) == false)
			return (0);
		param = get_param(argv);
		if (param == NULL)
			return (0);
		if (map_is_finishable(param->map) == false)
			free_error_non_finish(param);
		main_menu(param);
	}
	return (0);
}
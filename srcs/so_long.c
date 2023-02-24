/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:18:21 by syluiset          #+#    #+#             */
/*   Updated: 2023/02/24 17:48:24 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	free_error(t_map *map, t_player *player, t_mlx *mlx)
{
	free_map(map);
	free_player(player);
	free(mlx);
}

void	free_all(t_param *param)
{
	free_map(param->map);
	free_player(param->player);
	free_textures(param->textures, param->mlx->mlx);
	free_ennemy(param->boss);
	free_menu(param->menu);
	free(param->mlx);
	param->mlx = NULL;
	free(param);
	param = NULL;
}

t_param	*get_param(char **argv)
{
	t_map			*map;
	t_player		*player;
	t_all_texture	*all_texture;
	t_param			*param;
	t_mlx			*mlx;
	t_mlx			*mlx_menu;

	mlx = create_empty_mlx();
	mlx = create_empty_mlx();
	map = create_empty_map();
	player = create_empty_player();
	if (get_map(argv[1], map) == false || checking_map(map) == false)
		return (free_error(map, player, mlx), NULL);
	mlx->mlx = mlx_init();
	mlx_menu->mlx = mlx_init();
	mlx_menu->mlx_win = mlx_new_window(mlx->mlx, 800, 800, "SO_LONG");
	all_texture = create_all_texture(mlx, map->width, map->height);
	if (all_texture == NULL)
		return (ft_putstr_fd("Error\ncan't load texture\n", 2),
			exit(EXIT_FAILURE), NULL);
	param = create_param(map, mlx, player, all_texture);
	param->menu_mlx = mlx_menu;
	if (map->nb_ennemy > 0)
		param->boss = get_ennemy(map);
	return (param);
}

int	so_long(t_param *p)
{
	p->mlx->mlx_win = mlx_new_window(p->mlx->mlx, p->map->width * 64,
			p->map->height * 64, "SO_LONG");
	create_visu(p->map, p->mlx, p->player->coor, p->textures);
	mlx_loop_hook(p->mlx->mlx, &animation, p);
	mlx_hook(p->mlx->mlx_win, 17, 1L >> 0, &close_win, p);
	mlx_hook(p->mlx->mlx_win, 2, 1L >> 0, &render_next_frame, p);
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
			close_win(param, param->mlx->mlx, param->mlx->mlx_win);
		main_menu(param);
	}
	return (0);
}

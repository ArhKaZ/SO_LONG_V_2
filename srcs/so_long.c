/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:18:21 by syluiset          #+#    #+#             */
/*   Updated: 2023/02/14 17:09:55 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	free_error(t_map *map, t_player *player)
{
	free_map(map);
	free_player(player);
}

int		map_test(t_param *param)
{
	if (map_is_finishable(param->map) == false)
	{
		free_all(param);
		return (0);
	}
	return (1);
}

void	print_map(char **map)
{
	int i;

	i = 0;
	while (map[i] != NULL)
	{
		ft_printf("%s\n", map[i]);
		i++;
	}
}

t_param	*get_param(char **argv)
{
	t_map			*map;
	t_mlx			*mlx;
	t_player		*player;
	t_all_texture	*all_texture;
	t_param			*param;

	map = create_empty_map();
	player = create_empty_player();
	mlx = create_empty_mlx();
	if (get_map(argv[1], map) == false)
		return (0);
	if (checking_map(map) == false)
	{
		free_error(map, player);
		return (0);
	}
	mlx->mlx = mlx_init();
	mlx->mlx_win = mlx_new_window(mlx->mlx, map->width * 64, map->height * 64, "SO_LONG"); // 1920 par 1024
	all_texture = create_all_texture(mlx);
	if (all_texture == NULL)
		return (ft_putstr_fd("Error with texture\n", 2), exit(EXIT_FAILURE), NULL);
	create_visu(map, mlx, player->coor, all_texture);
	param = create_param(map, mlx, player, all_texture);
	if (map->nb_ennemy > 0)
		param->boss = get_ennemy(map);
	return (param);
}

int main(int argc, char **argv)
{
	t_param		*param;

	if (argc == 2)
	{
		if (check_extension(argv[1]) == false)
			return (0);
		param = get_param(argv);
		if (map_test(param) == 0)
			return (0);
		mlx_loop_hook(param->mlx->mlx, &animation, param);
		mlx_hook(param->mlx->mlx_win, 17, 1L >> 0, &close_win, param);
		mlx_hook(param->mlx->mlx_win, 2, 1L >> 0, &render_next_frame, param);
		mlx_loop(param->mlx->mlx);
	 }
}

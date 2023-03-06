/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:18:21 by syluiset          #+#    #+#             */
/*   Updated: 2023/03/06 14:21:54 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	close_with_cross_run(t_param *param)
{
	close_win(param, param->mlx->mlx, param->mlx->mlx_win);
	return (1);
}

void	get_ennemy_in_param(t_param *param)
{
	t_map	*map;

	map = param->map;
	if (map->nb_ennemy > 0)
	{
		param->boss = get_ennemy(map);
		if (param->boss == NULL)
		{
			ft_putstr_fd("Error\nEnnemy alloc as a problem\n", 2);
			close_with_cross_run(param);
		}
	}
}

t_param	*get_param(char **argv)
{
	t_all_texture	*all_texture;
	t_param			*p;

	p = create_param();
	if (!p)
	{
		ft_putstr_fd("Error\nParam alloc problem", 2);
		free_error(p);
		return (NULL);
	}
	if (get_map(argv[1], p->map) == false || checking_map(p->map) == false)
		return (free_error(p), NULL);
	p->mlx->mlx = mlx_init();
	if (p->mlx->mlx == NULL)
		return (free_error(p), NULL);
	p->mlx->menu = true;
	all_texture = create_all_texture(p->mlx, p->map->width, p->map->height);
	if (all_texture == NULL)
	{
		return (free_error(p), ft_putstr_fd("Error\ncan't load texture\n", 2),
			exit(EXIT_FAILURE), NULL);
	}
	p->textures = all_texture;
	get_ennemy_in_param(p);
	return (p);
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

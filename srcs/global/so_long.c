/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:18:21 by syluiset          #+#    #+#             */
/*   Updated: 2023/03/09 10:57:06 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

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

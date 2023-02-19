/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:22:07 by syluiset          #+#    #+#             */
/*   Updated: 2023/02/19 22:45:46 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../mlx_linux/mlx.h"
# include "../Libft_w_a/libft.h"
# include <stdbool.h>
# include <fcntl.h>

//!bonus
#include <unistd.h>
#include <time.h>
//!bonus

typedef struct s_mlx
{
	void	*mlx;
	void	*mlx_win;
}				t_mlx;

typedef struct s_gps
{
	int	y;
	int	x;
}				t_gps;

typedef struct s_player
{
	t_gps			*coor;
	int				collect;
	int				moves;
	int				hp;
	int				direction;
	unsigned int	score;
}				t_player;

typedef struct s_ennemy
{
	t_gps	*coor;
	struct s_ennemy	*next;
}				t_ennemy;

typedef struct s_texture
{
	void	*p;
	t_gps	*size;
	char	*addr;
	char	*path;
	int		bits_per_pixel;
	int		line_len;
	int		endian;
}				t_texture;

typedef struct s_coins
{
	t_texture	*frame1;
	t_texture	*frame2;
	t_texture	*frame3;
	t_texture	*frame4;
	t_texture	*frame5;
	t_texture	*frame6;
	t_texture	*frame7;
	t_texture	*frame8;
	t_texture	*frame9;
	t_texture	*frame10;
	t_texture	*frame11;
	t_texture	*frame12;
	t_texture	*frame13;
	t_texture	*frame14;
	t_texture	*frame15;
	int			frame_act;
}					t_coins;

typedef struct s_hp
{
	t_texture	*full;
	t_texture	*empty;
}				t_hp;

typedef struct s_black_hole
{
	t_texture	*frame1;
	t_texture	*frame2;
	t_texture	*frame3;
	t_texture	*frame4;
	t_texture	*frame5;
	t_texture	*frame6;
	t_texture	*frame7;
	t_texture	*frame8;
	t_texture	*frame9;
	int			frame_act;
}				t_black_hole;

typedef	struct s_sprite_boss
{
	t_texture	*boss_top;
	t_texture	*boss_left;
	t_texture	*boss_right;
	t_texture	*boss_bottom;
}				t_sprite_boss;

typedef struct s_sprite_player
{
	t_texture	*player_top;
	t_texture	*player_bottom;
	t_texture	*player_right;
	t_texture	*player_left;
}				t_sprite_player;

typedef	struct s_explode
{
	t_texture	*frame1;
	t_texture	*frame2;
	t_texture	*planet_explosion;
	t_texture	*boss_explosion1;
	t_texture	*boss_explosion2;
	t_texture	*boss_explosion3;
}				t_explode;

typedef	struct s_sprite_planet
{
	t_texture	*planet_1;
	t_texture	*planet_2;
	t_texture	*planet_3;
	t_texture	*planet_4;
	t_texture	*planet_exp;
}				t_sprite_planet;

typedef struct s_shoot_texture
{
	t_texture	*frame1_left;
	t_texture	*frame1_top;
	t_texture	*frame1_right;
	t_texture	*frame1_bot;
	t_texture	*frame2_left;
	t_texture	*frame2_top;
	t_texture	*frame2_right;
	t_texture	*frame2_bot;
	t_texture	*frame3_left;
	t_texture	*frame3_top;
	t_texture	*frame3_right;
	t_texture	*frame3_bot;
	t_texture	*frame4_left;
	t_texture	*frame4_top;
	t_texture	*frame4_right;
	t_texture	*frame4_bot;
	int			frame_act;
}				t_shoot_texture;

typedef struct s_shoot
{
	t_gps 			*coor;
	int 			direction;
	clock_t			shoot_time;
}				t_shoot;

typedef struct s_go
{
	t_texture	*little;
	t_texture	*medium;
	t_texture	*big;
}				t_go;

typedef struct s_end
{
	t_texture	*little;
	t_texture	*medium;
	t_texture	*big;
}				t_end;

typedef struct s_nb
{
	t_texture	*zero;
	t_texture	*one;
	t_texture	*two;
	t_texture	*three;
	t_texture	*four;
	t_texture	*five;
	t_texture	*six;
	t_texture	*seven;
	t_texture	*eight;
	t_texture	*nine;
}				t_nb;

// typedef struct s_all_nb
// {
// 	t_nb	*little;
// 	t_nb	*medium;
// 	t_nb	*big;
// }				t_all_nb;

typedef struct s_all_texture
{
	t_texture			*wall;
	t_texture			*background;
	t_coins				*coin;
	t_sprite_player		*player;
	t_sprite_boss		*ennemy;
	t_black_hole		*black_hole;
	t_black_hole		*black_hole_close;
	t_hp				*hp;
	t_go				*game_over;
	t_end				*end;
	t_explode			*explode;
	t_sprite_planet		*planets;
	t_shoot_texture		*shoot;
	t_nb			*nb;
}				t_all_texture;

typedef	struct s_map
{
	int	nb_empty;
	int	nb_wall;
	int	nb_item;
	int	nb_ennemy;
	t_gps	*coor_exit;
	int		nb_shot;
	int	exit;
	int	begin;
	char	**map;
	int	height;
	int	width;
}				t_map;

typedef struct s_param
{
	t_map			*map;
	t_mlx			*mlx;
	t_player 		*player;
	t_all_texture	*textures;
	t_ennemy		*boss;
	t_shoot			*shots;
	int				finish;
}				t_param;

bool	check_extension(char *path);

void	print_map(char **map);

t_map	*create_empty_map(void);

t_gps	*create_empty_gps(void);

t_player	*create_empty_player(void);

t_mlx	*create_empty_mlx(void);

t_param		*create_param(t_map *map, t_mlx *mlx, t_player *player, t_all_texture *all_texture);

void	try_go_wall(char **map_cp, t_gps *coor, t_map *map, int direction);

bool	change_to_x(t_map *map, char **map_cp, int x, int y);

char	*get_map_to_string(char *path, t_map *map);

bool	get_map(char *path, t_map *map);

bool	checking_map(t_map *map);

void	create_visu(t_map *map, t_mlx *mlx, t_gps *player, t_all_texture *all_texture);

int		render_next_frame(int keycode, t_param *param);

t_all_texture	*create_all_texture(t_mlx *mlx, int width, int height);

void	free_all(t_param *param);

void	free_player(t_player *player);

void	free_map(t_map *map);

void	put_strings(t_param *param);

void	put_move(t_map *map, t_mlx *mlx, t_player *player, t_all_texture *textures);

void	put_score(t_map *map, t_mlx *mlx, t_player *player, t_all_texture *textures);

int		get_random(int nb_max);

bool	map_is_finishable(t_map *map);

void	free_char_map(char **map);

int		close_win(t_param *param, void *mlx, void *mlx_win);

void	put_coins(t_map *map, void *mlx, void *mlx_win, t_texture *coin);

void	move_left(t_param *param);

void	move_right(t_param *param);

void	move_top(t_param *param);

void	move_bottom(t_param *param);

int		move_exit(t_param *param, t_gps *new, int move);

void	move_player_sprite(t_param *param, t_gps *new, int direction);

void	move_player(t_map *map, t_player *player, t_gps *new);

void	move_coins(t_param *param, t_gps *new, int direction);

void	not_move_player_sprite(t_param *param, int direction);

void	free_texture(t_texture *text, void *mlx);

void	free_textures(t_all_texture *texts, void *mlx);

bool	put_shot_in_coor(t_param *param, t_gps *new);

int		game_win(t_param *param);

int		put_frame_for_coin(t_param *param);

int		put_exit_animate(t_param *param);

int		get_random(int nb_max);

int	move_ennemy_left(t_param *param, t_gps *ennemy);

int	move_ennemy_right(t_param *param, t_gps *ennemy);

int	move_ennemy_top(t_param *param, t_gps *ennemy);

int	move_ennemy_bottom(t_param *param, t_gps *ennemy);

t_ennemy	*get_ennemy(t_map *map);

int		choose_direction(t_param *param);

void	move_to_boss(t_param *param, int direction);

void	not_move_ennemy_sprite(t_param *param, int direction);

void	less_hp(t_param *param, int direction);

void	put_hp(t_map *map, t_mlx *mlx, t_player *player, t_all_texture *text);

int	game_over(t_param *param);

int	animation(t_param *param);

void	put_image(t_mlx *mlx, void *sprite, t_gps *new, int plus);

void	del_ennemy(t_param *param, t_gps *coor);

clock_t	shooting(t_param *param);

int	animate_shoot(t_param *param, t_gps *coor);

int	shoot_exist(t_param *param);

void	create_new_shot(t_param *param);

void	del_shot(t_param *param);

int animate_shoot(t_param *param, t_gps *coor);

t_ennemy	*clear_ennemy(t_ennemy *ennemy);

void	free_ennemy(t_ennemy *boss);

int		is_end(t_param *param);

void	free_black_hole(t_black_hole *bh, void *mlx);

t_texture	*create_texture(char *path, t_mlx *mlx);
#endif

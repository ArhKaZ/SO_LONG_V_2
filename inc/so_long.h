/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:22:07 by syluiset          #+#    #+#             */
/*   Updated: 2023/03/09 10:57:56 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../mlx_linux/mlx.h"
# include "../Libft_w_a/libft.h"
# include <stdbool.h>
# include <fcntl.h>
# include <unistd.h>
# include <time.h>
# define UP 119
# define DOWN 115
# define ESC 65307
# define LEFT 97
# define RIGHT 100
# define CROSS_UP 65362
# define CROSS_DOWN 65364
# define ENTER 65293
# define SPACE 32

typedef struct s_mlx
{
	void	*mlx;
	void	*mlx_win;
	bool	menu;
}				t_mlx;

typedef struct s_gps
{
	int	y;
	int	x;
}				t_gps;

typedef struct s_player
{
	t_gps	*coor;
	int		collect;
	int		moves;
	int		hp;
	int		direction;
	int		score;
}				t_player;

typedef struct s_ennemy
{
	t_gps			*coor;
	int				direction;
	struct s_ennemy	*next;
}				t_ennemy;

typedef struct s_texture
{
	void	*p;
	t_gps	*size;
}				t_texture;

typedef struct s_coins
{
	t_texture	*coins[15];
	int			frame_act;
}					t_coins;

typedef struct s_hp
{
	t_texture	*full;
	t_texture	*empty;
}				t_hp;

typedef struct s_black_hole
{
	t_texture	*bh[9];
	int			frame_act;
}				t_black_hole;

typedef struct s_sprite_back
{
	t_texture	*back[2];
}				t_sprite_back;

typedef struct s_ship
{
	t_texture	*player[4];
	t_texture	*ennemy[4];
}				t_ship;

typedef struct s_explosion
{
	t_texture	*ennemy_ex[3];
	int			frame_act_e;
	int			frame_act_p;
}					t_explosion;

typedef struct s_sprite_planet
{
	t_texture	*planets[4];
	t_texture	*planet_exp;
}				t_sprite_planet;

typedef struct s_shoot_texture
{
	t_texture	*s_left[4];
	t_texture	*s_right[4];
	t_texture	*s_bot[4];
	t_texture	*s_top[4];
	int			frame_act;
}				t_shoot_texture;

typedef struct s_shoot
{
	t_gps		*coor;
	int			direction;
	clock_t		shoot_time;
}				t_shoot;

typedef struct s_end
{
	t_texture	*w_little;
	t_texture	*w_med;
	t_texture	*w_big;
	t_texture	*l_little;
	t_texture	*l_med;
	t_texture	*l_big;
}				t_end;

typedef struct s_nb
{
	t_texture	*nb[10];
}				t_nb;

typedef struct s_all_text
{
	t_texture			*wall;
	t_sprite_back		*back;
	t_coins				*coin;
	t_ship				*ships;
	t_black_hole		*black_hole;
	t_black_hole		*black_hole_close;
	t_hp				*hp;
	t_end				*end;
	t_explosion			*explosion;
	t_sprite_planet		*planets;
	t_shoot_texture		*shoot;
	t_nb				*nb;
}				t_all_text;

typedef struct s_map
{
	int		nb_empty;
	int		nb_wall;
	int		nb_item;
	int		nb_ennemy;
	t_gps	*coor_exit;
	int		nb_shot;
	int		exit;
	int		begin;
	char	**map;
	int		height;
	int		width;
}				t_map;

typedef struct s_menu
{
	t_texture	*menu[4];
	t_mlx		*mlx;
	int			select;
}				t_menu;

typedef struct s_param
{
	t_map			*map;
	t_mlx			*mlx;
	t_menu			*menu;
	t_player		*player;
	t_all_text		*textures;
	t_ennemy		*boss;
	t_shoot			*shots;
	int				finish;
	clock_t			time;
}				t_param;

bool			check_extension(char *path);

t_map			*create_empty_map(void);

t_gps			*create_gps(int x, int y);

t_player		*create_empty_player(void);

t_mlx			*create_empty_mlx(void);

t_param			*create_param(void);

void			try_go_wall(char **map_cp, t_gps *coor, t_map *map, int dir);

char			*get_map_to_string(char *path);

bool			get_map(char *path, t_map *map);

bool			checking_map(t_map *map);

bool			create_visu(t_map *m, t_mlx *mx, t_gps *p, t_all_text *texts);

int				render_next_frame(int keycode, t_param *param);

t_all_text		*create_all_texture(t_mlx *mlx, int width, int height);

void			free_all(t_param *param);

void			free_player(t_player *player);

void			free_map(t_map *map);

void			free_back(t_sprite_back *back, void *mlx);

void			free_hp(t_hp *hp, void *mlx);

void			free_black_hole(t_black_hole *bh, void *mlx);

void			free_ships_sprite(t_ship *ships, void *mlx);

void			free_coin(t_coins *text, void *mlx);

void			put_strings(t_param *param);

void			put_move(t_param *param);

void			put_score(t_param *param);

int				get_random(int nb_max);

bool			map_is_finishable(t_map *map);

void			free_char_map(char **map);

int				close_win(t_param *param, void *mlx, void *mlx_win);

bool			put_coins(t_map *map, t_mlx *mlx, t_texture *coin);

void			move_left(t_param *param);

void			move_right(t_param *param);

void			move_top(t_param *param);

void			move_bottom(t_param *param);

int				move_exit(t_param *param, t_gps *new, int move);

void			move_player_sprite(t_param *param, t_gps *new, int direction);

void			move_player(t_map *map, t_player *player, t_gps *new);

void			move_coins(t_param *param, t_gps *new, int direction);

void			not_move_player_sprite(t_param *param, int direction);

void			free_texture(t_texture *text, void *mlx);

void			free_textures(t_all_text *texts, void *mlx);

bool			put_shot_in_coor(t_param *param, t_gps *new);

int				put_frame_for_coin(t_param *param);

void			move_ennemy_left(t_param *param, t_gps *ennemy);

void			move_ennemy_right(t_param *param, t_gps *ennemy);

void			move_ennemy_top(t_param *param, t_gps *ennemy);

void			move_ennemy_bottom(t_param *param, t_gps *ennemy);

t_ennemy		*get_ennemy(t_map *map);

bool			check_line_empty(char *s);

void			free_error_main_menu(t_param *param, t_mlx *mlx);

void			choose_direction(t_param *param);

void			move_to_boss(t_param *param, int direction);

void			not_move_ennemy_sprite(t_param *param, int direction);

void			less_hp(t_param *param, int direction);

void			put_hp(t_param *param, t_hp *hp);

int				animation(t_param *param);

void			put_image(t_mlx *mlx, void *sprite, t_gps *new);

void			del_ennemy(t_param *param, t_gps *coor);

clock_t			shooting(t_param *param);

int				animate_shoot(t_param *param, t_gps *coor);

int				shoot_exist(t_param *param);

void			create_new_shot(t_param *param);

void			del_shot(t_param *param, t_shoot *shot);

void			free_ennemy(t_ennemy *boss);

void			free_error(t_param *param);

void			free_error_non_finish(t_param *param);

int				is_end(t_param *param);

void			free_black_hole(t_black_hole *bh, void *mlx);

t_texture		*create_texture(char *path, t_mlx *mlx);

t_explosion		*create_ex_sprite(t_mlx *mlx);

void			ex_for_dir(t_param *p, t_explosion *ex, t_mlx *mlx, int dir);

void			free_explosion(t_explosion *ex, void *mlx);

void			move_ennemy(t_param *param, int random);

void			move_ennemy_to_coin(t_param *param, t_gps *new, int direction);

void			move_ennemy_sprite(t_param *param, t_gps *new, int direction);

bool			put_wall_col(t_map *map, t_mlx *mlx, t_texture *wall);

bool			put_wall_line(t_map *map, t_mlx *mlx, t_texture *wall);

bool			put_background(t_map *map, t_mlx *mlx, t_texture *back[2]);

bool			put_obstacle(t_map *map, t_mlx *mlx, t_sprite_planet *texts);

void			change_exit(t_param *param);

t_nb			*create_nb(t_mlx *mlx, int width, int height);

t_black_hole	*create_black_hole_for_end(t_mlx *mlx);

t_sprite_back	*create_back(t_mlx *mlx);

t_black_hole	*create_black_hole(t_mlx *mlx);

t_coins			*create_collectible(t_mlx *mlx);

t_shoot_texture	*create_shoot_sprite(t_mlx *mlx);

void			put_image_xy(t_mlx *mlx, void *sprite, t_gps *coor);

void			free_shoot(t_shoot_texture *s, void *mlx);

void			free_nb(t_nb *nb, void *mlx);

void			free_end_and_go(t_end *end, void *mlx);

void			free_planets(t_sprite_planet *p, void *mlx);

void			put_last_image(t_param *p, t_gps *place, t_texture *s, int sz);

bool			check_char(char c);

bool			check_line(char **map, t_map *map_s);

bool			get_next_line_loop(int fd, char **line_pt);

void			add_to_map(t_map *map, char c);

int				main_menu(t_param *param);

int				so_long(t_param *param);

void			free_menu(t_menu *menu);

int				close_menu(t_param *param);

int				close_menu_start(t_param *p, void *m_m, void *m_w, void *mlx);

int				close_menu_exit(t_param *p, void *m_m, void *m_w, void *mlx);

t_gps			*get_next_coor_s(int direction, t_gps *coor);

void			put_shoot_in_direction(t_param *param, t_gps *new);

void			kill_ennemy(t_param *param, t_gps *new);

void			make_explosion(t_param *p, t_gps *new, t_shoot *s, int just_c);

t_shoot			*create_shot(clock_t time, int direction, t_gps *player);

int				move_in_menu(int keycode, t_param *param);

char			**checker_map(t_map *map, char **map_cp);

void			change_to_x(t_map *map, char **map_cp, int x, int y);

void			*get_sprite_obstacle(t_sprite_planet *texts);

void			*get_sprite_back(t_sprite_back *texts);

void			put_image_player(t_mlx *mlx, t_texture *sprite, t_gps *coor);

bool			verif_texture(t_all_text *texts);

void			verif_ship(t_ship *ship);

void			verif_collectible(t_coins *c);

void			verif_black_hole(t_black_hole *bh);

void			verif_shot(t_shoot_texture *s);

void			verif_planets(t_sprite_planet *pl);

void			verif_end(t_end *end);

void			verif_nb(t_nb *nb);

void			verif_explosion(t_explosion *ex);

t_param			*get_param(char **argv);

int				close_with_cross_run(t_param *param);
#endif

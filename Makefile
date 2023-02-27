#============================= FILES PART =====================================
SRCS			=	visual/animation.c				\
					visual/animation_shot.c		\
					actions/create_and_destroy.c	\
					visual/create_visu.c			\
					visual/create_visu_utils.c		\
					actions/ennemy.c				\
					visual/free_textures.c			\
					visual/free_textures_two.c		\
					visual/free_utils.c			\
					visual/game_end.c				\
					visual/game_end_utils.c		\
					map/get_map.c				\
					map/get_map_utils.c			\
					visual/hud.c					\
					menu/main_menu_utils.c		\
					menu/main_menu.c				\
					map/map.c					\
					map/map_error.c				\
					actions/move_ennemy.c			\
					actions/move_ennemy_utils.c		\
					actions/player_action.c			\
					actions/player_action_utils.c	\
					actions/player_damage.c			\
					visual/put_image.c				\
					actions/rand.c					\
					shot/shoot.c					\
					shot/shoot_utils.c			\
					shot/shoot_create_and_moves.c\
					actions/so_long.c				\
					map/test_map.c				\
					map/test_map_utils.c		\
					visual/texture.c				\
					visual/texture_animate.c		\
					visual/texture_explosion.c		\
					visual/texture_nb.c			\

SRCS_MAP		=	map/create_map.c	 \
					map/create_map_ennemy.c \

SRCS_D			=	srcs/

OBJS			=	$(SRCS:%.c=$(OBJS_D)%.o)

OBJS_MAP		=	$(SRCS_MAP:%.c=$(OBJS_D)%.o)

OBJS_D			=	obj/

HEAD			=	so_long.h

HEAD_MAP		=	map.h

HEAD_D			=	inc/

NAME			=	so_long

NAME_MAP		=	gen_map

LIBFT_D			=	Libft_w_a/

LIBFT_A			=	Libft_w_a/libft.a

LIBFT_H			=	Libft_w_a/libft.h
UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S),Linux)
	MLX_D	=	mlx_linux/

	MLX_A	=	mlx_linux/libmlx.a
endif

ifeq ($(UNAME_S),Darwin)
	MLX_D	=	minilibx/

	MLX_A	=	minilibx/libmlx.a
endif

#==============================================================================

#============================= BASH COMMAND ===================================
CC				=	cc

GCC				=	gcc

CCFLAG			=	-Wall -Werror -Wextra

FSA				=	-fsanitize=address -g3

RM				=	rm -f -r

ifeq ($(UNAME_S),Linux)
	MLXFLAG = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

	MLXFLAGO = -I/usr/include -Imlx_linux -O3 -g3
endif

ifeq ($(UNAME_S),Darwin)
	MLXFLAG = -framework OpenGL -framework AppKit
endif

MAKE			=	make

MAKEALL			=	make all

MAKEFC			=	make fclean
#==============================================================================

#============================= MK COMMAND =====================================
ifeq ($(UNAME_S), Linux)
$(NAME)			:	$(OBJS_D) $(OBJS) $(HEAD_D)$(HEAD)
				$(CC) $(CCFLAG) -o $(NAME) $(OBJS) $(LIBFT_A) $(MLX_A) $(MLXFLAG)

$(OBJS)			:	$(OBJS_D)%.o: $(SRCS_D)%.c $(HEAD_D)$(HEAD) $(MLX_A) $(LIBFT_A)
				$(CC) $(CCFLAG) -I$(HEAD_D) -I$(LIBFT_D) -I$(MLX_D) $(MLXFLAGO) -c $< -o $@
endif

ifeq ($(UNAME_S), Darwin)
$(NAME)			:	$(OBJS_D) $(OBJS) $(HEAD_D)$(HEAD)
				$(CC) $(CCFLAG) -o $(NAME) $(OBJS) $(LIBFT_A) $(MLX_A) $(MLXFLAG)

$(OBJS)			:	$(OBJS_D)%.o: $(SRCS_D)%.c $(HEAD_D)$(HEAD) $(MLX_A) $(LIBFT_A)
				$(CC) $(CCFLAG) -I$(HEAD_D)$(HEAD) -I$(LIBFT_D) -I$(MLX_D) -c $< -o $@
endif

map				:	$(OBJS_D) $(OBJS) $(OBJS_MAP) $(HEAD_D)$(HEAD_MAP)
				$(CC) $(CCFLAG) -o $(NAME_MAP) $(OBJS_MAP) $(LIBFT_A)

$(OBJS_MAP)		:	$(OBJS_D)%.o: %.c $(HEAD_D)$(HEAD_MAP) $(LIBFT_A)
				$(CC) $(CCFLAG) -I$(HEAD_D) -I$(LIBFT_D) -c $< -o $@

$(OBJS_D)		:
				mkdir -p $(OBJS_D)

$(MLX_A)		:	FORCE $(MLX_D)
				make -j -C $(MLX_D) 2>/dev/null >/dev/null

FORCE			:

fsanitize		:	$(MLX_A) $(LIBFT_A) $(OBJS_D) $(HEAD_D)$(HEAD) $(OBJS)
				$(CC) $(CCFLAG) $(FSA) -o $(NAME) $(OBJS) $(LIBFT_A) $(MLX_A) $(MLXFLAG)

all				: $(HEAD) $(NAME)

$(LIBFT_A)			:
				make -C $(LIBFT_D)

clean			:
				$(RM) $(OBJS) $(OBJS_D)

cleanlibext		:
				make fclean -C $(LIBFT_D)
				make clean -C $(MLX_D)

fclean			:	clean cleanlibext
				$(RM) $(NAME) $(NAME_MAP)

re				:	fclean $(NAME)

refs			:	fclean fsanitize

.PHONY			:	all clean fclean re
#==============================================================================

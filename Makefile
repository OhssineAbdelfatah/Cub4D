CC = cc 

CFLAGS = -Wall -Werror -Wextra #-fsanitize=address -g

LIBMLX = lib/mlx

######### FOR NEW MLX
MLXFLAGS_LINK = $(LIBMLX)/build/libmlx42.a -L /Users/ilaasri/.brew/Cellar/glfw/3.4/lib/ -lglfw -pthread -lm 
# MLXFLAGS_LINK = $(LIBMLX)/build/libmlx42.a -L /goinfre/aohssine/homebrew/Cellar/glfw/3.4/lib/ -lglfw -pthread -lm 
############################################


GNL = lib/gnl/get_next_line.c lib/gnl/get_next_line_utils.c

CONSTRUCTORS = mandatory/constructors/constructors.c mandatory/constructors/constructors_2.c 


GAME_FILES = mandatory/game/hooks_nd_loops.c mandatory/game/casting_tools_2.c  mandatory/game/casting.c mandatory/game/casting_tools.c  mandatory/game/tools_2.c\
			mandatory/game/tools.c mandatory/game/walls_rendering.c mandatory/game/rays.c \
			mandatory/game/player_move_hooks.c\
			mandatory/game/player_move.c \
			mandatory/game/game.c

CLEANING = mandatory/cleaning_nd_freeing/freedom.c mandatory/cleaning_nd_freeing/freedom_part2.c \
			mandatory/cleaning_nd_freeing/freedom_part3.c

TEXTURES	= mandatory/game/texture.c



CLEANING_B = bonus/cleaning_nd_freeing/freedom_bonus.c bonus/cleaning_nd_freeing/freedom_part2_bonus.c \
			bonus/cleaning_nd_freeing/freedom_part3_bonus.c

TEXTURES_B	= bonus/game/texture_bonus.c bonus/game/door_bonus.c		


BONUS_FILES = 	bonus/game/draw_mini_map_pro_bonus.c bonus/game/bonus.c \
				bonus/game/drawing_things_bonus.c bonus/game/floor_ceilling_bonus.c \
				bonus/game/shooting_animation_bonus.c

GAME_FILES_B = bonus/game/hooks_nd_loops_bonus.c bonus/game/casting_tools_2_bonus.c  bonus/game/casting_bonus.c bonus/game/casting_tools_bonus.c  bonus/game/tools_2_bonus.c\
			bonus/game/tools_bonus.c bonus/game/walls_rendering_bonus.c bonus/game/rays_bonus.c \
			bonus/game/drawing_bonus.c bonus/game/player_move_hooks_bonus.c\
			bonus/game/player_move_bonus.c \
			bonus/game/game_bonus.c


PARSING = 	mandatory/parsing/cub.c     mandatory/parsing/infos_utils2.c mandatory/parsing/infos_utils3.c \
			mandatory/parsing/map_check.c	\
			mandatory/parsing/infos_parse.c  mandatory/parsing/list_init.c    mandatory/parsing/map_parse.c	\
			mandatory/parsing/valid_map.c    mandatory/parsing/infos_utils.c  mandatory/parsing/list_utils.c	\
			mandatory/parsing/safe_func.c    mandatory/parsing/infos_parse2.c

ENEMIES_OBJ = bonus/obj_enemies/obj_tools_bonus.c bonus/obj_enemies/obj_bonus.c\
				bonus/obj_enemies/enemies_tools_bonus.c\
				bonus/obj_enemies/enemies_tools_part2_bonus.c\
				bonus/obj_enemies/enemies_bonus.c


CONSTRUCTORS_B = bonus/constructors/constructors0_bonus.c bonus/constructors/constructors_2_bonus.c \
				bonus/constructors/constructors_bonus.c bonus/constructors/constructors_tools_bonus.c\
				bonus/constructors/constructors_tools2_bonus.c\
				bonus/constructors/constructors_tools3_bonus.c


PARSING_B = bonus/parsing_bonus/cub_bonus.c     bonus/parsing_bonus/infos_utils2_bonus.c bonus/parsing_bonus/infos_utils3_bonus.c \
			bonus/parsing_bonus/map_check_bonus.c\
			bonus/parsing_bonus/infos_parse_bonus.c  bonus/parsing_bonus/list_init_bonus.c    bonus/parsing_bonus/map_parse_bonus.c	\
			bonus/parsing_bonus/valid_map_bonus.c    bonus/parsing_bonus/infos_utils_bonus.c  bonus/parsing_bonus/list_utils_bonus.c	\
			bonus/parsing_bonus/safe_func_bonus.c     bonus/parsing_bonus/map_tools_bonus.c\
			bonus/parsing_bonus/infos_parse2_bonus.c

MANDATORY = ${PARSING} ${GNL} ${TEXTURES} ${GAME_FILES} ${CONSTRUCTORS} ${CLEANING} mandatory/main.c 

BONUS = ${PARSING_B} ${GNL} ${TEXTURES_B} ${ENEMIES_OBJ} ${GAME_FILES_B} ${BONUS_FILES} ${CONSTRUCTORS_B} ${CLEANING_B} bonus/main_bonus.c

OBJ = $(MANDATORY:.c=.o)
OBJB = $(BONUS:.c=.o)


NC=\033[0m
RED=\033[0;31m
LGREY=\033[0;37m

CUB4D = "${RED}\n" \
"░█▀▀░█░█░█▀▄░█░█░█▀▄\n"\
"░█░░░█░█░█▀▄░░▀█░█░█\n"\
"░▀▀▀░▀▀▀░▀▀░░░░▀░▀▀░\n"\
"\n"\
"      by TILLAS & Nol-Yel \n"\
"${NC}"

NAME = cub3D
NAMEB = cub3D_bonus

My_lib = lib/libft/libft.a
Folder_lib = lib/libft/

HEADERS = mandatory/includes/game_structs.h mandatory/includes/macros.h mandatory/includes/norm_structs.h mandatory/includes/parsing.h mandatory/includes/ps.h 
HEADERS_B = bonus/includes/game_structs_bonus.h bonus/includes/macros_bonus.h bonus/includes/norm_structs_bonus.h bonus/includes/parsing_bonus.h bonus/includes/ps_bonus.h 

all : ASCII_ART $(My_lib) $(NAME) 

bonus :$(My_lib) $(NAMEB)

%.o : %.c  Makefile ${HEADERS} ${HEADERS_B}
	$(CC)  $(CFLAGS) $(FFLAG)   -c  $< -o $@

$(My_lib) : 
	make -C ${Folder_lib}

$(NAME) : $(OBJ) $(My_lib) 
	$(CC) $^ $(CFLAGS) $(My_lib) $(MLXFLAGS_LINK)  -o $@

$(NAMEB) : $(OBJB) $(My_lib) 
	$(CC) $^ $(CFLAGS) $(My_lib) $(MLXFLAGS_LINK)  -o $@

ASCII_ART :
	@echo $(CUB4D)

clean :
	make clean -C ${Folder_lib}
	rm -rf  $(OBJ) $(OBJB)

fclean : clean
	make fclean -C ${Folder_lib}
	rm -rf $(NAME) $(NAMEB)

re : fclean all

.PHONY : all clean fclean re bonus

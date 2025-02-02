CC = cc 

CFLAGS = -Wall -Werror -Wextra #-fsanitize=address -g
# -fsanitize=address -g

LIBMLX = ../lib/mlx

#######################################
# FOR LINUX :
# MLXFLAGS_OBJ = -Imlx_linux
# MLXFLAGS_LINK = -Lmlx -lmlx -L/usr/lib -lXext -lX11 -lm -lz
########################################  


#########################################
# FOR MAC :
##########FOR OLD MLX
# MLXFLAGS_OBJ = -Imlx
# MLXFLAGS_LINK = -L. -lmlx -framework OpenGL -framework AppKit

######### FOR NEW MLX
# MLXFLAGS_LINK = $(LIBMLX)/build/libmlx42.a -L /Users/ilaasri/.brew/Cellar/glfw/3.4/lib/ -lglfw -pthread -lm 
MLXFLAGS_LINK = $(LIBMLX)/build/libmlx42.a -L /goinfre/aohssine/homebrew/Cellar/glfw/3.4/lib/ -lglfw -pthread -lm 
############################################


ASCII_ART = "\033[31m\n"\
"                    (      \n"\
"             )     ))\ )   \n"\
"       (  ( /(  ( /(()/(   \n"\
"  (   ))\ )\()) )\())(_))  \n"\
"  )\ /((_|(_)\ ((_)(_))_   \n"\
" ((_|_))(| |(_)__ (_)   \  \n"\
"/ _|| || | '_ \|_ \ | |) | \n"\
"\__| \_,_|_.__/___/ |___/  \n"\
"  \033[0m "                          

GNL = ../lib/gnl/get_next_line.c ../lib/gnl/get_next_line_utils.c

BONUS_FILES = game/drawing_things_bonus.c game/enemies_bonus.c  game/floor_ceilling_bonus.c

GAME_FILES = game/hooks_nd_loops.c game/casting.c game/tools.c game/walls_rendering.c game/rays.c \
			game/drawing.c game/draw_minimap.c game/draw_mini_map_pro.c game/bonus.c \
			game/constructors.c game/constructors_bonus.c game/freedom.c\
			game/obj_bonus.c \
			game/game.c

TEXTURES	= game/texture.c 		

PARSING = 	parsing/cub.c          parsing/infos_utils2.c parsing/infos_utils3.c \
			parsing/map_check.c	\
			parsing/infos_parse.c  parsing/list_init.c    parsing/map_parse.c	\
			parsing/valid_map.c    parsing/infos_utils.c  parsing/list_utils.c	\
			parsing/safe_func.c    parsing/main.c parsing/test.c
			
CFILES = ${PARSING} ${GNL} ${TEXTURES} ${GAME_FILES} ${BONUS_FILES} main.c

OBJ = $(CFILES:.c=.o)
NAME = cub3D

My_lib = ../lib/libft/libft.a
Folder_lib = ../lib/libft/

all : $(My_lib) $(NAME)

%.o : %.c  Makefile ${HEADERS}
	$(CC)  $(CFLAGS) $(FFLAG)   -c  $< -o $@

$(My_lib) : 
	make -C ${Folder_lib}

$(NAME) : $(OBJ) $(My_lib) 
	$(CC) $^ $(CFLAGS) $(My_lib) $(MLXFLAGS_LINK)  -o $@

clean :
	make clean -C ${Folder_lib}
	rm -rf $(OBJ)

fclean : clean
	make fclean -C ${Folder_lib}
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
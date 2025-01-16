CC = cc 

CFLAGS = #-Wall -Werror -Wextra #-fsanitize=address -g




#######################################
# FOR LINUX :
MLXFLAGS_OBJ = -Imlx_linux
MLXFLAGS_LINK = -Lmlx -lmlx -L/usr/lib -lXext -lX11 -lm -lz
########################################  


#########################################
# FOR MAC :
# MLXFLAGS_OBJ = -Imlx
# MLXFLAGS_LINK = -L. -lmlx -framework OpenGL -framework AppKit
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

GNL = lib/gnl/get_next_line.c lib/gnl/get_next_line_utils.c

GAME_FILES = game/hooks_nd_loops.c game/casting.c game/tools.c game/walls_rendering.c game/rays.c \
			 game/drawing.c game/draw_minimap.c game/constructors.c game/main.c
			 

PARSING = 	parsing/cub.c          parsing/infos_utils2.c parsing/map_check.c	\
			parsing/infos_parse.c  parsing/list_init.c    parsing/map_parse.c	\
			parsing/valid_map.c    parsing/infos_utils.c  parsing/list_utils.c	\
			parsing/safe_func.c    parsing/main.c #test.c
			
CFILES = ${PARSING} ${GNL} ${GAME_FILES} main.c
 
OBJ = $(CFILES:.c=.o)
NAME = cub3D

My_lib = lib/libft/libft.a

all : $(My_lib) $(NAME)

%.o : %.c  Makefile ${HEADERS}
	$(CC)  $(CFLAGS) $(FFLAG)  $(MLXFLAGS_OBJ) -c  $< -o $@

$(My_lib) : 
	make -C lib/libft

$(NAME) : $(OBJ) $(My_lib) 
	$(CC) $^ $(CFLAGS) $(My_lib) $(MLXFLAGS_LINK)  -o $@

clean :
	make clean -C lib/libft
	rm -rf $(OBJ)

fclean : clean
	make fclean -C lib/libft
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
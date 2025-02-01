CC = cc 

CFLAGS = -Wall -Werror -Wextra #-fsanitize=address -g




#######################################
# FOR LINUX :
# MLXFLAGS_OBJ = -Imlx_linux
# MLXFLAGS_LINK = -Lmlx_linux -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz
########################################  


#########################################
# FOR MAC :
MLXFLAGS_OBJ = -Imlx
MLXFLAGS_LINK = -L. -lmlx -framework OpenGL -framework AppKit
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

# GAME_FILES = game/hooks_nd_loops.c game/casting.c game/tools.c game/walls_rendering.c game/rays.c \
# 			 game/drawing.c game/draw_minimap.c game/constructors.c game/main.c
			 

PARSING = 	cub.c          infos_utils2.c map_check.c	\
			infos_parse.c  list_init.c    map_parse.c	\
			valid_map.c    infos_utils.c  list_utils.c	\
			safe_func.c    main.c test.c
			
CFILES = ${PARSING} ${GNL}  main.c
 
OBJ = $(CFILES:.c=.o)
NAME = cub3D

My_lib = ../lib/libft/libft.a
FOLDER_LIBFT = ../lib/libft

all : $(My_lib) $(NAME)

%.o : %.c  Makefile ${HEADERS}
	$(CC)  $(CFLAGS) $(FFLAG)  -c  $< -o $@

$(My_lib) : 
	make -C $(FOLDER_LIBFT)

$(NAME) : $(OBJ) $(My_lib) 
	$(CC) $^ $(CFLAGS) $(My_lib)  -o $@

clean :
	make clean -C $(FOLDER_LIBFT)
	rm -rf $(OBJ)

fclean : clean
	make fclean -C $(FOLDER_LIBFT)
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
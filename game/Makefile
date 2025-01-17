CC = cc 

CFLAGS = -Wall -Werror -Wextra #-fsanitize=address

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

# MLXFLAGS_OBJ = -I/usr/include -Imlx_linux -O3

# MLXFLAGS_LINK = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

GNL = ../gnl/get_next_line/get_next_line.c ../gnl/get_next_line/get_next_line_utils.c

# PARSING = parsing/parse.c parsing/map.c parsing/map_list.c

CFILES =  	draw_mini_map_pro.c hooks_nd_loops.c casting.c tools.c walls_rendering.c rays.c drawing.c draw_minimap.c \
			 constructors.c  main.c   ${GNL}

OBJ = $(CFILES:.c=.o)

NAME = cub3D

My_lib = ../lib/libft/libft.a

all : ascii_art $(My_lib) $(NAME) 

%.o : %.c  Makefile ${HEADERS}
	$(CC)  $(CFLAGS) $(FFLAG)  $(MLXFLAGS_OBJ) -c  $< -o $@

$(My_lib) : 
	make -C ../lib/libft

$(NAME) : $(OBJ) $(My_lib) 
	$(CC) $^ $(CFLAGS)  $(My_lib) $(MLXFLAGS_LINK)  -o $@

clean :
	make clean -C ../lib/libft
	rm -rf $(OBJ)

fclean : clean
	make fclean -C ../lib/libft
	rm -rf $(NAME)

re : fclean all

ascii_art :
	@echo $(ASCII_ART)

.PHONY : all clean fclean re
CC = cc 

CFLAGS = -Wall -Werror -Wextra #-fsanitize=address

GNL = lib/gnl/get_next_line.c lib/gnl/get_next_line_utils.c


PARSING = 	parsing/cub.c          parsing/infos_utils2.c parsing/map_check.c\
			parsing/infos_parse.c  parsing/list_init.c    parsing/map_parse.c    parsing/valid_map.c\
			parsing/infos_utils.c  parsing/list_utils.c   parsing/test.c\
			parsing/safe_func.c
CFILES = ${PARSING} ${GNL}

OBJ = $(CFILES:.c=.o)
NAME = cub3D

My_lib = lib/libft/libft.a

all : $(My_lib) $(NAME)

%.o : %.c  Makefile ${HEADERS}
	$(CC)  $(CFLAGS) $(FFLAG)  $(RLINCLUDE) -c  $< -o $@

$(My_lib) : 
	make -C lib/libft

$(NAME) : $(OBJ) $(My_lib) 
	$(CC) $^ $(CFLAGS) $(My_lib) $(RLFLAGS)  -o $@

clean :
	make clean -C lib/libft
	rm -rf $(OBJ)

fclean : clean
	make fclean -C lib/libft
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
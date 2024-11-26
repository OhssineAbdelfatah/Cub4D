CC = cc 

CFLAGS = -Wall -Werror -Wextra #-fsanitize=address

GNL = lib/gnl/get_next_line.c lib/gnl/get_next_line_utils.c

PARSING = parsing/parse.c parsing/map.c parsing/map_list.c parsing/map_arr.c

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
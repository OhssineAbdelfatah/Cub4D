CC = cc
CFLAGS = -Werror -Wextra -Wall 
SRC = ft_putnbr_fd.c ft_putendl_fd.c ft_putstr_fd.c ft_putchar_fd.c ft_striteri.c ft_strmapi.c \
	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
	ft_isascii.c ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c \
	ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c ft_strdup.c \
	ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c \
	ft_strrchr.c ft_substr.c ft_tolower.c ft_toupper.c ft_strjoin.c \
	ft_strtrim.c ft_split.c ft_itoa.c  free_split.c  ft_strslen.c ft_strcmp.c \
	ft_strndup.c ft_strcpy.c ft_strcat.c

SRCB = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
	ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
	ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

OBJ = $(SRC:.c=.o) 
OBJB = $(SRCB:.c=.o) 
NAME = libft.a

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

bonus : $(NAME) $(OBJB) 
	ar rcs $^

%.o : %.c libft.h 
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -rf $(OBJ) $(OBJB)
	
fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : clean
	

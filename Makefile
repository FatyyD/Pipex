NAME = pipex

CC = gcc

CFLAGS = -Wall -Wextra -Werror
SRC = pipex.c/
	  pipex_utils.c/
	  pipex_splits.c/
	  pipex_erreur.c
	
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME) : $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)
	 
%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean :
	rm -rf $(OBJ)

fclean: clean 
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
NAME = so_long

HEADER = so_long.h

SRC =   put_assets.c\
		get_next_line.c\
		get_next_line_utils.c\
		check_map.c\
		print_errors.c\
		parse_map.c\
		moves.c\
		so_long.c\
		utils.c\
                                        

OBJ = ${SRC:.c=.o}

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ)  -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -Imlx -c $<

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all
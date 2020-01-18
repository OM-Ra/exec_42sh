NAME = 42sh

C_FILE = check_choice.c run_ampersant.c check_run.c run_pipe.c create_file.c \
		 run_exec.c dup_fd_and_close.c new_or_open_file.c redirect_stream.c \
		 main.c

LIB = ./libft/libft.a

HED = -I ./include

FILE_C = $(addprefix ./src/, $(C_FILE))

FILE_O = $(C_FILE:.c=.o)

GCC_O = gcc -c $(FILE_C) $(LIB) $(HED)

GCC = gcc -o $(NAME) $(FILE_O) $(LIB) $(HED)

all: $(NAME)

$(NAME):
	$(GCC_O)
	$(GCC)

clean:
	rm -f $(FILE_O)

fclean: clean
	rm -f $(NAME)

re: fclean all

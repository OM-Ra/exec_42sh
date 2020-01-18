#ifndef SH42_H
# define SH42_H

# include <stdio.h>
// # include <unistd.h> // есть в либе
# include <fcntl.h>
# include <stdlib.h>
// # include <string.h> // есть в либе
# include <sys/ioctl.h>
// # include <sys/ttycom.h>
# include <limits.h>
// # include <stdlib.h> // есть в либе
# include "libft.h"
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

int exec_status;
// структура для перенаправления потоков
typedef struct			s_red_stream
{
	int					stream_a;						// какой поток будет перенаправлен
	int					stream_in;						// в какой поток будет перенаправлен
	char				stream_name[BUFSIZ];			// в какой файл будет направлен поток

	struct s_red_stream	*next;
}						t_red_stream;

typedef struct			s_pars_list
{
	char				name_func[BUFSIZ];				// имя запускаемой программы
	char				name_run_func[BUFSIZ];			// имя запускаемой программы с путём запуска
	char				**pars_args;					// разбитые аргументы строки 
	int					status;							// статус завершения вызванной программы (заполню)

	int					flag_file;						// флаг файла: ">" = "1", ">>" = "2", "<" = "-1"
	char				name_file[BUFSIZ];				// имя запускаемого файла либо амперсанд с номером дескриптора: &fd

	t_red_stream		*stream_list;					// для перенаправления потоков

	int					echo_status;					// флаг заполнения статуса
	char				str_status[BUFSIZ][BUFSIZ];		// строки в которых нужно вставить статус

	int					flag_ampersant;					// флаг "&"
	int					nbr_ampersant;					// номер фонового режима
	char				name_ampersant_file[BUFSIZ];	// имя файла куда будет записан вывод фонового режима (заполню)

	int					flag_pipe;						// флаг "|"
	int					flag_semicolon;					// флаг ";"
	int					flag_and;						// флаг "&&"
	int					flag_or;						// флаг "||"

	struct s_pars_list	*right;
	struct s_pars_list	*left;
}						t_pars_list;

void					check_choice(t_pars_list **list);
int						check_run(t_pars_list **list);
int						create_file(t_pars_list *list);
int						dup_fd_and_close(int fd, int dup_fd);
int						run_ampersant(t_pars_list **list);
void					run_exec(int fd, t_pars_list *list);
int						run_pipe(int fd_stdin, t_pars_list **list);
int						new_or_open_file(char *file_name, int flag_open);
int						redirect_stream(t_red_stream *stream_list);

int						main(void);

/***
 Используемые функции:
 fork()
 execve()
 open()
 close()
 waitpid()
 pipe()
 dup2()
 exit()

 	Из либы:
 	ft_putstr_fd()
 	ft_putchar_fd()
***/

#endif

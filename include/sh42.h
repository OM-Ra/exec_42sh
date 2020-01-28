#ifndef SH42_H
# define SH42_H

// # include <stdlib.h> // есть в либе
// # include <unistd.h> // есть в либе
// # include <string.h> // есть в либе
// # include <sys/ttycom.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/ioctl.h>
# include <limits.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
# include "libft.h"

static int exec_status;									// хранит статус последнего завершения команды
// структура для труб
typedef struct			s_pipe_list
{
	int 				pfd[2];							// дескрипторы труб
	struct s_pipe_list	*right;
	struct s_pipe_list	*left;
}						t_pipe_list;
// структура для перенаправления потоков
typedef struct			s_red_stream
{
	int					stream_a;						// какой поток будет перенаправлен
	int					stream_in;						// в какой поток будет перенаправлен
	char				stream_name[BUFSIZ];			// в какой файл будет направлен поток
	int					fd_file;						// дескриптор открытого файла (по умолчанию -1, будет заполнено в exec)
	int					flag_file;						// флаг файла: ">" = "1", ">>" = "2", "<" = "-1" (по умолчанию 0)
	int					flag_close;						// флаг о закрытии дескриптора (по умолчанию 0)
	
	struct s_red_stream	*next;
}						t_red_stream;

typedef struct			s_pars_list
{
	char				name_func[BUFSIZ];				// имя запускаемой программы
	char				name_run_func[BUFSIZ];			// имя запускаемой программы с путём запуска
	char				*pars_args[BUFSIZ];				// разбитые аргументы строки 
	int					status;							// статус завершения вызванной программы (заполню)

	t_red_stream		*stream_list;					// структура для перенаправления потоков

	int					echo_status;					// флаг заполнения статуса
	char				str_status[BUFSIZ][BUFSIZ];		// строки в которых нужно вставить статус

	int					flag_ampersant;					// флаг "&"
	int					nbr_ampersant;					// номер фонового режима

	int					flag_pipe;						// флаг "|"
	int					flag_semicolon;					// флаг ";"
	int					flag_and;						// флаг "&&"
	int					flag_or;						// флаг "||"

	struct s_pars_list	*right;
	struct s_pars_list	*left;
}						t_pars_list;
/*
** exec function
*/
void					check_choice(t_pars_list **list);
int						check_run(t_pars_list **list);
int						stream_and_file(t_pars_list *list);
int						create_file(t_red_stream *stream_list);
int						redirect_stream(t_red_stream *stream_list);
int						dup_fd_and_close(int fd, int dup_fd);
int						run_ampersant(t_pars_list **list);
void					run_exec(int fd, t_pars_list *list);
void					run_pipe(t_pipe_list *pipelist, t_pars_list **list);
int						new_or_open_file(char *file_name, int flag_open);
t_pars_list				*free_pars_list(t_pars_list *list);
t_pipe_list				*new_pipe_list(t_pipe_list *pipelist);
void 					free_pipe_list(t_pipe_list *pipelist);
/*
** parsing function
*/
t_pars_list				*pars_new_list(t_pars_list *list);
char					*pars_read(void);
t_pars_list				*pars_parsing(char *line);
/*
** test function
*/
t_pars_list				*test(void);
int						main(void);

/***
 Используемые функции:
 fork()
 execve()
 acsses()
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

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


typedef struct			s_pars_list
{
	char				name_run_func[BUFSIZ];			// имя запускаемой программы
	char				**pars_args;					// разбитые аргументы строки 
	int					status;							// статус завершения вызванной программы (заполню)

	int					flag_file;						// флаг файла: ">" = "1", ">>" = "2", "<" = "-1"
	char				name_file[BUFSIZ];				// имя запускаемого файла либо амперсанд с номером дескриптора: &fd

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
void					dup_fd_and_close(int fd, int dup_fd);
int						run_ampersant(t_pars_list **list);
void					run_exec(int fd, t_pars_list *list);
int						run_pipe(int fd_stdin, t_pars_list **list);
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

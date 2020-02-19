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
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include "libft.h"

# define EXEC_ERROR_NUM 432
/**
*** константы для флагов разделителей команд
**/
# define F_SEMICOLON	1		// флаг ";"
# define F_AND			2		// флаг "&&"
# define F_OR			4		// флаг "||"
# define F_AMPERSANT	8		// флаг "&"
# define F_PIPE			16		// флаг "|"
# define V_STATUS		32		// фдаг $?
# define V_LASTPID		64		// флаг $$
# define V_WRITE_VAR	128		// флаг того, что нужно заполнять переменные

typedef struct			s_term_var
{
	char 				*path_term;							// храниет адрес терминала
	int 				exec_status;						// хранит статус последней запущеной команды
	pid_t				pid_last;							// хранит pid последней запущеной команды
}						t_term_var;

/////////// просто для определения
typedef struct			s_start_env
{
	char	shlvl[BUFSIZ];
	char	term[BUFSIZ];
	char	shell[BUFSIZ];
	char	pwd[BUFSIZ];
	char	old_pwd[BUFSIZ];
	char	path[BUFSIZ];
	char	home[BUFSIZ];
	char	user[BUFSIZ];
}						t_start_env;

// интерфейс
typedef struct			s_exec_lst
{
	t_start_env			exec_envlist;
}						t_exec_lst;

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
	int					stream_a;						// какой поток будет перенаправлен или закрыт, при соответствующем флаге
	int					stream_in;						// в какой поток будет перенаправлен
	char				stream_name[BUFSIZ];			// в какой файл будет направлен поток
	int					fd_file;						// дескриптор открытого файла (по умолчанию -1, будет заполнено в exec)
	int					flag_file;						// флаг файла: ">" = "1", ">>" = "2", "<" = "-1" (по умолчанию 0)
	int					flag_close;						// флаг о закрытии дескриптора (по умолчанию 0)
	int 				save_std;						// запоминает дублированный дескриптор стандартного вывода (по умолчанию -1)

	struct s_red_stream	*next;
	struct s_red_stream	*left;
}						t_red_stream;
///// структура для старых тестов
//typedef struct			s_pars_list
//{
//	char				name_func[BUFSIZ];				// имя запускаемой программы
//	char				name_run_func[BUFSIZ];			// имя запускаемой программы с путём запуска
//	char				*pars_args[BUFSIZ];				// разбитые аргументы строки
//	int					status;							// статус завершения вызванной программы (заполню)
//
//	t_red_stream		*stream_list;					// структура для перенаправления потоков
//
//	int					echo_status;					// флаг заполнения статуса
//	char				**str_status;					// строки в которых нужно вставить статус
//
//	int					flag_ampersant;					// флаг "&"
//	int					nbr_ampersant;					// номер фонового режима
//
//	int					flag_pipe;						// флаг "|"
//	int					flag_semicolon;					// флаг ";"
//	int					flag_and;						// флаг "&&"
//	int					flag_or;						// флаг "||"
//
//	struct s_pars_list	*right;
//	struct s_pars_list	*left;
//}						t_pars_list;

typedef struct			s_pars_list
{
	char				*name_func;						// имя запускаемой программы
	char				name_run_func[BUFSIZ];			// имя запускаемой программы с путём запуска
	char				**pars_args;					// разбитые аргументы строки
	int					status;							// статус завершения вызванной программы (заполню)
	pid_t				pid;

	t_red_stream		*stream_list;					// структура для перенаправления потоков

	int 				f_delimiter;					// флаг разделителей команд

	unsigned short		nbr_ampersant;

	char				**str_status;					// строки в которых нужно вставить статус
	char 				**str_lastpid;

	struct s_pars_list	*right;
	struct s_pars_list	*left;
}						t_pars_list;

static t_term_var		term_lst;
/*
** exec function
*/
void					check_choice(t_exec_lst execlist, t_pars_list **list);
int						check_run(t_exec_lst execlist, t_pars_list **list);
int						stream_and_file(t_pars_list *list);
int						create_file(t_red_stream *stream_list);
int						redirect_stream(t_red_stream *stream_list);
int						dup_fd_and_close(int fd, int dup_fd);
int						run_ampersant(t_exec_lst execlist, t_pars_list **list);
void					run_exec(t_exec_lst execlist, int fd, t_pars_list *list);
void					run_pipe(t_exec_lst execlist, t_pipe_list **pipelist, t_pars_list **list);
int						new_or_open_file(char *file_name, int flag_open);
t_pars_list				*free_pars_list(t_pars_list *list);
t_pipe_list				*new_pipe_list(t_pipe_list *pipelist);
void 					free_pipe_list(t_pipe_list *pipelist);
int						stream_close_fd(t_red_stream *stream_list);
void					error_system(int status);
void					stream_save_std(t_red_stream *stream_list);
void					close_and_open_std(t_red_stream *stream_list);
int						write_this_dir(t_pars_list *list);
/*
** parsing
*/
int 					pars_run_cmd(t_exec_lst execlist, char **arg_cmd, char *str);
void					pars_find_run_name(t_exec_lst execlist, char *name_cmd, char *buf_name_cmd);

char					*pars_write_args(t_pars_list *list, char *mainline, char *end);
char 					*pars_fill_args(t_pars_list *list, char *pointstr,  char *end);
/*
** comands
*/
int						check_cmd(char *name_func);
int						run_cmd(t_pars_list *list);
int						cmd_true(t_pars_list *list);
int						cmd_false(t_pars_list *list);
void 					cmd_check_var(t_pars_list *list);
/*
** comands delete (заглушка)
*/
int						minishell_env(int argc, char **argv, char **env);
int						ftsh_cd(int argc, char **argv, char **env);
int						ftsh_echo(int argc, char **argv, char **env);
int						ftsh_pwd(int argc, char *argv[], char *env[]);
int						ftsh_setenv(const char *name, const char *value, const int replace);
int						ftsh_unsetenv(const char *name);
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
void					test_put_100fd(void);

/***
 Используемые функции:
 fork()					- error_exit
 malloc()				- error_exit
 open()
 execve()
 acsses()
 close()
 waitpid()
 pipe()
 dup2()
 exit()

 	Из либы:
 	ft_putstr_fd()
 	ft_putchar_fd()
 	ft_strcmp()
 	ft_itoa()
***/

#endif

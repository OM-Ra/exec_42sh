/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_pipe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 11:43:00 by mdelphia          #+#    #+#             */
/*   Updated: 2019/12/10 11:43:03 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh42.h"
// функция для вывода всех дескрипторов
static void 	put_all_fd(t_pipe_list *pipelist, int fd)
{
	t_pipe_list *buf_list;

	buf_list = pipelist;
	dprintf(fd, "экз: %d:", pipelist->num_rec);
	while (buf_list->left)
		buf_list = buf_list->left;
	while (buf_list)
	{
		dprintf(fd, " >>> %d-чтение %d-запись", buf_list->pfd[0], buf_list->pfd[1]);
		buf_list = buf_list->right;
	}
	dprintf(fd, "\n");
}
// закрывает все дескрипторы трубы от заданного листа включительно
static void		close_all_fd(t_pipe_list *pipeList, int fd)
{
	t_pipe_list *buf_pipelist;

	buf_pipelist = pipeList;
	while (buf_pipelist)
	{
		close(buf_pipelist->pfd[0]);
		close(buf_pipelist->pfd[1]);
		dprintf(fd, "экз: %d: закрывает дескрипторы %d - чтение  %d- запись\n",buf_pipelist->num_rec, buf_pipelist->pfd[0], buf_pipelist->pfd[1]);
		buf_pipelist = buf_pipelist->left;
	}
}
// закрывает ненужные дескрипторы трубы
static void		close_pipe_fd(t_pipe_list *pipelist, int fd)
{
	t_pipe_list	*buf_pipelist;

	buf_pipelist = pipelist->left;
	if (buf_pipelist)
		{close(buf_pipelist->pfd[1]); dprintf(fd, "экз: %d: закрыл дескриптор %d - запись\n", buf_pipelist->num_rec, buf_pipelist->pfd[1]);}
	else
		return ;
	buf_pipelist = buf_pipelist->left; dprintf(fd, "экз: %d: заходит в закрытие всех оставшихся дескрипторов\n", pipelist->num_rec);
	close_all_fd(buf_pipelist, fd);
}
// рекурсивно запускает трубы
void			run_pipe(t_pipe_list *pipelist, t_pars_list **list)
{
	pid_t		pid;
	t_pars_list	*buf_list;
	t_pipe_list	*buf_pipelist;
	static int			fd;

	if (!fd)
		fd = new_or_open_file("/home/ra/Документы/42sh/test_pipe", 2);
	pipelist = new_pipe_list(pipelist); dprintf(fd, "создание листа %d\n", pipelist->num_rec);
	if (pipelist->num_rec)
		pipe(pipelist->pfd); dprintf(fd, "экз: %d: труба %d-чтение %d-запись\n", pipelist->num_rec, pipelist->pfd[0], pipelist->pfd[1]);
	buf_list = (*list);
	if((pid = fork()) < 0)
		exit(1);		////// сделать нормальное завершение
	if (!pid)
	{
		dprintf(fd, "экз: %d: зашёл в потомка\n", pipelist->num_rec); put_all_fd(pipelist, fd);
		buf_pipelist = pipelist->left;
		if (buf_list->flag_pipe)
			{dup_fd_and_close(pipelist->pfd[1], STDOUT_FILENO); dprintf(fd, "экз: %d: перенаправление потока для %d - запись\n", pipelist->num_rec, pipelist->pfd[1]);}
		else
			{close(pipelist->pfd[1]); dprintf(fd, "экз: %d: закрыл дескриптор %d - запись вместо перенаправления\n", pipelist->num_rec, pipelist->pfd[1]);}
		close(pipelist->pfd[0]); dprintf(fd, "экз: %d: закрыл %d - чтение\n", pipelist->num_rec, pipelist->pfd[0]);
		dprintf(fd, "экз: %d: заходит в закрытие дескрипторов\n", pipelist->num_rec);
		close_pipe_fd(pipelist, fd);
		create_file(buf_list);dprintf(fd, "экз: %d: exec\n", pipelist->num_rec);
		run_exec(buf_pipelist->pfd[0], buf_list);
	}
	dprintf(fd, "экз: %d: зашёл в родителя\n", pipelist->num_rec); put_all_fd(pipelist, fd);
	if ((buf_list->right) && (buf_list->flag_pipe))
	{
		dprintf(fd, "экз: %d: рекурся\n", pipelist->num_rec);
		(*list) = (*list)->right;
		run_pipe(pipelist, list);
	} dprintf(fd, "экз: %d: заходит в закрытие всех дескрипторов\n", pipelist->num_rec);
	close_all_fd(pipelist, fd);
	dprintf(fd, "экз: %d: ждёт\n", pipelist->num_rec);
	waitpid(pid, &buf_list->status, WUNTRACED);
}

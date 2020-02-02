/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_ampersant.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 11:42:36 by mdelphia          #+#    #+#             */
/*   Updated: 2019/12/10 11:42:38 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh42.h"
// вывод номера запускаемого фонового режима
static void	put_nbr_ampersant(char *str_nbr_ampersant)
{
	ft_putchar('[');
	ft_putstr(str_nbr_ampersant);
	ft_putstr("]\t");
	ft_putstr(ft_itoa(getpid()));
	ft_putchar('\n');
}
// вывод названия команд
static void	put_name_func(t_pars_list *buf_list, int check_nbr_ampersand)
{
	while (buf_list->nbr_ampersant == check_nbr_ampersand)
	{
		if (!buf_list->status)
			ft_putstr(buf_list->name_func);
		else
		{
			ft_putstr("\n\t\t\texit ");
			ft_putnbr(buf_list->status);
			ft_putchar('\t');
			ft_putstr(buf_list->name_func);
		}
		buf_list = buf_list->right;
		if (buf_list->nbr_ampersant == check_nbr_ampersand)
			ft_putstr(" | ");
	}
	ft_putchar('\n');
}
// вывод завершения выполнения команд в фоновом режиме
static void	put_end_ampersant(t_pars_list *buf_list, char *str_nbr_ampersant)
{
	ft_putchar('[');
	ft_putstr(str_nbr_ampersant);
	ft_putstr("] done\t");
	put_name_func(buf_list, buf_list->nbr_ampersant);
}
// запуск фонового режима
int			run_ampersant(t_exec execlist, t_pars_list **list)
{
	pid_t		pid;
	char		str_nbr_ampersant[BUFSIZ];
	t_pars_list	*buf_list;

	buf_list = *list;
	if (!(pid = fork()))
	{
		// setsid();				// чтобы сделать полного демона
		if (!(pid = fork()))
		{
			ft_strcat(str_nbr_ampersant, ft_itoa((*list)->nbr_ampersant));
			put_nbr_ampersant(str_nbr_ampersant);
			check_run(execlist, list);
			waitpid(pid, 0, WUNTRACED);
			put_end_ampersant(buf_list, str_nbr_ampersant);
			exit(0);
		}
		exit(0);
	}
	else if (pid > 0)
		waitpid(pid, &(*list)->status, WUNTRACED);
	return (0);
}

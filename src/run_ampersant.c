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
static void	put_nbr_ampersant(char *nbr_ampersant)
{
	ft_putchar('[');
	ft_putstr(nbr_ampersant);
	ft_putstr("]\t");
	ft_putstr(ft_itoa(getpid()));
	ft_putchar('\n');
}
// вывод завершения выполнения команд в фоновом режиме
static void	put_end_ampersant(char *nbr_ampersant) /////// дописать вывод для ошибок после завершения
{
	ft_putchar('[');
	ft_putstr(nbr_ampersant);
	ft_putstr("] done\n");
}
// запуск фонового режима
int			run_ampersant(t_pars_list **list)
{
	pid_t	pid;
	char	str_nbr_ampersant[BUFSIZ];

	if (!(pid = fork()))
	{
		if (!(pid = fork()))
		{
			ft_strcat(str_nbr_ampersant, ft_itoa((*list)->nbr_ampersant));
			put_nbr_ampersant(str_nbr_ampersant);
			check_run(list);
			waitpid(pid, 0, WUNTRACED);
			put_end_ampersant(str_nbr_ampersant);
			exit(0);
		}
		exit(0);
	}
	else if (pid > 0)
		waitpid(pid, &(*list)->status, WUNTRACED);
	return (0);
}

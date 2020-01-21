/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_choice.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 11:41:27 by mdelphia          #+#    #+#             */
/*   Updated: 2019/12/10 11:41:31 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh42.h"
// функция для промотки труб
static void	list_not_go_pipe(t_pars_list **list)
{
	if ((*list)->flag_pipe)
		while (*list)
		{
			(*list) = (*list)->right;
			if ((*list) && !(*list)->flag_pipe)
			{
				(*list) = (*list)->right;
				break ;
			}
		}
	else if ((*list)->flag_or)
		while (*list)
		{
			(*list) = (*list)->right;
			if ((*list) && !(*list)->flag_or)
			{
				(*list) = (*list)->right;
				break ;
			}
		}
}
// функция для промотки листов при успешном завершении команды
static void	status_ok(t_pars_list **list)
{
	t_pars_list *buf_list;

	while (*list)
	{
		buf_list = (*list);
		(*list) = (*list)->right;
		if ((buf_list->flag_semicolon) || (buf_list->flag_and))
			break ;
		else if (buf_list->flag_or)
			list_not_go_pipe(list);
	}	
}
// функция для промотки листов при команде завершившейся с ошибкой
static void	status_dontok(t_pars_list **list)
{
	t_pars_list *buf_list;

	while (*list)
	{
		buf_list = (*list);
		(*list) = (*list)->right;
		if ((buf_list->flag_semicolon) && (buf_list->flag_or))
			break ;
		if ((buf_list->flag_and) && ((*list)->flag_pipe))
			list_not_go_pipe(list);
	}
}
// функция для определения следующего запускаемого листа
static void	next_list(int status, t_pars_list **list)
{
	if (!status)
		status_ok(list);
	else if (status)
		status_dontok(list);
}
// проверка И / ИЛИ / & и выбор следующего запускаемого листа
void		check_choice(t_pars_list **list)
{
	int status;

	status = -1;
	while (*list)
	{
		if ((*list)->flag_ampersant)		// отдельно запускается фоновый режим выполнения команд
			status = run_ampersant(list);
		else
			status = check_run(list);		// запуск функции определения режима запускаемых команд (это могут быть трубы, или обычный режим, или внутренние команды)
		next_list(status, list);			// функция выбора следующего запускаемого листа
	}
}

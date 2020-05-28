/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_next_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 21:48:45 by mdelphia          #+#    #+#             */
/*   Updated: 2020/03/29 15:28:55 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static void	list_no_go_and(t_pars_list **list)
{
	if ((*list)->f_delimiter & F_PIPE)
		while (*list)
		{
			(*list) = (*list)->next;
			if ((*list) && !((*list)->f_delimiter & F_PIPE))
			{
				(*list) = (*list)->next;
				break ;
			}
		}
	else
		while (*list)
		{
			(*list) = (*list)->next;
			if ((*list) && !((*list)->f_delimiter & F_AND))
				break ;
		}
}

static void	list_not_go_pipe(t_pars_list **list)
{
	if ((*list)->f_delimiter & F_PIPE)
		while (*list)
		{
			(*list) = (*list)->next;
			if ((*list) && !((*list)->f_delimiter & F_PIPE))
				break ;
		}
	else if ((*list)->f_delimiter & F_OR)
		while (*list)
		{
			(*list) = (*list)->next;
			if ((*list) && !((*list)->f_delimiter & F_OR))
			{
				(*list) = (*list)->next;
				break ;
			}
		}
}

static void	status_ok(t_pars_list **list)
{
	t_pars_list *buf_list;

	while (*list)
	{
		buf_list = (*list);
		if ((buf_list->f_delimiter & F_SEMICOLON) ||
				(buf_list->f_delimiter & F_AND) ||
				(buf_list->f_delimiter & F_AMPERSANT &&
				!(buf_list->f_delimiter & F_OR)))
		{
			(*list) = (*list)->next;
			break ;
		}
		else if (buf_list->f_delimiter & F_OR)
		{
			(*list) = (*list)->next;
			list_not_go_pipe(list);
		}
		else
			(*list) = (*list)->next;
	}
}

static void	status_dontok(t_pars_list **list)
{
	t_pars_list *buf_list;

	while (*list)
	{
		buf_list = (*list);
		(*list) = (*list)->next;
		if ((buf_list->f_delimiter & F_SEMICOLON) ||
			(buf_list->f_delimiter & F_OR) ||
			(buf_list->f_delimiter & F_AMPERSANT &&
			!(buf_list->f_delimiter & F_AND)))
			break ;
		if (buf_list->f_delimiter & F_AND)
			list_no_go_and(list);
	}
}

void		exec_next_list(int status, t_pars_list **list)
{
	if (!status)
		status_ok(list);
	else
		status_dontok(list);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_pipe_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 14:01:57 by mdelphia          #+#    #+#             */
/*   Updated: 2020/02/29 21:00:07 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

t_pipe_list		*new_pipe_list(t_exec_lst *execlist, t_pipe_list *pipelist)
{
	t_pipe_list	*new_list;

	if (!(new_list = (t_pipe_list *)malloc(sizeof(t_pipe_list))))
		error_system(execlist, EXEC_ERROR_NUM);
	new_list->next = NULL;
	new_list->prev = NULL;
	new_list->pfd[0] = -1;
	new_list->pfd[1] = -1;
	if (pipelist)
	{
		pipelist->next = new_list;
		new_list->prev = pipelist;
	}
	return (new_list);
}

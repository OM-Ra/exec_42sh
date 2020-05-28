/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_pipe_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 14:00:13 by mdelphia          #+#    #+#             */
/*   Updated: 2020/02/29 21:00:07 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void		free_pipe_list(t_pipe_list *list)
{
	t_pipe_list		*buf_list;

	while (list)
	{
		buf_list = list;
		list = list->prev;
		free(buf_list);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_pipe_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 14:00:13 by mdelphia          #+#    #+#             */
/*   Updated: 2020/02/02 14:00:17 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh42.h"

void		free_pipe_list(t_pipe_list *list)
{
	t_pipe_list		*buf_list;

	while (list)
	{
		buf_list = list;
		list = list->left;
		free(buf_list);
	}
}

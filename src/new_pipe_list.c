/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_pipe_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 14:01:57 by mdelphia          #+#    #+#             */
/*   Updated: 2020/02/02 14:01:59 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh42.h"

t_pipe_list		*new_pipe_list(t_pipe_list *pipelist)
{
	t_pipe_list	*new_list;

	if(!(new_list = (t_pipe_list *)malloc(sizeof(t_pipe_list))))
		return (NULL);	////////// можно дописать глобальное завершение
	new_list->right = NULL;
	new_list->left = NULL;
	new_list->pfd[0] = -1;
	new_list->pfd[1] = -1;
	if (pipelist)
	{
		pipelist->right = new_list;
		new_list->left = pipelist;
	}
	return (new_list);
}

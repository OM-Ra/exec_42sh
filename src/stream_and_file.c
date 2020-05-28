/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stream_and_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 11:42:00 by mdelphia          #+#    #+#             */
/*   Updated: 2020/02/29 20:38:23 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int			stream_and_file(t_exec_lst *execlist, t_pars_list *list)
{
	if (list->stream_list)
	{
		exec_redirect_heredoc(execlist, list);
		if (redirect_stream(list->stream_list))
			return (-1);
	}
	return (0);
}

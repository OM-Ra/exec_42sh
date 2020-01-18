/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 11:42:00 by mdelphia          #+#    #+#             */
/*   Updated: 2019/12/10 11:42:03 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh42.h"
// для чтения из файла
static int	read_file(t_pars_list *list)
{
	int fd;

	if ((fd = open(list->name_file, O_RDWR)) < 0)
	{
		ft_putstr_fd ("42sh: no such file or directory: ", 2);
		ft_putstr_fd(list->name_file, 2);
		ft_putchar_fd('\n', 2);
		return (-1);
	}
	return (fd);	
}
// для создания файла или, просто, его открытие
int			create_file(t_pars_list *list)
{
	int fd;

	fd = 0;
	if (list->stream_list)
		if (redirect_stream(list->stream_list))
			return (-1);
	if (list->flag_file > 0)	// если нужно создать файл или открыть его для записи в него
	{
		if ((fd = new_or_open_file(list->name_file, list->flag_file)) < 0)
			return (-1);
		if (dup_fd_and_close(fd, STDOUT_FILENO))
			return (-1);
	}
	else if (list->flag_file < 0)	// если нужно открыть для чтения
	{
		if ((fd = read_file(list)) < 0)
			return (-1);
		if (dup_fd_and_close(fd, STDIN_FILENO))
			return (-1);
	}
	return (fd);
}

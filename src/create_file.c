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
// для создания или открытия файла и записи в него
static int	write_file(t_pars_list *list)
{
	int fd;
	int	flag_create;

	flag_create = (list->flag_file == 1) ? (O_TRUNC) : (O_APPEND); // определяется нужна ли дозапись (" >> " или " > ")
	if ((fd = open(list->name_file, O_CREAT |  O_RDWR |
		flag_create, S_IREAD | S_IWRITE)) < 0)
	{
		ft_putstr_fd("42sh: error create file\n", 2);
		return (-1);
	}
	return (fd);
}
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
int			create_file(t_pars_list *list) ///////////// довести до полностью рабочего варианта 
{
	int fd;

	fd = 0;
	if (list->flag_file > 0)	// если нужно создать файл или открыть его для записи в него
	{
		if ((fd = write_file(list)) < 0)
			return (-1);
		dup_fd_and_close(fd, STDOUT_FILENO);
	}
	else if (list->flag_file < 0)	// если нужно открыть
	{
		if ((fd = read_file(list)) < 0)
			return (-1);
		dup_fd_and_close(fd, STDIN_FILENO);
	}
	return (fd);
}

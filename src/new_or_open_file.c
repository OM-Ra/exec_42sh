#include "sh42.h"
// функция для открытия или создания файла
int		new_or_open_file(char *file_name, int flag_open)
{
	int fd;

	flag_open = (flag_open == 1) ? (O_TRUNC) : (O_APPEND); // определяется нужна ли дозапись (" > " или " >> ")
	if ((fd = open(file_name, O_CREAT |  O_RDWR | flag_open,
			S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) < 0)
	{
		ft_putstr_fd("42sh: error create file\n", 2);
		return (-1);
	}
	return (fd);
}

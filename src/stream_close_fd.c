#include "sh42.h"
// ошибка дескриптора
static int	error_fd(int fd)
{
	ft_putstr_fd("42sh: ", 2);
	ft_putnbr_fd(fd, 2);
	ft_putstr_fd(": invalid descriptor\n", 2);
	return (1);
}
// ошибка каталога или файлач
static int	error_name(char *stream_name)
{
	ft_putstr_fd("42sh: '", 2);
	ft_putstr_fd(stream_name, 2);
	ft_putstr_fd("': No such file or directory\n", 2);
	return (1);
}
// занимается факрытием дескриптора файла
static int	find_file(t_red_stream *stream_list)
{
	t_red_stream *buflist;

	buflist = stream_list->left;
	while (buflist)
	{
		if (!ft_strcmp(buflist->stream_name, stream_list->stream_name))
		{
			if (close(buflist->stream_a) == -1)
				return (error_fd(buflist->stream_a));
			return (0);
		}
		buflist = buflist->left;
	}
	return (error_name(stream_list->stream_name));
}
// закрывает дескриптор
int			stream_close_fd(t_red_stream *stream_list)
{
	if (stream_list->stream_name[0])
		return (find_file(stream_list));
	else if (close(stream_list->stream_a) == -1)
		return (1);
	return (0);
}

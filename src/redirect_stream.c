#include "sh42.h"

int		redirect_stream(t_red_stream *stream_list)
{
	t_red_stream	*buf_list;
	int				fd;

	buf_list = stream_list;
	while (buf_list)
	{
		if (buf_list->stream_name[0])
		{
			fd = new_or_open_file(buf_list->stream_name, 1);	// создаёт новый файл
			if (dup_fd_and_close(buf_list->stream_a, fd))		// перенаправляет потоки
				return (1);
		}
		else if (dup_fd_and_close(buf_list->stream_a, buf_list->stream_in))
				return (1);
			buf_list = buf_list->next;
	}
	return (0);
}

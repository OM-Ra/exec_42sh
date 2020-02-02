/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 14:02:51 by mdelphia          #+#    #+#             */
/*   Updated: 2020/02/02 14:02:52 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh42.h"
// установка флагов перед новой структурой или концом парсинга
static int		write_flags_pars(char *line, size_t *i, t_pars_list *buf_list)
{
	if (line[*i] == ';')
	{
		buf_list->flag_semicolon = 1;
		(*i)++;
	}
	else if ((line[*i] == '&') && (line[*i + 1] != '&'))
	{
		buf_list->flag_ampersant = 1;
		(*i)++;
	}
	else if ((line[*i] == '|') && (line[*i + 1] != '|'))
	{
		buf_list->flag_pipe = 1;
		(*i)++;
	}
	else if ((line[*i] == '&') && (line[*i + 1] == '&'))
		{
		buf_list->flag_and = 1;
			(*i) += 2;
		}
	else if ((line[*i] == '|') && (line[*i + 1] == '|'))
		{
		buf_list->flag_or = 1;
		(*i) += 2;
		}
	ft_spacepass(line, i);
	return (0);
}		
// проверка на завершения записи в структуру
static int		check_characters(char *line, size_t *i, t_pars_list *buf_list)
{
	if (line[*i] == '|' || line[*i] == '&' || line[*i] == ';')
		return (write_flags_pars(line, i, buf_list));
	return (1);
}

static int		write_pars_line(char *line, t_pars_list *buf_list)
{
	size_t	i;
	size_t	i_line;
	size_t	i_colum;
	char	buf[BUFSIZ];

	i = 0;
	while (line[i])
	{
		i_line = 0;
		i_colum = 0;
		ft_spacepass(line, &i);
		while (line[i])
		{
			if (check_characters(line, &i, buf_list) &&
				!((line[i] >= 9 && line[i] <= 13) || (line[i] == 32)))
				buf[i_colum++] = line[i++];
			else //if ((line[i] >= 9 && line[i] <= 13) || (line[i] == 32))
			{
				ft_spacepass(line, &i);
				buf[i_colum] = '\0';
				buf_list->pars_args[i_line++] = ft_strdup((char *) buf);
				buf[0] = '\0';
				if (!check_characters(line, &i, buf_list))
				{
					buf_list->pars_args[i_line] = NULL;
					break;
				}
				i_colum = 0;
			}
		}
		buf_list->pars_args[i_line] = NULL;
		ft_strcpy(buf_list->name_func, buf_list->pars_args[0]);
		if (line[i])
			if (!(buf_list = pars_new_list(buf_list)))
				return  (1);
	}
	return (0);
}

t_pars_list		*pars_parsing(char *line)
{
	t_pars_list	*list;
	t_pars_list	*buf_list;

	if (!line)
		return (NULL);
	list = pars_new_list(NULL);
	buf_list = list;
	if (write_pars_line(line, buf_list))
		return (NULL);//////////////// можно добавить free()
	free(line);
	return (list);
}

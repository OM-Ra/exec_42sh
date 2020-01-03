/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 14:28:54 by mdelphia          #+#    #+#             */
/*   Updated: 2019/05/21 14:28:56 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_numchar(char *line, char c)
{
	int		num;
	char	*str;

	num = 0;
	str = line;
	if (!line)
		return (-1);
	while (*str)
	{
		if (*str == c)
			num++;
		str++;
	}
	return (num);
}

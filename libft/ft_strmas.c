/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmas.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 12:16:17 by mdelphia          #+#    #+#             */
/*   Updated: 2019/07/02 12:16:23 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_lenmas(char **mas)
{
	size_t	len;
	size_t	i;

	len = 0;
	i = 0;
	while (mas[i][0])
		len += ft_strlen(mas[i++]);
	return (len);
}

char			*ft_strmas(char **mas)
{
	char	*str;
	char	*start;
	char	*buf;
	size_t	i;

	i = 0;
	if (!(str = (char *)malloc(ft_lenmas(mas) + 1)))
		return (NULL);
	start = str;
	while (mas[i][0])
	{
		buf = mas[i];
		while (*buf)
			*str++ = *buf++;
		i++;
	}
	*str = '\0';
	return (start);
}

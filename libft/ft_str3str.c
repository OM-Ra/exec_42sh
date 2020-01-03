/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str3str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 11:44:50 by mdelphia          #+#    #+#             */
/*   Updated: 2019/07/02 11:44:54 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_str3str(char *str1, char *str2, char *str3)
{
	char *str;
	char *start;
	char *buf;

	if (!(str = (char *)malloc(ft_strlen(str1) + ft_strlen(str2) +
			ft_strlen(str3) + 1)))
		return (NULL);
	start = str;
	buf = str1;
	while (*buf)
		*str++ = *buf++;
	buf = str2;
	while (*buf)
		*str++ = *buf++;
	buf = str3;
	while (*buf)
		*str++ = *buf++;
	*str = '\0';
	return (start);
}

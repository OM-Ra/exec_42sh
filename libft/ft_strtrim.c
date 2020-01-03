/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 16:10:35 by mdelphia          #+#    #+#             */
/*   Updated: 2019/04/10 16:10:38 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_emptyinput(char *str)
{
	if (!(str = (char *)malloc(sizeof(char) * 1)))
		return (NULL);
	*str = '\0';
	return (str);
}

char		*ft_strtrim(char const *s)
{
	size_t	start;
	size_t	end;
	size_t	i;
	char	*str;

	i = 0;
	if (!s)
		return (NULL);
	str = (char *)s;
	if (!(*s))
		return (ft_emptyinput(str));
	start = ft_space_start(s);
	end = ft_space_end(s);
	if (start >= end)
		return (ft_emptyinput(str));
	if (!(str = (char *)malloc(end - start + 2)))
		return (NULL);
	while (start <= end)
	{
		str[i] = s[start];
		start++;
		i++;
	}
	str[i] = '\0';
	return (str);
}

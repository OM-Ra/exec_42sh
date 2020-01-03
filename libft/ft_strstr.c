/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 12:04:39 by mdelphia          #+#    #+#             */
/*   Updated: 2019/04/29 12:23:12 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;
	size_t	j;
	char	*p;

	i = 0;
	if (!needle[i])
		return ((char *)haystack);
	if (!haystack[i] && !needle[i])
		return (NULL);
	if (ft_strlen(haystack) == 0)
		return (NULL);
	while (haystack[i])
	{
		j = 0;
		while (haystack[i + j] == needle[j])
		{
			if (!needle[j + 1])
				return (p = (char *)&haystack[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}

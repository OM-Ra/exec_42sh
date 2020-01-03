/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 13:55:24 by mdelphia          #+#    #+#             */
/*   Updated: 2019/04/10 13:55:31 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	unsigned char	*str;
	char			*start;

	if ((size + 1) == 0)
		return (NULL);
	if (!(str = (unsigned char *)malloc(size + 1)))
		return (NULL);
	start = (char *)str;
	while (0 <= (int)size--)
		*str++ = '\0';
	return (start);
}

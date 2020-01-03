/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 16:08:20 by mdelphia          #+#    #+#             */
/*   Updated: 2019/04/08 16:08:23 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*s1;
	unsigned char	*s2;

	s1 = (unsigned char *)dst;
	s2 = (unsigned char *)src;
	if (s1 == s2)
		return (dst);
	if (s1 < s2)
	{
		ft_memcpy(dst, src, len);
	}
	else if (s1 > s2)
	{
		s1 += len - 1;
		s2 += len - 1;
		while (len--)
			*s1-- = *s2--;
	}
	return (dst);
}

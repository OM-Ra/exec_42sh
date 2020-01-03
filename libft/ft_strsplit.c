/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 16:40:32 by mdelphia          #+#    #+#             */
/*   Updated: 2019/04/10 16:40:35 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_lenword(char const *s, char c, size_t *i)
{
	size_t	len;
	size_t	j;

	len = 0;
	j = *i;
	while (s[j] && s[j] == c)
		j++;
	while (s[j] && s[j] != c)
	{
		j++;
		len++;
	}
	return (len);
}

static char		*ft_writeword(char const *s, char c, size_t *i)
{
	size_t	j;
	char	*str;

	j = 0;
	if (!(str = (char *)malloc(ft_lenword(s, c, i) + 1)))
		return (NULL);
	while (s[*i] && s[*i] == c)
		(*i)++;
	while (s[*i] && s[*i] != c)
	{
		str[j] = s[*i];
		(*i)++;
		j++;
	}
	str[j] = '\0';
	return (str);
}

static size_t	ft_numwords(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	num;

	i = 0;
	num = 0;
	while (s[i])
	{
		j = 0;
		while (s[i] == c && s[i])
			i++;
		while (s[i] != c && s[i])
		{
			i++;
			j++;
		}
		if (j)
			num++;
	}
	return (num);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**str;
	size_t	i;
	size_t	k;
	size_t	num;

	i = 0;
	k = 0;
	if (!s || !c)
		return (NULL);
	num = ft_numwords(s, c);
	if (!(str = (char **)malloc(sizeof(char *) * (num + 1))))
		return (NULL);
	while (s[i] && k < num)
	{
		if (!(str[k] = ft_writeword(s, c, &i)))
		{
			ft_freesplit(str, k);
			return (NULL);
		}
		k++;
	}
	str[k] = NULL;
	return (str);
}

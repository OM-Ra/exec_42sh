/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 11:05:39 by mdelphia          #+#    #+#             */
/*   Updated: 2019/04/09 11:05:42 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_flag(size_t *i, const char *str, int *flag)
{
	if (str[*i] == '-')
	{
		*flag = -1;
		*i = *i + 1;
	}
	else if (str[*i] == '+')
		*i = *i + 1;
}

int			ft_atoi(const char *str)
{
	size_t			i;
	long long int	num;
	int				flag;
	long long int	buf;

	flag = 1;
	i = 0;
	num = 0;
	buf = num;
	ft_spacepass(str, &i);
	ft_flag(&i, str, &flag);
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + (str[i] - '0');
		if (num / 10 != buf)
		{
			if (flag == 1)
				return (-1);
			else if (flag == -1)
				return (0);
		}
		buf = num;
		i++;
	}
	return ((int)(num * flag));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalevesq <jalevesq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 09:50:23 by jalevesq          #+#    #+#             */
/*   Updated: 2022/11/03 14:08:20 by jalevesq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count(int n)
{
	int	i;

	i = 1;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n >= 10)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static char	*ft_fill_str(char *res, int n, size_t count_num)
{
	int	negative;

	negative = 0;
	if (n < 0)
	{
		n *= -1;
		negative = 1;
	}
	while (count_num > 0)
	{
		res[count_num - 1] = (n % 10) + '0';
		n /= 10;
		count_num--;
	}
	if (negative)
		res[0] = '-';
	res[ft_strlen(res)] = '\0';
	return (res);
}

char	*ft_itoa(int n)
{
	char	*res;
	size_t	count_num;

	count_num = count(n);
	if (n < -2147483647)
	{
		res = (char *)ft_calloc(12, sizeof(char));
		if (!res)
			return (NULL);
		ft_strlcpy(res, "-2147483648", 12);
		return (res);
	}
	res = (char *)ft_calloc(count_num + 1, sizeof(char));
	if (!res)
		return (NULL);
	return (ft_fill_str(res, n, count_num));
}

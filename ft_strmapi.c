/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalevesq <jalevesq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 14:05:10 by jalevesq          #+#    #+#             */
/*   Updated: 2022/11/01 16:49:09 by jalevesq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned	int, char))
{
	int		i;
	int		i2;
	char	*buffer;

	if (s == NULL || f == NULL)
		return (NULL);
	i2 = 0;
	i = ft_strlen(s);
	buffer = (char *)malloc(sizeof(char) * i + 1);
	if (!buffer)
		return (NULL);
	while (i2 < i)
	{
		buffer[i2] = (*f)(i2, s[i2]);
		i2++;
	}
	buffer[i2] = '\0';
	return (buffer);
}

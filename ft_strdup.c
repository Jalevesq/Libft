/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalevesq <jalevesq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 09:34:24 by jalevesq          #+#    #+#             */
/*   Updated: 2022/11/01 16:26:35 by jalevesq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	char	*offset;
	int		s1_size;

	s1_size = ft_strlen(s1);
	ptr = (char *)malloc(sizeof(char) * s1_size + 1);
	if (!ptr)
		return ((char *) NULL);
	offset = ptr;
	while (*s1)
	{
		*offset = *s1;
		offset++;
		s1++;
	}
	*offset = '\0';
	return (ptr);
}

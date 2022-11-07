/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalevesq <jalevesq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 09:58:57 by jalevesq          #+#    #+#             */
/*   Updated: 2022/11/04 07:29:52 by jalevesq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	if (s == 0 || s[0] == 0)
		return (0);
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (count);
}

char	*ft_2substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	size_t	size;
	char	*sub;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start > s_len)
		return (ft_strdup(""));
	if (start + len > s_len)
		len = s_len - start;
	size = len + 1;
	sub = (char *) malloc(size * sizeof(char));
	ft_memcpy(sub, s + start, len);
	sub[len] = '\0';
	return (sub);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	size_t	i;
	size_t	j;
	int		index;

	str = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!str)
		return (NULL);

	i = 0;
	j = 0;
	index = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == ft_strlen(s)) && index >= 0)
		{
			str[j++] = ft_2substr(s, index, i - index);
			index = -1;
		}
		i++;
	}
	str[j] = NULL;
	return (str);
}

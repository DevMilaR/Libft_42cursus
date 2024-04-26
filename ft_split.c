/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lromano <lromano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:15:35 by lromano           #+#    #+#             */
/*   Updated: 2024/01/29 15:37:46 by lromano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_subs(const char *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
		{
			i++;
		}
		if (s[i])
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

static size_t	sub_len(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != c && s[i])
	{
		i++;
	}
	return (i);
}

static char	**free_memory(const char **array, size_t count)
{
	while (count--)
	{
		free((void *)array[count]);
	}
	free(array);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	size_t	index;
	size_t	count;

	if (!s)
		return (NULL);
	index = 0;
	count = count_subs(s, c);
	array = (char **)malloc((count + 1) * sizeof(char *));
	if (!array)
		return (NULL);
	while (index < count)
	{
		while (*s == c)
			s++;
		array[index] = (char *)malloc((sub_len(s, c) + 1) * sizeof(char));
		if (!array[index])
			return (free_memory((const char **)array, index));
		ft_strlcpy(array[index], s, (sub_len(s, c) + 1));
		s = ft_strchr(s, (int)c);
		index++;
	}
	array[index] = NULL;
	return (array);
}

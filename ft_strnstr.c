/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lromano <lromano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 12:47:46 by lromano           #+#    #+#             */
/*   Updated: 2024/02/06 14:27:43 by lromano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	i_needle;

	if (*needle == '\0')
		return ((char *)haystack);
	i = 0;
	while (i < len && haystack[i])
	{
		i_needle = 0;
		while (haystack[i + i_needle] == needle[i_needle]
			&& (i + i_needle) < len)
		{
			i_needle++;
			if (!needle[i_needle])
				return ((char *)&haystack[i]);
		}
		i++;
	}
	return (NULL);
}

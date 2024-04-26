/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lromano <lromano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:35:41 by lromano           #+#    #+#             */
/*   Updated: 2024/01/23 16:06:20 by lromano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	size_t	len_s1;
	size_t	len_s2;
	size_t	len_dst;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	len_dst = len_s1 + len_s2 + 1;
	newstr = (char *)malloc(sizeof(char) * (len_dst));
	if (!newstr)
		return (NULL);
	ft_memcpy(newstr, s1, len_s1);
	ft_memcpy(newstr + len_s1, s2, len_s2);
	newstr[len_s1 + len_s2] = '\0';
	return (newstr);
}

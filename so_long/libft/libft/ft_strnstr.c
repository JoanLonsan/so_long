/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrescen <jcrescen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 15:03:12 by jcrescen          #+#    #+#             */
/*   Updated: 2022/10/06 19:02:38 by jcrescen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (*needle == '\0')
		return ((char *)haystack);
	if (*haystack == '\0' && len == 0)
		return (0);
	i = 0;
	while (haystack[i] != '\0')
	{
		j = 0;
		while (haystack[i + j] == needle[j] && ((i + j) < len))
		{
			if (haystack[i + j] == '\0' && needle[j] == '\0')
				return ((char *)&haystack[i]);
			j++;
		}
		if (!needle[j])
			return ((char *)(haystack + i));
		i++;
	}
	return (NULL);
}

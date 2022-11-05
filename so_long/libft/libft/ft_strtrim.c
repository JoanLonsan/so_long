/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 19:40:43 by marvin            #+#    #+#             */
/*   Updated: 2022/09/24 19:40:43 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_ask_set(char c, char const *set)
{
	while (*set)
		if (c == *set++)
			return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ss;
	char	*first;
	char	*last;

	if (!s1 || !set)
		return (0);
	first = (char *)s1;
	last = first + ft_strlen(s1);
	while (*first && ft_ask_set(*first, set))
		++first;
	while ((last > first) && ft_ask_set(*(last - 1), set))
		--last;
	ss = ft_substr(first, 0, (last - first));
	return (ss);
}

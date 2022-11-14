/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 20:26:49 by marvin            #+#    #+#             */
/*   Updated: 2022/09/24 20:26:49 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free_split(char **s)
{
	size_t	i;

	i = 0;
	while (s[i])
		free (s[i--]);
	free (s);
}

static size_t	ft_word_len(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			i++;
			while (*s && *s != c)
				++s;
		}
		else
			++s;
	}
	return (i);
}

char	**ft_split(const char *s, char c)
{
	char	**a;
	size_t	i;
	size_t	len;

	i = 0;
	a = malloc(sizeof(char *) * (ft_word_len(s, c) + 1));
	if (!a)
		return (0);
	while (*s)
	{
		if (*s != c)
		{
			len = 0;
			while (*s && *s != c && len++ >= 0)
				++s;
			a[i++] = ft_substr(s - len, 0, len);
			if (!a[i - 1])
				ft_free_split(a);
		}
		else
			++s;
	}
	a[i] = 0;
	return (a);
}

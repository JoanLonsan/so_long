/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrescen <jcrescen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 12:55:11 by jcrescen          #+#    #+#             */
/*   Updated: 2022/09/30 08:53:04 by jcrescen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	void	*aux;

	aux = dst;
	if (!dst && !src)
		return (NULL);
	if (src < dst)
	{
		src = src + len;
		dst = dst + len;
		while (len)
		{
			*(char *)--dst = *(char *)--src;
			len--;
		}
	}
	else
	{
		while (len)
		{
			*(char *)dst++ = *(char *)src++;
			len--;
		}
	}
	return (aux);
}

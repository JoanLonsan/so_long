/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrescen <jcrescen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 12:31:59 by jcrescen          #+#    #+#             */
/*   Updated: 2022/09/30 07:59:00 by jcrescen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	void	*aux;

	if (!dst && !src)
		return (NULL);
	aux = dst;
	while (n--)
	{
		*(char *)dst = *(char *)src;
		dst++;
		src++;
	}
	return (aux);
}

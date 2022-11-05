/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrescen <jcrescen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 15:21:32 by jcrescen          #+#    #+#             */
/*   Updated: 2022/10/06 20:07:22 by jcrescen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*a;

	if (count == 0 || size == 0)
	{
		count = 1;
		size = 1;
	}
	a = (void *)malloc(count * size);
	if (!a)
		return (NULL);
	ft_bzero(a, count * size);
	return (a);
}

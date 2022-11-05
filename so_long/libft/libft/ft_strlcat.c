/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrescen <jcrescen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 14:30:19 by jcrescen          #+#    #+#             */
/*   Updated: 2022/09/30 10:18:48 by jcrescen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dstlen;
	size_t	srclen;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	dst += dstlen;
	if (size > dstlen)
		ft_strlcpy(dst, src, (size - dstlen));
	if (size < dstlen)
		return (srclen + size);
	return (dstlen + srclen);
}

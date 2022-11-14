/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrescen <jcrescen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 09:33:34 by jcrescen          #+#    #+#             */
/*   Updated: 2022/10/01 22:34:56 by jcrescen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static size_t	ft_n_len(int n)
{
	size_t	i;

	i = 0;
	if (n == 0)
	{
		i++;
		return (i);
	}
	if (n < 0)
	{
		i++;
		n *= -1;
	}
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

int	ft_n_is_negative(int n)
{
	if (n < 0)
	{
		n *= -1;
		return (n);
	}
	return (n);
}

int	ft_n_sign(int n)
{
	if (n < 0)
		return (1);
	return (0);
}

char	*ft_itoa(int n)
{
	int		sign;
	int		len;
	char	*str;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	sign = ft_n_sign(n);
	n = ft_n_is_negative(n);
	len = ft_n_len(n) + sign;
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	str[len--] = '\0';
	while (len >= 0)
	{
		str[len--] = (n % 10) + 48;
		n = n / 10;
	}
	if (sign)
		str[0] = '-';
	return (str);
}

/*
int	main()
{
	printf("%s", ft_itoa(-12));
	return(0);
}
*/

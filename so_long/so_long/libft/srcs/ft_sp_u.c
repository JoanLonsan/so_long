/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sp_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrescen <jcrescen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 12:50:04 by jcrescen          #+#    #+#             */
/*   Updated: 2022/10/30 12:50:04 by jcrescen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_lenght_u(unsigned int u)
{
	int	i;

	i = 0;
	while (u != 0)
	{
		i++;
		u /= 10;
	}
	return (i);
}

static char	*ft_uitoa(unsigned int u)
{
	char	*number;
	int		i;

	i = ft_lenght_u(u);
	number = (char *)malloc(sizeof(char) * (i + 1));
	if (!number)
		return (0);
	number[i] = '\0';
	while (u != 0)
	{
		number[i - 1] = u % 10 + '0';
		u /= 10;
		i--;
	}
	return (number);
}

int	ft_sp_u(unsigned int u)
{
	int		len;
	char	*number;

	len = 0;
	if (u == 0)
		len += write(1, "0", 1);
	else
	{
		number = ft_uitoa(u);
		len += ft_sp_s(number);
		free(number);
	}
	return (len);
}

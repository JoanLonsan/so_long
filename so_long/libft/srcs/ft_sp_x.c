/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sp_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrescen <jcrescen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 12:50:06 by jcrescen          #+#    #+#             */
/*   Updated: 2022/10/30 12:50:06 by jcrescen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_lenght_x(unsigned int number)
{
	int	i;

	i = 0;
	while (number != 0)
	{
		i++;
		number /= 16;
	}
	return (i);
}

static void	ft_write_x(const char x, unsigned int number)
{
	if (number >= 16)
	{
		ft_write_x(x, number / 16);
		ft_write_x(x, number % 16);
	}
	else
	{
		if (number < 10)
			ft_putchar_fd((number + '0'), 1);
		else
		{
			if (x == 'x')
				ft_putchar_fd((number - 10 + 'a'), 1);
			else
				ft_putchar_fd((number - 10 + 'A'), 1);
		}
	}
}

int	ft_sp_x(const char x, unsigned int number)
{
	if (number == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	else
		ft_write_x(x, number);
	return (ft_lenght_x(number));
}

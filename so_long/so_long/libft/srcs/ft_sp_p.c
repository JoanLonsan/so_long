/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sp_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrescen <jcrescen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 12:49:59 by jcrescen          #+#    #+#             */
/*   Updated: 2022/10/30 12:49:59 by jcrescen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_lenght_pointer(unsigned long long pointer)
{
	int	len;

	len = 0;
	while (pointer != 0)
	{
		len++;
		pointer /= 16;
	}
	return (len);
}

static	void	ft_write_pointer(unsigned long long pointer)
{
	if (pointer >= 16)
	{
		ft_write_pointer(pointer / 16);
		ft_write_pointer(pointer % 16);
	}
	else
	{
		if (pointer <= 9)
			ft_putchar_fd((pointer + '0'), 1);
		else
			ft_putchar_fd((pointer - 10 + 'a'), 1);
	}
}

int	ft_sp_p(unsigned long long pointer)
{
	int	len;

	len = 0;
	len += write(1, "0x", 2);
	if (pointer == 0)
		len += write(1, "0", 1);
	else
	{
		ft_write_pointer(pointer);
		len += ft_lenght_pointer(pointer);
	}
	return (len);
}

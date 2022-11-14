/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sp_id.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrescen <jcrescen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 12:49:56 by jcrescen          #+#    #+#             */
/*   Updated: 2022/10/30 12:49:56 by jcrescen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_sp_id(int id)
{
	int		i;
	char	*number;

	i = 0;
	number = ft_itoa(id);
	i += ft_sp_s(number);
	free(number);
	return (i);
}

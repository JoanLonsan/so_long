/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_errors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrescen <jcrescen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 09:44:40 by jcrescen          #+#    #+#             */
/*   Updated: 2022/11/14 11:57:13 by jcrescen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"

int	ft_error(char *message)
{
	ft_printf("%s", message);
	return (0);
}

void	*ft_null_error(char *message)
{
	ft_printf("%s", message);
	return (0);
}

void	ft_print_warning(char *message)
{
	ft_prinft("Warning\n%s", message);
}

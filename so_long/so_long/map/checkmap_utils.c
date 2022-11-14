/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrescen <jcrescen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 13:40:25 by jcrescen          #+#    #+#             */
/*   Updated: 2022/11/14 13:46:08 by jcrescen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./map.h"

int	ft_valid_char(char c)
{
	if (c == '1' || c == '0' || c == 'C' || c == 'E' || c == 'P' || c == 'H'
		|| c == 'V' || c == 'F')
		return (TRUE);
	return (FALSE);
}

int	ft_valid_uniquechar(char c, char check, t_bool *bool)
{
	if (c == check && *bool == FALSE)
		*bool = TRUE;
	else if (c == check && *bool == TRUE)
		return (FALSE);
	return (TRUE);
}

int	ft_valid_border(char c, t_vector point, t_vector size)
{
	if (point.y == 0 || point.x == 0 || point.y == size.y - 1 ||
		point.x == size.x - 1)
		if (c != '1')
			return (FALSE);
	return (TRUE);
}

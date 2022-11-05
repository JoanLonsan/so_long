/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrescen <jcrescen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 16:36:12 by jcrescen          #+#    #+#             */
/*   Updated: 2022/11/05 16:36:13 by jcrescen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORE_H
# define CORE_H

# include "./libft/libft.h"
# include <stdio.h>

typedef enum e_bool
{
	TRUE = 1,
	FALSE = 0
}	t_bool;

typedef struct s_vector
{
	int	x;
	int	y;
}	t_vector;

int		error(char *message);
void	*null_error(char *message);
void	print_warning(char *message);

#endif
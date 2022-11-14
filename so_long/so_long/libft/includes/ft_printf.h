/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 21:54:49 by marvin            #+#    #+#             */
/*   Updated: 2022/10/02 21:54:49 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "../libft/libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
int		ft_sp_c(int c);
int		ft_sp_s(char *str);
int		ft_sp_p(unsigned long long pointer);
int		ft_sp_id(int digit);
int		ft_sp_u(unsigned int digit);
int		ft_sp_x(const char x, unsigned int number);

#endif

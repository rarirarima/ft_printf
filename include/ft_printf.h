/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryosukearima <ryosukearima@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 13:51:56 by ryosukearim       #+#    #+#             */
/*   Updated: 2022/02/01 21:22:48 by ryosukearim      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>

# define BASE16_S "0123456789abcdef"
# define BASE16_L "0123456789ABCDEF"

int		ft_printf(const char *fmt, ...);
size_t	ft_strlen(char const *str);
int		put_char(char c);
int		put_string(char *str);
int		process_string(char *str);
int		base_deci(long long nbr);
int		base_hexa(unsigned long long nbr, char *base);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryosukearima <ryosukearima@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 13:51:56 by ryosukearim       #+#    #+#             */
/*   Updated: 2022/01/08 23:52:57 by ryosukearim      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <strings.h>
# include <ctype.h>
# include <stdarg.h>
# include <limits.h>

# define BASE_16_S "0123456789abcdef"
# define BASE_16_L "0123456789ABCDEF"

typedef struct s_hexa
{
	unsigned long long	tmp;
	int					base_len;
	int					print_count;
	int					*mod_array;
}			t_hexa;

int		ft_printf(const char *fmt, ...);
size_t	ft_strlen(char const *str);
int		put_char(char c);
int		put_string(char *str);
int		process_string(char *str);
int		base_deci(long long nbr);
int		base_hexa(unsigned long long nbr, char *base);

#endif

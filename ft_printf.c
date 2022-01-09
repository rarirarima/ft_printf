/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryosukearima <ryosukearima@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 16:22:32 by ryosukearim       #+#    #+#             */
/*   Updated: 2022/01/09 21:55:06 by ryosukearim      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

static int	process_specifier(const char *fmt, va_list ap)
{
	int	i;

	i = 0;
	if (*fmt == 'c')
		i += put_char(va_arg(ap, int));
	else if (*fmt == 's')
		i += process_string(va_arg(ap, char *));
	else if (*fmt == 'p')
	{
		i += put_string("0x");
		i += base_hexa(va_arg(ap, unsigned long long), BASE_16_S);
	}
	else if (*fmt == 'd' || *fmt == 'i')
		i += base_deci(va_arg(ap, int));
	else if (*fmt == 'x')
		i += base_hexa((unsigned long long)va_arg(ap, unsigned int), BASE_16_S);
	else if (*fmt == 'X')
		i += base_hexa((unsigned long long)va_arg(ap, unsigned int), BASE_16_L);
	else if (*fmt == 'u')
		i += base_deci(va_arg(ap, unsigned int));
	else if (*fmt == '%')
		i += put_char('%');
	return (i);
}

static int	print_not_specifier(const char *fmt, const char *start)
{
	write(1, start, (fmt - start));
	return (fmt - start);
}

int	ft_printf(const char *fmt, ...)
{
	va_list		ap;
	int			print_count;
	const char	*start;

	if (!fmt)
		return (-1);
	print_count = 0;
	va_start(ap, fmt);
	while (*fmt)
	{
		start = fmt;
		while (*fmt != '%' && *fmt)
			fmt++;
		print_count += print_not_specifier(fmt, start);
		if (*fmt == '%')
		{
			print_count += process_specifier(++fmt, ap);
			fmt++;
		}
	}
	va_end(ap);
	return (print_count);
}

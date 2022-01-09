/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryosukearima <ryosukearima@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 16:30:24 by ryosukearim       #+#    #+#             */
/*   Updated: 2022/01/08 23:50:35 by ryosukearim      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static size_t	count_digit_number_ll(long long n)
{
	size_t	digit;

	digit = 0;
	if (n == 0)
		return (1);
	else if (n == LLONG_MIN)
		return (20);
	else if (n < 0)
	{
		n *= -1;
		digit++;
	}
	while (n > 0)
	{
		n = n / 10;
		digit++;
	}
	return (digit);
}

static void	int_to_char_array_put(long long nbr, char *str, size_t digit)
{
	size_t	i;

	i = digit;
	if (nbr < 0)
	{
		str[0] = '-';
		nbr *= -1;
	}
	while (nbr > 0)
	{
		str[i - 1] = (nbr % 10) + '0';
		nbr = nbr / 10;
		i--;
	}
	str[digit] = '\0';
}

static char	*ft_itoa_ll(long long nbr, size_t digits)
{
	char	*p;

	p = (char *)malloc(sizeof(char) * (digits + 1));
	if (!p)
	{
		free (p);
		return (NULL);
	}
	if (nbr == 0)
	{
		p[0] = '0';
		p[1] = '\0';
	}
	else if (nbr == LLONG_MIN)
		p = "-9223372036854775808";
	else
		int_to_char_array_put(nbr, p, digits);
	free (p);
	return (p);
}

int	base_deci(long long nbr)
{
	size_t	digits;

	digits = count_digit_number_ll(nbr);
	put_string(ft_itoa_ll(nbr, digits));
	return (digits);
}

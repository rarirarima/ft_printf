/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryosukearima <ryosukearima@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 16:30:24 by ryosukearim       #+#    #+#             */
/*   Updated: 2022/02/02 15:28:22 by ryosukearim      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0')
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

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

static void	ll_to_char(long long nbr, char *str, size_t digit)
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

int	base_deci(long long nbr)
{
	char	*ptr;
	size_t	print_count;
	size_t	digits;

	print_count = 0;
	digits = count_digit_number_ll(nbr);
	ptr = (char *)malloc(sizeof(char) * (digits + 1));
	if (!ptr)
		return (0);
	if (nbr == 0)
	{
		ptr[0] = '0';
		ptr[1] = '\0';
	}
	else if (nbr == LLONG_MIN)
	{
		ptr[0] = '\0';
		ft_strcat(ptr, "-9223372036854775808\0");
	}
	else
		ll_to_char(nbr, ptr, digits);
	print_count += put_string(ptr);
	free(ptr);
	return (print_count);
}

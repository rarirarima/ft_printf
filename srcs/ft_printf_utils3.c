/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryosukearima <ryosukearima@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 23:22:19 by ryosukearim       #+#    #+#             */
/*   Updated: 2022/01/08 23:49:58 by ryosukearim      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static size_t	count_digit_number_ull(unsigned long long n)
{
	size_t	digit;

	digit = 0;
	if (n == 0)
		return (1);
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

int	base_hexa(unsigned long long nbr, char *base)
{
	t_hexa	a;

	a.base_len = ft_strlen(base);
	a.print_count = 0;
	if (nbr == 0)
		return (put_char('0'));
	a.mod_array = (int *)malloc(sizeof(int *) * count_digit_number_ull(nbr));
	if (!a.mod_array)
	{
		free (a.mod_array);
		return (0);
	}
	while (nbr > 0)
	{
		a.tmp = nbr % a.base_len;
		a.mod_array[a.print_count] = a.tmp;
		nbr = nbr / a.base_len;
		a.print_count++;
	}
	a.tmp = a.print_count;
	while (a.tmp > 0 && base[a.mod_array[a.tmp - 1]])
		put_char(base[a.mod_array[a.tmp-- - 1]]);
	free (a.mod_array);
	return (a.print_count);
}

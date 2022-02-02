/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryosukearima <ryosukearima@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 23:22:19 by ryosukearim       #+#    #+#             */
/*   Updated: 2022/02/01 18:24:00 by ryosukearim      ###   ########.fr       */
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

typedef struct s_hexa
{
	unsigned long long	tmp;
	int					base_len;
	int					print_count;
	int					*save_mod;
}			t_hexa;

int	base_hexa(unsigned long long nbr, char *base)
{
	t_hexa	hexa;

	hexa.base_len = ft_strlen(base);
	hexa.print_count = 0;
	if (nbr == 0)
		return (put_char('0'));
	hexa.save_mod = (int *)malloc(sizeof(int *) * count_digit_number_ull(nbr));
	if (!hexa.save_mod)
		return (0);
	while (nbr > 0)
	{
		hexa.tmp = nbr % hexa.base_len;
		hexa.save_mod[hexa.print_count] = hexa.tmp;
		nbr = nbr / hexa.base_len;
		hexa.print_count++;
	}
	hexa.tmp = hexa.print_count;
	while (hexa.tmp > 0 && base[hexa.save_mod[hexa.tmp - 1]])
		put_char(base[hexa.save_mod[hexa.tmp-- - 1]]);
	free (hexa.save_mod);
	return (hexa.print_count);
}

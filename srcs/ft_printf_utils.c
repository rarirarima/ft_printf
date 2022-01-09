/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryosukearima <ryosukearima@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 16:29:50 by ryosukearim       #+#    #+#             */
/*   Updated: 2022/01/08 23:34:59 by ryosukearim      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

int	put_char(char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

size_t	ft_strlen(char const *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	put_string(char *str)
{
	size_t	print_count;
	size_t	i;

	print_count = 0;
	i = 0;
	while (str[i])
	{
		print_count += put_char(str[i++]);
	}
	return (print_count);
}

int	process_string(char *str)
{
	if (str == (char *) NULL)
		return (put_string("(null)"));
	else
		return (put_string(str));
}

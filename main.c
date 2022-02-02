#include "include/ft_printf.h"
#include <stdio.h>

// int main()
// {
// 	int ft = 0;
// 	int lib = 0;
// 	// ft = ft_printf("%d\n", LONG_MAX);
// 	// lib = printf("%ld\n", LONG_MAX);
// 	ft = ft_printf("ft : %d %d %d %d %d %d\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, LLONG_MAX, LLONG_MIN);
// 	lib = printf("lib: %d %d %d %d %d %d\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, LLONG_MAX, LLONG_MIN);
// 	printf("Return Value: 42 -> %d   Lib -> %d\n", ft, lib);


// 	ft = ft_printf("ft : %d\n");
// 	lib = printf("lib: %d\n");
// 	printf("Return Value: 42 -> %d   Lib -> %d\n", ft, lib);
// }

// int main()
// {
// 	int i;
// 	i = count_digit_number_ll(LLONG_MIN);
// 	printf("%d\n", i);

// 	i = count_digit_number_ll(LLONG_MAX);
// 	printf("%d\n", i);

// 	i = count_digit_number_ll(LONG_MIN);
// 	printf("%d\n", i);

// 	i = count_digit_number_ll(LONG_MAX);
// 	printf("%d\n", i);

// 	i = count_digit_number_ll(INT_MIN);
// 	printf("%d\n", i);

// 	i = count_digit_number_ll(INT_MAX);
// 	printf("%d\n", i);

// 	i = count_digit_number_ll(UINT_MAX);
// 	printf("%d\n", i);

// 	printf("%lld\n", LLONG_MAX);
// 	printf("%lld\n", LLONG_MIN);

// 	printf("%ld\n", LONG_MAX);
// 	printf("%ld\n", LONG_MIN);
// }

// static void	ft_putchar_fd(char c, int fd)
// {
// 	write(fd, &c, 1);
// }

// int	put_char(char c)
// {
// 	ft_putchar_fd(c, 1);
// 	return (1);
// }

// int	put_string(char *str)
// {
// 	size_t	print_count;
// 	size_t	i;

// 	print_count = 0;
// 	i = 0;
// 	while (str[i])
// 	{
// 		print_count += put_char(str[i++]);
// 	}
// 	return (print_count);
// }

// static size_t	count_digit_number_ll(long long n)
// {
// 	size_t	digit;

// 	digit = 0;
// 	if (n == 0)
// 		return (1);
// 	else if (n == LLONG_MIN)
// 		return (20);
// 	else if (n < 0)
// 	{
// 		n *= -1;
// 		digit++;
// 	}
// 	while (n > 0)
// 	{
// 		n = n / 10;
// 		digit++;
// 	}
// 	return (digit);
// }

// static void	ll_to_char(long long nbr, char *str, size_t digit)
// {
// 	size_t	i;

// 	i = digit;
// 	if (nbr < 0)
// 	{
// 		str[0] = '-';
// 		nbr *= -1;
// 	}
// 	while (nbr > 0)
// 	{
// 		str[i - 1] = (nbr % 10) + '0';
// 		nbr = nbr / 10;
// 		i--;
// 	}
// 	str[digit] = '\0';
// }

// int	base_deci(long long nbr)
// {
// 	char	*ptr;
// 	size_t	print_count;
// 	size_t	digits;

// 	print_count = 0;
// 	digits = count_digit_number_ll(nbr);
// 	ptr = (char *)malloc(sizeof(char) * (digits + 1));
// 	if (!ptr)
// 		return (0);
// 	if (nbr == 0)
// 	{
// 		ptr[0] = '0';
// 		ptr[1] = '\0';
// 	}
// 	else if (nbr == LLONG_MIN)
// 		ptr = "-9223372036854775808\0";
// 	else
// 		ll_to_char(nbr, ptr, digits);
// 	print_count += put_string(ptr);
// 	free(ptr);
// 	return (print_count);
// }

// static size_t	count_digit_number_ll(long long n)
// {
// 	size_t	digit;

// 	digit = 0;
// 	if (n == 0)
// 		return (1);
// 	else if (n == LLONG_MIN)
// 		return (20);
// 	else if (n < 0)
// 	{
// 		n *= -1;
// 		digit++;
// 	}
// 	while (n > 0)
// 	{
// 		n = n / 10;
// 		digit++;
// 	}
// 	return (digit);
// }

// static void	int_to_char_array_put(long long nbr, char *str, size_t digit)
// {
// 	size_t	i;

// 	i = digit;
// 	if (nbr < 0)
// 	{
// 		str[0] = '-';
// 		nbr *= -1;
// 	}
// 	while (nbr > 0)
// 	{
// 		str[i - 1] = (nbr % 10) + '0';
// 		nbr = nbr / 10;
// 		i--;
// 	}
// 	str[digit] = '\0';
// }

// static char	*ft_itoa_ll(long long nbr, size_t digits)
// {
// 	char	*p;

// 	p = (char *)malloc(sizeof(char) * (digits + 1));
// 	if (!p)
// 	{
// 		free (p);
// 		return (NULL);
// 	}
// 	if (nbr == 0)
// 	{
// 		p[0] = '0';
// 		p[1] = '\0';
// 	}
// 	else if (nbr == LLONG_MIN)
// 	p = "-9223372036854775808";
// 	else
// 		int_to_char_array_put(nbr, p, digits);
// 	free (p);
// 	return (p);
// }

// int	base_deci(long long nbr)
// {
// 	size_t	digits;

// 	digits = count_digit_number_ll(nbr);
// 	put_string(ft_itoa_ll(nbr, digits));
// 	return (digits);
// }

// int main()
// {
// 	base_deci(LONG_MIN);
// }

// static char	*ft_strcat(char *dest, char *src)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	j = 0;
// 	while (dest[i] != '\0')
// 		i++;
// 	while (src[j] != '\0')
// 	{
// 		dest[i + j] = src[j];
// 		j++;
// 	}
// 	dest[i + j] = '\0';
// 	return (dest);
// }

// static size_t	count_digit_number_ll(long long n)
// {
// 	size_t	digit;

// 	digit = 0;
// 	if (n == 0)
// 		return (1);
// 	else if (n == LLONG_MIN)
// 		return (20);
// 	else if (n < 0)
// 	{
// 		n *= -1;
// 		digit++;
// 	}
// 	while (n > 0)
// 	{
// 		n = n / 10;
// 		digit++;
// 	}
// 	return (digit);
// }

// static void	ll_to_char(long long nbr, char *str, size_t digit)
// {
// 	size_t	i;

// 	i = digit;
// 	if (nbr < 0)
// 	{
// 		str[0] = '-';
// 		nbr *= -1;
// 	}
// 	while (nbr > 0)
// 	{
// 		str[i - 1] = (nbr % 10) + '0';
// 		nbr = nbr / 10;
// 		i--;
// 	}
// 	str[digit] = '\0';
// }

// int	base_deci(long long nbr)
// {
// 	char	*ptr;
// 	size_t	print_count;
// 	size_t	digits;

// 	print_count = 0;
// 	digits = count_digit_number_ll(nbr);
// 	ptr = (char *)malloc(sizeof(char *) * (digits + 1));
// 	if (!ptr)
// 		return (0);
// 	if (nbr == 0)
// 	{
// 		ptr[0] = '0';
// 		ptr[1] = '\0';
// 	}
// 	else if (nbr == LLONG_MIN)
// 	{
// 		ptr[0] = '\0';
// 		ft_strcat(ptr, "-9223372036854775808\0");
// 	}
// 	else
// 		ll_to_char(nbr, ptr, digits);
// 	print_count += put_string(ptr);
// 	free(ptr);
// 	return (print_count);
// }

int	main()
{
	int	i;
	long long nbr;

	nbr = LLONG_MIN;
	i = base_deci(LLONG_MIN);
	ft_printf("\n%d\n", i);
	ft_printf("%d\n", nbr);

}

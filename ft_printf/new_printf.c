/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_printf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kotainou <kotainou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 13:41:16 by kotainou          #+#    #+#             */
/*   Updated: 2023/06/14 13:59:49 by kotainou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_printf(const char *format, ...)
{
	va_list		args;
	const char	*format_p = format;
	ssize_t		i;
	size_t		count;

	i = 0;
	count = 0;
	va_start(args, format);
	while (format_p[i])
	{
		if (format_p[i] == '%' && format_p[i + 1])
		{
			i++;
			i = ft_judg_format(format_p[i], args, i, &count);
			if (i == -1)
				return (-1);
			continue ;
		}
		count += ft_putchar(format_p[i]);
		i++;
	}
	va_end(args);
	return (count);
}

//引数にiを渡して適切な数字を返す
//なので返り値はsize_t型に全部なる

ssize_t	ft_judg_format(char percent, va_list args, size_t	i, size_t	*count)
{
	if (percent == 'c')
		*count += ft_putchar(va_arg(args, int));
	else if (percent == 's')
		*count += ft_putstr(va_arg(args, char *));
	else if (percent == 'p')
		*count += ft_putpoint(va_arg(args, void *));
	else if (percent == 'd' || percent == 'i')
		*count += ft_putnbr_main(va_arg(args, int), 1);
	else if (percent == 'u')
		*count += ft_unsign_putnbr_main(va_arg(args, unsigned int), 1);
	else if (percent == 'x')
		*count += ft_put_dec_to_hex_main(va_arg(args, unsigned int), percent);
	else if (percent == 'X')
		*count += ft_put_dec_to_hex_main(va_arg(args, unsigned int), percent);
	else if (percent == '%')
		*count += write(1, "%%", 1);
	i++;
	return (i);
}

// void	test(long long num)
// {
// 	int ret;
// 	printf("=== %lld ===\n", num);
// 	ret = printf(    "printf  : [%p]\n", (void *)num);
// 	printf("%d\n", ret);
// 	ret = ft_printf( "ft_printf:[%p]\n", (void *)num);
// 	printf("%d\n", ret);
// }

// int main()
// {
// 	int		test1;
// 	int		test2;
// 	int		ans1;
// 	int		ans2;

// 	ans1 = 0;
// 	ans2 = 0;
// 	test1 = 123;
// 	test2 = 0;
// 	ans1 = ft_printf("56789", 1);
// 	printf("\n");
// 	//ans2 = printf("%q", 1);
// 	printf("\n%d %d\n", ans1, ans2);
// }

	// test(-1);
	// test(1);
	// test(15);
	// test(16);
	// test(17);
	// test((long long)&test1);
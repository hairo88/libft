/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kotainou <kotainou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 15:55:35 by kotainou          #+#    #+#             */
/*   Updated: 2023/06/14 13:07:55 by kotainou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stddef.h>

size_t	ft_strlen(const char *str);
ssize_t	ft_judg_format(char percent, va_list args, size_t	i, size_t	*count);
int		ft_printf(const char *format, ...);
size_t	ft_putstr(char *str);
size_t	ft_putchar(char c);
void	ft_put_pointer_next(unsigned long pointer, size_t *count);
size_t	ft_putpoint(void	*pointer);
void	ft_putnbr_fd(int n, int fd);
size_t	ft_putnbr_main(int n, int fd);
size_t	ft_putnbr_count(int n);
void	ft_unsign_putnbr_fd(unsigned int n, int fd);
size_t	ft_unsign_putnbr_main(unsigned int n, int fd);
void	ft_put_dec_to_hex_small(unsigned int nbr);
void	ft_put_dec_to_hex_big(unsigned int nbr);
size_t	ft_put_dec_to_hex_main(unsigned int nbr, char format);
size_t	ft_putnbr_count_unsign(unsigned int n);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okahrama <okahrama@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 15:11:35 by okahrama          #+#    #+#             */
/*   Updated: 2026/02/24 13:30:17 by okahrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
int		ft_putchar(int c);
int		ft_putint(int c);
int		ft_putuint(unsigned int c);
int		ft_putstr(char *str);
int		ft_puthex(unsigned long hex_value);
int		ft_puthexx(unsigned int hex_value);
int		ft_putaddr(void *addr);
char	*ft_strchr(const char *str, int c);

#endif
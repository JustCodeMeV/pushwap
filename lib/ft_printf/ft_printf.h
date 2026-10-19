/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrouxel <vrouxel@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 17:16:18 by vrouxel           #+#    #+#             */
/*   Updated: 2026/09/20 21:30:05 by vrouxel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

int	ft_printf(const char *s, ...);
int	ft_putchar_count(char c);
int	ft_putptr_base(unsigned long n, char *base);
int	ft_putstr_count(char *s);
int	ft_putnbr_count(long n);
int	ft_putunbr_count(unsigned int n);

#endif
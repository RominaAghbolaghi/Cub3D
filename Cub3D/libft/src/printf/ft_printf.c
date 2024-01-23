/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauveur <jsauveur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 11:18:04 by jsauveur          #+#    #+#             */
/*   Updated: 2023/12/17 22:15:18 by jsauveur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"
#include <stdarg.h>

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;
	int		res;

	len = 0;
	res = 0;
	va_start(args, format);
	while (format[len])
	{
		if (format[len] == '%' && ft_strchr("cspdiuxX%", format[len + 1]))
		{
			res += ft_printbase(format, len, args);
			len++;
		}
		else
			res += ft_putchar(format[len]);
		len++;
	}
	va_end(args);
	return (res);
}

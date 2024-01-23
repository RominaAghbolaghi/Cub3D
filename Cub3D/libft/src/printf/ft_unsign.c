/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsign.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauveur <jsauveur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 13:28:17 by jsauveur          #+#    #+#             */
/*   Updated: 2023/12/17 22:15:18 by jsauveur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

int	ft_unsign(unsigned int nb)
{
	int	len;

	len = 0;
	if (nb == 0)
	{
		write (1, "0", 1);
		return (1);
	}
	else if (nb >= 0 && nb <= 9)
	{
		len += ft_putchar(nb + 48);
		return (len);
	}
	else if (nb > 9)
	{
		len += ft_putnbr(nb / 10);
		len += ft_putnbr(nb % 10);
		return (len);
	}
	else
		return (0);
}

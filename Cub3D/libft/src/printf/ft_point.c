/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_point.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauveur <jsauveur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 19:21:40 by jsauveur          #+#    #+#             */
/*   Updated: 2023/12/17 22:15:18 by jsauveur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

int	ft_point(unsigned long nb)
{
	int	len;

	len = 0;
	if (nb == 0)
	{
		write (1, "(nil)", 5);
		return (5);
	}
	else if (nb > 0)
	{
		len += ft_putstr("0x") + ft_lowerhex(nb);
	}
	return (len);
}

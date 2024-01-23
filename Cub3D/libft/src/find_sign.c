/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_sign.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauveur <jsauveur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 22:42:32 by jsauveur          #+#    #+#             */
/*   Updated: 2023/12/17 22:43:01 by jsauveur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* ************************************************************************** */

float	find_sign(float nb_float)
{
	if (nb_float > 0)
		return (1.0f);
	else if (nb_float < 0)
		return (-1.0f);
	else
		return (0.0f);
}

/* ************************************************************************** */

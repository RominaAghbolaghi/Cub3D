/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauveur <jsauveur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 14:55:15 by rmohamma          #+#    #+#             */
/*   Updated: 2023/12/17 22:22:59 by jsauveur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* ************************************************************************** */

char	*ft_strchr(const char *str, int c)
{
	size_t	i;

	i = 0;
	if (str == 0)
		return (0);
	while (str[i] != 0)
	{
		if (str[i] == c)
			return ((char *)&str[i]);
		i++;
	}
	if (str[i] == c)
		return ((char *)&str[i]);
	return (0);
}

/* ************************************************************************** */

// int main()
// {
// 	int     c;
// 	char    *ret;
// 	char s[] = "hello";

// 	c = 101;
// 	ret = ft_strchr(s, c);
// 	printf("%s\n", ret);
// 	return (0);
// }

/* ************************************************************************** */
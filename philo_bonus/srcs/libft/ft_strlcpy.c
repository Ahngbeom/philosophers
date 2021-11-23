/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 14:56:43 by bahn              #+#    #+#             */
/*   Updated: 2021/11/23 14:56:53 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

size_t	ft_strlcpy(char *dest, char *src, size_t size)
{
	size_t	i;
	size_t	src_length;

	i = 0;
	src_length = (size_t)ft_strlen(src);
	if (size == 0)
		return (src_length);
	while (i < size - 1 && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (src_length);
}
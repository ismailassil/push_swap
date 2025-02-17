/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassil <iassil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 09:24:00 by iassil            #+#    #+#             */
/*   Updated: 2024/01/30 15:28:55 by iassil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../_header/push_swap.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	t_srclen;
	size_t	i;

	i = 0;
	t_srclen = ft_strlen(src);
	if (dstsize < 1)
		return (t_srclen);
	while (src[i] != '\0' && i < (dstsize - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (t_srclen);
}

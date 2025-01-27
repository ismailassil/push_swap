/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassil <iassil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 17:16:47 by iassil            #+#    #+#             */
/*   Updated: 2024/01/31 17:51:52 by iassil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../_header/checker_bonus.h"

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	size_t	size;

	size = ft_strlen_(s1) + 1;
	ptr = (char *)malloc(size);
	if (ptr == NULL)
		return (NULL);
	ft_strlcpy(ptr, s1, size);
	return (ptr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassil <iassil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 20:25:23 by iassil            #+#    #+#             */
/*   Updated: 2024/01/31 17:51:52 by iassil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../_header/checker_bonus.h"

static int	ft_isspace(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

static int	ft_sign(const char *str, size_t *i)
{
	int	sign;

	sign = 1;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			sign *= -1;
		(*i)++;
	}
	return (sign);
}

long	ft_atoi(const char *str)
{
	size_t	i;
	long	result;
	long	res1;
	int		sign;

	i = 0;
	result = 0;
	while (ft_isspace(str[i]) == 1)
		i++;
	sign = ft_sign(str, &i);
	while (ft_isdigit(str[i]) > 0)
	{
		res1 = (result * 10) + (str[i] - 48);
		if (sign > 0 && res1 > INT_MAX)
			return (2147483649);
		else if (sign < 0 && (res1 * -1) < INT_MIN)
			return (2147483649);
		result = res1;
		i++;
	}
	return (result * sign);
}

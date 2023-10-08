/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:18:23 by achappui          #+#    #+#             */
/*   Updated: 2023/10/06 15:33:15 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_process_putnbr(unsigned int us_nb)
{
	if (us_nb >=10)
		ft_process_putnbr(us_nb / 10);
	us_nb = us_nb % 10 + 48;
	write(1, &us_nb, 1);
}

void	ft_putnbr(int nbr)
{
	unsigned int	us_nb;

	if (nbr < 0)
	{
		us_nb = -nbr;
		write(1, "-", 1);
	}
	else
		us_nb = nbr;
	ft_process_putnbr(us_nb);
	write(1, "\n", 1);
}

int	ft_atoi(char *str)
{
	int	s;
	int	number;

	s = 1;
	number = 0;
	while (*str > 8 && *str < 14)
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			s = -s;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		number *= 10;
		number += *str - 48;
		str++;
	}
	return (number);
}
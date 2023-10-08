/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 16:42:38 by achappui          #+#    #+#             */
/*   Updated: 2023/10/05 21:19:59 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tail_lib.h"

int	is_option(char *str)
{
	char	*only_c;
	int		i;

	only_c = "-c";
	i = 0;
	while (i < 3)
	{
		if (only_c[i] != str[i])
			return (-1);
		i++;
	}
	return (0);
}

int	is_quantity_atoi(char *str)
{
	int i;
	int	number;

	i = 0;
	number = 0;
	while (str[i] != '\0')
	{
		if (str[i] > '9' || str[i] < '0')
			return (-1);
		i++;
	}
	while (*str != '\0')
	{
		number *= 10;
		number += (*str) - 48;
	}
	return (number);
}

int	option_error(int argc, char **argv, int i)
{
	int	max;

	max = 0;
	if (is_option(argv[i]) == 0)
	{
		if (i == argc - 1)
		{
			ft_pustr_out("tail: option requires an argument -- 'c'\nTry 'tail --help' for more information.\n", 2);
			return (-1);
		}
		if ((max = is_quantity_atoi(argv[i + 1])) < 0)
		{
			ft_pustr_out("tail: invalid number of bytes: '", 2);
			ft_pustr_out(argv[i + 1], 2);
			ft_pustr_out("'\n", 2);
			return (-1);
		}
	}
	return (max);
}

int	main(int argc, char **argv)
{
	int		size;
	int		i;
	char	*file_name;
	int		max;

	i = 0;
	while (++i < argc)
	{
		if ((max = option_error(argc, argv, i)) == -1)
			return (1);
	}
	i = 0;
	while (++i < argc)
	{
		file_name = basename(argv[i]);
		if ((size = file_size(file_name)) == -1)
		{
			file_error(file_name);
			continue;
		}
		if (max == 0)
			max = size + 1;
		if (i > 1)
			write(1, "\n", 1);
		if (argc > 2)
		{
			write(1, "==> ", 4);
			ft_pustr_out(argv[i], 1);
			write(1, " <==\n", 5);
		}
		print_tail_cont(file_name, size, max);
	}
}
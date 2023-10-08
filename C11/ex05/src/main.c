/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 13:41:46 by achappui          #+#    #+#             */
/*   Updated: 2023/10/06 15:32:46 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

typedef enum operator
{
	ADD, SUB, MUL, DIV, MOD, NONE = -1
}	operator;

int		add(int a, int b);
int		sub(int a, int b);
int		mul(int a, int b);
int		div(int a, int b);
int		mod(int a, int b);
int		ft_atoi(char *str);
void	ft_putnbr(int nbr);
void	init_op_tab(int	(**op) (int, int));

int	which_op(char *str)
{
	if (str[0] != '\0')
	{
		if (str[1] == '\0')
		{
			switch (str[0])
			{
				case '+':
					return (ADD);
				case '-':
					return (SUB);
				case '*':
					return (MUL);
				case '/':
					return (DIV);
				case '%':
					return (MOD);
			}
		}
	}
	return (NONE);
}

int	main(int argc, char **argv)
{
	int	(*op[5]) (int, int);
	operator which;
	int	value2;

	init_op_tab(op);
	if (argc != 4)
		return (1);
	if ((which = which_op(argv[2])) == NONE)
	{
		write(1, "0\n", 2);
		return (1);
	}
	else
	{
		value2 = ft_atoi(argv[3]);
		if (value2 == 0 && which == DIV)
			write(2, "Stop : division by zero\n", 24);
		else if (value2 == 0 && which == MOD)
			write(2, "Stop : modulo by zero\n", 22);
		else
			ft_putnbr(op[which](ft_atoi(argv[1]), value2));
	}
	return (0);
}
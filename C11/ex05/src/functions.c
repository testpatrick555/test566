/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 13:43:40 by achappui          #+#    #+#             */
/*   Updated: 2023/10/06 15:12:58 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	add(int a, int b) {return (a + b);}
int	sub(int a, int b) {return (a - b);}
int	mul(int a, int b) {return (a * b);}
int	div(int a, int b) {return (a / b);}
int	mod(int a, int b) {return (a % b);}

void	init_op_tab(int	(**op) (int, int))
{
	op[0] = add;
	op[1] = sub;
	op[2] = mul;
	op[3] = div;
	op [4] = mod;
}
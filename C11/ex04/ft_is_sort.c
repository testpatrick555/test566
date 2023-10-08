/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 10:57:10 by achappui          #+#    #+#             */
/*   Updated: 2023/10/06 10:59:07 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_is_sort(int *tab, int length, int(*f)(int, int))
{
    int i;
    int neg;
    int pos;

    i = 1;
    pos = 0;
    neg = 0;
    while (i < length)
    {
        if (f(tab[i - 1], tab[i]) > 0)
            pos = 1;
        else if (f(tab[i - 1], tab[i]) < 0)
            neg = 1;
        i++;
    }
    if (neg == 1 && pos == 1)
        return (0);
    return (1);
}
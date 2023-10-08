/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 10:57:02 by achappui          #+#    #+#             */
/*   Updated: 2023/10/06 10:58:08 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int *ft_map(int *tab, int length, int(*f)(int))
{
    int i;
    int *new_tab;

    i = 0;
    new_tab = (int *)malloc(length * sizeof(int));
    while (i < length)
    {
        new_tab[i] = f(tab[i]);
        i++;
    }
}
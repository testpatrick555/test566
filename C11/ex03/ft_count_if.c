/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 10:57:07 by achappui          #+#    #+#             */
/*   Updated: 2023/10/06 10:58:26 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_count_if(char **tab, int length, int(*f)(char*))
{
    int i;
    int count;

    i = 0;
    count = 0;
    while (tab[i] != 0)
    {
        if (f(tab[i]) != 0)
            count++;
        i++;
    }
    return (count);
}
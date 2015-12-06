/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 16:56:53 by pbie              #+#    #+#             */
/*   Updated: 2015/11/30 16:48:01 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*This function displays the string s to the standard output. We do this using
 * our ft_putchar function. We start by declaring a size_t variable i that we
 * will use to move through our string. We use a size_t because it is
 * guaranteed to be big enough to contain the size of the biggest object your
 * system can handle. This way we can display the absolute biggest string that
 * our computer can handle. We set i equal to 0 to start at the beginning of
 * the parameter string s. We then do a simple loop stating that so long as we
 * have not reached the end of our string we want the loop to continue. We move
 * to each index position of our string and place the character in that
 * position as a parameter for our ft_putchar function. The ft_putchar function
 * will put that character in the standard output and then we increment the i
 * variable to continue moving through the string. We do this until we reach
 * the terminating '\0' of the string.*/

void		ft_putstr(char const *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
}

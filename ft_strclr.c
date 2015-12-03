/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 18:15:59 by pbie              #+#    #+#             */
/*   Updated: 2015/12/03 16:49:07 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*This function assigns the value '\0' to all the characters in a chain that
 * is passed to it's parameter. This sounds similar to the ft_bzero function but
 * we are changing the value of existing characters to '\0' to clear the existing
 * string rather than putting '\0' to placehold in a newly allocated memory zone*/

void		ft_strclr(char *s)
{
	/*First we create an unsigned int variable i. We use unsigned int to be able
	 *to have the unsigned int's ability to have a further positive reach than
	 a regular int incase our string is incredibly long. i will be our counter.*/
	unsigned int	i;

	/*We then use a loop to go through each position of our string until we
	 *reach the terminating '\0'. As we go to each space we set that character
	 position to '\0'. This may seem like it should end the loop but because we
	 increase the i variable after it moves to the next character that should 
	 exist. Thus continuing the loop until the end.*/
	i = 0;
	while (s[i] != '\0')
	{
		s[i] = '\0';
		i++;
	}
}

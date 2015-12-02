/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 18:27:28 by pbie              #+#    #+#             */
/*   Updated: 2015/12/02 22:59:03 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*This function is made to apply the parameter function f to each character in
 * a string passed as the parameter s. Each character is passed by the address
  to the function f so that it can be modified if necessary.*/

void		ft_striter(char *s, void (*f)(char *))
{
	/*We start off by creating our counter variable i and making it an unsigned
	 * int in case we have a very large string. We then run a loop that will
	 * continue until we reach the end of the given string. We run the function
	 * f on each character of the string. We use the string s + the variable i
	 * because this is an easier way to send an address of a string position.
	 * Once the end of our string is reached the function is finished.*/
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
	{
		f(s + i);
		i++;
	}
}

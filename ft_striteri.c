/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 18:34:01 by pbie              #+#    #+#             */
/*   Updated: 2015/12/02 23:37:54 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*This function applies the parameter function f to each character of a string
 * also passed in it's parameter at at precisely that character's index string
 * position. Each character that is passed into the function f is modified if
 * necessary.*/

void		ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	/*We start by creating our counter variable i as an unsigned variable to 
	 * compensate for the possibilty of a long string.*/
	unsigned int	i;

	/*We then start at the beginning of our string and work our way until the
	 * end, applying the function f to each character. When our loop reaches
	 * the of the string the function is finished.*/
	i = 0;
	while (s[i] != '\0')
	{
		f(i, s + i);
		i++;
	}
}

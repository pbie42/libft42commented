/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 17:23:50 by pbie              #+#    #+#             */
/*   Updated: 2015/12/07 22:55:12 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*According to the man this function locates the first occurence of c (converted
 * to an unsigned char) in string s. ft_memchr returns a pointer to the byte
 * located, or NULL if no such byte exists within n bytes.*/

void		*ft_memchr(const void *s, int c, size_t n)
{
	/*We start by creating a char pointer str that we will be placing a casted
	 * version of our s parameter into. We also create a size_t variable i that
	 * we will use as a counter. We make it size_t in order to compare it to
	 * the given size_t n in our loop condition. We i equal to 0 since we will
	 * also be using it to start at the beginning of our string str. We cast s
	 * as a char pointer and place it inside our str variable. We then enter
	 * our loop.*/
	char	*str;
	size_t	i;

	i = 0;
	str = (char *)s;
	/*While our i variable is less than the parameter n we will have our loop
	 * continue. Inside we want to see if the current index position that has
	 * been casted as an unsigned char is equal to the parameter c that has
	 * also been casted as an unsigned char. If this statement is true we will
	 * return a char casted pointer to the index position that contains c. If
	 * i is no longer less than n and we still have not located c, we will
	 * return NULL.*/
	while (i < n)
	{
		if ((unsigned char)str[i] == (unsigned char)c)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}

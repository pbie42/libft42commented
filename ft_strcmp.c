/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 21:23:12 by pbie              #+#    #+#             */
/*   Updated: 2015/12/03 17:02:10 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*According to the man this function lexicographically compares the NULL
 * terminated strings s1 and s2 that are passed into it's parameters. The
 * function returns an integer greater than, equal to, or less than 0 depending
 * on whether the string s1 is greater than, equal to, or less than string s2.
 * The comparison is done using unsigned characters, so that '\200' is greater
 * than '\0'.*/

int			ft_strcmp(const char *s1, const char *s2)
{
	/*We start by creating our counter variable i and making it an unsigned
	 * int in case we have a really long string. We then set it equal to 0 to
	 * place us at the start of our string in our loop.*/
	unsigned int	i;

	i = 0;
	/*Our while loop requres two conditions to be true for it to begin looping
	 * and to continue looping. We want the loop to happen as long as we have
	 * not reached the end of the string s1 AND we want the loop to happen only
	 * so long as the character at position i in s1 is the same as the character
	 * in postion i in s2. The second we find a difference in the string we want
	 * to compare the difference. */
	while (s1[i] != '\0' && s1[i] == s2[i])
		i++;
	/*When we have either found a non matching character or we have reached the 
	 * end of s1 we return the difference between the character in position i in
	 * s1 and teh character in position i in s2. NOTE: We are casting the
	 * characters into unsigned characters just like the man explained. The
	 * difference that is returned is based on the ascii table numerical value
	 * of the characters.*/
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

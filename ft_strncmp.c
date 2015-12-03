/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 21:34:25 by pbie              #+#    #+#             */
/*   Updated: 2015/12/03 17:55:09 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Similar to ft_strcmp the man says this function lexicographically compares the
 * NULL terminated strings s1 and s2 that are passed into the functions
 * parameters. The function returns an integer greater than, equal to, or less
 * than 0 depending on whether the string s1 is greater than, equal to, or less
 * than string s2. The comparison is again done using unsigned characters, so
 * that '\200' is greater than '\0'. The difference though, between ft_strncmp
 * and ft_strcmp is that we will only search string s1 to it's nth position. The
 * n is given in the parameters.*/

int			ft_strncmp(const char *s1, const char *s2, size_t n)
{
	/*We first declare our counter variable i as a size_t. We do this because
	 * the parameter we are taking in for n is a size_t. We will be needing
	 * to compare our give n value with our i value so they must be the same.*/
	size_t	i;
	/*We set i to 0 to place us at the beginning of our string when we start our
	 * loop. We then check to see if our given n is equal to 0. If it is we
	 * return 0. If not we begin our loop which requires three conditions to be
	 * true in order to happen. We want our loop to happen as long as our string
	 * has not reached it's end AND while the character at position i in s1 is
	 * the same as the character at position i in s2 AND while our counter 
	 * variable i is less than n - 1. We subtract 1 from the given n because
	 * a size_t variable is often used for a memory allocation function and will
	 * be the full size of the string. We subtract 1 to compensate for the fact
	 * that the given size_t is not supposed to be given as 0. If we find a 
	 * difference in characters, or our i variable becomes the same size as n
	 * minus 1, or we reach the end of s1, we finish the loop. We then return
	 * the difference between the current character in s1 at position i from the
	 * current character in s2 at position i. NOTE: We cast the characters as
	 * unsigned characters just like the man explained.*/
	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] != '\0' && s1[i] == s2[i] && i < n - 1)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

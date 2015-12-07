/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 18:21:12 by pbie              #+#    #+#             */
/*   Updated: 2015/12/07 23:05:04 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*According to the man this function compares byte string s1 against byte string
 * s2. Both strings are assumed to be n bytes long. The ft_memcmp function
 * returns zero if the two strings are identical, otherwise it returns the
 * difference between the first two differing bytes (treated as unsigned char
 * values, so that '\200' is greater than '\0', for example). Zero-length
 * strings are always identical.*/

int			ft_memcmp(const void *s1, const void *s2, size_t n)
{
	/*We start by creating two char pointer variables that we will be placing
	 * char casted versions of our parameters s1 and s2 inside. We also create
	 * a size_t variable i to count through the index positions of str1 and
	 * str2 as well as use it to compare to the parameter n which is also a
	 * size_t. We set i equal to 0 and we place the casted versions of s1 and
	 * s2 into str1 and str2. We then start our loop.*/
	char	*str1;
	char	*str2;
	size_t	i;

	i = 0;
	str1 = (char *)s1;
	str2 = (char *)s2;
	/*So long as i is less than the given n we will want our loop to continue.
	 * But if at any point before then, and if we reach an index position where
	 * the character in str1 is not the same as str2, we want to immediately
	 * return the difference between the two differing unsigned char casted
	 * bytes. If i reaches the point where it is no longer less than n and we
	 * have still not found any differing bytes we will return a 0 to say that
	 * both byte strings are the same.*/
	while (i < n)
	{
		if (str1[i] != str2[i])
			return ((unsigned char)str1[i] - (unsigned char)str2[i]);
		i++;
	}
	return (0);
}

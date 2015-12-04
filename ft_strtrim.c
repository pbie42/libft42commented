/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 19:00:25 by pbie              #+#    #+#             */
/*   Updated: 2015/12/04 18:40:26 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*This function allocates memory and returns a copy of the string passed in the
 * parameter but without any kind of blank spaces at the start or the end of
 * the string. This function considers blank spaces to be the characters ' ',
 * a standard space, '\n', a new line, and '\t', which is a tabulation space.
 * If there are no spaces at the beginning and end of the parameter string s
 * the function returns a copy of s. If the allocation of memory fails the
 * function returns NULL.*/

char		*ft_strtrim(char const *s)
{
	/*We start the function by delcaring four variables. The first three will
	 * be used as index counting variables. Once again we use unsigned in case
	 * we are dealing with a ridiculously long string. We also declare a new
	 * string str which is going to hold and return a copy of our parameter
	 * string.*/
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;
	char			*str;
	/*We set our variables i and k to 0. i will be our counter for the first
	 * part of our string looking for any spacing at the beginning. The 
	 * variable k we will get to later. For now just set it to 0. We then start
	 * a loop that will happen so long as the current index position of our
	 * parameter string is a space of some sort. We then follow this with an
	 * if statement saying if after the first while has finished and we are
	 * at the end of the string s already, or if there were no spaces at all
	 * and the string is right away terminated by a '\0' we are going to return
	 * a string that is NULL. We do this by using our previously made
	 * ft_memalloc function to create a allocated memory space worth two char 
	 * values that will be our destination string for our ft_strcpy function
	 * and a "" that will fill our string with a NULL space. The ft_strcpy 
	 * function will create the NULL string to return.*/
	i = 0;
	k = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	if (s[i] == '\0')
		return (ft_strcpy(ft_memalloc(sizeof(char) * 2), ""));
	/*Below is where we will search for any sort of spacing at the end of our
	 * parameter string s. We start by setting our counter j to the length
	 * of s by using our ft_strlen function and then subtracting one from the
	 * result. We subtract the 1 to compensate for a terminating '\0' because
	 * we will be decrementing from the end of string s this time. Our while
	 * loop follwing our setting of value to j starts at the last index 
	 * position of string s and moves backwards through the string. Once a non
	 * spacing character is found the loop stops. Once this loop is done we are
	 * ready to allocate memory for a fresh string.*/
	j = ft_strlen(s) - 1;
	while (s[j] == ' ' || s[j] == '\n' || s[j] == '\t')
		j--;
	/*We do a standard memory allocation for our fresh string but notice what
	 * we are doing to know the size of the string. We are subtracting i, which
	 * found our spacing at the beginning of the given string, from j, which 
	 * found our spacing at the end of the string, and then we are adding 2
	 * to that result. We do this because of how the counters work. They will
	 * place their index position on the character that stopped their
	 * incrementation and their decrementation. You add the 2 to bring you back
	 * to the length of the string you will be returning plus the space for the
	 * terminating '\0'. We then check to make sure our memory allocation
	 * worked. If not we return NULL.*/
	str = (char *)malloc(sizeof(char) * (j - i + 2));
	if (str == NULL)
		return (NULL);
	/*We now begin our final loop which will place a trimmed version of the
	 * string s into our fresh str string. We do a loop while k, which we
	 * set earlier to 0, is less than j minus i plus 1, which we do to make
	 * sure we do the full length of the portion that we want of s. Inside 
	 * the loop we take the index position in s that is the start of our trim
	 * and add k to that index so we will increment from that position. We then
	 * place the corresponding character into our new string. We run the loop
	 * until we reach the end of the portion of s that we want and then we exit
	 * the loop. We then add a terminating '\0' and return our trimmed string.*/
	while (k < j - i + 1)
	{
		str[k] = s[i + k];
		k++;
	}
	str[k] = '\0';
	return (str);
}

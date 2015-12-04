/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 17:41:51 by pbie              #+#    #+#             */
/*   Updated: 2015/12/04 15:48:37 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*This function allocates memory and returns a new string terminated by a '\0'
 * which is the result of a concatenation of the parameters s1 and s2. If the
 * allocation fails the function will return NULL.*/

char		*ft_strjoin(char const *s1, char const *s2)
{
	/*We begin by declaring three variables. The first two will be counters we
	 * will use to move through our strings. The third is the new string that
	 * we will be allocating memory to in order to return the concatenation of
	 * our parameter strings.*/
	int		i;
	int		j;
	char	*str;
	/*We set both of the counter variables to 0 since we will want both
	 * counters to start at the beginning of their respective strings. We then
	 * allocate memory using the malloc function with a combination of using
	 * our previously made ft_strlen functions. We use the ft_strlen function
	 * on both the parameter strings to figure out the full length for a 
	 * concatenation and we add 1 to this added length to make sure we can
	 * add a terminating '\0'. If the allocation failed we will return NULL.*/
	i = 0;
	j = 0;
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str == NULL)
		return (NULL);
	/*If the allocation worked we begin our concatenation of our given strings.
	 * We start with s1 with a standard string loop saying that as long as we
	 * have not reached the end of the string, continue. We place the index
	 * of both our new string str and our parameter s1 at i which at this 
	 * moment is 0. We then run through the length of s1 placing each character
	 * in s1 into str. Once this has finished we continue to the next loop.*/
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	/*This next loop is exactly the same as the previous loop except you must
	 * take note of our use of the counter variable j. j is currently equal to 
	 * 0 at this point in our function. For our new string str we set the index
	 * equal to the previous counter i plus our new counter j. This keeps us at
	 * the index position we ended on when our previous loop finished since it
	 * will be the value i was at the end of the previous loop plus j's current
	 * value of 0. We use j to set the index of our string s2 and let the loop
	 * go until we have reached the end of s2. Once the end of s2 has been
	 * reached we add a terminating '\0' to the end of our fresh string and
	 * return the new string which is a fresh concatenation of our parameters.*/
	while (s2[j] != '\0')
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}

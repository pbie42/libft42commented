/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 18:40:57 by pbie              #+#    #+#             */
/*   Updated: 2015/12/02 23:47:13 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*This functin applies the given function f to each character of the given
 * string in order to create a new string that is the result of have function
 * f run on string s. It will return a 'fresh' copy of the modified string*/

char		*ft_strmap(char const *s, char (*f)(char))
{
	/*We start by creating two variable. An unsigned int counter to move us
	 * through our string and char variable for our string that is to be 
	 * returned.*/
	unsigned int	i;
	char			*str;

	/*Next we allocate the memory necessary to make a copy of the modified 
	 * string we want to return. We use our ft_strlen function on the given
	 * string and make sure to add 1 to it to compensate for the terminating 
	 * '\0'. If the allocation fails we return NULL. Otherwise we continue.*/
	i = 0;
	str = (char *)malloc(sizeof(char) * (ft_strlen(s)) + 1);
	if (str == NULL)
		return (NULL);
	/*We now go through our string s and apply the function f to each of it's
	 * characters. We set the result of this into the corresponding position in
	 * our empty string. Once we reach the end of our parameter string we exit
	 * the loop and make sure to add a terminating '\0' to the end of our newly
	 * filled string. We then return our new string.*/
	while (s[i] != '\0')
	{
		str[i] = f(s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}

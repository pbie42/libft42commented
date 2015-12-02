/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 15:17:42 by pbie              #+#    #+#             */
/*   Updated: 2015/12/02 22:38:36 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*This function allocates memory and returns a 'fresh' string that ends with 
 *'\0'. Each character in the string is set to '\0' if the allocation fails the
 function returns NULL. To do this we simply use our ft_memalloc function with
 the size parameter given to our function. We make sure cast it as a char string
 because that is what we want to return and we have to add + 1 to our size_t
 to compensate for the terminating '\0'. NOTE: We are able to set each character 
 in the string to '\0' because our ft_memalloc uses our ft_bzero function*/
char		*ft_strnew(size_t size)
{
	return ((char *)ft_memalloc(size + 1));
}

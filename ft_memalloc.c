/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 18:32:41 by pbie              #+#    #+#             */
/*   Updated: 2015/12/02 20:53:02 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

	/*This function is designed to allocate and return a "fresh" zone of memory.
	 *The memory allocated is initialized to 0 using our ft_bzero function. If
	 the allocation fails we return NULL.*/

void		*ft_memalloc(size_t size)
{
	/*We first make a void variable of pointer m. This is so that we can use the
	 *zone of allocated memory that will be applied to it for any type of data.*/
	void	*m;
	/*We then use malloc to allocate memory to our m variable based on the size
	 *given in the parameter. If the allocation fails we return NULL. Otherwise
	 we then run the function ft_bzero on our allocated zone of memory m and
	 give it our size parameter. We then return our void variable m.*/
	m = malloc(size);
	if (m == NULL)
		return (NULL);
	ft_bzero(m, size);
	return (m);
}

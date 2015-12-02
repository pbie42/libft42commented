/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 15:17:42 by pbie              #+#    #+#             */
/*   Updated: 2015/12/02 21:06:27 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*This function allocates memory and returns a 'fresh' string that ends with 
 *'\0'. Each character in the string is set to '\0'*/

char		*ft_strnew(size_t size)
{
	return ((char *)ft_memalloc(size + 1));
}

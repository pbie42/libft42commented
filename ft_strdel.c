/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 15:20:39 by pbie              #+#    #+#             */
/*   Updated: 2015/12/02 22:42:34 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*This function takes in the parameter of an address to a chain of characters
 * that should be freed and then set to NULL. We do this by running our 
 * ft_memdel function and casting the pointer address as a void that we put 
 * into its parameter.*/

void		ft_strdel(char **as)
{
	ft_memdel((void **)as);
}

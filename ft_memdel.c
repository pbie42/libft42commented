/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 15:13:10 by pbie              #+#    #+#             */
/*   Updated: 2015/12/02 20:59:55 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*This function takes in the parameter of the address of a pointer. The zone
 *pointed to should be liberated with free. The pointer is then set to NULL.*/

void		ft_memdel(void **ap)
{
	free(*ap);
	*ap = NULL;
}

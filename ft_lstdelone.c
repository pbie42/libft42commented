/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 17:17:21 by pbie              #+#    #+#             */
/*   Updated: 2015/12/02 18:26:23 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*In this function we are taking in, as a parameter, the address of a pointer on 
 * a link and freeing the memory content of the link with the function 'del'
 * that has been passed as a parameter as well in order to free the memory of 
 * the link. The memory of the element next should never be freed. In order to
 * terminate the link, the pointer on the current link should be put to NULL.*/

#include "libft.h"

void		ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	/*First we check to make sure that the parameters that were passed into our
	 * function are not NULL. If they are not we then run our parameter passed
	 * function del by giving it's parameters our link alst's content and
	 * content_size. Once the function has deleted alst's content we the free
	 * the memory that was allocated to alst and then set it to NULL. Thus
	 * deleting on link in our list.*/
	if (del != NULL && alst != NULL)
	{
		del((**alst).content, (**alst).content_size);
		free(*alst);
		*alst = NULL;
	}
}

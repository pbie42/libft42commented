/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 18:21:05 by pbie              #+#    #+#             */
/*   Updated: 2015/12/02 19:04:11 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*In this function we will be adding a new link, called 'new' that is passed
 * in our parameters, to a list and placing this link at the head of our list.*/

void		ft_lstadd(t_list **alst, t_list *new)
{
	/*First we check to make sure the link new that is passed to our parameters
	 * is NULL. If it is not, we set our link new's element next to the first 
	 * link that is pointed to by alst in our parameters. We then set the
	 * pointer of alst to new, thus setting it to the head of our linked list.*/
	if (new != NULL)
	{
		new->next = *alst;
		*alst = new;
	}
}

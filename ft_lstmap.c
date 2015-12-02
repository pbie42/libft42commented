/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 16:32:50 by pbie              #+#    #+#             */
/*   Updated: 2015/12/02 20:37:19 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*This function takes the list of lst passed in the parameter and applies to
 * each link the function f (also passed in the parameter) and creates and 
 * returns a "fresh" list. This results in successive applications of the
 * function recursively until the end of the list is reached and the newlist
 * is returned.*/

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	/*First we create a new t_list structure variable newlist*/
	t_list *newlist;
	/*We then make sure that both the list passed as well as the function f are 
	 *not NULL. If they are we will return NULL. If not we will run the function
	 f on the link lst and set it into our newlist link variable. NOTE: We are
	 to assume that the function f allocates memory for our newlist variable
	 based on the data of lst. We then check if newlist is null as well as if
	 the link lst's element next is NULL. If neither are NULL we set our newlist
	 element next equal to the ft_lstmap function which has been passed lst's
	 element next (the link following it) as well as the function f. This allows
	 us to recursively apply the function f to all of the links and allows us to
	 allocate memory based on how many indiviual links we have in our list. Once
	 lst->next becomes equal to NULL this will break us out of the recursion and
	 have us return the newlist.*/
	if (lst != NULL && f != NULL)
	{
		newlist = f(lst);
		if (newlist != NULL && lst->next != NULL)
			newlist->next = ft_lstmap(lst->next, f);
		return (newlist);
	}
	return (NULL);
}

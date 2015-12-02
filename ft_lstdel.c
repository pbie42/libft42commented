/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 17:55:55 by pbie              #+#    #+#             */
/*   Updated: 2015/12/02 19:00:32 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*With this function we will be taking in as a parameter the address of a
 * pointer on a link and freeing the memory of this link and all of the 
 * links following it one after another using the function 'del' that has been 
 * passed in as a parameter as well. We will also be using the function free. 
 * In order to terminate the link, the pointer on the first link, once freed, 
 * should be set to NULL.*/

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	/*First we declare two link structures, one will be a temporary place
	 * holder and the other will hold the next link in the list.*/
	t_list	*tmp;
	t_list	*next;

	/*We set our temporary link to hold the link pointed to in our parameter,
	 * alst. We the check to make sure that the function passsed in our
	 * parameter is not NULL.*/
	tmp = *alst;
	if (del != NULL)
	{
		/*If the del function is not NULL we begin our loop in the process of
		 * deleting our parameter passed link and all the others following it
		 * in the linked list. We do this by saying loop so long as tmp, which
		 * is holding the current link, is not equal to NULL, which would mean 
		 * we have reached the end of our list.*/
		while (tmp != NULL)
		{
			/*We take our current link's element next (the link following it)
			 * and place it into our link variable next. Separating it from
			 * the current link. We then run our del function that was passed
			 * in our parameters and give it as parameters our current link's 
			 * content element and content_size element. Once those are deleted
			 * we the free the memory that is allocated in our tmp variable.
			 * We then set our next variable, which currently holds the link
			 * that should be following the one we just deleted, and put it
			 * into our tmp variable and start the loop again until we reach
			 * NULL. Thus ending the loop.*/
			next = tmp->next;
			del(tmp->content, tmp->content_size);
			free(tmp);
			tmp = next;
		}
		/*Once our loop is done and everything is deleted we then set the link
		 * alst to NULL. Effectively deleting the parameter passed link and
		 * all of those that were following it.*/
		*alst = NULL;
	}
}

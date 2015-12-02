/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 16:41:20 by pbie              #+#    #+#             */
/*   Updated: 2015/12/02 18:17:52 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*We will be allocating memory for, and returning, a "fresh" linked list. The 
 * elements content and content_size within our new link will be copied from the 
 * parameters of the function. If the parameter content is NULL the the element 
 * content_size is initialized to 0 regardless of the paramter of content_size.
 * The element of next is initialized to NULL. If the memory allocation fails
 * then we will return NULL*/

t_list			*ft_lstnew(void const *content, size_t content_size)
{
	/*We first declare a new t_list structure called 'new'*/
	t_list		*new;
	/*We then proceed to allocate the memory required for the stucture to exist*/
	new = (t_list *)malloc(sizeof(t_list) * 1);
	/*In the event that the memory allocation failed we return NULL*/
	if (new == NULL)
		return (NULL);
	/*If the parameter of content is NULL we set the content element to NULL
	 * and the content_size element to 0 regardless of the parameter given*/
	if (content == NULL)
	{
		new->content = NULL;
		new->content_size = 0;
	}
	/*If the above is not the case we move on. We allocate memory for our new
	 * linked list's element content by using our parameter of content_size.
	 * If the allocation fails for this we return NULL. If it works we use our
	 * ft_memmove function to move the data from our parameters into our linked
	 * new's content element. And last we set our link new's content_size to
	 * our parameter content_size*/
	else
	{
		new->content = malloc(content_size);
		if (new->content == NULL)
			return (NULL);
		ft_memmove(new->content, content, content_size);
		new->content_size = content_size;
	}
	/*Last we set our new link list new's next element to NULL so that we know
	 * that we are at the end of the list. We then return our new link.*/
	new->next = NULL;
	return (new);
}

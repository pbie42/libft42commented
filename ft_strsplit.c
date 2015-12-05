/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 16:21:25 by pbie              #+#    #+#             */
/*   Updated: 2015/12/05 19:03:30 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*This function will allocate memory and return a 'fresh' table of strings (all
 * terminated by a '\0', the table as well) as a result of the splitting of
 * the given string by the given character c. If memory allocation fails at
 * any point the function will return NULL. And example of this function is
 * ft_strsplit("*hello*fellow***students*", '*'). This should return a table
 * that splits the string int ["hello", "fellow", "students"]. This function
 * must be done in three parts. We will start at the ft_strsplit function at
 * the bottom. We put ft_strsplit at the end of our code because in order to 
 * use other functions we make specifically for it we have to make sure we have
 * them made before we get to our actual function.*/

/*The first function we have is a word counting function. We make this because
 * we will need to figure out how many strings we will be placing into our 
 * table that's to be returned from the ft_strsplit function. We want this
 * for when we allocate memory for the table.*/
static int			ft_cntwrd(char const *s, char c)
{
	/*We start by creating two variables. The first is an unsigned int i which
	 * we will use to move through the string that was given to ft_strsplit.
	 * We use unsigned in the event we get a ridiculously long string. We also
	 * make a counter variable we will be using to count the words in the
	 * string and then we will return it. NOTE: This function returns a static
	 * int. A static variable as a way of getting around not using global
	 * variables. A static variable keeps its value between invocations. We 
	 * use this for cases where a function needs to keep some state between
	 * invocations. We set both of our variables to 0 and begin our function.*/
	unsigned int	i;
	int				cntr;

	i = 0;
	cntr = 0;
	/*We go into our while loop and have it loop so long as we have not reached
	 * the end of the given string. Inside our loop we have another while loop
	 * that is saying so long as the index position we are in has the same
	 * character as our c parameter then we want to move past it. This is the
	 * same c character that the ft_strsplit function will be splitting the
	 * string by. So we want to skip over that character until we find our
	 * first real word. If, when our while loop has finished passing over
	 * c characters, we have not reached the end of the given string then we
	 * want to increase our word counter. We know that we have something that
	 * is not the character held by variable c and we want to split that from
	 * the string. We then go to another while loop that will pass over all of
	 * the characters in our word until we find another instance of the 
	 * character held by variable c. If we find one and we have not reached the
	 * end of our string we begin the loop again and continue until we have
	 * reached the end, counting all of the words along the way. We then
	 * return the cntr variable which will tell us how many words exist in our
	 * string.*/
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			cntr++;
		while (s[i] && (s[i] != c))
			i++;
	}
	return (cntr);
}
/*This next function is a variation of the ft_strdup function we have
 * previously made. According to the man the ft_strdup function allocates
 * sufficient memory for a copy of the given string, does the copy, and returns
 * a pointer to it. The ft_strndup function copies at most n (our size_t
 * parameter) characters from the given string, always NULL terminating the
 * copied string.*/
static char			*ft_strndup(const char *s, size_t n)
{
	/*We start by creating a string variable that we will be allocating memory
	 * to and that we will be returning as the result of this function. We 
	 * allocate the memory for this string by using this function's parameter
	 * of n. We get this parameter from our ft_strsplit function. It is the 
	 * length of one of the words that we a splitting into a table. We add 1 to
	 * this in the malloc function to ensure space for a terminating '\0'. We
	 * then check to see if the memory allocation failed. If it did we will
	 * return NULL. If the allocation succeeded then we want to place our word
	 * into our fresh string str. We do this by using our previously made 
	 * ft_strncpy function. We give ft_strncpy our memory allocated 'fresh'
	 * string, the parameter string s (which is taken from ft_strsplit but has
	 * been put in the ft_strndup function at the index the word we want to 
	 * place into str will start from) and the size_t parameter n. We then make
	 * sure to add a terminating character to the end of our fresh string and
	 * then return it. */
	char			*str;

	str = (char *)malloc(sizeof(char) * n + 1);
	if (str == NULL)
		return (NULL);
	str = ft_strncpy(str, s, n);
	str[n] = '\0';
	return (str);
}
/*With the two previous functions made we are now ready to begin our real
 * function, ft_strsplit*/
char				**ft_strsplit(char const *s, char c)
{
	/*We start by creating three counter variables. We will use these three
	 * variables to pinpoint index positions inside our parameter string s. We
	 * also create a char variable **tab. This variable is for our table that
	 * will hold our split strings. We set the variables i and k to 0 and well
	 * then allocate memory for our table. This is where we use our ft_cntwrd
	 * function above, to figure out how much space we need to allocate for our
	 * table. If the allocation fails we return a NULL.*/
	int				i;
	int				j;
	int				k;
	char			**tab;

	i = 0;
	k = 0;
	tab = (char **)malloc(sizeof(char *) * (ft_cntwrd(s, c)) + 1);
	if (tab == NULL)
		return (NULL);
	/*We now go into our loop to split our given string. Our main loop will
	 * continue so long as we have not reached the end of our parameter string.
	 * Inside we have another loop to pass over all of the parameter c
	 * characters that exist. This will stop when we reach our first not c 
	 * character. We then set our variable j equal to the value of i at This
	 * point in our function. j will be used to point to the starting index
	 * position of our first word inside our string s. We then continue moving
	 * through string s so long as we don't come across our parameter c
	 * character. Once we do we move to our if statement. If i is greater than
	 * j, which it should be if there is a word we want, we will then place
	 * that word into our table index position 0 (which is currently the value
	 * of k). We do this using the ft_strndup function from above and we give it
	 * two parameters; Our paramter string s (but at the index position of j,
	 * the beginning of the word we want) and the size/length of the word which
	 * we find by subtracting the value of j from the value of i (the start and
	 * end index positions of our word). We then increment k to move to the
	 * next position in our table. We repeat the main while loop until we reach
	 * the end of our parameter string s. We finish by adding a terminating
	 * NULL to our table tab. We then return our finished table.*/
	while (s[i])
	{
		while (s[i] == c)
			i++;
		j = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > j)
		{
			tab[k] = ft_strndup(s + j, i - j);
			k++;
		}
	}
	tab[k] = NULL;
	return (tab);
}

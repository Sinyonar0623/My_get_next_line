/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctharawi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 12:44:09 by ctharawi          #+#    #+#             */
/*   Updated: 2024/11/09 13:37:24 by ctharawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*ft_lstlast(t_list *node)
{
	if (!node)
		return (NULL);
	while (node->next)
		node = node->next;
	return (node);
}

t_list	*ft_lstnew(char *str)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(*node));
	if (!node)
		return (NULL);
	node->content = str;
	node->len = 0;
	node->next = NULL;
	return (node);
}

void	ft_lstadd_back(t_list **lst, t_list *node)
{
	t_list	*ptr;

	if (!node)
		return ;
	if (!*lst)
	{
		*lst = node;
		return ;
	}
	ptr = ft_lstlast(*lst);
	ptr->next = node;
}

void	ft_clear(t_list **lst)
{
	t_list	*ptr;

	if (!lst)
		return ;
	while (*lst)
	{
		ptr = *lst;
		*lst = (*lst)->next;
		if (ptr->content)
			free(ptr->content);
		if (ptr)
			free(ptr);
	}
	*lst = NULL;
}

void	*ft_calloc(size_t n, size_t size)
{
	void			*str;
	size_t			len;
	size_t			i;
	unsigned char	*ptr_str;

	len = n * size;
	if (!len || len / n != size)
		return (NULL);
	str = malloc(len);
	if (str == NULL)
		return (NULL);
	i = 0;
	ptr_str = str;
	while (i < len)
	{
		ptr_str[i] = '\0';
		i++;
	}
	return (ptr_str);
}

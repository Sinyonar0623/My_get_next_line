/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctharawi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 12:06:10 by ctharawi          #+#    #+#             */
/*   Updated: 2024/11/09 13:52:29 by ctharawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	ft_gettail(t_list **lst)
{
	t_list	*node;
	t_list	*tmp;
	char	*str;
	int		i;
	int		j;

	j = 0;
	tmp = ft_lstlast(*lst);
	if (!tmp)
		return ;
	str = tmp->content;
	j = tmp->len;
	tmp->content = NULL;
	ft_clear(lst);
	i = 0;
	if (str[j] != '\0')
	{
		while (str[j] != '\0')
			str[i++] = str[j++];
		str[i] = '\0';
		node = ft_lstnew(str);
		ft_lstadd_back(lst, node);
	}
	else
		free(str);
}

static void	ft_str_node_join(t_list *lst, char **str)
{
	int		i;
	int		j;
	t_list	*ptr;

	ptr = lst;
	j = 0;
	while (ptr)
	{
		j += ptr->len;
		ptr = ptr->next;
	}
	if (!j)
		return ;
	*str = (char *)malloc(sizeof(char) + (j + 1));
	if (!str)
		return ;
	j = 0;
	while (lst && lst->content)
	{
		i = 0;
		while (lst->content[i] && i < lst->len)
			(*str)[j++] = lst->content[i++];
		lst = lst->next;
	}
	(*str)[j] = '\0';
}

static int	ft_isnl(t_list *node)
{
	int	i;

	i = 0;
	node = ft_lstlast(node);
	if (!node)
		return (1);
	while (node->content[i])
	{
		if (node->content[i] == '\n')
		{
			node->len = i + 1;
			return (0);
		}
		i++;
	}
	node->len = i;
	return (1);
}

static void	ft_create(t_list **lst, int fd)
{
	int		read_byte;
	char	*str;
	t_list	*new_node;

	read_byte = 0;
	while (ft_isnl(*lst))
	{
		str = NULL;
		new_node = ft_lstnew(str);
		new_node->content = ft_calloc(sizeof(*str), (BUFFER_SIZE + 1));
		read_byte = read(fd, new_node->content, BUFFER_SIZE);
		if (read_byte <= 0)
		{
			free(new_node->content);
			free(new_node);
			return ;
		}
		new_node->content[BUFFER_SIZE] = '\0';
		ft_lstadd_back(lst, new_node);
	}
}

char	*get_next_line(int fd)
{
	static t_list	*lst = NULL;
	char			*str;

	str = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	ft_create(&lst, fd);
	if (!lst)
		return (NULL);
	ft_str_node_join(lst, &str);
	ft_gettail(&lst);
	return (str);
}

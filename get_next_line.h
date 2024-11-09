/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctharawi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 14:34:38 by ctharawi          #+#    #+#             */
/*   Updated: 2024/11/04 14:30:48 by ctharawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 7
# endif

typedef struct s_list
{
	char			*content;
	int				len;
	struct s_list	*next;
}					t_list;

t_list	*ft_lstlast(t_list *node);
t_list	*ft_lstnew(char *str);
void	ft_lstadd_back(t_list **lst, t_list *node);
void	ft_clear(t_list **lst);
void	*ft_calloc(size_t n, size_t size);
char	*get_next_line(int fd);

#endif

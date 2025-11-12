/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_redir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavivas- <gavivas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 19:12:32 by gavivas-          #+#    #+#             */
/*   Updated: 2025/11/12 19:55:53 by gavivas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_redir	*redir_new(t_rtype type, char *file)
{
	t_redir	*new;
	size_t	len;
	char	*copy;

	if (!file || !*file)
		return (NULL);
	len = ft_strlen(file);
	new = malloc(sizeof(t_redir));
	if (!new)
		return (NULL);
	copy = malloc(len + 1);
	if (!copy)
		return (free(new), NULL);
	ft_memcpy(copy, file, len);
	copy[len] = '\0';
	new->type = type;
	new->file = copy;
	new->fd = -1;
	new->next = NULL;
	return (new);
}

t_redir	*redir_last(t_redir *lst)
{
	t_redir	*tmp;

	tmp = lst;
	while (tmp != NULL && tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);
}

void	redir_add(t_redir **lst, t_redir *new)
{
	t_redir	*last;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = redir_last(*lst);
	last->next = new;
}

void	redir_clear(t_redir **lst)
{
	t_redir	*tmp;
	t_redir	*next;

	if (!lst || !*lst)
		return ;
	tmp = *lst;
	while (tmp)
	{
		next = tmp->next;
		if (tmp->fd != -1)
			close(tmp->fd);
		free(tmp->file);
		free(tmp);
		tmp = next;
	}
	*lst = NULL;
}

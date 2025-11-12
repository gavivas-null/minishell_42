/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_tokens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavivas- <gavivas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 19:56:19 by gavivas-          #+#    #+#             */
/*   Updated: 2025/10/27 19:56:20 by gavivas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_token	*create_token(char *content)
{
	t_token	*new;

	new = malloc(sizeof(t_token));
	if (!new)
		return (NULL);
	new->token = content;
	new->next = NULL;
	return (new);
}

t_token	*last_token(t_token *lst)
{
	t_token	*new;

	new = lst;
	while (new != NULL && new->next != NULL)
		new = new->next;
	return (new);
}

void	add_token(t_token **lst, t_token *new)
{
	if (new)
	{
		if (!*lst)
		{
			*lst = new;
		}
		else
			last_token(*lst)->next = new;
	}
}

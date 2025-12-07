/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_tokens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavivas- <gavivas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 19:56:19 by gavivas-          #+#    #+#             */
/*   Updated: 2025/12/07 20:55:30 by gavivas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_mini_token	*create_token(char *content)
{
	t_mini_token	*new;

	new = malloc(sizeof(t_mini_token));
	if (!new)
		return (NULL);
	new->token = content;
	new->next = NULL;
	return (new);
}

t_mini_token	*last_token(t_mini_token *lst)
{
	t_mini_token	*new;

	new = lst;
	while (new != NULL && new->next != NULL)
		new = new->next;
	return (new);
}

void	add_token(t_mini_token **lst, t_mini_token *new)
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

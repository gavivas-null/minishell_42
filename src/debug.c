/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavivas- <gavivas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 20:54:01 by gavivas-          #+#    #+#             */
/*   Updated: 2025/12/10 21:22:13 by gavivas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	debug_print_tokens(t_lexer *lex)
{
	t_token	*tok;
    int		index;

	index = 0;
	if (!lex)
		return ;
	tok = lex->head;
	while (tok != NULL)
	{
		if (tok->type == TOKEN_WORD)
			printf("[%i] TOKEN_WORD\n", index);
		else if (tok->type == TOKEN_PIPE)
			printf("[%i] TOKEN_PIPE\n", index);
		else if (tok->type == TOKEN_REDIR_IN)
			printf("[%i] TOKEN_REDIR_IN\n", index);
		else if (tok->type == TOKEN_REDIR_OUT)
			printf("[%i] TOKEN_REDIR_OUT\n", index);
		else if (tok->type == TOKEN_HEREDOC)
			printf("[%i] TOKEN_HEREDOC\n", index);
		else if (tok->type == TOKEN_APPEND)
			printf("[%i] TOKEN_APPEND\n", index);
		else if (tok->type == TOKEN_EOF)
			printf("[%i] TOKEN_EOF\n", index);
		else if (tok->type == TOKEN_ERROR)
			printf("[%i] TOKEN_ERROR\n", index);
		tok = tok->next;
		index++;
    }
}

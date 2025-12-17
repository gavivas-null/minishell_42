/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavivas- <gavivas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 17:41:34 by gavivas-          #+#    #+#             */
/*   Updated: 2025/12/17 18:30:51 by gavivas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <minishell.h>

static t_rtype	get_redir_type(t_token_type type)
{
	if (type == TOKEN_REDIR_IN)
		return (R_IN);
	if (type == TOKEN_REDIR_OUT)
		return (R_OUT_TRUNC);
	if (type == TOKEN_APPEND)
		return (R_OUT_APPEND);
	if (type == TOKEN_HEREDOC)
		return (R_HEREDOC);
	return (-1);
}

t_cmd   *parse_tokens(t_lexer *lex)
{
    t_token *tok;
    t_cmd   *cmd;

    if (!lex || !lex->head)
        return (NULL);
    cmd = cmd_new();
    if (!cmd)
        return (NULL);
    tok = lex->head;
    while (tok && tok->type != TOKEN_EOF)
    {
        if (tok->type == TOKEN_WORD && tok->value)
            cmd_add_arg(cmd, tok->value);
		else if (tok->type == TOKEN_PIPE)

        else if (tok->type == TOKEN_REDIR_IN)

        else if (tok->type == TOKEN_REDIR_OUT)

        else if (tok->type == TOKEN_HEREDOC)

        else if (tok->type == TOKEN_APPEND)

        else if (tok->type == TOKEN_EOF)

        else if (tok->type == TOKEN_ERROR)

        tok = tok->next;
    }
    return (cmd);
}

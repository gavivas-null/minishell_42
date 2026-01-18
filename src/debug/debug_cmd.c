/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavivas- <gavivas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 01:24:37 by gavivas-          #+#    #+#             */
/*   Updated: 2026/01/18 19:18:47 by gavivas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	print_rtype(t_rtype type)
{
	if (type == R_IN)
		printf("R_IN");
	else if (type == R_OUT_TRUNC)
		printf("R_OUT_TRUNC");
	else if (type == R_OUT_APPEND)
		printf("R_OUT_APPEND");
	else if (type == R_HEREDOC)
		printf("R_HEREDOC");
	else
		printf("R_UNKNOWN");
}

void	debug_print_cmd(t_cmd *cmd)
{
	t_redir	*r;
	int		i;

	if (!cmd)
		return ;
	printf("----- CMD -----\n");
	i = 0;
	while (cmd->argv && cmd->argv[i])
	{
		printf("[%d] argv: %s\n", i, cmd->argv[i]);
		i++;
	}
	r = cmd->redir;
	while (r)
	{
		printf("redir: ");
		print_rtype(r->type);
		printf(" file=%s fd=%d\n", r->file, r->fd);
		r = r->next;
	}
	printf("---------------\n");
}

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

static char	*debug_word_to_str(t_token *tok)
{
	t_segment	*seg;
	char		*res;
	char		*tmp;

	if (!tok || tok->type != TOKEN_WORD)
		return (NULL);
	res = ft_strdup("");
	if (!res)
		return (NULL);
	seg = tok->segments;
	while (seg)
	{
		tmp = ft_strjoin(res, seg->str);
		free(res);
		if (!tmp)
			return (NULL);
		res = tmp;
		seg = seg->next;
	}
	return (res);
}

int	debug_build_cmd_from_tokens(t_lexer *lex)
{
	t_token	*tok;
	t_cmd	*cmd;
	t_rtype	type;
	char	*word;

	if (!lex || !lex->head)
		return (0);
	tok = lex->head;
	if (tok->type != TOKEN_WORD)
		return (0);
	word = debug_word_to_str(tok);
	if (!word)
		return (0);
	if (ft_strcmp(word, "debug") != 0)
		return (free(word), 0);
	free(word);
	cmd = cmd_new();
	if (!cmd)
		return (1);
	tok = tok->next;
	while (tok && tok->type != TOKEN_EOF)
	{
		if (tok->type == TOKEN_WORD)
		{
			word = debug_word_to_str(tok);
			if (!word)
				return (cmd_clear(cmd), 1);
			cmd_add_arg(cmd, word);
			free(word);
		}
		else if (tok->type == TOKEN_REDIR_IN
			|| tok->type == TOKEN_REDIR_OUT
			|| tok->type == TOKEN_APPEND
			|| tok->type == TOKEN_HEREDOC)
		{
			type = get_redir_type(tok->type);
			tok = tok->next;
			if (tok && tok->type == TOKEN_WORD)
			{
				word = debug_word_to_str(tok);
				if (!word)
					return (cmd_clear(cmd), 1);
				cmd_add_redir(cmd, type, word);
				free(word);
			}
			else
				printf("debug: redirection without target\n");
		}
		tok = tok->next;
	}
	debug_print_cmd(cmd);
	cmd_clear(cmd);
	return (1);
}

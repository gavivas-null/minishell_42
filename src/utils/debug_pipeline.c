/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_pipeline.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavivas- <gavivas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 21:07:38 by gavivas-          #+#    #+#             */
/*   Updated: 2026/01/18 21:13:13 by gavivas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static char	*dbg_word_to_str(t_token *tok)
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

static void	dbg_print_redir_type(t_redir_type type)
{
	if (type == REDIR_IN)
		printf("< ");
	else if (type == REDIR_OUT)
		printf("> ");
	else if (type == REDIR_APPEND)
		printf(">> ");
	else if (type == REDIR_HEREDOC)
		printf("<< ");
}

static void	debug_print_cmd(t_cmd *cmd, int index)
{
	int		i;
	char	*word;
	t_redir	*r;

	printf("CMD[%d]\n", index);
	i = 0;
	while (i < cmd->argc)
	{
		word = dbg_word_to_str(cmd->argv[i]);
		if (word)
		{
			printf("  argv[%d]: %s\n", i, word);
			free(word);
		}
		i++;
	}
	r = cmd->redirs;
	while (r)
	{
		printf("  redir ");
		dbg_print_redir_type(r->type);
		word = dbg_word_to_str(r->target);
		if (word)
		{
			printf("%s\n", word);
			free(word);
		}
		r = r->next;
	}
}

void	debug_print_pipeline(t_pipeline *p)
{
	int	i;

	if (!p)
		return ;
	printf("PIPELINE (%d cmds)\n", p->count);
	i = 0;
	while (i < p->count)
	{
		debug_print_cmd(p->cmds[i], i);
		i++;
	}
}

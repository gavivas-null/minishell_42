/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavivas- <gavivas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 19:46:19 by gavivas-          #+#    #+#             */
/*   Updated: 2026/01/18 21:23:50 by gavivas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	start_shell(t_mini *mini)
{
	char		*line;
	char		*tmp;
	int			running;
	t_lexer		*lex;
	t_pipeline	*p;

	running = 1;
	(void)mini;
	while (running)
	{
		line = readline("minishell> ");
		if (line == NULL)
			break ;
		tmp = line;
		while (*tmp == ' ' || *tmp == '\t')
			tmp++;
		if (*tmp == '\0')
		{
			free(line);
			continue ;
		}
		add_history(tmp);
		lex = lexer_tokenize(tmp);
		if (!lex)
		{
			free(line);
			continue ;
		}
		if (lex->error)
		{
			lexer_destroy(lex);
			free(line);
			continue ;
		}
		p = parse_tokens(lex->head);
		if (!p)
			printf("syntax error\n");
		else
		{
			debug_print_pipeline(p);
			free_pipeline(p);
		}
		lexer_destroy(lex);
		free(line);
	}
}

int	main(int argc, char **args, char **envp)
{
	t_mini	mini;

	(void)argc;
	(void)args;
	extract_envp(&mini, envp);
	start_shell(&mini);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavivas- <gavivas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 19:46:19 by gavivas-          #+#    #+#             */
/*   Updated: 2025/12/13 01:31:48 by gavivas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	start_shell(t_mini *mini)
{
	char	*line;
	int		running;
	t_lexer	*lex;

	running = 1;
	mini->envp = NULL;
	while (running)
	{
		line = readline("minishell> ");
		if (line == NULL)
			break ;
		if (line[0] == '\0')
		{
			free(line);
			continue ;
		}
		add_history(line);
		lex = lexer_tokenize(line);
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
		if (debug_build_cmd_from_tokens(lex) == 1)
		{
			lexer_destroy(lex);
			free(line);
			continue ;
		}
		debug_print_tokens(lex);
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

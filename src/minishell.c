/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavivas- <gavivas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 19:46:19 by gavivas-          #+#    #+#             */
/*   Updated: 2025/10/29 18:47:39 by gavivas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	start_shell(t_mini *mini)
{
	char	*line;
	int		running;

	running = 1;
	mini->data = NULL;
	while (running)
	{
		line = readline("minishell> ");
		if (line == NULL)
			break ;
		else if (line[0] == '\0')
			continue ;
		add_history(line);
		read_tokens(mini, line);
		find_variable_key(mini->envp, line);
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

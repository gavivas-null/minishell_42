/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavivas- <gavivas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 19:49:37 by gavivas-          #+#    #+#             */
/*   Updated: 2025/10/26 19:53:56 by gavivas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	start_shell(void)
{
	char	*line;
	int		running;

	running = 1;
	while (running)
	{
		line = readline("minishell> ");
		if (line == NULL)
			running = 0;
		else if (line[0] == '\0')
			continue ;
		add_history(line);
		free(line);
	}
}

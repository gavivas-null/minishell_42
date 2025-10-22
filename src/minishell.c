/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavivas- <gavivas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 19:46:19 by gavivas-          #+#    #+#             */
/*   Updated: 2025/10/22 21:52:44 by gavivas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	main(void)
{
	char	*line;
	char	*my_history;

	my_history = "tmp/minishell_history";
	read_history(my_history);
	using_history();
	stifle_history(5);
	while ((line = readline("minishell> ")) != NULL)
	{
		printf("Got: %s\n", line);
		add_history(line);
		write_history(my_history);
		free(line);
	}
	clear_history();
	return (0);
}

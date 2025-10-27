/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_envp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavivas- <gavivas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 19:54:57 by gavivas-          #+#    #+#             */
/*   Updated: 2025/10/27 20:08:31 by gavivas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	extract_envp(t_mini *mini, char **envp)
{
	int	i;

	i = 0;
	(void)mini;
	while (envp[i])
	{
		printf("envp:		%s\n", envp[i]);
		i++;
	}
}

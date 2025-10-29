/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavivas- <gavivas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 17:34:26 by gavivas-          #+#    #+#             */
/*   Updated: 2025/10/29 18:46:55 by gavivas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	*find_variable_key(t_envp *dct, char *key)
{
	t_envp	*tmp;
	int		cmp;

	tmp = dct;
	while (tmp != NULL)
	{
		cmp = ft_strcmp(tmp->key, key);
		if (cmp == 0)
		{
			return (tmp->value);
		}
		tmp = tmp->next;
	}
	return (NULL);
}

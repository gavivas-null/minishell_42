/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavivas- <gavivas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 17:34:26 by gavivas-          #+#    #+#             */
/*   Updated: 2025/10/29 20:23:50 by gavivas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_envp	*find_variable_key(t_envp *dct, char *key)
{
	t_envp	*tmp;
	int		cmp;

	tmp = dct;
	if (key[0] != '$')
		return (NULL);
	else
		key++;
	while (tmp != NULL)
	{
		cmp = ft_strcmp(tmp->key, key);
		if (cmp == 0)
		{
			printf("%s\n", tmp->value);
			return (tmp);
		}
		tmp = tmp->next;
	}
	return (NULL);
}

int	insert_new_variable(t_envp *dct, char *key, char *value)
{
	if (find_variable_key(dct, key) != NULL)
	{
		printf("esta variable ya existe: %s=%s\n", key, value);
		return (EXIT_FAILURE);
	}
	return (EXIT_FAILURE);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavivas- <gavivas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 17:34:26 by gavivas-          #+#    #+#             */
/*   Updated: 2025/10/29 20:59:04 by gavivas-         ###   ########.fr       */
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

t_envp	*add_variable(t_envp **env, char *key, char *value)
{
	t_envp	*tmp;
	t_envp	*node;

	if (!key || !*key)
		return (NULL);
	if (!ft_isalpha(key[0]) || key[0] != '_')
		return (NULL);
	if (!ft_str_isalnum(key))
		return (NULL);
}
